#include "PunchPlugin.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

PunchPlugin::PunchPlugin()
    : Plugin(parameterCount, 0, 0)
{
    punchDSP.init(getSampleRate());
    ringbuf = zix_ring_new(sizeof(float) * 48001);

    printf("sizeof(float) * 48001 = %li\n", sizeof(float) * 48001);
    zix_ring_mlock(ringbuf);
    printf("ring capacity %i\n", zix_ring_capacity(ringbuf));
    avgBuffer = new float[zix_ring_capacity(ringbuf)];
    lastAvg = 0;
}

PunchPlugin::~PunchPlugin()
{
    printf("cleaning up\n");
    zix_ring_free(ringbuf);
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

float PunchPlugin::getGR()
{
    //
    size_t const maxRead = zix_ring_read_space(ringbuf);
    size_t const maxFloats = maxRead / sizeof(float);

    if (maxRead && avgBuffer)
    {
        float avg = 0;
        zix_ring_read(ringbuf, avgBuffer, maxRead);

        for (size_t i = 0; i < maxFloats; i++)
        {
            avg += avgBuffer[i];
        }
        avg = avg / maxFloats;
        lastAvg = avg;
    }
    return lastAvg;
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
    if (zix_ring_write_space(ringbuf) >= sizeof(float) * frames)
    {
        zix_ring_write(ringbuf, gr, sizeof(float) * frames);
    }

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
