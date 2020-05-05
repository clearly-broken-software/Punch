
#include "NanoHistogram.hpp"

START_NAMESPACE_DISTRHO

NanoHistogram::NanoHistogram(NanoWidget *widget, Callback *cb)
    : NanoWidget(widget, CREATE_ANTIALIAS | CREATE_STENCIL_STROKES),
      fCallback(cb)
{
    historyHead = 0;
    fInVolumeHistory.resize(history);
    fOutVolumeHistory.resize(history);
    fGainReductionHistory.resize(history);
}

void NanoHistogram::setValues(float in, float out, float gr)
{
    // normalize (value - min) / (max - min);
    const float min = -60.0f;
    const float max_minus_min = -60.0f;
    const float nIn = (in - min) / max_minus_min;
    const float nOut = (out - min) / max_minus_min;
    const float nGr = (gr - min) / max_minus_min;

    fInVolumeHistory[historyHead] = -nIn;
    fOutVolumeHistory[historyHead] = -nOut;
    fGainReductionHistory[historyHead] = -nGr;
    historyHead++;
    historyHead %= history;
}

void NanoHistogram::setHistoryLength(int h)
{
    history = h;
    fInVolumeHistory.resize(history);
    fOutVolumeHistory.resize(history);
    fGainReductionHistory.resize(history);
    std::fill(fInVolumeHistory.begin(), fInVolumeHistory.end(), -60.0f);
    std::fill(fOutVolumeHistory.begin(), fOutVolumeHistory.end(), -60.0f);
    std::fill(fGainReductionHistory.begin(), fGainReductionHistory.end(), 0.0f);
}

void NanoHistogram::onNanoDisplay()
{
    drawOutput();
    drawInput();
    drawGainReduction();
}

bool NanoHistogram::onScroll(const ScrollEvent &ev)
{
    if (!contains(ev.pos))
        return false;
    float delta = ev.delta.getY();
    fCallback->nanoHistogramValueChanged(this, delta);
    return true;
}

void NanoHistogram::drawOutput()
{
    const auto w = getWidth();
    const auto h = getHeight();
    Color col1 = TurquoiseGreen0;
    Color col2 = TurquoiseGreen4;
    col1.alpha = 0.25f;
    col2.alpha = 0.125f;

    const Paint bg = linearGradient(w / 2, 0, w / 2, h, col1, col2);
    beginPath();
    strokeColor(GreenSheen1);
    strokeWidth(1.0f);
    moveTo(0, h - fOutVolumeHistory[historyHead] * h);
    for (int i = 1, j; i < history; i++)
    {
        j = (i + historyHead) % history;
        lineTo(i, h - fOutVolumeHistory[j] * h);
    }
    lineTo(w, h);
    lineTo(0, h);
    lineTo(0, h - fOutVolumeHistory[historyHead] * h);
    fillPaint(bg);
    fill();
    stroke();
    closePath();
}

void NanoHistogram::drawInput()
{
    const auto w = getWidth();
    const auto h = getHeight();
    Color col1 = PaleSpringBud0;
    col1.alpha = 0.25f;
    Color col2 = PaleSpringBud4;
    col2.alpha = 0.125f;
    const Paint bg = linearGradient(w / 2, 0, w / 2, h, col1, col2);
    beginPath();
    strokeColor(PaleSpringBud1);
    strokeWidth(1.0f);
    moveTo(0, h - fInVolumeHistory[historyHead] * -h);
    for (int i = 1, j; i < history; i++)
    {
        j = (i + historyHead) % history;
        lineTo(i, h - fInVolumeHistory[j] * h);
    }
    lineTo(w, h);
    lineTo(0, h);
    lineTo(0, h - fInVolumeHistory[historyHead] * h);
    fillPaint(bg);
    fill();
    stroke();
    closePath();
}

void NanoHistogram::drawGainReduction()
{
    const auto w = getWidth();
    const auto h = getHeight();
    Color col1 = RadicalRed0;
    Color col2 = RadicalRed4;
    col1.alpha = 0.25;
    col2.alpha = 0.125;

    const Paint bg = linearGradient(w / 2, 0, w / 2, h, col1, col2);
    beginPath();
    strokeColor(RadicalRed1);
    strokeWidth(1.0f);
    moveTo(0, h - fGainReductionHistory[historyHead] * h);
    for (int i = 1, j; i < history; i++)
    {
        j = (i + historyHead) % history;
        lineTo(i, h - fGainReductionHistory[j] * h);
    }
    lineTo(w, 0);
    lineTo(0, 0);
    lineTo(0, h - fGainReductionHistory[historyHead] * h);
    fillPaint(bg);
    fill();
    stroke();
    closePath();
}
END_NAMESPACE_DISTRHO
