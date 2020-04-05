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

#include "NanoMeter.hpp"
#include "Window.hpp"

START_NAMESPACE_DISTRHO


NanoMeter::NanoMeter(Widget* parent)
    : NanoWidget(parent),
      fValue(0.0f),
      fMin(0.0f),
      fMax(1.0f)
{
}

void NanoMeter::onNanoDisplay()
{
float normValue = 1 - (fValue-fMin) / (fMax - fMin);
auto w = getWidth();
auto h = getHeight();
auto meterHeight = normValue * h;
// background
beginPath();
fillColor(64,64,64,255);

rect(0,0,w,h);
fill();
closePath();
// meter
beginPath();
fillColor(0,128,0,255);
rect (0,0,w,meterHeight);
fill();
closePath();
}

void NanoMeter::setValue(float value)
{
    fValue = value; 
    repaint();
}

void NanoMeter::setRange(float min, float max)
{
    fMin = min;
    fMax = max;

}

END_NAMESPACE_DISTRHO
