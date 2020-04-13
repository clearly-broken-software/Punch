#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
#

# --------------------------------------------------------------
# Project name, used for binaries

NAME = Punch

# --------------------------------------------------------------
# Files to build

FILES_DSP = PunchPlugin.cpp\
			PunchDSP.cpp

FILES_UI  = PunchUI.cpp \
			Widgets/src/NanoMeter.cpp \
			Widgets/src/NanoKnob.cpp \
			Widgets/src/NanoHistogram.cpp \
			Widgets/src/NanoSlider.cpp \
			Widgets/src/CbWidget.cpp \
			Widgets/src/ToolTip.cpp \
			Widgets/src/Tab.cpp \
			Widgets/src/Toggle.cpp

# --------------------------------------------------------------
# Do some magic

include ../../dpf/Makefile.plugins.mk

# --------------------------------------------------------------
# Extra Flags
BASE_FLAGS += -I. -I./Widgets -I./dsp

# --------------------------------------------------------------
# Enable all possible plugin types

ifeq ($(HAVE_JACK),true)
TARGETS += jack
endif

ifeq ($(LINUX),true)
ifeq ($(HAVE_DGL),true)
ifeq ($(HAVE_LIBLO),true)
# TARGETS += ladspa
# TARGETS += dssi
endif
endif
endif

ifeq ($(HAVE_DGL),true)
TARGETS += lv2
else
TARGETS += lv2_dsp
endif

TARGETS += vst

all: $(TARGETS)

# --------------------------------------------------------------
