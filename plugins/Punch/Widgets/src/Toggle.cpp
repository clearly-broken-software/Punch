

#include "Toggle.hpp"
#include "Window.hpp"

START_NAMESPACE_DISTRHO

Toggle::Toggle(Widget *parent, Callback *cb)
    : NanoWidget(parent),
      fCallback(cb),
      toggleActive(false)
{
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
    labelColor = Color(255, 255, 255);
    backgroundColor = Color(32, 32, 32);
    Label = "Toggle";
    clickArea.setSize(40, 20);
    clickArea.setPos(25, 2);
}

void Toggle::setValue(float value)
{
    if (value)
        toggleActive = true;
    else
    {
        toggleActive = false;
    }
}

void Toggle::onNanoDisplay()
{

    auto w = getWidth();
    auto h = getHeight();
    auto strokeW = 2.0f;
    auto backX1 = w / 2 - toggleWidth / 2 - 2 * strokeW;
    auto backY1 = strokeW;
    // Background
    beginPath();
    roundedRect(backX1,
                backY1,
                toggleWidth - 2 * strokeW,
                toggleHeight - 2 * strokeW,
                7);
    fillColor(64, 64, 64, 255);
    //fillColor(backgroundColor);
    strokeColor(borderColor);
    strokeWidth(strokeW);
    fill();
    stroke();
    closePath();

    // Toggle
    beginPath();
    const auto toggleX = 8 + backX1 + (toggleActive * 20.f);
    const auto toggleRadius = (20 - 4 * strokeW) / 2;

    arc(toggleX, 20 / 2, toggleRadius, 0, 360, CW);
    strokeWidth(1);
    strokeColor(backgroundColor);
    fillColor(labelColor);
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
    float tx = w / 2.0f;
    float ty = h / 2.0f;
    textAlign(ALIGN_CENTER | ALIGN_MIDDLE);

    fillColor(255, 255, 255, 255);
    text(tx, ty, Label.c_str(), NULL);
    closePath();
}

void Toggle::setLabel(std::string label)
{
    Label = label;
}

void Toggle::setLabelColor(const Color color)
{
    labelColor = color;
    borderColor = color;
}
void Toggle::setBackgroundColor(const Color color)
{
    backgroundColor = color;
}

bool Toggle::onMouse(const MouseEvent &ev)
{
    if (ev.press & clickArea.contains(ev.pos))
    {
        toggleActive = !toggleActive;
        //  setLabelColor(labelColor);
        fCallback->toggleClicked(this, toggleActive);
    }
    else if (ev.press)
    {
        printf("%i\n", clickArea.contains(ev.pos));
        printf("%i\n", clickArea.getX());
    }
    return false;
}

END_NAMESPACE_DISTRHO
