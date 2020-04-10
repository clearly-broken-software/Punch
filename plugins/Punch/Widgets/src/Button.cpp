

#include "Button.hpp"
#include "Window.hpp"

START_NAMESPACE_DISTRHO

Button::Button(Widget *parent, Callback *cb)
    : NanoWidget(parent),
      fCallback(cb),
      buttonActive(false)
{
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
    labelColor = Color(255, 255, 255);
    backgroundColor = Color(32,32,32);
    Label = "button";
}

void Button::onNanoDisplay()
{
    auto w = getWidth();
    auto h = getHeight();
    auto margin = 1.0f;

    // Background
    beginPath();
    fillColor(backgroundColor);
    strokeColor(borderColor);
    rect(margin,margin,w - 2 * margin,h-2*margin);
    fill();
    stroke();
    closePath();

    //Label
    beginPath();
    fontFaceId(fNanoFont);
    fontSize(14);
    fillColor(labelColor);
    Rectangle<float> bounds;
    textBounds(0, 0, Label.c_str(), NULL, bounds);
    float tw = bounds.getWidth();
    float th = bounds.getHeight();
    float tx = w / 2.0f ;
    float ty = h / 2.0f;
    textAlign(ALIGN_CENTER | ALIGN_MIDDLE);

    fillColor(255, 255, 255, 255);
    text(tx, ty, Label.c_str(), NULL);
    closePath();
}

void Button::setLabel(std::string label)
{
    Label = label;
}

void Button::setLabelColor(const Color color)
{
    labelColor = color;
    borderColor = color;
}
void Button::setBackgroundColor(const Color color)
{
    backgroundColor = color;
}


bool Button::onMouse(const MouseEvent &ev)
{
    if (ev.press & contains(ev.pos))
    {
        buttonActive = true;
        setLabelColor(labelColor);     
        fCallback->buttonClicked(this, true);
    }
    else
    {
        buttonActive = false;
        //setLabelColor(Color(128,128,128));
    }
    return false;
}

END_NAMESPACE_DISTRHO
