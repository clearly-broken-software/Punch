#ifndef CC_PARAMETERS_H_INCLUDED
#define CC_PARAMETERS_H_INCLUDED
struct parameter
{
    const float def;
    const float min;
    const float max;
};

const char *paramNames[]{
    "Input Gain",
    "Threshold",
    "Strength",
    "Attack",
    "Release",
    "Knee",
    "Output Gain (dB)",
    "Peak/RMS",
    "Detector Strength",
    "RMS Size",
    "Detector Release",
    "Sidechain Hpf",
    "Slow/Fast",
    "Power",
    "Max Gain Reduction",
    "Curve",
    "Shape",
    "FB/FF",
    "High Shelf Freq",
    "Gain/HS Xfade",
    "Dry/Wet",
    "Ratelimit Amount",
    "Max Attack",
    "Max Decay",
    "Decay Mult",
    "Decay Power",
    "IM Size",
    "Bypass",
    "Auto-Release",
    "GR"};

const parameter paramRange[]{
    {0, -40, 40},
    {-27.1, -80, 0},
    {1, 0, 8},
    {23.700001, 0.001, 500},
    {16, 0, 1000},
    {0, 0, 30},
    {0, -40, 40},
    {1, 0, 1},
    {1, 0, 8},
    {96, 2, 16384},
    {0.1, 0.1, 2000},
    {154, 1, 400},
    {0, 0, 1},
    {1.88, -33, 33},
    {-15, -60, 0},
    {0, -1, 1},
    {94, 1, 100},
    {0, 0, 1},
    {134, 1, 400},
    {0.81099999, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1020, 6, 8000},
    {3813, 6, 8000},
    {20000, 0, 200000},
    {50, 0, 50},
    {108, 1, 16384},
    {0, 0, 1},
    {0, -90, 0},
    {0, -60, 0}};

const char *parameterUnits[]{
    "dB",
    "dB",
    "",
    "ms",
    "ms",
    "dB",
    "dB",
    "",
    "",
    "",
    "ms",
    "Hz",
    "",
    "",
    "dB",
    "",
    "",
    "",
    "Hz",
    "",
    "",
    "",
    "dB/s",
    "dB/s",
    "",
    "",
    "",
    "",
    "",
    "dB",
};
const char *parameterTooltips[]{
    //Input Gain
    "The input signal level is increased by this amount (in dB) to make up for the level lost due to compression",
    //Threshold
    "When the signal level exceeds the Threshold (in dB), its level is compressed according to the Ratio",
    //strength
    "The amount of compression: 0 is no compression, 1 is limiter and above 1 is overcompression ",
    //Attack
    "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new lower target level (the compression `kicking in')",
    //Release
    "Time constant (ms) coming out of compression",
    //Knee
    "Soft knee amount in dB",
    //output gain (dB)
    "Gain applied to the mix of dry and wet, at the output",
    //peak/RMS
    "Peak or RMS level detection",
    //det strength
    "Multiplication factor at the detector stage",
    //RMS size
    "The number of samples that the RMS is taken of",
    //Detector Release
    "Release time of the detector. You normaly want this to be small, so the rate limiter later on in the chain can do it's thing.",
    //sidechain hpf
    "The cutoff frequency of the high pass filter in the sidechain",
    //slow/fast
    "Slow: log  domain return-to-threshold detector  Fast: linear return-to-zero detector",
    //power
    "Exponentially increase or decrease the detector GR",
    //Max Gain Reduction
    "The maximum amount of gain reduction",
    //curve
    "Curve the amount of GR in the detector",
    //shape
    "Wave-shape the amount of GR in the detector",
    //feedback/feedforward
    "Crossfade between feedback and feedforward GR detection",
    //hi shelf freq
    "The frequency of the high shelf filter used for gain reduction",
    //gain/hi-shelve crossfade
    "Crossfade between full range gain reduction, and high shelf gain reduction",
    //dry/wet
    "Mix between uncompressed and compressed sound",
    //ratelimit amount
    "The amount of rate limiting, IOW: slowing down the attack and release",
    //max attack
    "Maximum linear attack speed in dB/s",
    //max decay
    "Maximum linear decay speed in dB/s",
    //decayMult
    "The ratelimiter looks at the amount of change in the direction of the GR and slows the release down if there is a lot of change. So if the GR is going back and forth, it releases slow, and if it goes only up, it releases fast. This control multiplies the amount of slowdown",
    //decayPower
    "The ratelimiter looks at the amount of change in the direction of the GR and slows the release down if there is a lot of change. So if the GR is going back and forth, it releases slow, and if it goes only up, it releases fast. This control exponentially increases the amount of slowdown",
    //IM_size
    "The number of samples the rate limiter takes into acount for determining the amount of direction change",
      //bypass
    "Bypass the compressor",
    //auto-release
    "The amount of release slowdown due to auto-release",
    //GR
    "gain reduction in dB"
  };
#endif
