

#include "NanoKnob.hpp"
#include "Window.hpp"
#include <iostream>

START_NAMESPACE_DISTRHO

NanoKnob::NanoKnob(Widget *parent, Callback *cb)
    : CbWidget(parent),
      fRadius(1.0f),
      fCallback(cb),
      mouseDown(false),
      margin(1.0f)
{
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
}

void NanoKnob::onNanoDisplay()
{

    float normValue = (fValue - fMin) / (fMax - fMin);
    auto w = getWidth();
    auto h = getHeight();
    const float percentFilled = (fValue - fMin) / (fMax - fMin);
    // Knob
    beginPath();
    fillColor(64, 64, 64, 255);
    circle(w / 2, fRadius + margin, fRadius);
    fill();
    closePath();
    // arc
    beginPath();
    strokeWidth(margin * 2);
    strokeColor(cRange);
    arc(w / 2, fRadius + margin, fRadius - margin, 0.75f * M_PI, 0.25f * M_PI, NanoVG::Winding::CW);
    stroke();
    closePath();

    beginPath();
    strokeColor(cValue);
    arc(w / 2, fRadius + margin, fRadius - margin, 0.75f * M_PI, (0.75f + 1.5f * percentFilled) * M_PI, NanoVG::Winding::CW);
    stroke();
    closePath();

    //Indicator line
    beginPath();
    save();
    translate(w / 2, fRadius + margin);
    rotate((2.0f + ((normValue - 0.5f) * 1.5f)) * M_PI);
    fillColor(cValue);
    const float indicatorWidth = 3.0f * margin;
    const float x = w / 2 - indicatorWidth / 2;
    const float y = 0; // h/2 - fRadius;
    rect(x - w / 2, y - fRadius + margin, indicatorWidth, fRadius / 4);
    fill();
    restore();
    closePath();
    //Label
    beginPath();
    fontFaceId(fNanoFont);
    fontSize(12); // * margin);
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
    fontSize(12 * margin);
    textAlign(ALIGN_MIDDLE | ALIGN_TOP);
    textBounds(0, 0, buffer, NULL, bounds);
    fontFaceId(fNanoFont);
    fillColor(255, 255, 255, 255);
    tx = w / 2 - bounds.getWidth() / 2;
    ty = fRadius - bounds.getHeight() / 2;
    text(tx, ty, buffer, NULL);
    closePath();
}

void NanoKnob::setRadius(float radius)
{
    fRadius = radius;
}

void NanoKnob::setLabel(std::string label)
{
    Label = label;
}

void NanoKnob::setColors(Color value, Color range)
{
    cValue = value;
    cRange = range;
}

void NanoKnob::setMargin(float _margin)
{
    margin = _margin;
}
bool NanoKnob::onMouse(const MouseEvent &ev)
{
    if (ev.press & contains(ev.pos))
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

bool NanoKnob::onMotion(const MotionEvent &ev)
{
    if (contains(ev.pos))

    {
        *ptrHasMouse = this;
    }
    else
    {
        if (*ptrHasMouse)
        {

            if ((*ptrHasMouse)->getId() == getId())
                *ptrHasMouse = nullptr;
        }
    }

    if (mouseDown)
    {
        const float resistance = 200.0f;
        const float difference = (mousePoint.getY() - ev.pos.getY()) / resistance * (fMax - fMin);
        mousePoint.setY(ev.pos.getY());
        setValue(fValue + difference);
        fCallback->nanoKnobValueChanged(this, fValue);
        *ptrHasMouse = nullptr;
        return true;
    }

    return false;
}

bool NanoKnob::onScroll(const ScrollEvent &ev)
{
    if (!contains(ev.pos))
        return false;
    float delta = ev.delta.getY() * (fMax - fMin) / 50;
    setValue(fValue + delta);
    fCallback->nanoKnobValueChanged(this, getValue());
    *ptrHasMouse = nullptr;
    return true;
}

END_NAMESPACE_DISTRHO
