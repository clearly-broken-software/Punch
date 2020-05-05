#include "Tab.hpp"
#include "Resources/Colors.hpp"
#include "Window.hpp"
#include "DistrhoPluginInfo.h"

START_NAMESPACE_DISTRHO

Tab::Tab(Widget *widget, Callback *cb)
    : NanoWidget(widget),
      fCallback(cb),
      fold(false)
{
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
}

void Tab::onNanoDisplay()
{

    // body
    beginPath();
    rect(0, 21, getWidth(), getHeight() - 21);
    fillColor(backGroundColor);
    fill();
    closePath();
    // header
    // get textbounds
    auto foo = getId();
    std::string plusMinus = "  ";
    if (foo != kTabEasy)
    {
        plusMinus = fold ? "+ " : "− ";
    }
    std::string tmpLabel = plusMinus + Label;
    Rectangle<float> bounds;
    fontSize(16);
    textBounds(0, 0, tmpLabel.c_str(), NULL, bounds);
    const uint w = bounds.getWidth();
    const uint h = bounds.getHeight();

    beginPath();
    strokeColor(204, 204, 204);
    strokeWidth(1.0f);
    rect(1, 1, getWidth() - 2, 19);
    fillColor(32, 32, 32);
    stroke();
    fill();
    closePath();

    beginPath();
    strokeColor(135, 135, 135, 128);
    moveTo(5, 7);
    lineTo(getWidth() - 5, 7);
    moveTo(5, 14);
    lineTo(getWidth() - 5, 14);
    stroke();
    closePath();

    beginPath();
    rect(5, 7, getWidth() - 10, 7);
    fill();
    closePath();

    beginPath();
    // box behind text
    // center vertical
    int ty = 20 / 2 - h / 2;
    int tx = (w + 2) / 2 - (w) / 2 + 11;
    beginPath();
    rect(11, ty, w, h);
    fillColor(32, 32, 32);
    fill();
    closePath();

    beginPath();
    textAlign(ALIGN_LEFT | ALIGN_TOP);
    fillColor(230, 230, 230);
    //fontSize(16);
    if (tmpLabel.size() > 0)
        text(tx, ty + 1, tmpLabel.c_str(), NULL);
    closePath();
}

bool Tab::onMouse(const MouseEvent &ev)
{
    header.setSize(getWidth(), 20);
    header.setPos(0, 0);
    if (ev.press & header.contains(ev.pos))
    {
        fold = !fold;
        fCallback->tabClicked(this, fold);
    }
    return false;
}

void Tab::setLabel(std::string label)
{
    Label = label;
}

void Tab::setColor(Color color)
{
    backGroundColor = color;
}

void Tab::setFold(bool _fold)
{
    fold = _fold;
}

END_NAMESPACE_DISTRHO
