
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: CharacterCompressor.dsp
// Name: CharacterCompressor
// Author: Bart Brouns
// Copyright: (C) 2014 Bart Brouns
// License: 
// Version: 0.3.3
//------------------------------------------------------------------------------






#pragma once
#ifndef CharacterCompressor_Faust_pp_Gen_HPP_
#define CharacterCompressor_Faust_pp_Gen_HPP_

#include <memory>

class CharacterCompressor {
public:
    CharacterCompressor();
    ~CharacterCompressor();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        const float *in0,const float *in1,
        float *out0,float *out1,
        unsigned count) noexcept;

    enum { NumInputs = 2 };
    enum { NumOutputs = 2 };
    enum { NumActives = 22 };
    enum { NumPassives = 1 };
    enum { NumParameters = 23 };

    enum Parameter {
        p_Threshold,
        p_strength,
        p_Attack,
        p_Release,
        p_Input_Gain,
        p_peak_RMS,
        p_detector_Ratio,
        p_Release2,
        p_sidechain_hpf,
        p_power,
        p_Max_Gain_Reduction,
        p_curve,
        p_shape,
        p_feedback_feedforward,
        p_hi_shelf_freq,
        p_gain_hi_shelve_crossfade,
        p_output_gain__dB_,
        p_ratelimit_amount,
        p_max_attack,
        p_max_decay,
        p_decayMult,
        p_decayPower,
        P_gainReduction,
        
    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;

    
    float get_Threshold() const noexcept;
    
    float get_strength() const noexcept;
    
    float get_Attack() const noexcept;
    
    float get_Release() const noexcept;
    
    float get_Input_Gain() const noexcept;
    
    float get_peak_RMS() const noexcept;
    
    float get_detector_Ratio() const noexcept;
    
    float get_Release2() const noexcept;
    
    float get_sidechain_hpf() const noexcept;
    
    float get_power() const noexcept;
    
    float get_Max_Gain_Reduction() const noexcept;
    
    float get_curve() const noexcept;
    
    float get_shape() const noexcept;
    
    float get_feedback_feedforward() const noexcept;
    
    float get_hi_shelf_freq() const noexcept;
    
    float get_gain_hi_shelve_crossfade() const noexcept;
    
    float get_output_gain__dB_() const noexcept;
    
    float get_ratelimit_amount() const noexcept;
    
    float get_max_attack() const noexcept;
    
    float get_max_decay() const noexcept;
    
    float get_decayMult() const noexcept;
    
    float get_decayPower() const noexcept;
    
    float get_gainReduction() const noexcept;
    
    
    void set_Threshold(float value) noexcept;
    
    void set_strength(float value) noexcept;
    
    void set_Attack(float value) noexcept;
    
    void set_Release(float value) noexcept;
    
    void set_Input_Gain(float value) noexcept;
    
    void set_peak_RMS(float value) noexcept;
    
    void set_detector_Ratio(float value) noexcept;
    
    void set_Release2(float value) noexcept;
    
    void set_sidechain_hpf(float value) noexcept;
    
    void set_power(float value) noexcept;
    
    void set_Max_Gain_Reduction(float value) noexcept;
    
    void set_curve(float value) noexcept;
    
    void set_shape(float value) noexcept;
    
    void set_feedback_feedforward(float value) noexcept;
    
    void set_hi_shelf_freq(float value) noexcept;
    
    void set_gain_hi_shelve_crossfade(float value) noexcept;
    
    void set_output_gain__dB_(float value) noexcept;
    
    void set_ratelimit_amount(float value) noexcept;
    
    void set_max_attack(float value) noexcept;
    
    void set_max_decay(float value) noexcept;
    
    void set_decayMult(float value) noexcept;
    
    void set_decayPower(float value) noexcept;
    

public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;



};




#endif // CharacterCompressor_Faust_pp_Gen_HPP_
