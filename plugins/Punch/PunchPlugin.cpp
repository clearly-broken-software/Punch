/*
 * Copyright (C) 20202 Rob van den Berg <rghvdberg at gmail dot org>
 *
 * This file is part of CharacterCompressor
 *
 * Punch is free software: you can redistribute it and/or modify
 * it under the of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Punch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Uprising.  If not, see <https://www.gnu.org/licenses/>.
 */


#include "DistrhoPluginInfo.h"
#include "DistrhoPlugin.hpp"
#include "PunchDSP.hpp"
#include <chrono>

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class PunchPlugin : public Plugin
{
public:
    PunchPlugin()
        : Plugin(parameterCount, 0, 0)
    {
        punchDSP.init(getSampleRate());
        //newTime = std::chrono::high_resolution_clock::now();
    }

protected:
    const char *getLabel() const override
    {
        return "Punch";
    }

    const char *getDescription() const override
    {
        return "Punch, a compressor with character";
    }

    const char *getMaker() const override
    {
        return "Clearly Broken Software";
    }

    const char *getHomePage() const override
    {
        return "https://github.com/clearly-broken-software/Punch";
    }

    const char *getLicense() const override
    {
        return "GPL";
    }

    uint32_t getVersion() const override
    {
        return d_version(0, 0, 1);
    }

    int64_t getUniqueId() const override
    {
        return d_cconst('P', 'u', 'n', 'c');
    }

    void initParameter(uint32_t index, Parameter &parameter) override
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

    float getParameterValue(uint32_t index) const override
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

    void setParameterValue(uint32_t index, float value) override
    {
        punchDSP.set_parameter(index, value);
    }

    void run(const float **inputs, float **outputs, uint32_t frames) override
    {
        punchDSP.process(inputs[0], inputs[1], outputs[0], outputs[1], frames);

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

private:
    PunchDSP punchDSP;
    float fInput, fOutput;
    //std::chrono::high_resolution_clock::time_point oldTime, newTime;

    /*  void printFPS() const
    {
       const std::chrono::high_resolution_clock::time_point currentime = std::chrono::high_resolution_clock::now();
       const long int epoch = currentime.time_since_epoch().count();
       printf("%li\n",  epoch);
    
    } */

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PunchPlugin)
};

Plugin *createPlugin()
{
    return new PunchPlugin();
}

END_NAMESPACE_DISTRHO
