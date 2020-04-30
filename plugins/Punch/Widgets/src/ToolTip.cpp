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
    rect(0, 0, w, h);
    fill();
    stroke();
    closePath();
    //Label
    beginPath();
    fontFaceId(fNanoFont);
    textAlign(ALIGN_LEFT | ALIGN_TOP);
    fontSize(14);
    fillColor(255, 255, 255, 255);
    textBox(2, 2, 200.0f, Label.c_str(), NULL);
    closePath();
}

void ToolTip::setLabel(std::string label)
{
    Label = label;
    float bounds[4];
    textBoxBounds(0, 0, 200.0f, Label.c_str(), NULL, bounds);
    const uint w = bounds[2] + 4;
    const uint h = bounds[3] + 4;
    setSize(w, h);
}

END_NAMESPACE_DISTRHO
