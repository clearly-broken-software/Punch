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

#include "NanoSlider.hpp"
#include "Window.hpp"

START_NAMESPACE_DISTRHO

NanoSlider::NanoSlider(Widget *widget, Callback *cb)
    : CbWidget(widget),
      fCallback(cb),
      mouseDown(false)

{
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
    handle.setPos(0, 0);
    handle.setSize(getWidth(), 2);
}

void NanoSlider::onNanoDisplay()
{
    const float normValue = (fValue - fMin) / (fMax - fMin);
    auto w = getWidth();
    auto h = getHeight();
    auto margin = 1.0f;
    const float handleHeight = std::max(h / 10.0f, 2.0f);
    const float range = h - handleHeight;
    handle.setSize(w, handleHeight);
    handle.setPos(0, range * normValue);

    // Slider
    beginPath();
    fillColor(64, 64, 64, 255);
    roundedRect(0.0f, 0.0f, w, h, 2.0f);
    fill();
    closePath();

    // Handle
    beginPath();
    fillColor(cHandle);
    roundedRect(0, range * normValue, w, handleHeight, 2.0f);
    fill();
    closePath();

    /*  //Label
    beginPath();
    fontFaceId(fNanoFont);
    fontSize(14);
    Rectangle<float> bounds;
    textBounds(0, 0, Label.c_str(), NULL, bounds);
    float tw = bounds.getWidth();
    float th = bounds.getHeight();
    float tx = w / 2.0f - tw / 2.0f;
    float ty = h - th;

    fillColor(255, 255, 255, 255);
    text(tx, ty, Label.c_str(), NULL);
    closePath();

    // Value
    // draw value bg
    beginPath();
    fillColor(50, 50, 50, 255);
    const float bgWidth = fRadius + fRadius / 4;
    const float bgHeight = 18;
    rect(w / 2 - bgWidth / 2, fRadius - bgHeight / 2, bgWidth, bgHeight);
    fill();
    closePath();
    // text
    beginPath();
    char buffer[32];
    sprintf(buffer, "%.1f", getValue());
    fontSize(12);
    textAlign(ALIGN_MIDDLE | ALIGN_TOP);
    textBounds(0, 0, buffer, NULL, bounds);
    fontFaceId(fNanoFont);
    fillColor(255, 255, 255, 255);
    tx = w / 2 - bounds.getWidth() / 2;
    ty = fRadius - bounds.getHeight() / 2;
    text(tx, ty, buffer, NULL);
    closePath(); */
}

void NanoSlider::setLabel(std::string label)
{
    Label = label;
}

void NanoSlider::setColor(Color color)
{
    cHandle = color;
}

bool NanoSlider::onMouse(const MouseEvent &ev)
{
    auto foo = handle.contains(ev.pos);
    if (ev.press & foo)
    {
        mouseDown = true;
        mousePoint = ev.pos;
        return false;
    }
    else if (mouseDown)
    {
        mouseDown = false;
        return false;
    }
    return false;
}

bool NanoSlider::onMotion(const MotionEvent &ev)
{

    if (contains(ev.pos) && !mouseDown)

    {
        *ptrHasMouse = this;
    }
    else
    {
        if (*ptrHasMouse)
        {
            if (((*ptrHasMouse)->getId() == getId()) && !mouseDown)
                *ptrHasMouse = nullptr;
        }
    }

    if (mouseDown)
    {
        const float resistance = 200.0f;
        const float difference = (mousePoint.getY() - ev.pos.getY()) / resistance * (fMax - fMin);
        mousePoint.setY(ev.pos.getY());
        setValue(fValue - difference);
        fCallback->nanoSliderValueChanged(this, fValue);
        return true;
    }

    return false;
}

bool NanoSlider::onScroll(const ScrollEvent &ev)
{
    if (!contains(ev.pos))
        return false;
    float delta = ev.delta.getY() * (fMax - fMin) / 20;
    setValue(fValue - delta);
    fCallback->nanoSliderValueChanged(this, fValue);
    return true;
}

END_NAMESPACE_DISTRHO
