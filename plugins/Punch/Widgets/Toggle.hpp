

#ifndef TOGGLE_HPP_INCLUDED
#define TOGGLE_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"

#include <string>

START_NAMESPACE_DISTRHO

class Toggle : public NanoWidget
{
public:
    class Callback
    {
    public:
        virtual ~Callback() {}
        virtual void toggleClicked(Toggle *toggle, bool value) = 0;
    };
    explicit Toggle(Widget *parent, Callback *cb);

    void setLabel(std::string label);
    void setLabelColor(Color color);
    void setBackgroundColor(Color color);
    void setValue(float value);

protected:
    void onNanoDisplay() override;
    bool onMouse(const MouseEvent &ev) override;

private:
    Rectangle<int> clickArea;
    const uint toggleWidth = 40;
    const uint toggleHeight = 20;
    std::string Label;
    Color labelColor,backgroundColor,borderColor;
    Callback *const fCallback;
    bool toggleActive;
    FontId fNanoFont;
    DISTRHO_LEAK_DETECTOR(Toggle)
};

END_NAMESPACE_DISTRHO

#endif
