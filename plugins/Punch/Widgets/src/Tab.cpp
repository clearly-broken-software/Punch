#include "Tab.hpp"

START_NAMESPACE_DISTRHO

Tab::Tab(Widget *widget)
    : NanoWidget(widget)
{
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
}

void Tab::onNanoDisplay()
{
  //
}

void Tab::setLabel(std::string label)
{
    Label = label;
    Rectangle<float> bounds;
    textBounds(0, 0, Label.c_str(), NULL, bounds);
    const uint w = bounds.getWidth();
    const uint h = bounds.getHeight();
    setSize(w, h);
}

END_NAMESPACE_DISTRHO
