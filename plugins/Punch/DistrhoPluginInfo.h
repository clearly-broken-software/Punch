// TODO Add License

#ifndef DISTRHO_PLUGIN_INFO_H_INCLUDED
#define DISTRHO_PLUGIN_INFO_H_INCLUDED

#define DISTRHO_PLUGIN_BRAND "Clearly Broken Software"
#define DISTRHO_PLUGIN_NAME "Punch"
#define DISTRHO_PLUGIN_URI "https://github.com/clearly-broken-software/Punch"

#define DISTRHO_PLUGIN_IS_SYNTH 0
#define DISTRHO_PLUGIN_HAS_UI 1
#define DISTRHO_P
#define DISTRHO_PLUGIN_IS_RT_SAFE 1
#define DISTRHO_PLUGIN_NUM_INPUTS 2
#define DISTRHO_PLUGIN_NUM_OUTPUTS 2
#define DISTRHO_PLUGIN_WANT_STATE 0
#define DISTRHO_PLUGIN_WANT_FULL_STATE 0
#define DISTRHO_UI_USE_NANOVG 1
#define DISTRHO_PLUGIN_WANT_DIRECT_ACCESS 1

//#define DISTRHO_UI_USER_RESIZABLE 1

#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:CompressorPlugin"

enum Parameters // exposed to the host
{
    // easy
    kInputGain,
    kThreshold,
    kStrength,
    kAttack,
    kRelease,
    kKnee,
    kOutputGain,
    
    // advanced
    // detector
    kPeakRMS,
    kDetStrength,
    kRMSSize,
    kDetectorRelease,
    kSideChainHPF,
    kSlowFast,

    // shape
    kPower,
    kMaxGainReduction,
    kCurve,
    kShape,
    kFeedbackFeedforward,
    kHiShelfFreq,
    kGainHiShelfCrossfade, 
    kDryWet,

    // rate limit
    kRateLimitAmount,
    kMaxAttack,
    kMaxDecay,
    kDecayMult,
    kDecayPower,
    kIMSize,

    //
    kBypass, //  easy tab 
    
    // output params 
    kAutoRelease,
    kGr,

    // internal use (dsp not in faust)
    kInputLevel,
    kOutputLevel,
    parameterCount
};

enum Elements {
    kTabEasy = 100,
    kTabAdvanced,
    kTabDetector,
    kTabShape,
    kTabRateLimit,
    kHistogram,
    kTooltip
};

#endif // DISTRHO_PLUGIN_INFO_H_INCLUDED
