

#ifndef NANO_KNOB_HPP_INCLUDED
#define NANO_KNOB_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"
#include "CbWidget.hpp"
#include <string>

START_NAMESPACE_DISTRHO

class NanoKnob : public CbWidget
{
public:
    class Callback
    {
    public:
        virtual ~Callback() {}
        virtual void nanoKnobValueChanged(NanoKnob *knob, float value) = 0;
    };
    explicit NanoKnob(Widget *parent, Callback *cb);

    void setRadius(float radius);
    void setLabel(std::string label);
    void setColors(Color value, Color range);
    void setMargin(float margin);

protected:
    void onNanoDisplay() override;
    bool onMouse(const MouseEvent &ev) override;
    bool onScroll(const ScrollEvent &ev) override;
    bool onMotion(const MotionEvent &ev) override;

private:
    float fRadius,margin;
    
    std::string Label;
    Callback *const fCallback;
    bool mouseDown;
    Point<int> mousePoint;
    FontId fNanoFont;
    Color cValue, cRange;

    DISTRHO_LEAK_DETECTOR(NanoKnob)
};

END_NAMESPACE_DISTRHO

#endif
