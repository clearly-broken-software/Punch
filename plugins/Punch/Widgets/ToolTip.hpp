
#ifndef TOOLTIP_HPP_INCLUDED
#define TOOLTIP_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"
#include "CbWidget.hpp"
#include <string>

START_NAMESPACE_DISTRHO

class ToolTip : public NanoWidget {
public:
   
    explicit ToolTip(Widget *parent);
    void setLabel(std::string label);
  
protected:
    void onNanoDisplay() override;

private:
    std::string Label;
    FontId fNanoFont;

    DISTRHO_LEAK_DETECTOR(NanoSlider)
};


END_NAMESPACE_DISTRHO
#endif