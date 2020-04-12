
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







#include "PunchDSP.hpp"



#include <utility>
#include <cmath>

class PunchDSP::BasicDsp {
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

typedef PunchDSP::BasicDsp dsp;

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
	
	FAUSTFLOAT fCheckbox0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fVec0[2];
	float fRec1[2];
	float fRec0[3];
	float fRec3[2];
	float fRec2[3];
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fVec1[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	float fConst2;
	FAUSTFLOAT fHslider10;
	float fConst3;
	FAUSTFLOAT fHslider11;
	float fVec2[3];
	float fRec15[3];
	float fConst4;
	FAUSTFLOAT fHslider12;
	float fConst5;
	float fVec3[2];
	float fConst6;
	float fVec4[3];
	float fConst7;
	float fVec5[7];
	float fConst8;
	float fVec6[15];
	float fConst9;
	int IOTA;
	float fVec7[32];
	float fConst10;
	float fVec8[64];
	float fConst11;
	float fVec9[128];
	float fConst12;
	float fVec10[256];
	float fConst13;
	float fVec11[512];
	float fConst14;
	float fVec12[1024];
	float fConst15;
	float fVec13[2048];
	float fConst16;
	float fVec14[4096];
	float fConst17;
	float fVec15[8192];
	float fConst18;
	float fVec16[16384];
	float fConst19;
	float fVec17[32768];
	float fConst20;
	FAUSTFLOAT fHslider13;
	float fConst21;
	FAUSTFLOAT fHslider14;
	float fRec14[2];
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	float fRec13[2];
	float fConst22;
	float fConst23;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	float fConst24;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	float fVec18[3];
	float fConst25;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	float fVec19[2];
	float fVec20[3];
	float fVec21[7];
	float fVec22[15];
	float fVec23[32];
	float fVec24[64];
	float fVec25[128];
	float fVec26[256];
	float fVec27[512];
	float fVec28[1024];
	float fVec29[2048];
	float fVec30[4096];
	float fVec31[8192];
	float fVec32[16384];
	float fVec33[32768];
	FAUSTFLOAT fHslider23;
	FAUSTFLOAT fVbargraph0;
	float fRec16[2];
	float fVec34[2];
	float fRec12[2];
	float fRec11[3];
	float fRec18[2];
	float fRec17[3];
	float fRec9[2];
	FAUSTFLOAT fHslider24;
	float fRec8[2];
	float fRec7[2];
	FAUSTFLOAT fVbargraph1;
	float fVec35[2];
	float fRec5[2];
	float fRec4[3];
	float fRec20[2];
	float fRec19[3];
	FAUSTFLOAT fHslider25;
	float fRec21[2];
	float fRec23[2];
	float fRec22[3];
	float fRec25[2];
	float fRec24[3];
	float fVec36[2];
	float fRec27[2];
	float fRec26[3];
	float fRec29[2];
	float fRec28[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.0");
		m->declare("author", "Bart Brouns");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("copyright", "(C) 2014 Bart Brouns");
		m->declare("filename", "CharacterCompressor.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/highshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("lib/CharacterCompressor.lib/author", "Bart Brouns");
		m->declare("lib/CharacterCompressor.lib/copyright", "(C) 2020 Bart Brouns");
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
		m->declare("maths.lib/version", "2.2");
		m->declare("name", "CharacterCompressor");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.1");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.1");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("version", "0.3.3");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 3;
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
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
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
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
	
	static void classInit(int sample_rate) {
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (6.28318548f / fConst0);
		fConst3 = (6.53275824f / fConst0);
		fConst4 = (2.26757365e-05f * fConst0);
		fConst5 = (44100.0f / fConst0);
		fConst6 = (22050.0f / fConst0);
		fConst7 = (11025.0f / fConst0);
		fConst8 = (5512.5f / fConst0);
		fConst9 = (2756.25f / fConst0);
		fConst10 = (1378.125f / fConst0);
		fConst11 = (689.0625f / fConst0);
		fConst12 = (344.53125f / fConst0);
		fConst13 = (172.265625f / fConst0);
		fConst14 = (86.1328125f / fConst0);
		fConst15 = (43.0664062f / fConst0);
		fConst16 = (21.5332031f / fConst0);
		fConst17 = (10.7666016f / fConst0);
		fConst18 = (5.38330078f / fConst0);
		fConst19 = (2.69165039f / fConst0);
		fConst20 = (339.785217f / fConst0);
		fConst21 = (1812.18787f / fConst0);
		fConst22 = std::log(float(LDBL_MIN));
		fConst23 = std::log(float(LDBL_MAX));
		fConst24 = (1.0f / fConst0);
		fConst25 = (2.26757365e-07f * fConst0);
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(134.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.81100000000000005f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fHslider5 = FAUSTFLOAT(1.0f);
		fHslider6 = FAUSTFLOAT(-15.0f);
		fHslider7 = FAUSTFLOAT(94.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(1.0f);
		fHslider9 = FAUSTFLOAT(1.0f);
		fHslider10 = FAUSTFLOAT(154.0f);
		fHslider11 = FAUSTFLOAT(0.0f);
		fHslider12 = FAUSTFLOAT(96.0f);
		fHslider13 = FAUSTFLOAT(23.699999999999999f);
		fHslider14 = FAUSTFLOAT(0.10000000000000001f);
		fHslider15 = FAUSTFLOAT(-27.100000000000001f);
		fHslider16 = FAUSTFLOAT(0.0f);
		fHslider17 = FAUSTFLOAT(1.8799999999999999f);
		fHslider18 = FAUSTFLOAT(0.0f);
		fHslider19 = FAUSTFLOAT(3813.0f);
		fHslider20 = FAUSTFLOAT(1020.0f);
		fHslider21 = FAUSTFLOAT(20000.0f);
		fHslider22 = FAUSTFLOAT(108.0f);
		fHslider23 = FAUSTFLOAT(50.0f);
		fHslider24 = FAUSTFLOAT(16.0f);
		fHslider25 = FAUSTFLOAT(0.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec1[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec15[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec3[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fVec4[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 7); l11 = (l11 + 1)) {
			fVec5[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 15); l12 = (l12 + 1)) {
			fVec6[l12] = 0.0f;
		}
		IOTA = 0;
		for (int l13 = 0; (l13 < 32); l13 = (l13 + 1)) {
			fVec7[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 64); l14 = (l14 + 1)) {
			fVec8[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 128); l15 = (l15 + 1)) {
			fVec9[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 256); l16 = (l16 + 1)) {
			fVec10[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 512); l17 = (l17 + 1)) {
			fVec11[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 1024); l18 = (l18 + 1)) {
			fVec12[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2048); l19 = (l19 + 1)) {
			fVec13[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 4096); l20 = (l20 + 1)) {
			fVec14[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 8192); l21 = (l21 + 1)) {
			fVec15[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 16384); l22 = (l22 + 1)) {
			fVec16[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 32768); l23 = (l23 + 1)) {
			fVec17[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec14[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec13[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fVec18[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fVec19[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fVec20[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 7); l29 = (l29 + 1)) {
			fVec21[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 15); l30 = (l30 + 1)) {
			fVec22[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 32); l31 = (l31 + 1)) {
			fVec23[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 64); l32 = (l32 + 1)) {
			fVec24[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 128); l33 = (l33 + 1)) {
			fVec25[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 256); l34 = (l34 + 1)) {
			fVec26[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 512); l35 = (l35 + 1)) {
			fVec27[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 1024); l36 = (l36 + 1)) {
			fVec28[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2048); l37 = (l37 + 1)) {
			fVec29[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 4096); l38 = (l38 + 1)) {
			fVec30[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 8192); l39 = (l39 + 1)) {
			fVec31[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 16384); l40 = (l40 + 1)) {
			fVec32[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 32768); l41 = (l41 + 1)) {
			fVec33[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec16[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fVec34[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec12[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec11[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec18[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec17[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec9[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec8[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec7[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fVec35[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec5[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec4[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec20[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec19[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec21[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec23[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec22[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec25[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec24[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fVec36[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec27[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 3); l63 = (l63 + 1)) {
			fRec26[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec29[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 3); l65 = (l65 + 1)) {
			fRec28[l65] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("CharacterCompressor");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("easy");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "tooltip", "The input signal level is increased by this amount (in dB) to make up for the level lost due to compression");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("Input Gain", &fHslider2, 0.0f, -40.0f, 40.0f, 0.100000001f);
		ui_interface->declare(&fHslider15, "1", "");
		ui_interface->declare(&fHslider15, "tooltip", "When the signal level exceeds the Threshold (in dB), its level is compressed according to the Ratio");
		ui_interface->declare(&fHslider15, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider15, -27.1000004f, -80.0f, 0.0f, 0.100000001f);
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->declare(&fHslider4, "tooltip", "");
		ui_interface->addHorizontalSlider("strength", &fHslider4, 1.0f, 0.0f, 8.0f, 0.100000001f);
		ui_interface->declare(&fHslider13, "3", "");
		ui_interface->declare(&fHslider13, "scale", "log");
		ui_interface->declare(&fHslider13, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new lower target level (the compression `kicking in')");
		ui_interface->declare(&fHslider13, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider13, 23.7000008f, 0.00100000005f, 500.0f, 0.100000001f);
		ui_interface->declare(&fHslider24, "4", "");
		ui_interface->declare(&fHslider24, "scale", "log");
		ui_interface->declare(&fHslider24, "tooltip", "time constant (ms) coming out of compression");
		ui_interface->declare(&fHslider24, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider24, 16.0f, 0.0f, 1000.0f, 0.100000001f);
		ui_interface->declare(&fHslider16, "5", "");
		ui_interface->declare(&fHslider16, "tooltip", "soft knee amount in dB");
		ui_interface->declare(&fHslider16, "unit", "dB");
		ui_interface->addHorizontalSlider("Knee", &fHslider16, 0.0f, 0.0f, 30.0f, 0.100000001f);
		ui_interface->declare(&fHslider25, "5", "");
		ui_interface->declare(&fHslider25, "tooltip", "");
		ui_interface->addHorizontalSlider("output gain (dB)", &fHslider25, 0.0f, -40.0f, 40.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("advanced");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("detector");
		ui_interface->declare(&fHslider9, "2", "");
		ui_interface->addHorizontalSlider("peak/RMS", &fHslider9, 1.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->declare(&fHslider8, "2", "");
		ui_interface->declare(&fHslider8, "tooltip", "");
		ui_interface->addHorizontalSlider("det strength", &fHslider8, 1.0f, 0.0f, 8.0f, 0.100000001f);
		ui_interface->declare(&fHslider12, "3", "");
		ui_interface->declare(&fHslider12, "scale", "log");
		ui_interface->declare(&fHslider12, "tooltip", "");
		ui_interface->addHorizontalSlider("RMS size", &fHslider12, 96.0f, 2.0f, 16384.0f, 1.0f);
		ui_interface->declare(&fHslider14, "7", "");
		ui_interface->declare(&fHslider14, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new higher target level (the compression 'releasing')");
		ui_interface->declare(&fHslider14, "unit", "ms");
		ui_interface->addHorizontalSlider("Detector Release", &fHslider14, 0.100000001f, 0.100000001f, 2000.0f, 0.100000001f);
		ui_interface->declare(&fHslider10, "8", "");
		ui_interface->declare(&fHslider10, "scale", "log");
		ui_interface->declare(&fHslider10, "tooltip", "");
		ui_interface->addHorizontalSlider("sidechain hpf", &fHslider10, 154.0f, 1.0f, 400.0f, 1.0f);
		ui_interface->declare(&fCheckbox1, "9", "");
		ui_interface->declare(&fCheckbox1, "tooltip", "Unchecked: log  domain return-to-threshold detector       Checked: linear return-to-fi.zero detector");
		ui_interface->addCheckButton("slow/fast", &fCheckbox1);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("shape");
		ui_interface->declare(&fHslider17, "1", "");
		ui_interface->declare(&fHslider17, "tooltip", "");
		ui_interface->addHorizontalSlider("power", &fHslider17, 1.88f, -33.0f, 33.0f, 0.00999999978f);
		ui_interface->declare(&fHslider6, "2", "");
		ui_interface->declare(&fHslider6, "tooltip", "The maximum amount of gain reduction");
		ui_interface->declare(&fHslider6, "unit", "dB");
		ui_interface->addHorizontalSlider("Max Gain Reduction", &fHslider6, -15.0f, -60.0f, 0.0f, 0.100000001f);
		ui_interface->declare(&fHslider18, "4", "");
		ui_interface->declare(&fHslider18, "tooltip", "");
		ui_interface->addHorizontalSlider("curve", &fHslider18, 0.0f, -1.0f, 1.0f, 0.00999999978f);
		ui_interface->declare(&fHslider7, "5", "");
		ui_interface->declare(&fHslider7, "tooltip", "");
		ui_interface->addHorizontalSlider("shape", &fHslider7, 94.0f, 1.0f, 100.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(&fHslider11, "0", "");
		ui_interface->declare(&fHslider11, "tooltip", "");
		ui_interface->addHorizontalSlider("feedback/feedforward", &fHslider11, 0.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "tooltip", "");
		ui_interface->addHorizontalSlider("hi shelf freq", &fHslider0, 134.0f, 1.0f, 400.0f, 1.0f);
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "tooltip", "");
		ui_interface->addHorizontalSlider("gain/hi-shelve crossfade", &fHslider3, 0.81099999f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->addHorizontalSlider("dry/wet", &fHslider1, 1.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("ratelimit");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(&fHslider5, "0", "");
		ui_interface->declare(&fHslider5, "tooltip", "");
		ui_interface->addHorizontalSlider("ratelimit amount", &fHslider5, 1.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider20, "1", "");
		ui_interface->declare(&fHslider20, "tooltip", "");
		ui_interface->declare(&fHslider20, "unit", "dB/s");
		ui_interface->addHorizontalSlider("max attack", &fHslider20, 1020.0f, 6.0f, 8000.0f, 1.0f);
		ui_interface->declare(&fHslider19, "2", "");
		ui_interface->declare(&fHslider19, "tooltip", "");
		ui_interface->declare(&fHslider19, "unit", "dB/s");
		ui_interface->addHorizontalSlider("max decay", &fHslider19, 3813.0f, 6.0f, 8000.0f, 1.0f);
		ui_interface->declare(&fHslider21, "3", "");
		ui_interface->declare(&fHslider21, "tooltip", "");
		ui_interface->addHorizontalSlider("decayMult", &fHslider21, 20000.0f, 0.0f, 200000.0f, 100.0f);
		ui_interface->declare(&fHslider23, "4", "");
		ui_interface->declare(&fHslider23, "tooltip", "");
		ui_interface->addHorizontalSlider("decayPower", &fHslider23, 50.0f, 0.0f, 50.0f, 0.100000001f);
		ui_interface->declare(&fHslider22, "5", "");
		ui_interface->declare(&fHslider22, "scale", "log");
		ui_interface->declare(&fHslider22, "tooltip", "");
		ui_interface->addHorizontalSlider("IM_size", &fHslider22, 108.0f, 1.0f, 16384.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(&fVbargraph0, "1", "");
		ui_interface->declare(&fVbargraph0, "tooltip", "the amount of release slowdown due to auto-release");
		ui_interface->declare(&fVbargraph0, "unit", "dB");
		ui_interface->addVerticalBargraph("auto-release", &fVbargraph0, -90.0f, 0.0f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fVbargraph1, "1", "");
		ui_interface->declare(&fVbargraph1, "tooltip", "gain reduction in dB");
		ui_interface->declare(&fVbargraph1, "unit", "dB");
		ui_interface->addVerticalBargraph("GR", &fVbargraph1, -60.0f, 0.0f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->addCheckButton("bypass", &fCheckbox0);
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		float fSlow0 = float(fCheckbox0);
		float fSlow1 = (1.0f - fSlow0);
		float fSlow2 = std::tan((fConst1 * float(fHslider0)));
		float fSlow3 = (1.0f / fSlow2);
		float fSlow4 = (((fSlow3 + 1.0f) / fSlow2) + 1.0f);
		float fSlow5 = (fSlow1 / fSlow4);
		float fSlow6 = float(fHslider1);
		float fSlow7 = (1.0f - fSlow6);
		float fSlow8 = mydsp_faustpower2_f(fSlow2);
		float fSlow9 = (1.0f / fSlow8);
		float fSlow10 = (fSlow3 + 1.0f);
		float fSlow11 = (0.0f - (1.0f / (fSlow2 * fSlow10)));
		float fSlow12 = (1.0f / fSlow10);
		float fSlow13 = (1.0f - fSlow3);
		float fSlow14 = (1.0f / fSlow4);
		float fSlow15 = (((fSlow3 + -1.0f) / fSlow2) + 1.0f);
		float fSlow16 = (2.0f * (1.0f - fSlow9));
		float fSlow17 = (0.0f - (2.0f / fSlow8));
		float fSlow18 = (0.00100000005f * float(fHslider2));
		float fSlow19 = float(fHslider3);
		float fSlow20 = (0.0500000007f * (1.0f - fSlow19));
		float fSlow21 = float(fHslider4);
		float fSlow22 = (fSlow21 * fSlow1);
		float fSlow23 = float(fHslider5);
		float fSlow24 = (20.0f * (1.0f - fSlow23));
		float fSlow25 = std::pow(10.0f, (0.0500000007f * std::min<float>(-0.00100000005f, float(fHslider6))));
		float fSlow26 = (1.0f - fSlow25);
		float fSlow27 = mydsp_faustpower2_f((101.0f - float(fHslider7)));
		float fSlow28 = (1.0f / fSlow26);
		float fSlow29 = float(fCheckbox1);
		int iSlow30 = int(fSlow29);
		float fSlow31 = float(fHslider8);
		int iSlow32 = int((1.0f - fSlow29));
		float fSlow33 = float(fHslider9);
		float fSlow34 = (1.0f - fSlow33);
		float fSlow35 = float(fHslider10);
		float fSlow36 = (fConst2 * fSlow35);
		float fSlow37 = std::sin(fSlow36);
		float fSlow38 = (fSlow37 * float(sinhf(float((fConst3 * (fSlow35 / fSlow37))))));
		float fSlow39 = (1.0f / (fSlow38 + 1.0f));
		float fSlow40 = std::cos(fSlow36);
		float fSlow41 = (-1.0f - fSlow40);
		float fSlow42 = float(fHslider11);
		float fSlow43 = (1.0f - fSlow42);
		float fSlow44 = (0.5f * (fSlow40 + 1.0f));
		float fSlow45 = (2.0f * fSlow40);
		float fSlow46 = (fSlow38 + -1.0f);
		float fSlow47 = float(fHslider12);
		float fSlow48 = (fConst4 / fSlow47);
		float fSlow49 = (fConst5 * fSlow47);
		int iSlow50 = (1 & (fSlow49 == 0.0f));
		int iSlow51 = (int(std::floor(fSlow49)) % 2);
		int iSlow52 = (int(std::floor((fConst6 * fSlow47))) % 2);
		int iSlow53 = (int(std::floor((fConst7 * fSlow47))) % 2);
		int iSlow54 = (iSlow51 + (2 * iSlow52));
		int iSlow55 = (int(std::floor((fConst8 * fSlow47))) % 2);
		int iSlow56 = (iSlow54 + (4 * iSlow53));
		int iSlow57 = (int(std::floor((fConst9 * fSlow47))) % 2);
		int iSlow58 = (iSlow56 + (8 * iSlow55));
		int iSlow59 = (int(std::floor((fConst10 * fSlow47))) % 2);
		int iSlow60 = (iSlow58 + (16 * iSlow57));
		int iSlow61 = (int(std::floor((fConst11 * fSlow47))) % 2);
		int iSlow62 = (iSlow60 + (32 * iSlow59));
		int iSlow63 = (int(std::floor((fConst12 * fSlow47))) % 2);
		int iSlow64 = (iSlow62 + (64 * iSlow61));
		int iSlow65 = (int(std::floor((fConst13 * fSlow47))) % 2);
		int iSlow66 = (iSlow64 + (128 * iSlow63));
		int iSlow67 = (int(std::floor((fConst14 * fSlow47))) % 2);
		int iSlow68 = (iSlow66 + (256 * iSlow65));
		int iSlow69 = (int(std::floor((fConst15 * fSlow47))) % 2);
		int iSlow70 = (iSlow68 + (512 * iSlow67));
		int iSlow71 = (int(std::floor((fConst16 * fSlow47))) % 2);
		int iSlow72 = (iSlow70 + (1024 * iSlow69));
		int iSlow73 = (int(std::floor((fConst17 * fSlow47))) % 2);
		int iSlow74 = (iSlow72 + (2048 * iSlow71));
		int iSlow75 = (int(std::floor((fConst18 * fSlow47))) % 2);
		int iSlow76 = (iSlow74 + (4096 * iSlow73));
		int iSlow77 = (int(std::floor((fConst19 * fSlow47))) % 2);
		int iSlow78 = (iSlow76 + (8192 * iSlow75));
		float fSlow79 = (fConst20 / float(fHslider13));
		float fSlow80 = (fConst21 / float(fHslider14));
		float fSlow81 = float(fHslider15);
		float fSlow82 = float(fHslider16);
		float fSlow83 = (0.5f * fSlow82);
		float fSlow84 = (fSlow81 - fSlow83);
		float fSlow85 = (fSlow81 + fSlow83);
		float fSlow86 = (0.5f / fSlow82);
		float fSlow87 = float(fHslider17);
		float fSlow88 = ((float((fSlow87 >= 0.0f)) / mydsp_faustpower3_f((fSlow87 + 1.0f))) + (float((fSlow87 < 0.0f)) * mydsp_faustpower3_f((1.0f - fSlow87))));
		float fSlow89 = std::exp((6.93147182f * (0.0f - float(fHslider18))));
		float fSlow90 = (fConst24 * float(fHslider19));
		float fSlow91 = (0.0f - (fConst24 * float(fHslider20)));
		float fSlow92 = float(fHslider22);
		float fSlow93 = (fConst25 * (float(fHslider21) / fSlow92));
		float fSlow94 = (fConst5 * fSlow92);
		int iSlow95 = (1 & (fSlow94 == 0.0f));
		int iSlow96 = (int(std::floor(fSlow94)) % 2);
		int iSlow97 = (int(std::floor((fConst6 * fSlow92))) % 2);
		int iSlow98 = (int(std::floor((fConst7 * fSlow92))) % 2);
		int iSlow99 = (iSlow96 + (2 * iSlow97));
		int iSlow100 = (int(std::floor((fConst8 * fSlow92))) % 2);
		int iSlow101 = (iSlow99 + (4 * iSlow98));
		int iSlow102 = (int(std::floor((fConst9 * fSlow92))) % 2);
		int iSlow103 = (iSlow101 + (8 * iSlow100));
		int iSlow104 = (int(std::floor((fConst10 * fSlow92))) % 2);
		int iSlow105 = (iSlow103 + (16 * iSlow102));
		int iSlow106 = (int(std::floor((fConst11 * fSlow92))) % 2);
		int iSlow107 = (iSlow105 + (32 * iSlow104));
		int iSlow108 = (int(std::floor((fConst12 * fSlow92))) % 2);
		int iSlow109 = (iSlow107 + (64 * iSlow106));
		int iSlow110 = (int(std::floor((fConst13 * fSlow92))) % 2);
		int iSlow111 = (iSlow109 + (128 * iSlow108));
		int iSlow112 = (int(std::floor((fConst14 * fSlow92))) % 2);
		int iSlow113 = (iSlow111 + (256 * iSlow110));
		int iSlow114 = (int(std::floor((fConst15 * fSlow92))) % 2);
		int iSlow115 = (iSlow113 + (512 * iSlow112));
		int iSlow116 = (int(std::floor((fConst16 * fSlow92))) % 2);
		int iSlow117 = (iSlow115 + (1024 * iSlow114));
		int iSlow118 = (int(std::floor((fConst17 * fSlow92))) % 2);
		int iSlow119 = (iSlow117 + (2048 * iSlow116));
		int iSlow120 = (int(std::floor((fConst18 * fSlow92))) % 2);
		int iSlow121 = (iSlow119 + (4096 * iSlow118));
		int iSlow122 = (int(std::floor((fConst19 * fSlow92))) % 2);
		int iSlow123 = (iSlow121 + (8192 * iSlow120));
		float fSlow124 = float(fHslider23);
		float fSlow125 = (0.0500000007f * fSlow19);
		float fSlow126 = (0.00100000005f * float(fHslider24));
		int iSlow127 = (std::fabs(fSlow126) < 1.1920929e-07f);
		float fSlow128 = (iSlow127 ? 0.0f : std::exp((0.0f - (fConst24 / (iSlow127 ? 1.0f : fSlow126)))));
		float fSlow129 = (0.00100000005f * float(fHslider25));
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = float(input0[i]);
			fVec0[0] = fTemp0;
			fRec1[0] = ((fSlow11 * fVec0[1]) - (fSlow12 * ((fSlow13 * fRec1[1]) - (fSlow3 * fTemp0))));
			fRec0[0] = (fRec1[0] - (fSlow14 * ((fSlow15 * fRec0[2]) + (fSlow16 * fRec0[1]))));
			fRec3[0] = (0.0f - (fSlow12 * ((fSlow13 * fRec3[1]) - (fTemp0 + fVec0[1]))));
			fRec2[0] = (fRec3[0] - (fSlow14 * ((fSlow15 * fRec2[2]) + (fSlow16 * fRec2[1]))));
			fRec6[0] = (fSlow18 + (0.999000013f * fRec6[1]));
			float fTemp1 = std::pow(10.0f, (0.0500000007f * fRec6[0]));
			float fTemp2 = float(input1[i]);
			fVec1[0] = fTemp2;
			float fTemp3 = (fTemp0 + fTemp2);
			float fTemp4 = ((fSlow43 * fRec9[1]) + (fSlow42 * (fTemp3 * fTemp1)));
			fVec2[0] = fTemp4;
			fRec15[0] = (fSlow39 * (((((fSlow41 * fVec2[1]) + (fSlow44 * fTemp4)) + (fSlow44 * fVec2[2])) + (fSlow45 * fRec15[1])) + (fSlow46 * fRec15[2])));
			float fTemp5 = mydsp_faustpower2_f(fRec15[0]);
			fVec3[0] = fTemp5;
			float fTemp6 = (fTemp5 + fVec3[1]);
			fVec4[0] = fTemp6;
			float fTemp7 = (fTemp6 + fVec4[2]);
			fVec5[0] = fTemp7;
			float fTemp8 = (fTemp7 + fVec5[4]);
			fVec6[0] = fTemp8;
			float fTemp9 = (fTemp8 + fVec6[8]);
			fVec7[(IOTA & 31)] = fTemp9;
			float fTemp10 = (fTemp9 + fVec7[((IOTA - 16) & 31)]);
			fVec8[(IOTA & 63)] = fTemp10;
			float fTemp11 = (fTemp10 + fVec8[((IOTA - 32) & 63)]);
			fVec9[(IOTA & 127)] = fTemp11;
			float fTemp12 = (fTemp11 + fVec9[((IOTA - 64) & 127)]);
			fVec10[(IOTA & 255)] = fTemp12;
			float fTemp13 = (fTemp12 + fVec10[((IOTA - 128) & 255)]);
			fVec11[(IOTA & 511)] = fTemp13;
			float fTemp14 = (fTemp13 + fVec11[((IOTA - 256) & 511)]);
			fVec12[(IOTA & 1023)] = fTemp14;
			float fTemp15 = (fTemp14 + fVec12[((IOTA - 512) & 1023)]);
			fVec13[(IOTA & 2047)] = fTemp15;
			float fTemp16 = (fTemp15 + fVec13[((IOTA - 1024) & 2047)]);
			fVec14[(IOTA & 4095)] = fTemp16;
			float fTemp17 = (fTemp16 + fVec14[((IOTA - 2048) & 4095)]);
			fVec15[(IOTA & 8191)] = fTemp17;
			float fTemp18 = (fTemp17 + fVec15[((IOTA - 4096) & 8191)]);
			fVec16[(IOTA & 16383)] = fTemp18;
			fVec17[(IOTA & 32767)] = (fTemp18 + fVec16[((IOTA - 8192) & 16383)]);
			float fTemp19 = std::fabs(((fSlow34 * std::fabs(fRec15[0])) + (fSlow33 * std::sqrt((fSlow48 * (((((((((((((((iSlow50 ? fTemp5 : (iSlow51 ? fTemp5 : 0.0f)) + (iSlow52 ? fVec4[iSlow51] : 0.0f)) + (iSlow53 ? fVec5[iSlow54] : 0.0f)) + (iSlow55 ? fVec6[iSlow56] : 0.0f)) + (iSlow57 ? fVec7[((IOTA - iSlow58) & 31)] : 0.0f)) + (iSlow59 ? fVec8[((IOTA - iSlow60) & 63)] : 0.0f)) + (iSlow61 ? fVec9[((IOTA - iSlow62) & 127)] : 0.0f)) + (iSlow63 ? fVec10[((IOTA - iSlow64) & 255)] : 0.0f)) + (iSlow65 ? fVec11[((IOTA - iSlow66) & 511)] : 0.0f)) + (iSlow67 ? fVec12[((IOTA - iSlow68) & 1023)] : 0.0f)) + (iSlow69 ? fVec13[((IOTA - iSlow70) & 2047)] : 0.0f)) + (iSlow71 ? fVec14[((IOTA - iSlow72) & 4095)] : 0.0f)) + (iSlow73 ? fVec15[((IOTA - iSlow74) & 8191)] : 0.0f)) + (iSlow75 ? fVec16[((IOTA - iSlow76) & 16383)] : 0.0f)) + (iSlow77 ? fVec17[((IOTA - iSlow78) & 32767)] : 0.0f)))))));
			float fTemp20 = (iSlow32 ? 0.0f : fTemp19);
			float fTemp21 = ((fTemp20 < fRec14[1]) ? fSlow80 : fSlow79);
			fRec14[0] = ((fTemp20 * fTemp21) + (fRec14[1] * (1.0f - fTemp21)));
			float fTemp22 = (20.0f * std::log10((iSlow32 ? fTemp19 : fRec14[0])));
			int iTemp23 = ((fTemp22 > fSlow84) + (fTemp22 > fSlow85));
			float fTemp24 = (fTemp22 - fSlow81);
			float fTemp25 = (0.0f - (fSlow31 * std::max<float>(0.0f, ((iTemp23 == 0) ? 0.0f : ((iTemp23 == 1) ? (fSlow86 * mydsp_faustpower2_f((fSlow83 + fTemp24))) : fTemp24)))));
			float fTemp26 = (iSlow30 ? 0.0f : fTemp25);
			float fTemp27 = ((fTemp26 < fRec13[1]) ? fSlow79 : fSlow80);
			fRec13[0] = ((fTemp26 * fTemp27) + (fRec13[1] * (1.0f - fTemp27)));
			float fTemp28 = std::max<float>(float(LDBL_MIN), std::min<float>(1.0f, std::pow(10.0f, (0.0500000007f * (iSlow30 ? fTemp25 : fRec13[0])))));
			float fTemp29 = std::log(fTemp28);
			float fTemp30 = (std::pow(fTemp28, std::min<float>((fConst22 / fTemp29), std::max<float>((fConst23 / fTemp29), fSlow88))) - fSlow25);
			float fTemp31 = (fSlow28 * fTemp30);
			float fTemp32 = std::log10((fSlow25 + (fSlow26 * (float(tanhf(float((fSlow27 * (std::pow((fSlow28 * (fTemp30 * float((fTemp31 > 0.0f)))), fSlow89) + (-1.0f - std::pow(((0.0f - fTemp31) * float((fTemp31 <= 0.0f))), fSlow89))))))) + 1.0f))));
			float fTemp33 = ((20.0f * fTemp32) - fRec16[1]);
			fVec18[0] = fTemp33;
			float fTemp34 = std::fabs((fVec18[1] - fVec18[2]));
			fVec19[0] = fTemp34;
			float fTemp35 = (fTemp34 + fVec19[1]);
			fVec20[0] = fTemp35;
			float fTemp36 = (fTemp35 + fVec20[2]);
			fVec21[0] = fTemp36;
			float fTemp37 = (fTemp36 + fVec21[4]);
			fVec22[0] = fTemp37;
			float fTemp38 = (fTemp37 + fVec22[8]);
			fVec23[(IOTA & 31)] = fTemp38;
			float fTemp39 = (fTemp38 + fVec23[((IOTA - 16) & 31)]);
			fVec24[(IOTA & 63)] = fTemp39;
			float fTemp40 = (fTemp39 + fVec24[((IOTA - 32) & 63)]);
			fVec25[(IOTA & 127)] = fTemp40;
			float fTemp41 = (fTemp40 + fVec25[((IOTA - 64) & 127)]);
			fVec26[(IOTA & 255)] = fTemp41;
			float fTemp42 = (fTemp41 + fVec26[((IOTA - 128) & 255)]);
			fVec27[(IOTA & 511)] = fTemp42;
			float fTemp43 = (fTemp42 + fVec27[((IOTA - 256) & 511)]);
			fVec28[(IOTA & 1023)] = fTemp43;
			float fTemp44 = (fTemp43 + fVec28[((IOTA - 512) & 1023)]);
			fVec29[(IOTA & 2047)] = fTemp44;
			float fTemp45 = (fTemp44 + fVec29[((IOTA - 1024) & 2047)]);
			fVec30[(IOTA & 4095)] = fTemp45;
			float fTemp46 = (fTemp45 + fVec30[((IOTA - 2048) & 4095)]);
			fVec31[(IOTA & 8191)] = fTemp46;
			float fTemp47 = (fTemp46 + fVec31[((IOTA - 4096) & 8191)]);
			fVec32[(IOTA & 16383)] = fTemp47;
			fVec33[(IOTA & 32767)] = (fTemp47 + fVec32[((IOTA - 8192) & 16383)]);
			float fTemp48 = (0.0f - std::fabs((std::pow(((fSlow93 * (((((((((((((((iSlow95 ? fTemp34 : (iSlow96 ? fTemp34 : 0.0f)) + (iSlow97 ? fVec20[iSlow96] : 0.0f)) + (iSlow98 ? fVec21[iSlow99] : 0.0f)) + (iSlow100 ? fVec22[iSlow101] : 0.0f)) + (iSlow102 ? fVec23[((IOTA - iSlow103) & 31)] : 0.0f)) + (iSlow104 ? fVec24[((IOTA - iSlow105) & 63)] : 0.0f)) + (iSlow106 ? fVec25[((IOTA - iSlow107) & 127)] : 0.0f)) + (iSlow108 ? fVec26[((IOTA - iSlow109) & 255)] : 0.0f)) + (iSlow110 ? fVec27[((IOTA - iSlow111) & 511)] : 0.0f)) + (iSlow112 ? fVec28[((IOTA - iSlow113) & 1023)] : 0.0f)) + (iSlow114 ? fVec29[((IOTA - iSlow115) & 2047)] : 0.0f)) + (iSlow116 ? fVec30[((IOTA - iSlow117) & 4095)] : 0.0f)) + (iSlow118 ? fVec31[((IOTA - iSlow119) & 8191)] : 0.0f)) + (iSlow120 ? fVec32[((IOTA - iSlow121) & 16383)] : 0.0f)) + (iSlow122 ? fVec33[((IOTA - iSlow123) & 32767)] : 0.0f))) + 1.0f), fSlow124) + -1.0f)));
			fVbargraph0 = FAUSTFLOAT((fSlow1 * std::min<float>(1.0f, std::max<float>(-90.0f, fTemp48))));
			fRec16[0] = std::min<float>(0.0f, (fRec16[1] + std::min<float>(fSlow90, std::max<float>(fSlow91, ((fTemp33 > 0.0f) ? (fTemp33 * std::pow(10.0f, (0.0500000007f * fTemp48))) : fTemp33)))));
			float fTemp49 = ((fSlow24 * fTemp32) + (fSlow23 * fRec16[0]));
			float fTemp50 = (fTemp3 * std::pow(10.0f, (fSlow20 * fTemp49)));
			fVec34[0] = fTemp50;
			fRec12[0] = ((fSlow11 * fVec34[1]) - (fSlow12 * ((fSlow13 * fRec12[1]) - (fSlow3 * fTemp50))));
			fRec11[0] = (fRec12[0] - (fSlow14 * ((fSlow15 * fRec11[2]) + (fSlow16 * fRec11[1]))));
			fRec18[0] = (0.0f - (fSlow12 * ((fSlow13 * fRec18[1]) - (fTemp50 + fVec34[1]))));
			fRec17[0] = (fRec18[0] - (fSlow14 * ((fSlow15 * fRec17[2]) + (fSlow16 * fRec17[1]))));
			fRec9[0] = (fSlow14 * (((((fSlow9 * fRec11[0]) + (fSlow17 * fRec11[1])) + (fSlow9 * fRec11[2])) * std::pow(10.0f, (fSlow125 * fTemp49))) + (fRec17[2] + (fRec17[0] + (2.0f * fRec17[1])))));
			float fRec10 = fTemp49;
			float fTemp51 = ((fRec7[1] > fRec10) ? 0.0f : fSlow128);
			fRec8[0] = ((fRec8[1] * fTemp51) + (fRec10 * (1.0f - fTemp51)));
			fRec7[0] = fRec8[0];
			fVbargraph1 = FAUSTFLOAT((fSlow22 * fRec7[0]));
			float fTemp52 = (fSlow21 * fRec7[0]);
			float fTemp53 = std::pow(10.0f, (fSlow20 * fTemp52));
			float fTemp54 = ((fTemp0 * fTemp1) * fTemp53);
			fVec35[0] = fTemp54;
			fRec5[0] = ((fSlow11 * fVec35[1]) - (fSlow12 * ((fSlow13 * fRec5[1]) - (fSlow3 * fTemp54))));
			fRec4[0] = (fRec5[0] - (fSlow14 * ((fSlow15 * fRec4[2]) + (fSlow16 * fRec4[1]))));
			float fTemp55 = std::pow(10.0f, (fSlow125 * fTemp52));
			fRec20[0] = (0.0f - (fSlow12 * ((fSlow13 * fRec20[1]) - (fTemp54 + fVec35[1]))));
			fRec19[0] = (fRec20[0] - (fSlow14 * ((fSlow15 * fRec19[2]) + (fSlow16 * fRec19[1]))));
			fRec21[0] = (fSlow129 + (0.999000013f * fRec21[1]));
			float fTemp56 = std::pow(10.0f, (0.0500000007f * fRec21[0]));
			output0[i] = FAUSTFLOAT(((fSlow5 * (((fSlow7 * ((((fSlow9 * fRec0[0]) + (fSlow17 * fRec0[1])) + (fSlow9 * fRec0[2])) + (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))))) + (fSlow6 * (((((fSlow9 * fRec4[0]) + (fSlow17 * fRec4[1])) + (fSlow9 * fRec4[2])) * fTemp55) + (fRec19[2] + (fRec19[0] + (2.0f * fRec19[1])))))) * fTemp56)) + (fSlow0 * fTemp0)));
			fRec23[0] = ((fSlow11 * fVec1[1]) - (fSlow12 * ((fSlow13 * fRec23[1]) - (fSlow3 * fTemp2))));
			fRec22[0] = (fRec23[0] - (fSlow14 * ((fSlow15 * fRec22[2]) + (fSlow16 * fRec22[1]))));
			fRec25[0] = (0.0f - (fSlow12 * ((fSlow13 * fRec25[1]) - (fTemp2 + fVec1[1]))));
			fRec24[0] = (fRec25[0] - (fSlow14 * ((fSlow15 * fRec24[2]) + (fSlow16 * fRec24[1]))));
			float fTemp57 = ((fTemp2 * fTemp1) * fTemp53);
			fVec36[0] = fTemp57;
			fRec27[0] = ((fSlow11 * fVec36[1]) - (fSlow12 * ((fSlow13 * fRec27[1]) - (fSlow3 * fTemp57))));
			fRec26[0] = (fRec27[0] - (fSlow14 * ((fSlow15 * fRec26[2]) + (fSlow16 * fRec26[1]))));
			fRec29[0] = (0.0f - (fSlow12 * ((fSlow13 * fRec29[1]) - (fTemp57 + fVec36[1]))));
			fRec28[0] = (fRec29[0] - (fSlow14 * ((fSlow15 * fRec28[2]) + (fSlow16 * fRec28[1]))));
			output1[i] = FAUSTFLOAT(((fSlow5 * (fTemp56 * ((fSlow7 * ((((fSlow9 * fRec22[0]) + (fSlow17 * fRec22[1])) + (fSlow9 * fRec22[2])) + (fRec24[2] + (fRec24[0] + (2.0f * fRec24[1]))))) + (fSlow6 * ((fTemp55 * (((fSlow9 * fRec26[0]) + (fSlow17 * fRec26[1])) + (fSlow9 * fRec26[2]))) + (fRec28[2] + (fRec28[0] + (2.0f * fRec28[1])))))))) + (fSlow0 * fTemp2)));
			output2[i] = FAUSTFLOAT(fTemp52);
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec6[1] = fRec6[0];
			fVec1[1] = fVec1[0];
			fVec2[2] = fVec2[1];
			fVec2[1] = fVec2[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fVec3[1] = fVec3[0];
			fVec4[2] = fVec4[1];
			fVec4[1] = fVec4[0];
			for (int j0 = 6; (j0 > 0); j0 = (j0 - 1)) {
				fVec5[j0] = fVec5[(j0 - 1)];
			}
			for (int j1 = 14; (j1 > 0); j1 = (j1 - 1)) {
				fVec6[j1] = fVec6[(j1 - 1)];
			}
			IOTA = (IOTA + 1);
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fVec18[2] = fVec18[1];
			fVec18[1] = fVec18[0];
			fVec19[1] = fVec19[0];
			fVec20[2] = fVec20[1];
			fVec20[1] = fVec20[0];
			for (int j2 = 6; (j2 > 0); j2 = (j2 - 1)) {
				fVec21[j2] = fVec21[(j2 - 1)];
			}
			for (int j3 = 14; (j3 > 0); j3 = (j3 - 1)) {
				fVec22[j3] = fVec22[(j3 - 1)];
			}
			fRec16[1] = fRec16[0];
			fVec34[1] = fVec34[0];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fVec35[1] = fVec35[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fVec36[1] = fVec36[0];
			fRec27[1] = fRec27[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




PunchDSP::PunchDSP()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

PunchDSP::~PunchDSP()
{
}

void PunchDSP::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void PunchDSP::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void PunchDSP::process(
    const float *in0,const float *in1,
    float *out0,float *out1,float *out2,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),const_cast<float *>(in1),
    };
    float *outputs[] = {
        out0,out1,out2,
    };
    dsp.compute(count, inputs, outputs);

}

const char *PunchDSP::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Input Gain";
    
    case 1:
        return "Threshold";
    
    case 2:
        return "strength";
    
    case 3:
        return "Attack";
    
    case 4:
        return "Release";
    
    case 5:
        return "Knee";
    
    case 6:
        return "output gain (dB)";
    
    case 7:
        return "peak/RMS";
    
    case 8:
        return "det strength";
    
    case 9:
        return "RMS size";
    
    case 10:
        return "Detector Release";
    
    case 11:
        return "sidechain hpf";
    
    case 12:
        return "slow/fast";
    
    case 13:
        return "power";
    
    case 14:
        return "Max Gain Reduction";
    
    case 15:
        return "curve";
    
    case 16:
        return "shape";
    
    case 17:
        return "feedback/feedforward";
    
    case 18:
        return "hi shelf freq";
    
    case 19:
        return "gain/hi-shelve crossfade";
    
    case 20:
        return "dry/wet";
    
    case 21:
        return "ratelimit amount";
    
    case 22:
        return "max attack";
    
    case 23:
        return "max decay";
    
    case 24:
        return "decayMult";
    
    case 25:
        return "decayPower";
    
    case 26:
        return "IM_size";
    
    case 27:
        return "bypass";
    
    case 28:
        return "auto-release";
    
    case 29:
        return "GR";
    
    default:
        return 0;
    }
}

const char *PunchDSP::parameter_short_label(unsigned index) noexcept
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
    
    case 23:
        return "";
    
    case 24:
        return "";
    
    case 25:
        return "";
    
    case 26:
        return "";
    
    case 27:
        return "";
    
    case 28:
        return "";
    
    case 29:
        return "";
    
    default:
        return 0;
    }
}

const char *PunchDSP::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Input_Gain";
    
    case 1:
        return "Threshold";
    
    case 2:
        return "strength";
    
    case 3:
        return "Attack";
    
    case 4:
        return "Release";
    
    case 5:
        return "Knee";
    
    case 6:
        return "output_gain__dB_";
    
    case 7:
        return "peak_RMS";
    
    case 8:
        return "det_strength";
    
    case 9:
        return "RMS_size";
    
    case 10:
        return "Detector_Release";
    
    case 11:
        return "sidechain_hpf";
    
    case 12:
        return "slow_fast";
    
    case 13:
        return "power";
    
    case 14:
        return "Max_Gain_Reduction";
    
    case 15:
        return "curve";
    
    case 16:
        return "shape";
    
    case 17:
        return "feedback_feedforward";
    
    case 18:
        return "hi_shelf_freq";
    
    case 19:
        return "gain_hi_shelve_crossfade";
    
    case 20:
        return "dry_wet";
    
    case 21:
        return "ratelimit_amount";
    
    case 22:
        return "max_attack";
    
    case 23:
        return "max_decay";
    
    case 24:
        return "decayMult";
    
    case 25:
        return "decayPower";
    
    case 26:
        return "IM_size";
    
    case 27:
        return "bypass";
    
    case 28:
        return "auto_release";
    
    case 29:
        return "GR";
    
    default:
        return 0;
    }
}

const char *PunchDSP::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "dB";
    
    case 1:
        return "dB";
    
    case 2:
        return "";
    
    case 3:
        return "ms";
    
    case 4:
        return "ms";
    
    case 5:
        return "dB";
    
    case 6:
        return "";
    
    case 7:
        return "";
    
    case 8:
        return "";
    
    case 9:
        return "";
    
    case 10:
        return "ms";
    
    case 11:
        return "";
    
    case 12:
        return "";
    
    case 13:
        return "";
    
    case 14:
        return "dB";
    
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
        return "dB/s";
    
    case 23:
        return "dB/s";
    
    case 24:
        return "";
    
    case 25:
        return "";
    
    case 26:
        return "";
    
    case 27:
        return "";
    
    case 28:
        return "dB";
    
    case 29:
        return "dB";
    
    default:
        return 0;
    }
}

const PunchDSP::ParameterRange *PunchDSP::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 0, -40, 40 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { -27.1, -80, 0 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 1, 0, 8 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 23.700001, 0.001, 500 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 16, 0, 1000 };
        return &range;
    }
    
    case 5: {
        static const ParameterRange range = { 0, 0, 30 };
        return &range;
    }
    
    case 6: {
        static const ParameterRange range = { 0, -40, 40 };
        return &range;
    }
    
    case 7: {
        static const ParameterRange range = { 1, 0, 1 };
        return &range;
    }
    
    case 8: {
        static const ParameterRange range = { 1, 0, 8 };
        return &range;
    }
    
    case 9: {
        static const ParameterRange range = { 96, 2, 16384 };
        return &range;
    }
    
    case 10: {
        static const ParameterRange range = { 0.1, 0.1, 2000 };
        return &range;
    }
    
    case 11: {
        static const ParameterRange range = { 154, 1, 400 };
        return &range;
    }
    
    case 12: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    case 13: {
        static const ParameterRange range = { 1.88, -33, 33 };
        return &range;
    }
    
    case 14: {
        static const ParameterRange range = { -15, -60, 0 };
        return &range;
    }
    
    case 15: {
        static const ParameterRange range = { 0, -1, 1 };
        return &range;
    }
    
    case 16: {
        static const ParameterRange range = { 94, 1, 100 };
        return &range;
    }
    
    case 17: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    case 18: {
        static const ParameterRange range = { 134, 1, 400 };
        return &range;
    }
    
    case 19: {
        static const ParameterRange range = { 0.81099999, 0, 1 };
        return &range;
    }
    
    case 20: {
        static const ParameterRange range = { 1, 0, 1 };
        return &range;
    }
    
    case 21: {
        static const ParameterRange range = { 1, 0, 1 };
        return &range;
    }
    
    case 22: {
        static const ParameterRange range = { 1020, 6, 8000 };
        return &range;
    }
    
    case 23: {
        static const ParameterRange range = { 3813, 6, 8000 };
        return &range;
    }
    
    case 24: {
        static const ParameterRange range = { 20000, 0, 200000 };
        return &range;
    }
    
    case 25: {
        static const ParameterRange range = { 50, 0, 50 };
        return &range;
    }
    
    case 26: {
        static const ParameterRange range = { 108, 1, 16384 };
        return &range;
    }
    
    case 27: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    case 28: {
        static const ParameterRange range = { 0, -90, 0 };
        return &range;
    }
    
    case 29: {
        static const ParameterRange range = { 0, -60, 0 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool PunchDSP::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool PunchDSP::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    case 12:
        return true;
    
    case 27:
        return true;
    
    default:
        return false;
    }
}

bool PunchDSP::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    case 12:
        return true;
    
    case 27:
        return true;
    
    default:
        return false;
    }
}

bool PunchDSP::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    case 3:
        return true;
    
    case 4:
        return true;
    
    case 9:
        return true;
    
    case 11:
        return true;
    
    case 26:
        return true;
    
    default:
        return false;
    }
}

float PunchDSP::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider2;
    
    case 1:
        return dsp.fHslider15;
    
    case 2:
        return dsp.fHslider4;
    
    case 3:
        return dsp.fHslider13;
    
    case 4:
        return dsp.fHslider24;
    
    case 5:
        return dsp.fHslider16;
    
    case 6:
        return dsp.fHslider25;
    
    case 7:
        return dsp.fHslider9;
    
    case 8:
        return dsp.fHslider8;
    
    case 9:
        return dsp.fHslider12;
    
    case 10:
        return dsp.fHslider14;
    
    case 11:
        return dsp.fHslider10;
    
    case 12:
        return dsp.fCheckbox1;
    
    case 13:
        return dsp.fHslider17;
    
    case 14:
        return dsp.fHslider6;
    
    case 15:
        return dsp.fHslider18;
    
    case 16:
        return dsp.fHslider7;
    
    case 17:
        return dsp.fHslider11;
    
    case 18:
        return dsp.fHslider0;
    
    case 19:
        return dsp.fHslider3;
    
    case 20:
        return dsp.fHslider1;
    
    case 21:
        return dsp.fHslider5;
    
    case 22:
        return dsp.fHslider20;
    
    case 23:
        return dsp.fHslider19;
    
    case 24:
        return dsp.fHslider21;
    
    case 25:
        return dsp.fHslider23;
    
    case 26:
        return dsp.fHslider22;
    
    case 27:
        return dsp.fCheckbox0;
    
    case 28:
        return dsp.fVbargraph0;
    
    case 29:
        return dsp.fVbargraph1;
    
    default:
        (void)dsp;
        return 0;
    }
}

void PunchDSP::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider2 = value;
        break;
    
    case 1:
        dsp.fHslider15 = value;
        break;
    
    case 2:
        dsp.fHslider4 = value;
        break;
    
    case 3:
        dsp.fHslider13 = value;
        break;
    
    case 4:
        dsp.fHslider24 = value;
        break;
    
    case 5:
        dsp.fHslider16 = value;
        break;
    
    case 6:
        dsp.fHslider25 = value;
        break;
    
    case 7:
        dsp.fHslider9 = value;
        break;
    
    case 8:
        dsp.fHslider8 = value;
        break;
    
    case 9:
        dsp.fHslider12 = value;
        break;
    
    case 10:
        dsp.fHslider14 = value;
        break;
    
    case 11:
        dsp.fHslider10 = value;
        break;
    
    case 12:
        dsp.fCheckbox1 = value;
        break;
    
    case 13:
        dsp.fHslider17 = value;
        break;
    
    case 14:
        dsp.fHslider6 = value;
        break;
    
    case 15:
        dsp.fHslider18 = value;
        break;
    
    case 16:
        dsp.fHslider7 = value;
        break;
    
    case 17:
        dsp.fHslider11 = value;
        break;
    
    case 18:
        dsp.fHslider0 = value;
        break;
    
    case 19:
        dsp.fHslider3 = value;
        break;
    
    case 20:
        dsp.fHslider1 = value;
        break;
    
    case 21:
        dsp.fHslider5 = value;
        break;
    
    case 22:
        dsp.fHslider20 = value;
        break;
    
    case 23:
        dsp.fHslider19 = value;
        break;
    
    case 24:
        dsp.fHslider21 = value;
        break;
    
    case 25:
        dsp.fHslider23 = value;
        break;
    
    case 26:
        dsp.fHslider22 = value;
        break;
    
    case 27:
        dsp.fCheckbox0 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float PunchDSP::get_Input_Gain() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float PunchDSP::get_Threshold() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider15;
}

float PunchDSP::get_strength() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}

float PunchDSP::get_Attack() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider13;
}

float PunchDSP::get_Release() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider24;
}

float PunchDSP::get_Knee() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider16;
}

float PunchDSP::get_output_gain__dB_() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider25;
}

float PunchDSP::get_peak_RMS() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider9;
}

float PunchDSP::get_det_strength() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider8;
}

float PunchDSP::get_RMS_size() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider12;
}

float PunchDSP::get_Detector_Release() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider14;
}

float PunchDSP::get_sidechain_hpf() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider10;
}

float PunchDSP::get_slow_fast() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fCheckbox1;
}

float PunchDSP::get_power() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider17;
}

float PunchDSP::get_Max_Gain_Reduction() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider6;
}

float PunchDSP::get_curve() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider18;
}

float PunchDSP::get_shape() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider7;
}

float PunchDSP::get_feedback_feedforward() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider11;
}

float PunchDSP::get_hi_shelf_freq() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float PunchDSP::get_gain_hi_shelve_crossfade() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float PunchDSP::get_dry_wet() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float PunchDSP::get_ratelimit_amount() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider5;
}

float PunchDSP::get_max_attack() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider20;
}

float PunchDSP::get_max_decay() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider19;
}

float PunchDSP::get_decayMult() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider21;
}

float PunchDSP::get_decayPower() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider23;
}

float PunchDSP::get_IM_size() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider22;
}

float PunchDSP::get_bypass() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fCheckbox0;
}

float PunchDSP::get_auto_release() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fVbargraph0;
}

float PunchDSP::get_GR() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fVbargraph1;
}


void PunchDSP::set_Input_Gain(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void PunchDSP::set_Threshold(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider15 = value;
}

void PunchDSP::set_strength(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void PunchDSP::set_Attack(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider13 = value;
}

void PunchDSP::set_Release(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider24 = value;
}

void PunchDSP::set_Knee(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider16 = value;
}

void PunchDSP::set_output_gain__dB_(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider25 = value;
}

void PunchDSP::set_peak_RMS(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider9 = value;
}

void PunchDSP::set_det_strength(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider8 = value;
}

void PunchDSP::set_RMS_size(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider12 = value;
}

void PunchDSP::set_Detector_Release(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider14 = value;
}

void PunchDSP::set_sidechain_hpf(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider10 = value;
}

void PunchDSP::set_slow_fast(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fCheckbox1 = value;
}

void PunchDSP::set_power(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider17 = value;
}

void PunchDSP::set_Max_Gain_Reduction(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider6 = value;
}

void PunchDSP::set_curve(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider18 = value;
}

void PunchDSP::set_shape(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider7 = value;
}

void PunchDSP::set_feedback_feedforward(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider11 = value;
}

void PunchDSP::set_hi_shelf_freq(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}

void PunchDSP::set_gain_hi_shelve_crossfade(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void PunchDSP::set_dry_wet(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void PunchDSP::set_ratelimit_amount(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider5 = value;
}

void PunchDSP::set_max_attack(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider20 = value;
}

void PunchDSP::set_max_decay(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider19 = value;
}

void PunchDSP::set_decayMult(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider21 = value;
}

void PunchDSP::set_decayPower(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider23 = value;
}

void PunchDSP::set_IM_size(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider22 = value;
}

void PunchDSP::set_bypass(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fCheckbox0 = value;
}




