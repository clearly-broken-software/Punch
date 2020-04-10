

#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"

#include <string>

START_NAMESPACE_DISTRHO

class Button : public NanoWidget
{
public:
    class Callback
    {
    public:
        virtual ~Callback() {}
        virtual void buttonClicked(Button *button, bool value) = 0;
    };
    explicit Button(Widget *parent, Callback *cb);

    void setLabel(std::string label);
    void setLabelColor(Color color);
    void setBackgroundColor(Color color);

protected:
    void onNanoDisplay() override;
    bool onMouse(const MouseEvent &ev) override;

private:
    std::string Label;
    Color labelColor, backgroundColor, borderColor;
    Callback *const fCallback;
    bool buttonActive;
    FontId fNanoFont;
    DISTRHO_LEAK_DETECTOR(Button)
};

END_NAMESPACE_DISTRHO

#endif
