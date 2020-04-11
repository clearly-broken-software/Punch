#ifndef TAB_HPP_INCLUDED
#define TAB_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"
#include <string>

START_NAMESPACE_DISTRHO

class Tab : public NanoWidget
{
public:
    class Callback
    {
    public:
        virtual ~Callback() {}
        virtual void tabClicked(Tab *tab, bool value) = 0;
    };

    explicit Tab(Widget *parent, Callback *cb);
    void setLabel(std::string label);
    void setColor(Color color);
    void setFold(bool fold);

protected:
    void onNanoDisplay() override;
    bool onMouse(const MouseEvent &ev) override;

private:
    Callback *const fCallback;
    std::string Label;
    FontId fNanoFont;
    Color backGroundColor;
    Rectangle<int> header;
    bool fold;

    DISTRHO_LEAK_DETECTOR(Tab)
};

END_NAMESPACE_DISTRHO
#endif