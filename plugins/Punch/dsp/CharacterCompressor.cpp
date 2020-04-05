
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







#include "CharacterCompressor.hpp"



#include <utility>
#include <cmath>

class CharacterCompressor::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef CharacterCompressor::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <float.h>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

static float mydsp_faustpower2_f(float value) {
	return (value * value);
	
}
static float mydsp_faustpower3_f(float value) {
	return ((value * value) * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fRec5[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	float fConst2;
	FAUSTFLOAT fHslider9;
	float fConst3;
	FAUSTFLOAT fHslider10;
	float fVec0[3];
	float fRec7[3];
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	float fVec1[2];
	float fVec2[3];
	float fVec3[7];
	float fVec4[15];
	int IOTA;
	float fVec5[32];
	float fVec6[64];
	float fVec7[128];
	float fVec8[256];
	float fVec9[512];
	float fVec10[1024];
	float fVec11[2048];
	float fVec12[4096];
	float fVec13[8192];
	float fVec14[16384];
	float fVec15[32768];
	FAUSTFLOAT fHslider13;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider14;
	float fRec6[2];
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	float fConst8;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	float fVec16[3];
	FAUSTFLOAT fHslider19;
	float fConst9;
	float fVec17[2];
	float fVec18[3];
	float fVec19[7];
	float fVec20[15];
	float fVec21[32];
	float fVec22[64];
	float fVec23[128];
	float fVec24[256];
	float fVec25[512];
	float fVec26[1024];
	float fVec27[2048];
	float fVec28[4096];
	float fVec29[8192];
	float fVec30[16384];
	float fVec31[32768];
	FAUSTFLOAT fHslider20;
	float fRec8[2];
	FAUSTFLOAT fVbargraph0;
	float fVec32[2];
	float fRec3[2];
	float fRec2[3];
	float fRec10[2];
	float fRec9[3];
	float fRec0[2];
	float fVec33[2];
	float fRec12[2];
	float fRec11[3];
	float fRec14[2];
	float fRec13[3];
	float fRec1[2];
	FAUSTFLOAT fHslider21;
	float fRec15[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.0");
		m->declare("author", "Bart Brouns");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("copyright", "(C) 2014 Bart Brouns");
		m->declare("filename", "CharacterCompressor");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("lib/CharacterCompressor.lib/author", "Bart Brouns");
		m->declare("lib/CharacterCompressor.lib/copyright", "(C) 2014 Bart Brouns");
		m->declare("lib/CharacterCompressor.lib/name", "CharacterCompressor");
		m->declare("lib/CharacterCompressor.lib/version", "0.3.3");
		m->declare("lib/slidingReduce.lib/author", "Bart Brouns (bart@magnetophon.nl)");
		m->declare("lib/slidingReduce.lib/copyright", "Bart Brouns");
		m->declare("lib/slidingReduce.lib/license", "LGPL");
		m->declare("lib/slidingReduce.lib/name", "Sliding Reduce Library");
		m->declare("lib/slidingReduce.lib/version", "0.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "CharacterCompressor");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("version", "0.3.3");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 2;
		
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
		
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	FAUSTPP_VIRTUAL int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (6.28318548f / fConst0);
		fConst3 = (6.53275824f / fConst0);
		fConst4 = (339.785217f / fConst0);
		fConst5 = (1812.18787f / fConst0);
		fConst6 = std::log(float(LDBL_MIN));
		fConst7 = std::log(float(LDBL_MAX));
		fConst8 = (1.0f / fConst0);
		fConst9 = (44100.0f / fConst0);
		
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(134.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.81100000000000005f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fHslider5 = FAUSTFLOAT(-15.0f);
		fHslider6 = FAUSTFLOAT(94.0f);
		fHslider7 = FAUSTFLOAT(20.0f);
		fHslider8 = FAUSTFLOAT(1.0f);
		fHslider9 = FAUSTFLOAT(154.0f);
		fHslider10 = FAUSTFLOAT(0.0f);
		fHslider11 = FAUSTFLOAT(0.48199999999999998f);
		fHslider12 = FAUSTFLOAT(23.699999999999999f);
		fHslider13 = FAUSTFLOAT(-27.100000000000001f);
		fHslider14 = FAUSTFLOAT(0.10000000000000001f);
		fHslider15 = FAUSTFLOAT(1.881f);
		fHslider16 = FAUSTFLOAT(0.0f);
		fHslider17 = FAUSTFLOAT(3813.0f);
		fHslider18 = FAUSTFLOAT(1020.0f);
		fHslider19 = FAUSTFLOAT(20000.0f);
		fHslider20 = FAUSTFLOAT(50.0f);
		fHslider21 = FAUSTFLOAT(0.0f);
		
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec4[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec5[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec7[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fVec2[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 7); l6 = (l6 + 1)) {
			fVec3[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 15); l7 = (l7 + 1)) {
			fVec4[l7] = 0.0f;
			
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 32); l8 = (l8 + 1)) {
			fVec5[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 64); l9 = (l9 + 1)) {
			fVec6[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 128); l10 = (l10 + 1)) {
			fVec7[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 256); l11 = (l11 + 1)) {
			fVec8[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 512); l12 = (l12 + 1)) {
			fVec9[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 1024); l13 = (l13 + 1)) {
			fVec10[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 2048); l14 = (l14 + 1)) {
			fVec11[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 4096); l15 = (l15 + 1)) {
			fVec12[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 8192); l16 = (l16 + 1)) {
			fVec13[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 16384); l17 = (l17 + 1)) {
			fVec14[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 32768); l18 = (l18 + 1)) {
			fVec15[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec6[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fVec16[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fVec17[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fVec18[l22] = 0.0f;
			
		}
		for (int l23 = 0; (l23 < 7); l23 = (l23 + 1)) {
			fVec19[l23] = 0.0f;
			
		}
		for (int l24 = 0; (l24 < 15); l24 = (l24 + 1)) {
			fVec20[l24] = 0.0f;
			
		}
		for (int l25 = 0; (l25 < 32); l25 = (l25 + 1)) {
			fVec21[l25] = 0.0f;
			
		}
		for (int l26 = 0; (l26 < 64); l26 = (l26 + 1)) {
			fVec22[l26] = 0.0f;
			
		}
		for (int l27 = 0; (l27 < 128); l27 = (l27 + 1)) {
			fVec23[l27] = 0.0f;
			
		}
		for (int l28 = 0; (l28 < 256); l28 = (l28 + 1)) {
			fVec24[l28] = 0.0f;
			
		}
		for (int l29 = 0; (l29 < 512); l29 = (l29 + 1)) {
			fVec25[l29] = 0.0f;
			
		}
		for (int l30 = 0; (l30 < 1024); l30 = (l30 + 1)) {
			fVec26[l30] = 0.0f;
			
		}
		for (int l31 = 0; (l31 < 2048); l31 = (l31 + 1)) {
			fVec27[l31] = 0.0f;
			
		}
		for (int l32 = 0; (l32 < 4096); l32 = (l32 + 1)) {
			fVec28[l32] = 0.0f;
			
		}
		for (int l33 = 0; (l33 < 8192); l33 = (l33 + 1)) {
			fVec29[l33] = 0.0f;
			
		}
		for (int l34 = 0; (l34 < 16384); l34 = (l34 + 1)) {
			fVec30[l34] = 0.0f;
			
		}
		for (int l35 = 0; (l35 < 32768); l35 = (l35 + 1)) {
			fVec31[l35] = 0.0f;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec8[l36] = 0.0f;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fVec32[l37] = 0.0f;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec3[l38] = 0.0f;
			
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec2[l39] = 0.0f;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec10[l40] = 0.0f;
			
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec9[l41] = 0.0f;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec0[l42] = 0.0f;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fVec33[l43] = 0.0f;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec12[l44] = 0.0f;
			
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec11[l45] = 0.0f;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec14[l46] = 0.0f;
			
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec13[l47] = 0.0f;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec1[l48] = 0.0f;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec15[l49] = 0.0f;
			
		}
		
	}
	
	FAUSTPP_VIRTUAL void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	
	FAUSTPP_VIRTUAL void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("CharacterCompressor");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fVbargraph0, "1", "");
		ui_interface->declare(&fVbargraph0, "tooltip", "input level in dB");
		ui_interface->declare(&fVbargraph0, "unit", "dB");
		ui_interface->addVerticalBargraph("0x55e0898a84a0", &fVbargraph0, -60.0f, 0.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		//ui_interface->openTabBox("0x00");
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("easy");
		ui_interface->declare(&fHslider13, "1", "");
		ui_interface->declare(&fHslider13, "tooltip", "When the signal level exceeds the Threshold (in dB), its level is compressed according to the Ratio");
		ui_interface->declare(&fHslider13, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider13, -27.1000004f, -80.0f, 0.0f, 0.100000001f);
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->declare(&fHslider3, "tooltip", "");
		ui_interface->addHorizontalSlider("strength", &fHslider3, 1.0f, 0.0f, 2.0f, 0.00100000005f);
		ui_interface->declare(&fHslider12, "3", "");
		ui_interface->declare(&fHslider12, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new lower target level (the compression `kicking in')");
		ui_interface->declare(&fHslider12, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider12, 23.7000008f, 0.100000001f, 500.0f, 0.100000001f);
		ui_interface->declare(&fHslider11, "4", "");
		ui_interface->declare(&fHslider11, "tooltip", "");
		ui_interface->addHorizontalSlider("Release", &fHslider11, 0.481999993f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider1, "5", "");
		ui_interface->declare(&fHslider1, "tooltip", "The input signal level is increased by this amount (in dB) to make up for the level lost due to compression");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Input Gain", &fHslider1, 0.0f, -40.0f, 40.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("advanced");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("detector");
		ui_interface->declare(&fHslider8, "2", "");
		ui_interface->addHorizontalSlider("peak/RMS", &fHslider8, 1.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider7, "5", "");
		ui_interface->declare(&fHslider7, "tooltip", "A compression Ratio of N means that for each N dB increase in input signal level above Threshold, the output level goes up 1 dB");
		ui_interface->addHorizontalSlider("detector Ratio", &fHslider7, 20.0f, 1.0f, 20.0f, 0.100000001f);
		ui_interface->declare(&fHslider14, "7", "");
		ui_interface->declare(&fHslider14, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new higher target level (the compression 'releasing')");
		ui_interface->declare(&fHslider14, "unit", "ms");
		ui_interface->addHorizontalSlider("Release2", &fHslider14, 0.100000001f, 0.100000001f, 2000.0f, 0.100000001f);
		ui_interface->declare(&fHslider9, "8", "");
		ui_interface->declare(&fHslider9, "tooltip", "");
		ui_interface->addHorizontalSlider("sidechain hpf", &fHslider9, 154.0f, 1.0f, 400.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("shape");
		ui_interface->declare(&fHslider15, "1", "");
		ui_interface->declare(&fHslider15, "tooltip", "");
		ui_interface->addHorizontalSlider("power", &fHslider15, 1.88100004f, -33.0f, 33.0f, 0.00100000005f);
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->declare(&fHslider5, "tooltip", "The maximum amount of gain reduction");
		ui_interface->declare(&fHslider5, "unit", "dB");
		ui_interface->addHorizontalSlider("Max Gain Reduction", &fHslider5, -15.0f, -60.0f, 0.0f, 0.100000001f);
		ui_interface->declare(&fHslider16, "3", "");
		ui_interface->declare(&fHslider16, "tooltip", "");
		ui_interface->addHorizontalSlider("curve", &fHslider16, 0.0f, -1.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider6, "4", "");
		ui_interface->declare(&fHslider6, "tooltip", "");
		ui_interface->addHorizontalSlider("shape", &fHslider6, 94.0f, 1.0f, 100.0f, 0.00100000005f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(&fHslider10, "0", "");
		ui_interface->declare(&fHslider10, "tooltip", "");
		ui_interface->addHorizontalSlider("feedback/feedforward", &fHslider10, 0.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "tooltip", "");
		ui_interface->addHorizontalSlider("hi shelf freq", &fHslider0, 134.0f, 1.0f, 400.0f, 1.0f);
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "tooltip", "");
		ui_interface->addHorizontalSlider("gain/hi-shelve crossfade", &fHslider2, 0.81099999f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider21, "3", "");
		ui_interface->declare(&fHslider21, "tooltip", "");
		ui_interface->addHorizontalSlider("output gain (dB)", &fHslider21, 0.0f, -40.0f, 40.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("ratelimit");
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->declare(&fHslider4, "tooltip", "");
		ui_interface->addHorizontalSlider("ratelimit amount", &fHslider4, 1.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider18, "1", "");
		ui_interface->declare(&fHslider18, "tooltip", "");
		ui_interface->declare(&fHslider18, "unit", "dB/s");
		ui_interface->addHorizontalSlider("max attack", &fHslider18, 1020.0f, 6.0f, 8000.0f, 1.0f);
		ui_interface->declare(&fHslider17, "2", "");
		ui_interface->declare(&fHslider17, "tooltip", "");
		ui_interface->declare(&fHslider17, "unit", "dB/s");
		ui_interface->addHorizontalSlider("max decay", &fHslider17, 3813.0f, 6.0f, 8000.0f, 1.0f);
		ui_interface->declare(&fHslider19, "3", "");
		ui_interface->declare(&fHslider19, "tooltip", "");
		ui_interface->addHorizontalSlider("decayMult", &fHslider19, 20000.0f, 0.0f, 20000.0f, 0.00100000005f);
		ui_interface->declare(&fHslider20, "4", "");
		ui_interface->declare(&fHslider20, "tooltip", "");
		ui_interface->addHorizontalSlider("decayPower", &fHslider20, 50.0f, 0.0f, 50.0f, 0.00100000005f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::tan((fConst1 * float(fHslider0)));
		float fSlow1 = (1.0f / fSlow0);
		float fSlow2 = (1.0f / (((fSlow1 + 1.0f) / fSlow0) + 1.0f));
		float fSlow3 = mydsp_faustpower2_f(fSlow0);
		float fSlow4 = (1.0f / fSlow3);
		float fSlow5 = (fSlow1 + 1.0f);
		float fSlow6 = (0.0f - (1.0f / (fSlow5 * fSlow0)));
		float fSlow7 = (0.00100000005f * std::pow(10.0f, (0.0500000007f * float(fHslider1))));
		float fSlow8 = float(fHslider2);
		float fSlow9 = (1.0f - fSlow8);
		float fSlow10 = (0.0500000007f * float(fHslider3));
		float fSlow11 = float(fHslider4);
		float fSlow12 = (20.0f * (1.0f - fSlow11));
		float fSlow13 = (0.00100000005f * std::pow(10.0f, (0.0500000007f * float(fHslider5))));
		float fSlow14 = mydsp_faustpower2_f((101.0f - float(fHslider6)));
		float fSlow15 = (0.0500000007f * (1.0f - (1.0f / float(fHslider7))));
		float fSlow16 = float(fHslider8);
		float fSlow17 = (1.0f - fSlow16);
		float fSlow18 = float(fHslider9);
		float fSlow19 = (fConst2 * fSlow18);
		float fSlow20 = std::sin(fSlow19);
		float fSlow21 = (fSlow20 * float(sinhf(float((fConst3 * (fSlow18 / fSlow20))))));
		float fSlow22 = (1.0f / (fSlow21 + 1.0f));
		float fSlow23 = std::cos(fSlow19);
		float fSlow24 = (-1.0f - fSlow23);
		float fSlow25 = float(fHslider10);
		float fSlow26 = (1.0f - fSlow25);
		float fSlow27 = (0.5f * (fSlow23 + 1.0f));
		float fSlow28 = (2.0f * fSlow23);
		float fSlow29 = (fSlow21 + -1.0f);
		float fSlow30 = float(fHslider11);
		float fSlow31 = float(fHslider12);
		int iSlow32 = int(std::max<float>(96.0f, std::pow(2.0f, std::min<float>((14.0f * std::pow(fSlow30, 0.125f)), (14.0f * std::pow((0.00200000009f * fSlow31), 0.25f))))));
		float fSlow33 = float(iSlow32);
		float fSlow34 = (1.0f / fSlow33);
		int iSlow35 = (1 & (iSlow32 == 0));
		int iSlow36 = (int(std::floor(fSlow33)) % 2);
		int iSlow37 = (int(std::floor((0.5f * fSlow33))) % 2);
		int iSlow38 = (int(std::floor((0.25f * fSlow33))) % 2);
		int iSlow39 = (iSlow36 + (2 * iSlow37));
		int iSlow40 = (int(std::floor((0.125f * fSlow33))) % 2);
		int iSlow41 = (iSlow39 + (4 * iSlow38));
		int iSlow42 = (int(std::floor((0.0625f * fSlow33))) % 2);
		int iSlow43 = (iSlow41 + (8 * iSlow40));
		int iSlow44 = (int(std::floor((0.03125f * fSlow33))) % 2);
		int iSlow45 = (iSlow43 + (16 * iSlow42));
		int iSlow46 = (int(std::floor((0.015625f * fSlow33))) % 2);
		int iSlow47 = (iSlow45 + (32 * iSlow44));
		int iSlow48 = (int(std::floor((0.0078125f * fSlow33))) % 2);
		int iSlow49 = (iSlow47 + (64 * iSlow46));
		int iSlow50 = (int(std::floor((0.00390625f * fSlow33))) % 2);
		int iSlow51 = (iSlow49 + (128 * iSlow48));
		int iSlow52 = (int(std::floor((0.001953125f * fSlow33))) % 2);
		int iSlow53 = (iSlow51 + (256 * iSlow50));
		int iSlow54 = (int(std::floor((0.0009765625f * fSlow33))) % 2);
		int iSlow55 = (iSlow53 + (512 * iSlow52));
		int iSlow56 = (int(std::floor((0.00048828125f * fSlow33))) % 2);
		int iSlow57 = (iSlow55 + (1024 * iSlow54));
		int iSlow58 = (int(std::floor((0.000244140625f * fSlow33))) % 2);
		int iSlow59 = (iSlow57 + (2048 * iSlow56));
		int iSlow60 = (int(std::floor((0.000122070312f * fSlow33))) % 2);
		int iSlow61 = (iSlow59 + (4096 * iSlow58));
		int iSlow62 = (int(std::floor((6.10351562e-05f * fSlow33))) % 2);
		int iSlow63 = (iSlow61 + (8192 * iSlow60));
		float fSlow64 = float(fHslider13);
		float fSlow65 = (fConst4 / fSlow31);
		float fSlow66 = (fConst5 / float(fHslider14));
		float fSlow67 = float(fHslider15);
		float fSlow68 = ((float((fSlow67 >= 0.0f)) / mydsp_faustpower3_f((fSlow67 + 1.0f))) + (float((fSlow67 < 0.0f)) * mydsp_faustpower3_f((1.0f - fSlow67))));
		float fSlow69 = std::exp((6.93147182f * (0.0f - float(fHslider16))));
		float fSlow70 = (fConst8 * float(fHslider17));
		float fSlow71 = (0.0f - (fConst8 * float(fHslider18)));
		int iSlow72 = int(std::max<float>(1.0f, (fConst9 * std::pow(2.0f, (14.0f * fSlow30)))));
		float fSlow73 = float(iSlow72);
		float fSlow74 = (0.00999999978f * (float(fHslider19) / fSlow73));
		int iSlow75 = (1 & (iSlow72 == 0));
		int iSlow76 = (int(std::floor(fSlow73)) % 2);
		int iSlow77 = (int(std::floor((0.5f * fSlow73))) % 2);
		int iSlow78 = (int(std::floor((0.25f * fSlow73))) % 2);
		int iSlow79 = (iSlow76 + (2 * iSlow77));
		int iSlow80 = (int(std::floor((0.125f * fSlow73))) % 2);
		int iSlow81 = (iSlow79 + (4 * iSlow78));
		int iSlow82 = (int(std::floor((0.0625f * fSlow73))) % 2);
		int iSlow83 = (iSlow81 + (8 * iSlow80));
		int iSlow84 = (int(std::floor((0.03125f * fSlow73))) % 2);
		int iSlow85 = (iSlow83 + (16 * iSlow82));
		int iSlow86 = (int(std::floor((0.015625f * fSlow73))) % 2);
		int iSlow87 = (iSlow85 + (32 * iSlow84));
		int iSlow88 = (int(std::floor((0.0078125f * fSlow73))) % 2);
		int iSlow89 = (iSlow87 + (64 * iSlow86));
		int iSlow90 = (int(std::floor((0.00390625f * fSlow73))) % 2);
		int iSlow91 = (iSlow89 + (128 * iSlow88));
		int iSlow92 = (int(std::floor((0.001953125f * fSlow73))) % 2);
		int iSlow93 = (iSlow91 + (256 * iSlow90));
		int iSlow94 = (int(std::floor((0.0009765625f * fSlow73))) % 2);
		int iSlow95 = (iSlow93 + (512 * iSlow92));
		int iSlow96 = (int(std::floor((0.00048828125f * fSlow73))) % 2);
		int iSlow97 = (iSlow95 + (1024 * iSlow94));
		int iSlow98 = (int(std::floor((0.000244140625f * fSlow73))) % 2);
		int iSlow99 = (iSlow97 + (2048 * iSlow96));
		int iSlow100 = (int(std::floor((0.000122070312f * fSlow73))) % 2);
		int iSlow101 = (iSlow99 + (4096 * iSlow98));
		int iSlow102 = (int(std::floor((6.10351562e-05f * fSlow73))) % 2);
		int iSlow103 = (iSlow101 + (8192 * iSlow100));
		float fSlow104 = float(fHslider20);
		float fSlow105 = (1.0f / fSlow5);
		float fSlow106 = (1.0f - fSlow1);
		float fSlow107 = (((fSlow1 + -1.0f) / fSlow0) + 1.0f);
		float fSlow108 = (2.0f * (1.0f - fSlow4));
		float fSlow109 = (0.0f - (2.0f / fSlow3));
		float fSlow110 = (0.00100000005f * float(fHslider21));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec4[0] = (fSlow7 + (0.999000013f * fRec4[1]));
			fRec5[0] = (fSlow13 + (0.999000013f * fRec5[1]));
			float fTemp0 = (1.0f - fRec5[0]);
			float fTemp1 = float(input1[i]);
			float fTemp2 = float(input0[i]);
			float fTemp3 = ((fSlow26 * (fRec0[1] + fRec1[1])) + (fSlow25 * (fRec4[0] * (fTemp1 + fTemp2))));
			fVec0[0] = fTemp3;
			fRec7[0] = (fSlow22 * (((((fSlow24 * fVec0[1]) + (fSlow27 * fTemp3)) + (fSlow27 * fVec0[2])) + (fSlow28 * fRec7[1])) + (fSlow29 * fRec7[2])));
			float fTemp4 = mydsp_faustpower2_f(fRec7[0]);
			fVec1[0] = fTemp4;
			float fTemp5 = (fTemp4 + fVec1[1]);
			fVec2[0] = fTemp5;
			float fTemp6 = (fTemp5 + fVec2[2]);
			fVec3[0] = fTemp6;
			float fTemp7 = (fTemp6 + fVec3[4]);
			fVec4[0] = fTemp7;
			float fTemp8 = (fTemp7 + fVec4[8]);
			fVec5[(IOTA & 31)] = fTemp8;
			float fTemp9 = (fTemp8 + fVec5[((IOTA - 16) & 31)]);
			fVec6[(IOTA & 63)] = fTemp9;
			float fTemp10 = (fTemp9 + fVec6[((IOTA - 32) & 63)]);
			fVec7[(IOTA & 127)] = fTemp10;
			float fTemp11 = (fTemp10 + fVec7[((IOTA - 64) & 127)]);
			fVec8[(IOTA & 255)] = fTemp11;
			float fTemp12 = (fTemp11 + fVec8[((IOTA - 128) & 255)]);
			fVec9[(IOTA & 511)] = fTemp12;
			float fTemp13 = (fTemp12 + fVec9[((IOTA - 256) & 511)]);
			fVec10[(IOTA & 1023)] = fTemp13;
			float fTemp14 = (fTemp13 + fVec10[((IOTA - 512) & 1023)]);
			fVec11[(IOTA & 2047)] = fTemp14;
			float fTemp15 = (fTemp14 + fVec11[((IOTA - 1024) & 2047)]);
			fVec12[(IOTA & 4095)] = fTemp15;
			float fTemp16 = (fTemp15 + fVec12[((IOTA - 2048) & 4095)]);
			fVec13[(IOTA & 8191)] = fTemp16;
			float fTemp17 = (fTemp16 + fVec13[((IOTA - 4096) & 8191)]);
			fVec14[(IOTA & 16383)] = fTemp17;
			fVec15[(IOTA & 32767)] = (fTemp17 + fVec14[((IOTA - 8192) & 16383)]);
			float fTemp18 = (20.0f * std::log10(((fSlow17 * fRec7[0]) + (fSlow16 * std::sqrt((fSlow34 * (((((((((((((((iSlow35?fTemp4:(iSlow36?fTemp4:0.0f)) + (iSlow37?fVec2[iSlow36]:0.0f)) + (iSlow38?fVec3[iSlow39]:0.0f)) + (iSlow40?fVec4[iSlow41]:0.0f)) + (iSlow42?fVec5[((IOTA - iSlow43) & 31)]:0.0f)) + (iSlow44?fVec6[((IOTA - iSlow45) & 63)]:0.0f)) + (iSlow46?fVec7[((IOTA - iSlow47) & 127)]:0.0f)) + (iSlow48?fVec8[((IOTA - iSlow49) & 255)]:0.0f)) + (iSlow50?fVec9[((IOTA - iSlow51) & 511)]:0.0f)) + (iSlow52?fVec10[((IOTA - iSlow53) & 1023)]:0.0f)) + (iSlow54?fVec11[((IOTA - iSlow55) & 2047)]:0.0f)) + (iSlow56?fVec12[((IOTA - iSlow57) & 4095)]:0.0f)) + (iSlow58?fVec13[((IOTA - iSlow59) & 8191)]:0.0f)) + (iSlow60?fVec14[((IOTA - iSlow61) & 16383)]:0.0f)) + (iSlow62?fVec15[((IOTA - iSlow63) & 32767)]:0.0f))))))));
			float fTemp19 = ((fTemp18 - fSlow64) * float((fSlow64 < fTemp18)));
			float fTemp20 = ((fTemp19 < fRec6[1])?fSlow66:fSlow65);
			fRec6[0] = ((fTemp19 * fTemp20) + (fRec6[1] * (1.0f - fTemp20)));
			float fTemp21 = std::max<float>(float(LDBL_MIN), std::min<float>(1.0f, std::pow(10.0f, (0.0f - (fSlow15 * fRec6[0])))));
			float fTemp22 = std::log(fTemp21);
			float fTemp23 = (std::pow(fTemp21, std::min<float>((fConst6 / fTemp22), std::max<float>((fConst7 / fTemp22), fSlow68))) - fRec5[0]);
			float fTemp24 = (fTemp23 / fTemp0);
			float fTemp25 = std::log10((fRec5[0] + (fTemp0 * (float(tanhf(float((fSlow14 * (std::pow(((fTemp23 * float((fTemp24 > 0.0f))) / fTemp0), fSlow69) + (-1.0f - std::pow(((0.0f - fTemp24) * float((fTemp24 <= 0.0f))), fSlow69))))))) + 1.0f))));
			float fTemp26 = ((20.0f * fTemp25) - fRec8[1]);
			fVec16[0] = fTemp26;
			float fTemp27 = std::fabs((fVec16[1] - fVec16[2]));
			fVec17[0] = fTemp27;
			float fTemp28 = (fTemp27 + fVec17[1]);
			fVec18[0] = fTemp28;
			float fTemp29 = (fTemp28 + fVec18[2]);
			fVec19[0] = fTemp29;
			float fTemp30 = (fTemp29 + fVec19[4]);
			fVec20[0] = fTemp30;
			float fTemp31 = (fTemp30 + fVec20[8]);
			fVec21[(IOTA & 31)] = fTemp31;
			float fTemp32 = (fTemp31 + fVec21[((IOTA - 16) & 31)]);
			fVec22[(IOTA & 63)] = fTemp32;
			float fTemp33 = (fTemp32 + fVec22[((IOTA - 32) & 63)]);
			fVec23[(IOTA & 127)] = fTemp33;
			float fTemp34 = (fTemp33 + fVec23[((IOTA - 64) & 127)]);
			fVec24[(IOTA & 255)] = fTemp34;
			float fTemp35 = (fTemp34 + fVec24[((IOTA - 128) & 255)]);
			fVec25[(IOTA & 511)] = fTemp35;
			float fTemp36 = (fTemp35 + fVec25[((IOTA - 256) & 511)]);
			fVec26[(IOTA & 1023)] = fTemp36;
			float fTemp37 = (fTemp36 + fVec26[((IOTA - 512) & 1023)]);
			fVec27[(IOTA & 2047)] = fTemp37;
			float fTemp38 = (fTemp37 + fVec27[((IOTA - 1024) & 2047)]);
			fVec28[(IOTA & 4095)] = fTemp38;
			float fTemp39 = (fTemp38 + fVec28[((IOTA - 2048) & 4095)]);
			fVec29[(IOTA & 8191)] = fTemp39;
			float fTemp40 = (fTemp39 + fVec29[((IOTA - 4096) & 8191)]);
			fVec30[(IOTA & 16383)] = fTemp40;
			fVec31[(IOTA & 32767)] = (fTemp40 + fVec30[((IOTA - 8192) & 16383)]);
			fRec8[0] = std::max<float>((20.0f * std::log10(fRec5[0])), std::min<float>(0.0f, (fRec8[1] + std::min<float>(fSlow70, std::max<float>(fSlow71, ((fTemp26 > 0.0f)?(fTemp26 * std::pow(10.0f, (0.0500000007f * (0.0f - std::fabs((std::pow(((fSlow74 * (((((((((((((((iSlow75?fTemp27:(iSlow76?fTemp27:0.0f)) + (iSlow77?fVec18[iSlow76]:0.0f)) + (iSlow78?fVec19[iSlow79]:0.0f)) + (iSlow80?fVec20[iSlow81]:0.0f)) + (iSlow82?fVec21[((IOTA - iSlow83) & 31)]:0.0f)) + (iSlow84?fVec22[((IOTA - iSlow85) & 63)]:0.0f)) + (iSlow86?fVec23[((IOTA - iSlow87) & 127)]:0.0f)) + (iSlow88?fVec24[((IOTA - iSlow89) & 255)]:0.0f)) + (iSlow90?fVec25[((IOTA - iSlow91) & 511)]:0.0f)) + (iSlow92?fVec26[((IOTA - iSlow93) & 1023)]:0.0f)) + (iSlow94?fVec27[((IOTA - iSlow95) & 2047)]:0.0f)) + (iSlow96?fVec28[((IOTA - iSlow97) & 4095)]:0.0f)) + (iSlow98?fVec29[((IOTA - iSlow99) & 8191)]:0.0f)) + (iSlow100?fVec30[((IOTA - iSlow101) & 16383)]:0.0f)) + (iSlow102?fVec31[((IOTA - iSlow103) & 32767)]:0.0f))) + 1.0f), fSlow104) + -1.0f)))))):fTemp26))))));
			float fTemp41 = std::pow(10.0f, (fSlow10 * ((fSlow12 * fTemp25) + (fSlow11 * fRec8[0]))));
			float fTemp42 = std::log10(fTemp41);
			fVbargraph0 = FAUSTFLOAT((20.0f * fTemp42));
			float fTemp43 = (fRec4[0] * std::pow(10.0f, (fSlow9 * std::log10(fTemp41))));
			float fTemp44 = (fTemp43 * fTemp2);
			fVec32[0] = fTemp44;
			fRec3[0] = ((fSlow6 * fVec32[1]) - (fSlow105 * ((fSlow106 * fRec3[1]) - (fSlow1 * fTemp44))));
			fRec2[0] = (fRec3[0] - (fSlow2 * ((fSlow107 * fRec2[2]) + (fSlow108 * fRec2[1]))));
			float fTemp45 = std::pow(10.0f, (fSlow8 * fTemp42));
			fRec10[0] = (0.0f - (fSlow105 * ((fSlow106 * fRec10[1]) - (fTemp44 + fVec32[1]))));
			fRec9[0] = (fRec10[0] - (fSlow2 * ((fSlow107 * fRec9[2]) + (fSlow108 * fRec9[1]))));
			fRec0[0] = (fSlow2 * (((((fSlow4 * fRec2[0]) + (fSlow109 * fRec2[1])) + (fSlow4 * fRec2[2])) * fTemp45) + (fRec9[2] + (fRec9[0] + (2.0f * fRec9[1])))));
			float fTemp46 = (fTemp43 * fTemp1);
			fVec33[0] = fTemp46;
			fRec12[0] = ((fSlow6 * fVec33[1]) - (fSlow105 * ((fSlow106 * fRec12[1]) - (fSlow1 * fTemp46))));
			fRec11[0] = (fRec12[0] - (fSlow2 * ((fSlow107 * fRec11[2]) + (fSlow108 * fRec11[1]))));
			fRec14[0] = (0.0f - (fSlow105 * ((fSlow106 * fRec14[1]) - (fTemp46 + fVec33[1]))));
			fRec13[0] = (fRec14[0] - (fSlow2 * ((fSlow107 * fRec13[2]) + (fSlow108 * fRec13[1]))));
			fRec1[0] = (fSlow2 * ((fTemp45 * (((fSlow4 * fRec11[0]) + (fSlow109 * fRec11[1])) + (fSlow4 * fRec11[2]))) + (fRec13[2] + (fRec13[0] + (2.0f * fRec13[1])))));
			fRec15[0] = (fSlow110 + (0.999000013f * fRec15[1]));
			float fTemp47 = std::pow(10.0f, (0.0500000007f * fRec15[0]));
			output0[i] = FAUSTFLOAT((fRec0[0] * fTemp47));
			output1[i] = FAUSTFLOAT((fRec1[0] * fTemp47));
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec1[1] = fVec1[0];
			fVec2[2] = fVec2[1];
			fVec2[1] = fVec2[0];
			for (int j0 = 6; (j0 > 0); j0 = (j0 - 1)) {
				fVec3[j0] = fVec3[(j0 - 1)];
				
			}
			for (int j1 = 14; (j1 > 0); j1 = (j1 - 1)) {
				fVec4[j1] = fVec4[(j1 - 1)];
				
			}
			IOTA = (IOTA + 1);
			fRec6[1] = fRec6[0];
			fVec16[2] = fVec16[1];
			fVec16[1] = fVec16[0];
			fVec17[1] = fVec17[0];
			fVec18[2] = fVec18[1];
			fVec18[1] = fVec18[0];
			for (int j2 = 6; (j2 > 0); j2 = (j2 - 1)) {
				fVec19[j2] = fVec19[(j2 - 1)];
				
			}
			for (int j3 = 14; (j3 > 0); j3 = (j3 - 1)) {
				fVec20[j3] = fVec20[(j3 - 1)];
				
			}
			fRec8[1] = fRec8[0];
			fVec32[1] = fVec32[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec0[1] = fRec0[0];
			fVec33[1] = fVec33[0];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec1[1] = fRec1[0];
			fRec15[1] = fRec15[0];
			
		}
		
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




CharacterCompressor::CharacterCompressor()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

CharacterCompressor::~CharacterCompressor()
{
}

void CharacterCompressor::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void CharacterCompressor::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void CharacterCompressor::process(
    const float *in0,const float *in1,
    float *out0,float *out1,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),const_cast<float *>(in1),
    };
    float *outputs[] = {
        out0,out1,
    };
    dsp.compute(count, inputs, outputs);

}

const char *CharacterCompressor::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Threshold";
    
    case 1:
        return "strength";
    
    case 2:
        return "Attack";
    
    case 3:
        return "Release";
    
    case 4:
        return "Input Gain";
    
    case 5:
        return "peak/RMS";
    
    case 6:
        return "detector Ratio";
    
    case 7:
        return "Release2";
    
    case 8:
        return "sidechain hpf";
    
    case 9:
        return "power";
    
    case 10:
        return "Max Gain Reduction";
    
    case 11:
        return "curve";
    
    case 12:
        return "shape";
    
    case 13:
        return "feedback/feedforward";
    
    case 14:
        return "hi shelf freq";
    
    case 15:
        return "gain/hi-shelve crossfade";
    
    case 16:
        return "output gain (dB)";
    
    case 17:
        return "ratelimit amount";
    
    case 18:
        return "max attack";
    
    case 19:
        return "max decay";
    
    case 20:
        return "decayMult";
    
    case 21:
        return "decayPower";
    
    case 22:
        return "gainReduction";
    
    default:
        return 0;
    }
}

const char *CharacterCompressor::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "";
    
    case 5:
        return "";
    
    case 6:
        return "";
    
    case 7:
        return "";
    
    case 8:
        return "";
    
    case 9:
        return "";
    
    case 10:
        return "";
    
    case 11:
        return "";
    
    case 12:
        return "";
    
    case 13:
        return "";
    
    case 14:
        return "";
    
    case 15:
        return "";
    
    case 16:
        return "";
    
    case 17:
        return "";
    
    case 18:
        return "";
    
    case 19:
        return "";
    
    case 20:
        return "";
    
    case 21:
        return "";
    
    case 22:
        return "";
    
    default:
        return 0;
    }
}

const char *CharacterCompressor::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Threshold";
    
    case 1:
        return "strength";
    
    case 2:
        return "Attack";
    
    case 3:
        return "Release";
    
    case 4:
        return "Input_Gain";
    
    case 5:
        return "peak_RMS";
    
    case 6:
        return "detector_Ratio";
    
    case 7:
        return "Release2";
    
    case 8:
        return "sidechain_hpf";
    
    case 9:
        return "power";
    
    case 10:
        return "Max_Gain_Reduction";
    
    case 11:
        return "curve";
    
    case 12:
        return "shape";
    
    case 13:
        return "feedback_feedforward";
    
    case 14:
        return "hi_shelf_freq";
    
    case 15:
        return "gain_hi_shelve_crossfade";
    
    case 16:
        return "output_gain__dB_";
    
    case 17:
        return "ratelimit_amount";
    
    case 18:
        return "max_attack";
    
    case 19:
        return "max_decay";
    
    case 20:
        return "decayMult";
    
    case 21:
        return "decayPower";
    
    case 22:
        return "gainReduction";
    
    default:
        return 0;
    }
}

const char *CharacterCompressor::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "dB";
    
    case 1:
        return "";
    
    case 2:
        return "ms";
    
    case 3:
        return "";
    
    case 4:
        return "dB";
    
    case 5:
        return "";
    
    case 6:
        return "";
    
    case 7:
        return "ms";
    
    case 8:
        return "";
    
    case 9:
        return "";
    
    case 10:
        return "dB";
    
    case 11:
        return "";
    
    case 12:
        return "";
    
    case 13:
        return "";
    
    case 14:
        return "";
    
    case 15:
        return "";
    
    case 16:
        return "";
    
    case 17:
        return "";
    
    case 18:
        return "dB/s";
    
    case 19:
        return "dB/s";
    
    case 20:
        return "";
    
    case 21:
        return "";
    
    case 22:
        return "dB";
    
    default:
        return 0;
    }
}

const CharacterCompressor::ParameterRange *CharacterCompressor::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { -27.1, -80, 0 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 1, 0, 2 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 23.700001, 0.1, 500 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 0.48199999, 0, 1 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 0, -40, 40 };
        return &range;
    }
    
    case 5: {
        static const ParameterRange range = { 1, 0, 1 };
        return &range;
    }
    
    case 6: {
        static const ParameterRange range = { 20, 1, 20 };
        return &range;
    }
    
    case 7: {
        static const ParameterRange range = { 0.1, 0.1, 2000 };
        return &range;
    }
    
    case 8: {
        static const ParameterRange range = { 154, 1, 400 };
        return &range;
    }
    
    case 9: {
        static const ParameterRange range = { 1.881, -33, 33 };
        return &range;
    }
    
    case 10: {
        static const ParameterRange range = { -15, -60, 0 };
        return &range;
    }
    
    case 11: {
        static const ParameterRange range = { 0, -1, 1 };
        return &range;
    }
    
    case 12: {
        static const ParameterRange range = { 94, 1, 100 };
        return &range;
    }
    
    case 13: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    case 14: {
        static const ParameterRange range = { 134, 1, 400 };
        return &range;
    }
    
    case 15: {
        static const ParameterRange range = { 0.81099999, 0, 1 };
        return &range;
    }
    
    case 16: {
        static const ParameterRange range = { 0, -40, 40 };
        return &range;
    }
    
    case 17: {
        static const ParameterRange range = { 1, 0, 1 };
        return &range;
    }
    
    case 18: {
        static const ParameterRange range = { 1020, 6, 8000 };
        return &range;
    }
    
    case 19: {
        static const ParameterRange range = { 3813, 6, 8000 };
        return &range;
    }
    
    case 20: {
        static const ParameterRange range = { 20000, 0, 20000 };
        return &range;
    }
    
    case 21: {
        static const ParameterRange range = { 50, 0, 50 };
        return &range;
    }
    
    case 22: {
        static const ParameterRange range = { 0, -60, 0 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool CharacterCompressor::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool CharacterCompressor::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool CharacterCompressor::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool CharacterCompressor::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

float CharacterCompressor::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider13;
    
    case 1:
        return dsp.fHslider3;
    
    case 2:
        return dsp.fHslider12;
    
    case 3:
        return dsp.fHslider11;
    
    case 4:
        return dsp.fHslider1;
    
    case 5:
        return dsp.fHslider8;
    
    case 6:
        return dsp.fHslider7;
    
    case 7:
        return dsp.fHslider14;
    
    case 8:
        return dsp.fHslider9;
    
    case 9:
        return dsp.fHslider15;
    
    case 10:
        return dsp.fHslider5;
    
    case 11:
        return dsp.fHslider16;
    
    case 12:
        return dsp.fHslider6;
    
    case 13:
        return dsp.fHslider10;
    
    case 14:
        return dsp.fHslider0;
    
    case 15:
        return dsp.fHslider2;
    
    case 16:
        return dsp.fHslider21;
    
    case 17:
        return dsp.fHslider4;
    
    case 18:
        return dsp.fHslider18;
    
    case 19:
        return dsp.fHslider17;
    
    case 20:
        return dsp.fHslider19;
    
    case 21:
        return dsp.fHslider20;
    
    case 22:
        return dsp.fVbargraph0;
    
    default:
        (void)dsp;
        return 0;
    }
}

void CharacterCompressor::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider13 = value;
        break;
    
    case 1:
        dsp.fHslider3 = value;
        break;
    
    case 2:
        dsp.fHslider12 = value;
        break;
    
    case 3:
        dsp.fHslider11 = value;
        break;
    
    case 4:
        dsp.fHslider1 = value;
        break;
    
    case 5:
        dsp.fHslider8 = value;
        break;
    
    case 6:
        dsp.fHslider7 = value;
        break;
    
    case 7:
        dsp.fHslider14 = value;
        break;
    
    case 8:
        dsp.fHslider9 = value;
        break;
    
    case 9:
        dsp.fHslider15 = value;
        break;
    
    case 10:
        dsp.fHslider5 = value;
        break;
    
    case 11:
        dsp.fHslider16 = value;
        break;
    
    case 12:
        dsp.fHslider6 = value;
        break;
    
    case 13:
        dsp.fHslider10 = value;
        break;
    
    case 14:
        dsp.fHslider0 = value;
        break;
    
    case 15:
        dsp.fHslider2 = value;
        break;
    
    case 16:
        dsp.fHslider21 = value;
        break;
    
    case 17:
        dsp.fHslider4 = value;
        break;
    
    case 18:
        dsp.fHslider18 = value;
        break;
    
    case 19:
        dsp.fHslider17 = value;
        break;
    
    case 20:
        dsp.fHslider19 = value;
        break;
    
    case 21:
        dsp.fHslider20 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float CharacterCompressor::get_Threshold() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider13;
}

float CharacterCompressor::get_strength() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float CharacterCompressor::get_Attack() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider12;
}

float CharacterCompressor::get_Release() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider11;
}

float CharacterCompressor::get_Input_Gain() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float CharacterCompressor::get_peak_RMS() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider8;
}

float CharacterCompressor::get_detector_Ratio() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider7;
}

float CharacterCompressor::get_Release2() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider14;
}

float CharacterCompressor::get_sidechain_hpf() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider9;
}

float CharacterCompressor::get_power() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider15;
}

float CharacterCompressor::get_Max_Gain_Reduction() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider5;
}

float CharacterCompressor::get_curve() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider16;
}

float CharacterCompressor::get_shape() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider6;
}

float CharacterCompressor::get_feedback_feedforward() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider10;
}

float CharacterCompressor::get_hi_shelf_freq() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float CharacterCompressor::get_gain_hi_shelve_crossfade() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float CharacterCompressor::get_output_gain__dB_() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider21;
}

float CharacterCompressor::get_ratelimit_amount() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}

float CharacterCompressor::get_max_attack() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider18;
}

float CharacterCompressor::get_max_decay() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider17;
}

float CharacterCompressor::get_decayMult() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider19;
}

float CharacterCompressor::get_decayPower() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider20;
}

float CharacterCompressor::get_gainReduction() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fVbargraph0;
}


void CharacterCompressor::set_Threshold(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider13 = value;
}

void CharacterCompressor::set_strength(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void CharacterCompressor::set_Attack(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider12 = value;
}

void CharacterCompressor::set_Release(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider11 = value;
}

void CharacterCompressor::set_Input_Gain(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void CharacterCompressor::set_peak_RMS(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider8 = value;
}

void CharacterCompressor::set_detector_Ratio(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider7 = value;
}

void CharacterCompressor::set_Release2(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider14 = value;
}

void CharacterCompressor::set_sidechain_hpf(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider9 = value;
}

void CharacterCompressor::set_power(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider15 = value;
}

void CharacterCompressor::set_Max_Gain_Reduction(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider5 = value;
}

void CharacterCompressor::set_curve(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider16 = value;
}

void CharacterCompressor::set_shape(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider6 = value;
}

void CharacterCompressor::set_feedback_feedforward(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider10 = value;
}

void CharacterCompressor::set_hi_shelf_freq(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}

void CharacterCompressor::set_gain_hi_shelve_crossfade(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void CharacterCompressor::set_output_gain__dB_(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider21 = value;
}

void CharacterCompressor::set_ratelimit_amount(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void CharacterCompressor::set_max_attack(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider18 = value;
}

void CharacterCompressor::set_max_decay(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider17 = value;
}

void CharacterCompressor::set_decayMult(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider19 = value;
}

void CharacterCompressor::set_decayPower(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider20 = value;
}




