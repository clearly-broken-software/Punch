#include "PunchPlugin.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

PunchPlugin::PunchPlugin()
    : Plugin(parameterCount, 0, 0)
{
    punchDSP.init(getSampleRate());
    const auto ringSize = sizeof(float) * 48001;
    grBuf = zix_ring_new(ringSize);
    zix_ring_mlock(grBuf);

    audioInBuf = zix_ring_new(ringSize);
    zix_ring_mlock(audioInBuf);
    audioOutBuf = zix_ring_new(ringSize);
    zix_ring_mlock(audioOutBuf);

    const size_t avgBufferSize = zix_ring_capacity(grBuf) / sizeof(float);
    avgBuffer = new float[avgBufferSize];
    //lastAvg = 0;
    lastGr = 0.0f;
    lastAudioIn = 0.0f;
    lastAudioOut = 0.0f;
}

PunchPlugin::~PunchPlugin()
{
    printf("cleaning up\n");
    zix_ring_free(grBuf);
    zix_ring_free(audioInBuf);
    zix_ring_free(audioOutBuf);
    delete avgBuffer;
}

void PunchPlugin::initParameter(uint32_t index, Parameter &parameter)
{

    switch (index)
    {

    case kInputLevel:
    {
        parameter.name = "input level";
        parameter.symbol = "inputLevel";
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        parameter.hints = kParameterIsOutput;
        break;
    }
    case kOutputLevel:
    {
        parameter.name = "output level";
        parameter.symbol = "outputLevel";
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        parameter.hints = kParameterIsOutput;
        break;
    }
    case kGr:
    {
        parameter.hints = kParameterIsOutput;
        parameter.ranges.min = punchDSP.parameter_range(index)->min;
        parameter.ranges.max = punchDSP.parameter_range(index)->max;
        parameter.ranges.def = punchDSP.parameter_range(index)->init;
        parameter.name = punchDSP.parameter_label(index);
        parameter.symbol = punchDSP.parameter_symbol(index);
        parameter.unit = punchDSP.parameter_unit(index);
        break;
    }
    case kAutoRelease:
        parameter.hints = kParameterIsOutput;
        parameter.ranges.min = punchDSP.parameter_range(index)->min;
        parameter.ranges.max = punchDSP.parameter_range(index)->max;
        parameter.ranges.def = punchDSP.parameter_range(index)->init;
        parameter.name = punchDSP.parameter_label(index);
        parameter.symbol = punchDSP.parameter_symbol(index);
        parameter.unit = punchDSP.parameter_unit(index);
        break;
    case kScrollSpeed:
        parameter.hints = kParameterIsAutomable;
        parameter.ranges.min = 0.01f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.03;
        parameter.name = "Scroll speed";
        parameter.symbol = "scrollspeed";
        break;
    default:
        parameter.hints = kParameterIsAutomable;
        parameter.ranges.min = punchDSP.parameter_range(index)->min;
        parameter.ranges.max = punchDSP.parameter_range(index)->max;
        parameter.ranges.def = punchDSP.parameter_range(index)->init;
        parameter.name = punchDSP.parameter_label(index);
        //parameter. = punchDSP.parameter_short_label(index);
        parameter.symbol = punchDSP.parameter_symbol(index);
        parameter.unit = punchDSP.parameter_unit(index);
        break;
    }
}

void PunchPlugin::getHistoGramValues(int pixels, float *gr, float *audioIn, float *audioOut)
{
    // TODO loooooonnnngggg function , optimize this perhaps

    // gr
    size_t maxRead = zix_ring_read_space(grBuf);
    if (maxRead == 0) // no bytes to read, fill histogram with last value
    {
        for (int i = 0; i < pixels; i++)
        {
            gr[i] = lastGr;
            audioIn[i] = lastAudioIn;
            audioOut[i] = lastAudioOut;
        }
        return;
    }

    size_t maxFloats = maxRead / sizeof(float);
    //  printf("%i,%i\n",maxRead,maxFloats);

    zix_ring_read(grBuf, avgBuffer, maxRead);
    auto range = maxFloats / pixels;
    for (int i = 0; i < pixels; i++)
    {
        float sum = 0;
        for (int j = 0; j < range; j++)
        {
            sum += avgBuffer[j + i * range];
        }
        gr[i] = sum / range;
        //   printf("avg i %i values[%i] %f", i, values[i]);
    }
     lastGr = gr[pixels -1]; 
    
    // audio in
    maxRead = zix_ring_read_space(audioInBuf);
    if (maxRead == 0)
    {
        for (int i = 0; i < pixels; i++)
        {
            gr[i] = lastGr;
            audioIn[i] = lastAudioIn;
            audioOut[i] = lastAudioOut;
        }
        return;
    }

    maxFloats = maxRead / sizeof(float);
    zix_ring_read(audioInBuf, avgBuffer, maxRead);
    range = maxFloats / pixels;
    for (int i = 0; i < pixels; i++)
    {
        float sum = 0;
        for (int j = 0; j < range; j++)
        {
            sum += fabs(avgBuffer[j + i * range]);
        }
        float avg = sum / range;
        audioIn[i] = avg > 0.0f ? 20 * log10(avg) : -60.0f;
        //  printf("audio in %f\n", audioIn[i]);
    }
    lastAudioIn = audioIn[pixels -1]; 
    
    // audio out
    maxRead = zix_ring_read_space(audioOutBuf);
    if (maxRead == 0)
        if (maxRead == 0)
        {
            for (int i = 0; i < pixels; i++)
            {
                gr[i] = lastGr;
                audioIn[i] = lastAudioIn;
                audioOut[i] = lastAudioOut;
            }
            return;
        }
    maxFloats = maxRead / sizeof(float);
    zix_ring_read(audioOutBuf, avgBuffer, maxRead);
    range = maxFloats / pixels;
    for (int i = 0; i < pixels; i++)
    {
        float sum = 0;
        for (int j = 0; j < range; j++)
        {
            sum += fabs(avgBuffer[j + i * range]);
        }
        float avg = sum / range;
        audioOut[i] = avg > 0.0f ? 20 * log10(avg) : -60.0f;
        //     printf("audio out[%i] %f\n", i, audioOut[i]);
    }
    lastAudioOut = audioOut[pixels -1]; 
}

float PunchPlugin::getParameterValue(uint32_t index) const
{
    switch (index)
    {
    case kInputLevel:
        return fInput;
        break;
    case kOutputLevel:
        return fOutput;
        break;
    case kScrollSpeed:
        return scrollSpeed;
        break;

    default:
        return punchDSP.get_parameter(index);
    }
}

void PunchPlugin::setParameterValue(uint32_t index, float value)
{
    switch (index)
    {
    case kScrollSpeed:
        scrollSpeed = value;
        break;
    default:
        punchDSP.set_parameter(index, value);
    }
}

void PunchPlugin::run(const float **inputs, float **outputs, uint32_t frames)
{
    float gr[frames];
    punchDSP.process(inputs[0], inputs[1], outputs[0], outputs[1], gr, frames);

    if (zix_ring_write_space(grBuf) >= sizeof(float) * frames)
        zix_ring_write(grBuf, gr, sizeof(float) * frames);
    //TODO sum the inputs and outputs
    if (zix_ring_write_space(audioOutBuf) >= sizeof(float) * frames)
        zix_ring_write(audioInBuf, inputs[0], sizeof(float) * frames);

    if (zix_ring_write_space(audioOutBuf) >= sizeof(float) * frames)
        zix_ring_write(audioOutBuf, outputs[0], sizeof(float) * frames);

    float tmp;
    float tmpLeft = 0.0f;
    float tmpRight = 0.0f;

    // inputs;

    for (uint32_t i = 0; i < frames; ++i)
    {
        // left
        tmp = std::abs(inputs[0][i]);
        if (tmp > tmpLeft)
            tmpLeft = tmp;
        // right
        tmp = std::abs(inputs[1][i]);
        if (tmp > tmpRight)
            tmpRight = tmp;
    }

    if (tmpLeft > 1.0f)
        tmpLeft = 1.0f;
    if (tmpRight > 1.0f)
        tmpRight = 1.0f;
    fInput = (tmpLeft + tmpRight) / 2;

    // outputs;
    tmpLeft = 0.0f;
    tmpRight = 0.0f;
    for (uint32_t i = 0; i < frames; ++i)
    {
        // left
        tmp = std::abs(outputs[0][i]);
        if (tmp > tmpLeft)
            tmpLeft = tmp;
        // right
        tmp = std::abs(outputs[1][i]);
        if (tmp > tmpRight)
            tmpRight = tmp;
    }

    if (tmpLeft > 1.0f)
        tmpLeft = 1.0f;
    if (tmpRight > 1.0f)
        tmpRight = 1.0f;
    fOutput = (tmpLeft + tmpRight) / 2;
}

Plugin *createPlugin()
{
    return new PunchPlugin();
}

END_NAMESPACE_DISTRHO
