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

#include "NanoHistogram.hpp"

START_NAMESPACE_DISTRHO

NanoHistogram::NanoHistogram(NanoWidget *widget)
    : NanoWidget(widget, 3)
{
    historyHead = 0;
    //fInVolumeHistory.resize(history);
    // fOutVolumeHistory.resize(history);
    // fGainReductionHistory.resize(history);
}

void NanoHistogram::setValues(float in, float out, float gr)
{
    // printf("setValues in %f, out %f, gr %f\n",in, out,gr);

    fInVolumeHistory[historyHead] = in;
    fOutVolumeHistory[historyHead] = out;
    fGainReductionHistory[historyHead] = gr;
}

void NanoHistogram::setHistoryLength(int h)
{
    history = h;
    fInVolumeHistory.resize(history);
    fOutVolumeHistory.resize(history);
    fGainReductionHistory.resize(history);
    std::fill(fInVolumeHistory.begin(), fInVolumeHistory.end(), -60.0f);
    std::fill(fOutVolumeHistory.begin(), fOutVolumeHistory.end(), -60.0f);
    std::fill(fGainReductionHistory.begin(), fGainReductionHistory.end(), 0.0f);
}

void NanoHistogram::onNanoDisplay()
{
    drawInput();
    drawOutput();
    drawGainReduction();
    historyHead++;
    historyHead %= history;
}

void NanoHistogram::drawOutput()
{
    const auto w = getWidth();
    const auto h = getHeight();
    const Paint bg = linearGradient(w / 2, 0, w / 2, h, Secondary1Shade0, Secondary1Shade4);
    beginPath();
    strokeColor(Secondary1Shade1);
    strokeWidth(1.0f);
    moveTo(0, -fOutVolumeHistory[historyHead]);
    for (int i = 1, j; i < history; i++)
    {
        j = (i + historyHead) % history;
        lineTo(i, 0 - fOutVolumeHistory[j]);
    }
    lineTo(w, h);
    lineTo(0, h);
    lineTo(0, -fOutVolumeHistory[historyHead]);

    fillColor(0, 0, 0);
    fill();
    fillPaint(bg);
    fill();
    stroke();
    closePath();
}

void NanoHistogram::drawInput()
{
    const auto w = getWidth();
    const auto h = getHeight();
    const Paint bg = linearGradient(w / 2, 0, w / 2, h, PrimaryShade0, PrimaryShade4);
    beginPath();
    strokeColor(PrimaryShade1);
    strokeWidth(1.0f);
    moveTo(0, -fInVolumeHistory[historyHead]);
    for (int i = 1, j; i < history; i++)
    {
        j = (i + historyHead) % history;
        lineTo(i, 0 - fInVolumeHistory[j]);
    }
    lineTo(w, h);
    lineTo(0, h);
    lineTo(0, -fInVolumeHistory[historyHead]);

    fillColor(0, 0, 0);
    fill();
    fillPaint(bg);
    fill();
    stroke();
    closePath();
}
void NanoHistogram::drawGainReduction()
{
    const auto w = getWidth();
    const auto h = getHeight();
    const float r1 = Secondary2Shade0.red;
    const float g1 = Secondary2Shade0.green;
    const float b1 = Secondary2Shade0.blue;
    const float r2 = Secondary2Shade4.red;
    const float g2 = Secondary2Shade4.green;
    const float b2 = Secondary2Shade4.blue;
    const Color col1 = Color(r1, g1, b1, 0.8f);
    const Color col2 = Color(r2, g2, b2, 0.8f);

    const Paint bg = linearGradient(w / 2, 0, w / 2, h, col1, col2);
    beginPath();
    strokeColor(Secondary2Shade1);
    strokeWidth(1.0f);
    moveTo(0, -fGainReductionHistory[historyHead]);
    for (int i = 1, j; i < history; i++)
    {
        j = (i + historyHead) % history;
        lineTo(i, 0 - fGainReductionHistory[j]);
    }
    lineTo(w, 0);
    lineTo(0, 0);
    lineTo(0, -fGainReductionHistory[historyHead]);
    stroke();

    //fillColor(255,255,255);
    fillPaint(bg);
    fill();
    closePath();
}
END_NAMESPACE_DISTRHO
