#ifndef PUNCH_PLUGIN_HPP_INCLUDED
#define PUNCH_PLUGIN_HPP_INCLUDED
#include "DistrhoPluginInfo.h"
#include "DistrhoPlugin.hpp"
#include "PunchDSP.hpp"
#include "zix/ring.h"
//#include "zix/trie.h"
#include <chrono>

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class PunchPlugin : public Plugin
{
public:
    PunchPlugin();
    float getGR();
    ~PunchPlugin();

protected:
    const char *getLabel() const override
    {
        return "Punch";
    }

    const char *getDescription() const override
    {
        return "Punch, a compressor with character";
    }

    const char *getMaker() const override
    {
        return "Clearly Broken Software";
    }

    const char *getHomePage() const override
    {
        return "https://github.com/clearly-broken-software/Punch";
    }

    const char *getLicense() const override
    {
        return "GPL";
    }

    uint32_t getVersion() const override
    {
        return d_version(0, 0, 1);
    }

    int64_t getUniqueId() const override
    {
        return d_cconst('P', 'u', 'n', 'c');
    }

    void initParameter(uint32_t index, Parameter &parameter) override;
    float getParameterValue(uint32_t index) const override;
    void setParameterValue(uint32_t index, float value) override;
    void run(const float **inputs, float **outputs, uint32_t frames) override;
    

private:
    PunchDSP punchDSP;
    float fInput, fOutput;
    ZixRing* ringbuf;
    double scrollSpeed;
    float * avgBuffer = nullptr;
    float lastAvg; 
    

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PunchPlugin)
};


END_NAMESPACE_DISTRHO

#endif
