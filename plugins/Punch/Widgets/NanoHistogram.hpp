/*
 * Copyright (C) 2018-2019 Rob van den Berg <rghvdberg at gmail dot org>
 *
 * This file is part of CharacterCompressor
 *
 * Nnjas2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CharacterCompressor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CharacterCompressor.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef NANO_HISTOGRAM_HPP_INCLUDED
#define NANO_HISTOGRAM_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"
#include "../Resources/Colors.hpp"

START_NAMESPACE_DISTRHO

class NanoHistogram : public NanoWidget
{
public:
    explicit NanoHistogram(NanoWidget * parent);
    void setValues(float input, float output, float gain_reduction);
    void setHistoryLength( int history);
 
protected:
    void onNanoDisplay() override;

private:
    
    int historyHead, history;
    void drawOutput();
    void drawInput();
    void drawGainReduction();
    std::vector<float> fInVolumeHistory;
    std::vector<float> fOutVolumeHistory;
    std::vector<float> fGainReductionHistory;
    DISTRHO_LEAK_DETECTOR(NanoHistogram)
};

END_NAMESPACE_DISTRHO

#endif
