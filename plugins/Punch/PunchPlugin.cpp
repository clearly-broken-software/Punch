#include "PunchPlugin.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

PunchPlugin::PunchPlugin()
    : Plugin(parameterCount, 0, 0)
{
    punchDSP.init(getSampleRate());
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
    return punchDSP.get_parameter(kGr);
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
    default:
        return punchDSP.get_parameter(index);
    }
}

void PunchPlugin::setParameterValue(uint32_t index, float value) 
{
    punchDSP.set_parameter(index, value);
}

void PunchPlugin::run(const float **inputs, float **outputs, uint32_t frames) 
{
    float gr[frames];
    punchDSP.process(inputs[0], inputs[1], outputs[0], outputs[1], gr, frames);

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
