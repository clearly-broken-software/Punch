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

#ifndef NANO_SLIDER_HPP_INCLUDED
#define NANO_SLIDER_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"
#include "CbWidget.hpp"
#include <string>

START_NAMESPACE_DISTRHO

class NanoSlider : public CbWidget
{
public:
    class Callback
    {
    public:
        virtual ~Callback() {}
        virtual void nanoSliderValueChanged(NanoSlider *slider, float value) = 0;
    };
    explicit NanoSlider(Widget *parent, Callback *cb);

    void setLabel(std::string lable);
    void setColor(Color color);

protected:
    void onNanoDisplay() override;
    bool onMouse(const MouseEvent &ev) override;
    bool onScroll(const ScrollEvent &ev) override;
    bool onMotion(const MotionEvent &ev) override;

private:
    float fRadius;
    std::string Label;
    Callback *const fCallback;
    bool mouseDown;
    Point<int> mousePoint;
    FontId fNanoFont;
    Rectangle<int> handle;
    Color cHandle;
    bool hasMouse;

    DISTRHO_LEAK_DETECTOR(NanoSlider)
};

END_NAMESPACE_DISTRHO

#endif
