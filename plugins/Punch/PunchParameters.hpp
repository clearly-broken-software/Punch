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
    "strength",
    "Attack",
    "Release",
    "Knee",
    "output gain (dB)",
    "peak/RMS",
    "det strength",
    "RMS size",
    "Detector Release",
    "sidechain hpf",
    "slow/fast",
    "power",
    "Max Gain Reduction",
    "curve",
    "shape",
    "feedback/feedforward",
    "hi shelf freq",
    "gain/hi-shelve crossfade",
    "dry/wet",
    "ratelimit amount",
    "max attack",
    "max decay",
    "decayMult",
    "decayPower",
    "IM_size",
    "bypass",
    "auto-release",
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
    "",
    "",
    "",
    "",
    "ms",
    "",
    "",
    "",
    "dB",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "dB/s",
    "dB/s",
    "",
    "",
    "",
    "",
    "dB",
    "dB",
};
const char *parameterTooltips[]{
    //Input Gain
    "The input signal level is increased by this amount (in dB) to make up for the level lost due to compression",
    //Threshold
    "When the signal level exceeds the Threshold (in dB), its level is compressed according to the Ratio",
    //strength
    "",
    //Attack
    "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new lower target level (the compression `kicking in')",
    //Release
    "time constant (ms) coming out of compression",
    //Knee
    "soft knee amount in dB",
    //output gain (dB)
    "",
    //peak/RMS
    "",
    //det strength
    "",
    //RMS size
    "",
    //Detector Release
    "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new higher target level (the compression 'releasing')",
    //sidechain hpf
    "",
    //slow/fast
    "Unchecked: log  domain return-to-threshold detector       Checked: linear return-to-fi.zero detector",
    //power
    "",
    //Max Gain Reduction
    "The maximum amount of gain reduction",
    //curve
    "",
    //shape
    "",
    //feedback/feedforward
    ""
    //hi shelf freq
    "",
    //gain/hi-shelve crossfade
    "",
    //dry/wet
    "",
    //ratelimit amount
    "",
    //max attack
    "",
    //max decay
    "",
    //decayMult
    "",
    //decayPower
    "",
    //IM_size
    "",
    //auto-release
    "tooltip", "the amount of release slowdown due to auto-release",
    //GR
    "gain reduction in dB",
    //bypass
    ""};
#endif