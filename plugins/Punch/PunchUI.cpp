// TODO Add License

#include "PunchUI.hpp"
#include "PunchDSP.hpp"
#include "Window.hpp"
#include <iostream>

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

PunchUI::PunchUI()
    : UI(500, 300)
{

    widgetPtr = nullptr;
    dblWidgetPtr = &widgetPtr;

    drawTooltip = false;

    Window &pw = getParentWindow();
    pw.addIdleCallback(this);
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
    const Size<uint> knobSize(80, 100);
    const Size<uint> smallKnobSize(50, 60);
    const float knobRadius = 35; // 80 /2 - 5
    const float smallKnobRadius = smallKnobSize.getWidth() / 2 - 5;
    const int knob_x_spacing = 100;
    const int smallKnob_y_spacing = 55;
    const int knob_x = 10;
    const int knob_y = 45;
    const auto ui_width = getWidth();
    const auto ui_height = getHeight();

    newTime = std::chrono::high_resolution_clock::now();
    oldTime = newTime;

    tabEasy = new Tab(this);
    tabEasy->setAbsolutePos(0, 0);
    tabEasy->setSize(100, 100);
    tabEasy->setVisible(true);

    tabAdvanced = new Tab(this);
    tabAdvanced->setAbsolutePos(0, 0);
    tabAdvanced->setSize(100, 100);
    tabAdvanced->setVisible(false);

    tabDetector = new Tab(tabAdvanced);
    tabDetector->setLabel("Detector");

    tabShape = new Tab(tabAdvanced);
    tabShape->setLabel("Shape");

    tabRateLimit = new Tab(tabAdvanced);
    tabRateLimit->setLabel("Rate Limit");

    buttonEasy = new Button(this, this);
    buttonEasy->setId(800);
    buttonEasy->setSize(ui_width / 2, 20);
    buttonEasy->setAbsolutePos(0, 0);
    buttonEasy->setLabel("Easy");
    buttonEasy->setLabelColor(Secondary1Shade1);
    buttonEasy->setBackgroundColor(Secondary1Shade0);

    buttonAdvanced = new Button(this, this);
    buttonAdvanced->setId(801);
    buttonAdvanced->setSize(ui_width / 2, 20);
    buttonAdvanced->setAbsolutePos(ui_width / 2, 0);
    buttonAdvanced->setLabel("Advanced");
    buttonAdvanced->setLabelColor(Secondary2Shade0);
    buttonAdvanced->setBackgroundColor(Secondary2Shade4);

    /* ---------------------------- EASY -----------------------------------------*/
    fInputGain = new NanoKnob(tabEasy, this);
    fInputGain->setId(kInputGain);
    fInputGain->setAbsolutePos(knob_x + knob_x_spacing * 0, knob_y);
    fInputGain->setSize(knobSize);
    fInputGain->setRadius(knobRadius);
    fInputGain->setValue(paramRange[kInputGain].def);
    fInputGain->setRange(paramRange[kInputGain].min, paramRange[kInputGain].max);
    fInputGain->setLabel(paramNames[kInputGain]);
    fInputGain->setColors(PrimaryShade0, PrimaryShade1);
    fInputGain->setPtrHasMouse(dblWidgetPtr);
    // fInputGain->setZ(6);

    fThreshold = new NanoKnob(tabEasy, this);
    fThreshold->setId(kThreshold);
    fThreshold->setAbsolutePos(knob_x + knob_x_spacing * 1, knob_y);
    fThreshold->setSize(knobSize);
    fThreshold->setRadius(knobRadius);
    fThreshold->setValue(paramRange[kThreshold].def);
    fThreshold->setRange(paramRange[kThreshold].min, paramRange[kThreshold].max);
    fThreshold->setLabel(paramNames[kThreshold]);
    fThreshold->setColors(Secondary2Shade1, Secondary2Shade2);
    fThreshold->setPtrHasMouse(dblWidgetPtr);
    //   fThreshold->setZ(2);

    fStrength = new NanoKnob(tabEasy, this);
    fStrength->setId(kStrength);
    fStrength->setAbsolutePos(knob_x + knob_x_spacing * 2, knob_y);
    fStrength->setSize(knobSize);
    fStrength->setRadius(knobRadius);
    fStrength->setValue(paramRange[kStrength].def);
    fStrength->setRange(paramRange[kStrength].min, paramRange[kStrength].max);
    fStrength->setLabel(paramNames[kStrength]);
    fStrength->setColors(Secondary2Shade1, Secondary2Shade2);
    fStrength->setPtrHasMouse(dblWidgetPtr);
    //  fStrength->setZ(2);

    fAttack = new NanoKnob(tabEasy, this);
    fAttack->setId(kAttack);
    fAttack->setAbsolutePos(knob_x + knob_x_spacing * 3, knob_y);
    fAttack->setSize(knobSize);
    fAttack->setRadius(knobRadius);
    fAttack->setValue(paramRange[kAttack].def);
    fAttack->setRange(paramRange[kAttack].min, paramRange[kAttack].max);
    fAttack->setLabel(paramNames[kAttack]);
    fAttack->setColors(Secondary2Shade1, Secondary2Shade2);
    fAttack->setPtrHasMouse(dblWidgetPtr);
    //   fAttack->setZ(2);

    fRelease = new NanoKnob(tabEasy, this);
    fRelease->setId(kRelease);
    fRelease->setAbsolutePos(knob_x + knob_x_spacing * 4, knob_y);
    fRelease->setSize(knobSize);
    fRelease->setRadius(knobRadius);
    fRelease->setValue(paramRange[kRelease].def);
    fRelease->setRange(paramRange[kRelease].min, paramRange[kRelease].max);
    fRelease->setLabel(paramNames[kRelease]);
    fRelease->setColors(Secondary2Shade1, Secondary2Shade2);
    fRelease->setPtrHasMouse(dblWidgetPtr);
    //   fRelease->setZ(2);

    fKnee = new NanoKnob(tabEasy, this);
    fKnee->setId(kKnee);
    fKnee->setAbsolutePos(knob_x + knob_x_spacing * 5, knob_y);
    fKnee->setSize(knobSize);
    fKnee->setRadius(knobRadius);
    fKnee->setValue(paramRange[kKnee].def);
    fKnee->setRange(paramRange[kKnee].min, paramRange[kKnee].max);
    fKnee->setLabel(paramNames[kKnee]);
    fKnee->setColors(Secondary2Shade1, Secondary2Shade2);
    fKnee->setPtrHasMouse(dblWidgetPtr);
    //    fKnee->setZ(2);

    fOutputGain = new NanoKnob(tabEasy, this);
    fOutputGain->setId(kOutputGain);
    fOutputGain->setAbsolutePos(knob_x + knob_x_spacing * 6, knob_y);
    fOutputGain->setSize(knobSize);
    fOutputGain->setRadius(knobRadius);
    fOutputGain->setValue(paramRange[kOutputGain].def);
    fOutputGain->setRange(paramRange[kOutputGain].min, paramRange[kOutputGain].max);
    fOutputGain->setLabel(paramNames[kOutputGain]);
    fOutputGain->setColors(Secondary2Shade1, Secondary2Shade2);
    fOutputGain->setPtrHasMouse(dblWidgetPtr);
    //    fOutputGain->setZ(2);

    /* ---------------------- Advanced --------------------------------------------*/

    fGR = new NanoMeter(this);
    fGR->setId(kGr);
    fGR->setAbsolutePos(ui_width - 10, ui_height - 60);
    fGR->setSize(10, 60);
    fGR->setRange(paramRange[kGr].min, paramRange[kGr].max);
    fGR->setValue(paramRange[kGr].def);
    fGR->setZ(1);

    /*   fPeakRMS = new NanoKnob(tabDetector, this);
    fPeakRMS->setId(kPeakRMS);
    fPeakRMS->setAbsolutePos(10, 45 + smallKnob_y_spacing * 0);
    fPeakRMS->setSize(smallKnobSize);
    fPeakRMS->setRadius(smallKnobRadius);
    fPeakRMS->setValue(paramRange[kPeakRMS].def);
    fPeakRMS->setRange(paramRange[kPeakRMS].min, paramRange[kPeakRMS].max);
    fPeakRMS->setLabel(paramNames[kPeakRMS]);
    fPeakRMS->setColors(PrimaryShade0, PrimaryShade1);
    fPeakRMS->setMargin(0.75f);
    fPeakRMS->setPtrHasMouse(dblWidgetPtr);
   

    fDetectorRatio = new NanoKnob(tabDetector, this);
    fDetectorRatio->setId(kPeakRMS);
    fDetectorRatio->setAbsolutePos(10, 45 + smallKnob_y_spacing * 1);
    fDetectorRatio->setSize(smallKnobSize);
    fDetectorRatio->setRadius(smallKnobRadius);
    fDetectorRatio->setValue(paramRange[kPeakRMS].def);
    fDetectorRatio->setRange(paramRange[kPeakRMS].min, paramRange[kPeakRMS].max);
    fDetectorRatio->setLabel(paramNames[kPeakRMS]);
    fDetectorRatio->setColors(PrimaryShade0, PrimaryShade1);
    fDetectorRatio->setMargin(0.75f);
    fDetectorRatio->setPtrHasMouse(dblWidgetPtr);

    fRelease2 = new NanoKnob(tabDetector, this);
    fRelease2->setId(kDetStrength);
    fRelease2->setAbsolutePos(10, 45 + smallKnob_y_spacing * 2);
    fRelease2->setSize(smallKnobSize);
    fRelease2->setRadius(smallKnobRadius);
    fRelease2->setValue(paramRange[kDetStrength].def);
    fRelease2->setRange(paramRange[kDetStrength].min, paramRange[kDetStrength].max);
    fRelease2->setLabel(paramNames[kDetStrength]);
    fRelease2->setColors(PrimaryShade0, PrimaryShade1);
    fRelease2->setMargin(0.75f);
    fRelease2->setPtrHasMouse(dblWidgetPtr);
 */
    fHistogram = new NanoHistogram(this);
    fHistogram->setId(999); // FIX MAGIC NUMBER
    fHistogram->setHistoryLength(490);
    fHistogram->setSize(490, 60);
    fHistogram->setAbsolutePos(0, getHeight() - 60);
    fHistogram->setZ(7);

    fTooltip = new ToolTip(this);
    fTooltip->setId(888);
    fTooltip->setAbsolutePos(100, 70);
    fTooltip->setLabel("this is a tooltip");
    fTooltip->setZ(0);
    fTooltip->setVisible(false);
}

void PunchUI::parameterChanged(uint32_t index, float value)
{
    switch (index)
    {
    case kInputGain:
        fInputGain->setValue(value);
        break;
    case kThreshold:
        fThreshold->setValue(value);
        break;
    case kStrength:
        fStrength->setValue(value);
        break;
    case kAttack:
        fAttack->setValue(value);
        break;
    case kRelease:
        fRelease->setValue(value);
        break;
    case kKnee:
        fKnee->setValue(value);
        break;
    case kOutputGain:
        fOutputGain->setValue(value);
        break;

    /* --- histogram -- */
    case kGr:
        fGR->setValue(value);
        fdBGainReduction = value;
        break;
    case kInputLevel:
        fdBInput = value > 0.0f ? fdBInput = 20 * log10(value) : fdBInput = -60.0f;
        break;
    case kOutputLevel:
        fOutputLevel = value > 0.0f ? fdBOutput = 20 * log10(value) : fdBOutput = -60.0f;
        break;

    default:
        break;
    }
}

void PunchUI::onNanoDisplay()
{
    auto w = getWidth();
    auto h = getHeight();
    beginPath();
    fillColor(32, 32, 32);
    rect(0, 0, w, h);
    fill();
    closePath();
    if (drawTooltip && widgetPtr)
    {
        // construct tooltip label
        float value = widgetPtr->getValue();
        uint id = widgetPtr->getId();
        const char *unit = parameterUnits[id];
        const char *name = paramNames[id];
        char buffer[32];
        sprintf(buffer, "%s : %.1f %s", name, value, unit);
        const std::string label = buffer;
        fTooltip->setLabel(label);
        // check if tooltip doesn't go offscreen
        // TODO check top and bottom of UI
        fTooltip->setAbsolutePos(tooltipPosition);
        const auto tt_width = fTooltip->getWidth();
        const auto ui_width = getWidth();
        if ((tooltipPosition.getX() + tt_width) > ui_width)
            fTooltip->setAbsoluteX(ui_width - tt_width);
        fTooltip->setVisible(true);
    }

    else
        fTooltip->setVisible(false);
}

void PunchUI::idleCallback()
{
    fHistogram->setValues(fdBInput, fdBOutput, fdBGainReduction);
    newTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed_seconds = newTime - oldTime;
    if ((elapsed_seconds.count() > 1.0f))
        widgetPtr ? drawTooltip = true : drawTooltip = false;
    repaint();
}

void PunchUI::nanoKnobValueChanged(NanoKnob *knob, const float value)
{
    int KnobId = knob->getId();
    setParameterValue(KnobId, value);
}

void PunchUI::nanoSliderValueChanged(NanoSlider *slider, const float value)
{
    int SliderId = slider->getId();
    setParameterValue(SliderId, value);
}

void PunchUI::buttonClicked(Button *button, const bool value)
{
    const uint id = button->getId();
    switch (id)
    {
    case 800:
        tabEasy->show();
        tabAdvanced->hide();
        buttonEasy->setLabelColor(Secondary1Shade1);
        buttonEasy->setBackgroundColor(Secondary1Shade0);
        buttonAdvanced->setLabelColor(Secondary2Shade0);
        buttonAdvanced->setBackgroundColor(Secondary2Shade4);
        this->setHeight(uiHeightSmall);
        fHistogram->setAbsoluteY(this->getHeight() - fHistogram->getHeight());
        fGR->setAbsoluteY(this->getHeight() - fGR->getHeight());

        break;
    case 801:
        tabEasy->hide();
        tabAdvanced->show();
        buttonEasy->setLabelColor(Secondary1Shade0);
        buttonEasy->setBackgroundColor(Secondary1Shade4);
        buttonAdvanced->setLabelColor(Secondary2Shade1);
        buttonAdvanced->setBackgroundColor(Secondary2Shade2);
        this->setHeight(uiHeightLarge);
        fHistogram->setAbsoluteY(this->getHeight() - fHistogram->getHeight());
        fGR->setAbsoluteY(this->getHeight() - fGR->getHeight());
    default:
        break;
    }
}

bool PunchUI::onMotion(const MotionEvent &ev)
{
    oldTime = std::chrono::high_resolution_clock::now();
    tooltipPosition = ev.pos;
    const uint toolTipY = tooltipPosition.getY() - 20;
    tooltipPosition.setY(toolTipY);
    drawTooltip = false;
    return true;
}

UI *createUI()
{
    return new PunchUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
