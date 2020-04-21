// TODO Add License

#include "PunchUI.hpp"
#include "PunchDSP.hpp"
#include "Window.hpp"
#include <iostream>

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

PunchUI::PunchUI()
    : UI(800, 500)
{
    fb = nvgluCreateFramebuffer(,100,100, 0 );
    plugin = static_cast<PunchPlugin *>(getPluginInstancePointer());
    widgetPtr = nullptr;
    dblWidgetPtr = &widgetPtr;
    drawTooltip = false;
    fpsFrames = 0;
    fpsSum = 0.0;
    fpsSumSquares = 0.0;
    fpsMean = 0.0;

    Window &pw = getParentWindow();
    pw.addIdleCallback(this);
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
    largeKnobSize = Size<uint>(100, 100);
    smallKnobSize = Size<uint>(90, 90);

    const float largeKnobRadius = 35; // 80 /2 - 5
    const float smallKnobRadius = 30;
    const int largeKnobXSpacing = largeKnobSize.getWidth() + 10;
    const int smallKnobXSpacing = smallKnobSize.getWidth() + 10;
    const float smallKnobMargin = 0.8f;

    const int knob_x = 10;
    const int knob_y = 30;

    newTime = std::chrono::high_resolution_clock::now();
    oldTime = newTime;
    oldFPSTime = newTime;
    newFPSTime = newTime;

    tabEasy = new Tab(this, this);
    tabEasy->setId(kTabEasy);
    tabEasy->setAbsolutePos(0, 0);
    tabEasy->setSize(getWidth(), largeKnobSize.getHeight() + knob_y);
    tabEasy->setColor(PrimaryShade4);
    tabEasy->setLabel("Quick Controls");

    tabDetector = new Tab(this, this);
    tabDetector->setId(kTabDetector);
    tabDetector->setLabel("Detector");
    tabDetector->setAbsolutePos(0, tabEasy->getHeight() + tabEasy->getAbsoluteY());
    tabDetector->setSize(getWidth(), 20);
    tabDetector->setColor(Secondary1Shade4);
    tabDetector->setFold(true);

    tabShape = new Tab(this, this);
    tabShape->setId(kTabShape);
    tabShape->setLabel("Shape");
    tabShape->setAbsolutePos(0, tabDetector->getHeight() + tabDetector->getAbsoluteY());
    tabShape->setSize(getWidth(), 20);
    tabShape->setColor(Secondary2Shade4);
    tabShape->setFold(true);

    tabRateLimit = new Tab(this, this);
    tabRateLimit->setId(kTabRateLimit);
    tabRateLimit->setLabel("Rate Limit");
    tabRateLimit->setAbsolutePos(0, tabShape->getHeight() + tabShape->getAbsoluteY());
    tabRateLimit->setSize(getWidth(), 20);
    tabRateLimit->setColor(ComplementShade4);
    tabRateLimit->setFold(true);

    /* ---------------------------- EASY -----------------------------------------*/
    fInputGain = new NanoKnob(tabEasy, this);
    fInputGain->setId(kInputGain);
    fInputGain->setAbsolutePos(knob_x + largeKnobXSpacing * 0, knob_y);
    fInputGain->setSize(largeKnobSize);
    fInputGain->setRadius(largeKnobRadius);
    fInputGain->setValue(paramRange[kInputGain].def);
    fInputGain->setRange(paramRange[kInputGain].min, paramRange[kInputGain].max);
    fInputGain->setLabel(paramNames[kInputGain]);
    fInputGain->setColors(PrimaryShade0, PrimaryShade1);
    fInputGain->setPtrHasMouse(dblWidgetPtr);

    fThreshold = new NanoKnob(tabEasy, this);
    fThreshold->setId(kThreshold);
    fThreshold->setAbsolutePos(knob_x + largeKnobXSpacing * 1, knob_y);
    fThreshold->setSize(largeKnobSize);
    fThreshold->setRadius(largeKnobRadius);
    fThreshold->setValue(paramRange[kThreshold].def);
    fThreshold->setRange(paramRange[kThreshold].min, paramRange[kThreshold].max);
    fThreshold->setLabel(paramNames[kThreshold]);
    fThreshold->setColors(Secondary2Shade1, Secondary2Shade2);
    fThreshold->setPtrHasMouse(dblWidgetPtr);

    fStrength = new NanoKnob(tabEasy, this);
    fStrength->setId(kStrength);
    fStrength->setAbsolutePos(knob_x + largeKnobXSpacing * 2, knob_y);
    fStrength->setSize(largeKnobSize);
    fStrength->setRadius(largeKnobRadius);
    fStrength->setValue(paramRange[kStrength].def);
    fStrength->setRange(paramRange[kStrength].min, paramRange[kStrength].max);
    fStrength->setLabel(paramNames[kStrength]);
    fStrength->setColors(Secondary2Shade1, Secondary2Shade2);
    fStrength->setPtrHasMouse(dblWidgetPtr);

    fAttack = new NanoKnob(tabEasy, this);
    fAttack->setId(kAttack);
    fAttack->setAbsolutePos(knob_x + largeKnobXSpacing * 3, knob_y);
    fAttack->setSize(largeKnobSize);
    fAttack->setRadius(largeKnobRadius);
    fAttack->setValue(paramRange[kAttack].def);
    fAttack->setRange(paramRange[kAttack].min, paramRange[kAttack].max);
    fAttack->setLabel(paramNames[kAttack]);
    fAttack->setColors(Secondary2Shade1, Secondary2Shade2);
    fAttack->setPtrHasMouse(dblWidgetPtr);

    fRelease = new NanoKnob(tabEasy, this);
    fRelease->setId(kRelease);
    fRelease->setAbsolutePos(knob_x + largeKnobXSpacing * 4, knob_y);
    fRelease->setSize(largeKnobSize);
    fRelease->setRadius(largeKnobRadius);
    fRelease->setValue(paramRange[kRelease].def);
    fRelease->setRange(paramRange[kRelease].min, paramRange[kRelease].max);
    fRelease->setLabel(paramNames[kRelease]);
    fRelease->setColors(Secondary2Shade1, Secondary2Shade2);
    fRelease->setPtrHasMouse(dblWidgetPtr);

    fKnee = new NanoKnob(tabEasy, this);
    fKnee->setId(kKnee);
    fKnee->setAbsolutePos(knob_x + largeKnobXSpacing * 5, knob_y);
    fKnee->setSize(largeKnobSize);
    fKnee->setRadius(largeKnobRadius);
    fKnee->setValue(paramRange[kKnee].def);
    fKnee->setRange(paramRange[kKnee].min, paramRange[kKnee].max);
    fKnee->setLabel(paramNames[kKnee]);
    fKnee->setColors(Secondary2Shade1, Secondary2Shade2);
    fKnee->setPtrHasMouse(dblWidgetPtr);

    fOutputGain = new NanoKnob(tabEasy, this);
    fOutputGain->setId(kOutputGain);
    fOutputGain->setAbsolutePos(knob_x + largeKnobXSpacing * 6, knob_y);
    fOutputGain->setSize(largeKnobSize);
    fOutputGain->setRadius(largeKnobRadius);
    fOutputGain->setValue(paramRange[kOutputGain].def);
    fOutputGain->setRange(paramRange[kOutputGain].min, paramRange[kOutputGain].max);
    fOutputGain->setLabel(paramNames[kOutputGain]);
    fOutputGain->setColors(Secondary2Shade1, Secondary2Shade2);
    fOutputGain->setPtrHasMouse(dblWidgetPtr);

    /* ---------------------- Advanced --------------------------------------------*/
    // Detector
    auto tabX = tabDetector->getAbsoluteX();
    auto tabY = tabDetector->getAbsoluteY() + 25;

    fPeakRMS = new NanoKnob(tabDetector, this);
    fPeakRMS->setId(kPeakRMS);
    fPeakRMS->setAbsolutePos(tabX + smallKnobXSpacing * 0, tabY);
    fPeakRMS->setSize(smallKnobSize);
    fPeakRMS->setRadius(smallKnobRadius);
    fPeakRMS->setValue(paramRange[kPeakRMS].def);
    fPeakRMS->setRange(paramRange[kPeakRMS].min, paramRange[kPeakRMS].max);
    fPeakRMS->setLabel(paramNames[kPeakRMS]);
    fPeakRMS->setColors(PrimaryShade0, PrimaryShade1);
    fPeakRMS->setMargin(smallKnobMargin);
    fPeakRMS->setPtrHasMouse(dblWidgetPtr);
    fPeakRMS->setVisible(false);

    fDetStrength = new NanoKnob(tabDetector, this);
    fDetStrength->setId(kDetStrength);
    fDetStrength->setAbsolutePos(tabX + smallKnobXSpacing * 1, tabY);
    fDetStrength->setSize(smallKnobSize);
    fDetStrength->setRadius(smallKnobRadius);
    fDetStrength->setValue(paramRange[kDetStrength].def);
    fDetStrength->setRange(paramRange[kDetStrength].min, paramRange[kDetStrength].max);
    fDetStrength->setLabel(paramNames[kDetStrength]);
    fDetStrength->setColors(PrimaryShade0, PrimaryShade1);
    fDetStrength->setMargin(smallKnobMargin);
    fDetStrength->setPtrHasMouse(dblWidgetPtr);
    fDetStrength->setVisible(false);

    fRmsSize = new NanoKnob(tabDetector, this);
    fRmsSize->setId(kRMSSize);
    fRmsSize->setAbsolutePos(tabX + smallKnobXSpacing * 2, tabY);
    fRmsSize->setSize(smallKnobSize);
    fRmsSize->setRadius(smallKnobRadius);
    fRmsSize->setValue(paramRange[kRMSSize].def);
    fRmsSize->setRange(paramRange[kRMSSize].min, paramRange[kRMSSize].max);
    fRmsSize->setLabel(paramNames[kRMSSize]);
    fRmsSize->setColors(PrimaryShade0, PrimaryShade1);
    fRmsSize->setMargin(smallKnobMargin);
    fRmsSize->setPtrHasMouse(dblWidgetPtr);
    fRmsSize->setVisible(false);

    fDetectorRelease = new NanoKnob(tabDetector, this);
    fDetectorRelease->setId(kDetectorRelease);
    fDetectorRelease->setAbsolutePos(tabX + smallKnobXSpacing * 3, tabY);
    fDetectorRelease->setSize(smallKnobSize);
    fDetectorRelease->setRadius(smallKnobRadius);
    fDetectorRelease->setValue(paramRange[kDetectorRelease].def);
    fDetectorRelease->setRange(paramRange[kDetectorRelease].min, paramRange[kDetectorRelease].max);
    fDetectorRelease->setLabel(paramNames[kDetectorRelease]);
    fDetectorRelease->setColors(PrimaryShade0, PrimaryShade1);
    fDetectorRelease->setMargin(smallKnobMargin);
    fDetectorRelease->setPtrHasMouse(dblWidgetPtr);
    fDetectorRelease->setVisible(false);

    fSideChainHpf = new NanoKnob(tabDetector, this);
    fSideChainHpf->setId(kSideChainHPF);
    fSideChainHpf->setAbsolutePos(tabX + smallKnobXSpacing * 4, tabY);
    fSideChainHpf->setSize(smallKnobSize);
    fSideChainHpf->setRadius(smallKnobRadius);
    fSideChainHpf->setValue(paramRange[kSideChainHPF].def);
    fSideChainHpf->setRange(paramRange[kSideChainHPF].min, paramRange[kSideChainHPF].max);
    fSideChainHpf->setLabel(paramNames[kSideChainHPF]);
    fSideChainHpf->setColors(PrimaryShade0, PrimaryShade1);
    fSideChainHpf->setMargin(smallKnobMargin);
    fSideChainHpf->setPtrHasMouse(dblWidgetPtr);
    fSideChainHpf->setVisible(false);

    fSlowFast = new Toggle(tabDetector, this);
    fSlowFast->setSize(smallKnobSize);
    fSlowFast->setId(kSlowFast);
    fSlowFast->setLabel("Slow - Fast");
    fSlowFast->setAbsolutePos(tabX + smallKnobXSpacing * 5, tabY);
    fSlowFast->setLabelColor(PrimaryShade0);
    fSlowFast->setBackgroundColor(PrimaryShade1);
    fSlowFast->setVisible(false);

    tabY = tabShape->getAbsoluteY() + 25;

    // shape
    fPower = new NanoKnob(tabShape, this);
    fPower->setId(kPower);
    fPower->setAbsolutePos(tabX + smallKnobXSpacing * 0, tabY);
    fPower->setSize(smallKnobSize);
    fPower->setRadius(smallKnobRadius);
    fPower->setValue(paramRange[kPower].def);
    fPower->setRange(paramRange[kPower].min, paramRange[kPower].max);
    fPower->setLabel(paramNames[kPower]);
    fPower->setColors(PrimaryShade0, PrimaryShade1);
    fPower->setMargin(smallKnobMargin);
    fPower->setPtrHasMouse(dblWidgetPtr);
    fPower->setVisible(false);

    fMaxGainReduction = new NanoKnob(tabShape, this);
    fMaxGainReduction->setId(kMaxGainReduction);
    fMaxGainReduction->setAbsolutePos(tabX + smallKnobXSpacing * 1, tabY);
    fMaxGainReduction->setSize(smallKnobSize);
    fMaxGainReduction->setRadius(smallKnobRadius);
    fMaxGainReduction->setValue(paramRange[kMaxGainReduction].def);
    fMaxGainReduction->setRange(paramRange[kMaxGainReduction].min, paramRange[kMaxGainReduction].max);
    fMaxGainReduction->setLabel(paramNames[kMaxGainReduction]);
    fMaxGainReduction->setColors(PrimaryShade0, PrimaryShade1);
    fMaxGainReduction->setMargin(smallKnobMargin);
    fMaxGainReduction->setPtrHasMouse(dblWidgetPtr);
    fMaxGainReduction->setVisible(false);

    fCurve = new NanoKnob(tabShape, this);
    fCurve->setId(kCurve);
    fCurve->setAbsolutePos(tabX + smallKnobXSpacing * 2, tabY);
    fCurve->setSize(smallKnobSize);
    fCurve->setRadius(smallKnobRadius);
    fCurve->setValue(paramRange[kCurve].def);
    fCurve->setRange(paramRange[kCurve].min, paramRange[kCurve].max);
    fCurve->setLabel(paramNames[kCurve]);
    fCurve->setColors(PrimaryShade0, PrimaryShade1);
    fCurve->setMargin(smallKnobMargin);
    fCurve->setPtrHasMouse(dblWidgetPtr);
    fCurve->setVisible(false);

    fShape = new NanoKnob(tabShape, this);
    fShape->setId(kShape);
    fShape->setAbsolutePos(tabX + smallKnobXSpacing * 3, tabY);
    fShape->setSize(smallKnobSize);
    fShape->setRadius(smallKnobRadius);
    fShape->setValue(paramRange[kShape].def);
    fShape->setRange(paramRange[kShape].min, paramRange[kShape].max);
    fShape->setLabel(paramNames[kShape]);
    fShape->setColors(PrimaryShade0, PrimaryShade1);
    fShape->setMargin(smallKnobMargin);
    fShape->setPtrHasMouse(dblWidgetPtr);
    fShape->setVisible(false);

    fFeedbackFeedforward = new NanoKnob(tabShape, this);
    fFeedbackFeedforward->setId(kFeedbackFeedforward);
    fFeedbackFeedforward->setAbsolutePos(tabX + smallKnobXSpacing * 4, tabY);
    fFeedbackFeedforward->setSize(smallKnobSize);
    fFeedbackFeedforward->setRadius(smallKnobRadius);
    fFeedbackFeedforward->setValue(paramRange[kFeedbackFeedforward].def);
    fFeedbackFeedforward->setRange(paramRange[kFeedbackFeedforward].min, paramRange[kFeedbackFeedforward].max);
    fFeedbackFeedforward->setLabel(paramNames[kFeedbackFeedforward]);
    fFeedbackFeedforward->setColors(PrimaryShade0, PrimaryShade1);
    fFeedbackFeedforward->setMargin(smallKnobMargin);
    fFeedbackFeedforward->setPtrHasMouse(dblWidgetPtr);
    fFeedbackFeedforward->setVisible(false);

    fHiShelfFreq = new NanoKnob(tabShape, this);
    fHiShelfFreq->setId(kHiShelfFreq);
    fHiShelfFreq->setAbsolutePos(tabX + smallKnobXSpacing * 5, tabY);
    fHiShelfFreq->setSize(smallKnobSize);
    fHiShelfFreq->setRadius(smallKnobRadius);
    fHiShelfFreq->setValue(paramRange[kHiShelfFreq].def);
    fHiShelfFreq->setRange(paramRange[kHiShelfFreq].min, paramRange[kHiShelfFreq].max);
    fHiShelfFreq->setLabel(paramNames[kHiShelfFreq]);
    fHiShelfFreq->setColors(PrimaryShade0, PrimaryShade1);
    fHiShelfFreq->setMargin(smallKnobMargin);
    fHiShelfFreq->setPtrHasMouse(dblWidgetPtr);
    fHiShelfFreq->setVisible(false);

    fGainHiShelfCrossfade = new NanoKnob(tabShape, this);
    fGainHiShelfCrossfade->setId(kGainHiShelfCrossfade);
    fGainHiShelfCrossfade->setAbsolutePos(tabX + smallKnobXSpacing * 6, tabY);
    fGainHiShelfCrossfade->setSize(smallKnobSize);
    fGainHiShelfCrossfade->setRadius(smallKnobRadius);
    fGainHiShelfCrossfade->setValue(paramRange[kGainHiShelfCrossfade].def);
    fGainHiShelfCrossfade->setRange(paramRange[kGainHiShelfCrossfade].min, paramRange[kGainHiShelfCrossfade].max);
    fGainHiShelfCrossfade->setLabel(paramNames[kGainHiShelfCrossfade]);
    fGainHiShelfCrossfade->setColors(PrimaryShade0, PrimaryShade1);
    fGainHiShelfCrossfade->setMargin(smallKnobMargin);
    fGainHiShelfCrossfade->setPtrHasMouse(dblWidgetPtr);
    fGainHiShelfCrossfade->setVisible(false);

    fDryWet = new NanoKnob(tabShape, this);
    fDryWet->setId(kDryWet);
    fDryWet->setAbsolutePos(tabX + smallKnobXSpacing * 7, tabY);
    fDryWet->setSize(smallKnobSize);
    fDryWet->setRadius(smallKnobRadius);
    fDryWet->setValue(paramRange[kDryWet].def);
    fDryWet->setRange(paramRange[kDryWet].min, paramRange[kDryWet].max);
    fDryWet->setLabel(paramNames[kDryWet]);
    fDryWet->setColors(PrimaryShade0, PrimaryShade1);
    fDryWet->setMargin(smallKnobMargin);
    fDryWet->setPtrHasMouse(dblWidgetPtr);
    fDryWet->setVisible(false);

    // rate limit
    tabY = tabRateLimit->getAbsoluteY() + 25;

    fRateLimitAmount = new NanoKnob(tabRateLimit, this);
    fRateLimitAmount->setId(kRateLimitAmount);
    fRateLimitAmount->setAbsolutePos(tabX + smallKnobXSpacing * 0, tabY);
    fRateLimitAmount->setSize(smallKnobSize);
    fRateLimitAmount->setRadius(smallKnobRadius);
    fRateLimitAmount->setValue(paramRange[kRateLimitAmount].def);
    fRateLimitAmount->setRange(paramRange[kRateLimitAmount].min, paramRange[kRateLimitAmount].max);
    fRateLimitAmount->setLabel(paramNames[kRateLimitAmount]);
    fRateLimitAmount->setColors(PrimaryShade0, PrimaryShade1);
    fRateLimitAmount->setMargin(smallKnobMargin);
    fRateLimitAmount->setPtrHasMouse(dblWidgetPtr);
    fRateLimitAmount->setVisible(false);

    fMaxAttack = new NanoKnob(tabRateLimit, this);
    fMaxAttack->setId(kMaxAttack);
    fMaxAttack->setAbsolutePos(tabX + smallKnobXSpacing * 1, tabY);
    fMaxAttack->setSize(smallKnobSize);
    fMaxAttack->setRadius(smallKnobRadius);
    fMaxAttack->setValue(paramRange[kMaxAttack].def);
    fMaxAttack->setRange(paramRange[kMaxAttack].min, paramRange[kMaxAttack].max);
    fMaxAttack->setLabel(paramNames[kMaxAttack]);
    fMaxAttack->setColors(PrimaryShade0, PrimaryShade1);
    fMaxAttack->setMargin(smallKnobMargin);
    fMaxAttack->setPtrHasMouse(dblWidgetPtr);
    fMaxAttack->setVisible(false);

    fMaxDecay = new NanoKnob(tabRateLimit, this);
    fMaxDecay->setId(kMaxDecay);
    fMaxDecay->setAbsolutePos(tabX + smallKnobXSpacing * 2, tabY);
    fMaxDecay->setSize(smallKnobSize);
    fMaxDecay->setRadius(smallKnobRadius);
    fMaxDecay->setValue(paramRange[kMaxDecay].def);
    fMaxDecay->setRange(paramRange[kMaxDecay].min, paramRange[kMaxDecay].max);
    fMaxDecay->setLabel(paramNames[kMaxDecay]);
    fMaxDecay->setColors(PrimaryShade0, PrimaryShade1);
    fMaxDecay->setMargin(smallKnobMargin);
    fMaxDecay->setPtrHasMouse(dblWidgetPtr);
    fMaxDecay->setVisible(false);

    fDecayMult = new NanoKnob(tabRateLimit, this);
    fDecayMult->setId(kDecayMult);
    fDecayMult->setAbsolutePos(tabX + smallKnobXSpacing * 3, tabY);
    fDecayMult->setSize(smallKnobSize);
    fDecayMult->setRadius(smallKnobRadius);
    fDecayMult->setValue(paramRange[kDecayMult].def);
    fDecayMult->setRange(paramRange[kDecayMult].min, paramRange[kDecayMult].max);
    fDecayMult->setLabel(paramNames[kDecayMult]);
    fDecayMult->setColors(PrimaryShade0, PrimaryShade1);
    fDecayMult->setMargin(smallKnobMargin);
    fDecayMult->setPtrHasMouse(dblWidgetPtr);
    fDecayMult->setVisible(false);

    fDecayPower = new NanoKnob(tabRateLimit, this);
    fDecayPower->setId(kDecayPower);
    fDecayPower->setAbsolutePos(tabX + smallKnobXSpacing * 4, tabY);
    fDecayPower->setSize(smallKnobSize);
    fDecayPower->setRadius(smallKnobRadius);
    fDecayPower->setValue(paramRange[kDecayPower].def);
    fDecayPower->setRange(paramRange[kDecayPower].min, paramRange[kDecayPower].max);
    fDecayPower->setLabel(paramNames[kDecayPower]);
    fDecayPower->setColors(PrimaryShade0, PrimaryShade1);
    fDecayPower->setMargin(smallKnobMargin);
    fDecayPower->setPtrHasMouse(dblWidgetPtr);
    fDecayPower->setVisible(false);

    fIMSize = new NanoKnob(tabRateLimit, this);
    fIMSize->setId(kIMSize);
    fIMSize->setAbsolutePos(tabX + smallKnobXSpacing * 5, tabY);
    fIMSize->setSize(smallKnobSize);
    fIMSize->setRadius(smallKnobRadius);
    fIMSize->setValue(paramRange[kIMSize].def);
    fIMSize->setRange(paramRange[kIMSize].min, paramRange[kIMSize].max);
    fIMSize->setLabel(paramNames[kIMSize]);
    fIMSize->setColors(PrimaryShade0, PrimaryShade1);
    fIMSize->setMargin(smallKnobMargin);
    fIMSize->setPtrHasMouse(dblWidgetPtr);
    fIMSize->setVisible(false);

    //

    fGR = new NanoMeter(this);
    fGR->setId(kGr);
    fGR->setAbsolutePos(getWidth() - 10, tabRateLimit->getAbsoluteY() + tabRateLimit->getHeight());
    fGR->setSize(10, getHeight() - tabRateLimit->getAbsoluteY() + tabRateLimit->getHeight());
    fGR->setRange(paramRange[kGr].min, paramRange[kGr].max);
    fGR->setValue(paramRange[kGr].def);

    fHistogram = new NanoHistogram(this);
    fHistogram->setId(kHistogram); // FIX MAGIC NUMBER
    fHistogram->setHistoryLength(uiWidth - fGR->getWidth());
    fHistogram->setAbsolutePos(0, tabRateLimit->getAbsoluteY() + tabRateLimit->getHeight());
    fHistogram->setSize(uiWidth - fGR->getWidth(), getHeight() - fHistogram->getAbsoluteY());

    fTooltip = new ToolTip(this);
    fTooltip->setId(kTooltip);
    fTooltip->setAbsolutePos(100, 70);
    fTooltip->setLabel("this is a tooltip");
    fTooltip->setVisible(false);
}

void PunchUI::positionWidgets()
{
    tabShape->setAbsolutePos(0, tabDetector->getHeight() + tabDetector->getAbsoluteY());
    auto tabY = tabShape->getAbsoluteY() + 25;
    fPower->setAbsoluteY(tabY);
    fMaxGainReduction->setAbsoluteY(tabY);
    fCurve->setAbsoluteY(tabY);
    fShape->setAbsoluteY(tabY);
    fFeedbackFeedforward->setAbsoluteY(tabY);
    fHiShelfFreq->setAbsoluteY(tabY);
    fGainHiShelfCrossfade->setAbsoluteY(tabY);
    fDryWet->setAbsoluteY(tabY);
    //
    tabRateLimit->setAbsolutePos(0, tabShape->getHeight() + tabShape->getAbsoluteY());
    tabY = tabRateLimit->getAbsoluteY() + 25;
    fRateLimitAmount->setAbsoluteY(tabY);
    fMaxAttack->setAbsoluteY(tabY);
    fMaxDecay->setAbsoluteY(tabY);
    fDecayMult->setAbsoluteY(tabY);
    fDecayPower->setAbsoluteY(tabY);
    fIMSize->setAbsoluteY(tabY);
    //
    fHistogram->setAbsoluteY(tabRateLimit->getHeight() + tabRateLimit->getAbsoluteY());
    fHistogram->setHeight(getHeight() - fHistogram->getAbsoluteY());
    fGR->setAbsoluteY(fHistogram->getAbsoluteY());
    fGR->setHeight(fHistogram->getHeight());
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
    case kPeakRMS:
        fPeakRMS->setValue(value);
        break;
    case kDetStrength:
        fDetStrength->setValue(value);
        break;
    case kRMSSize:
        fRmsSize->setValue(value);
        break;
    case kDetectorRelease:
        fDetectorRelease->setValue(value);
        break;
    case kSideChainHPF:
        fSideChainHpf->setValue(value);
        break;
    case kSlowFast:
        fSlowFast->setValue(value);
        break;
    /* --- shape --- */
    case kPower:
        fPower->setValue(value);
        break;
    case kMaxGainReduction:
        fMaxGainReduction->setValue(value);
        break;
    case kCurve:
        fCurve->setValue(value);
        break;
    case kShape:
        fShape->setValue(value);
        break;
    case kFeedbackFeedforward:
        fFeedbackFeedforward->setValue(value);
        break;
    case kHiShelfFreq:
        fHiShelfFreq->setValue(value);
        break;
    case kGainHiShelfCrossfade:
        fGainHiShelfCrossfade->setValue(value);
        break;
    case kDryWet:
        fDryWet->setValue(value);
        break;
        //
    case kRateLimitAmount:
        fRateLimitAmount->setValue(value);
        break;
    case kMaxAttack:
        fMaxAttack->setValue(value);
        break;
    case kMaxDecay:
        fMaxDecay->setValue(value);
        break;
    case kDecayMult:
        fDecayMult->setValue(value);
        break;
    case kDecayPower:
        fDecayPower->setValue(value);
        break;
    case kIMSize:
        fIMSize->setValue(value);
        break;
    case kBypass:
        fIMSize->setValue(value);
        break;
    case kAutoRelease:
        //  fAutoRelease->setValue(value);
        break;

    /* --- histogram -- */
    case kGr:
        //fGR->setValue(value);
        // fdBGainReduction = value;
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
        // float value = widgetPtr->getValue();
        uint id = widgetPtr->getId();
        //   const char *unit = parameterUnits[id];
        //  const char *name = paramNames[id];
        const char *tooltip = parameterTooltips[id];
        char buffer[512];
        sprintf(buffer, "%s", tooltip);
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
    fdBGainReduction = plugin->getGR();
    fHistogram->setValues(fdBInput, fdBOutput, fdBGainReduction);
    newTime = std::chrono::high_resolution_clock::now();
    newFPSTime = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed_frames = newFPSTime - oldFPSTime;
    fpsFrames++;
    fpsSum = fpsSum + (1 / elapsed_frames.count());
    fpsSumSquares = fpsSumSquares + pow( 1 / elapsed_frames.count(), 2);
    fpsMean = fpsSum / (float) fpsFrames;
    fpsStandardDeviation = sqrt(fpsSumSquares - pow(fpsSum, 2) / fpsFrames) / (fpsFrames - 1);
    if (fpsFrames == 1)
        fpsStandardDeviation = 0;
    printf("fpsMean =  %f, sd = %f, fps %f\n", fpsMean, fpsStandardDeviation, 1 / elapsed_frames.count());

    oldFPSTime = newFPSTime;
    const std::chrono::duration<float> elapsed_seconds = newTime - oldTime;

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

void PunchUI::toggleClicked(Toggle *toggle, const bool clicked)
{
    auto id = toggle->getId();
    switch (id)
    {
    case kSlowFast:

        setParameterValue(id, clicked ? 1.0f : 0.0f);
        break;

    default:
        break;
    }
}

void PunchUI::tabClicked(Tab *tab, const bool fold)
{
    auto tabID = tab->getId();
    switch (tabID)
    {
    case kTabEasy:
        return;
        break;
    case kTabDetector:
        if (fold)
        {
            tab->setHeight(20);
            fPeakRMS->setVisible(false);
            fDetStrength->setVisible(false);
            fRmsSize->setVisible(false);
            fDetectorRelease->setVisible(false);
            fSideChainHpf->setVisible(false);
            fSlowFast->setVisible(false);
        }
        else
        {
            tab->setHeight(smallKnobSize.getHeight() + 20); // FIXME hardcode
            fPeakRMS->setVisible(true);
            fDetStrength->setVisible(true);
            fRmsSize->setVisible(true);
            fDetectorRelease->setVisible(true);
            fSideChainHpf->setVisible(true);
            fSlowFast->setVisible(true);
        }
        break;
    case kTabShape:
        if (fold)
        {
            tab->setHeight(20);
            fPower->setVisible(false);
            fMaxGainReduction->setVisible(false);
            fCurve->setVisible(false);
            fShape->setVisible(false);
            fFeedbackFeedforward->setVisible(false);
            fHiShelfFreq->setVisible(false);
            fGainHiShelfCrossfade->setVisible(false);
            fDryWet->setVisible(false);
        }
        else
        {
            tab->setHeight(smallKnobSize.getHeight() + 20);
            fPower->setVisible(true);
            fMaxGainReduction->setVisible(true);
            fCurve->setVisible(true);
            fShape->setVisible(true);
            fFeedbackFeedforward->setVisible(true);
            fHiShelfFreq->setVisible(true);
            fGainHiShelfCrossfade->setVisible(true);
            fDryWet->setVisible(true);
        }
        break;
    case kTabRateLimit:
        if (fold)
        {
            tab->setHeight(20);
            fRateLimitAmount->setVisible(false);
            fMaxAttack->setVisible(false);
            fMaxDecay->setVisible(false);
            fDecayMult->setVisible(false);
            fDecayPower->setVisible(false);
            fIMSize->setVisible(false);
        }
        else
        {
            tab->setHeight(smallKnobSize.getHeight() + 20);
            fRateLimitAmount->setVisible(true);
            fMaxAttack->setVisible(true);
            fMaxDecay->setVisible(true);
            fDecayMult->setVisible(true);
            fDecayPower->setVisible(true);
            fIMSize->setVisible(true);
        }
        break;
    default:
        break;
    }
    positionWidgets();
}

bool PunchUI::onMotion(const MotionEvent &ev)
{
    oldTime = std::chrono::high_resolution_clock::now();
    tooltipPosition = ev.pos;
    const uint toolTipY = tooltipPosition.getY() + 10;
    const uint toolTipX = tooltipPosition.getX() + 10;
    tooltipPosition.setY(toolTipY);
    tooltipPosition.setX(toolTipX);
    drawTooltip = false;
    return true;
}

UI *createUI()
{
    return new PunchUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
