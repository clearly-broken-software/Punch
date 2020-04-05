#ifndef TAB_HPP_INCLUDED
#define TAB_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"
#include <string>

START_NAMESPACE_DISTRHO

class Tab : public NanoWidget {
public:
   
    explicit Tab(Widget *parent);
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