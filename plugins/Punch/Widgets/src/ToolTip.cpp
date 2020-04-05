#include "ToolTip.hpp"

START_NAMESPACE_DISTRHO

ToolTip::ToolTip(Widget *widget)
    : NanoWidget(widget)
{
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
}

void ToolTip::onNanoDisplay()
{
    auto w = getWidth();
    auto h = getHeight();
    beginPath();
    fillColor(0.0f, 0.0f, 0.0f, .7f);
    strokeColor(255, 255, 255);
    rect(0, 0, w, h );
    fill();
    stroke();
    closePath();
    //Label
    beginPath();
    fontFaceId(fNanoFont);
    textAlign( ALIGN_CENTER | ALIGN_TOP);
    fontSize(14);
    fillColor(255, 255, 255, 255);
    text(w/2, 0, Label.c_str(), NULL);
    closePath();
}

void ToolTip::setLabel(std::string label)
{
    Label = label;
    Rectangle<float> bounds;
    textBounds(0, 0, Label.c_str(), NULL, bounds);
    const uint w = bounds.getWidth();
    const uint h = bounds.getHeight();
    setSize(w, h);
}

END_NAMESPACE_DISTRHO
