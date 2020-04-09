// TODO Add license

#include "DistrhoPluginInfo.h"
#include "DistrhoUI.hpp"
#include "PunchParameters.hpp"
#include "Widgets/NanoMeter.hpp"
#include "Widgets/NanoKnob.hpp"
#include "Widgets/NanoHistogram.hpp"
#include "Widgets/NanoSlider.hpp"
#include "Widgets/ToolTip.hpp"
#include "Widgets/Tab.hpp"
#include "Widgets/Button.hpp"
#include "Widgets/Toggle.hpp"
#include "Resources/Colors.hpp"
#include <chrono>

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class PunchUI : public UI,
                public NanoKnob::Callback,
                public NanoSlider::Callback,
                public Button::Callback,
                public IdleCallback,
                public Toggle::Callback
{
public:
    PunchUI();

protected:
    void parameterChanged(uint32_t index, float value) override;
    void onNanoDisplay() override;
    void nanoKnobValueChanged(NanoKnob *nanoKnob, const float value) override;
    void nanoSliderValueChanged(NanoSlider *nanoSlider, const float value) override;
    void buttonClicked(Button *button, const bool clicked) override;
    void toggleClicked(Toggle *toggle, const bool clicked) override;
    void idleCallback() override;
    bool onMotion(const MotionEvent &ev) override;
    //  void onResize(const ResizeEvent &ev) override;

private:
    const uint32_t uiWidth = 800;
    const uint32_t uiHeight = 800;
    ScopedPointer<Tab> tabEasy, tabAdvanced, tabDetector, tabShape, tabRateLimit;
    ScopedPointer<Button> buttonEasy, buttonAdvanced;
    /* -------------------- EASY CONTROLS ------------------------------------*/
    ScopedPointer<NanoKnob> fInputGain, fThreshold, fStrength, fAttack, fRelease,
        fKnee, fOutputGain;
    //TODO ScopedPointer<NanoCheckBox> fByPass;

    /* -------------------- ADVANCED CONTROLS --------------------------------*/
    // Detector Tab
    ScopedPointer<NanoKnob> fPeakRMS, fDetStrength, fRmsSize, fDetectorRelease,
        fSideChainHpf;
    ScopedPointer<Toggle> fSlowFast;

    // ------------------------- Shape Tab ------------------------------------
    ScopedPointer<NanoKnob> fPower, fMaxGainReduction, fCurve, fShape,
        fFeedbackFeedforward, fHiShelfFreq, fGainHiShelfCrossFade,
        fGainHiShelfCrossfade, fDryWet;
    // ----------------------- Rate Limit Tab ---------------------------------
    ScopedPointer<NanoKnob> fRateLimitAmount, fMaxAttack, fMaxDecay, fDecayMult,
        fDecayPower, fIMSize;

    // ------------------------------------------------------------------------
    ScopedPointer<NanoMeter> fAutoRelease, fGR;
    ScopedPointer<NanoHistogram> fHistogram;
    ScopedPointer<ToolTip> fTooltip;
    // ------------------------------------------------------------------------

    // internal parameters
    float fInputLevel, fOutputLevel, fdBInput, fdBOutput, fdBGainReduction;

    FontId fNanoFont;

    Point<int> tooltipPosition;
    bool drawTooltip;
    std::chrono::high_resolution_clock::time_point oldTime, newTime;
    CbWidget *widgetPtr;
    CbWidget **dblWidgetPtr;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PunchUI)
};

END_NAMESPACE_DISTRHO
