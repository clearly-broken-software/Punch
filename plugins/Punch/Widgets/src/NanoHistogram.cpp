
#include "NanoHistogram.hpp"

START_NAMESPACE_DISTRHO

NanoHistogram::NanoHistogram(NanoWidget *widget, Callback *cb)
    : NanoWidget(widget, CREATE_ANTIALIAS),
    fCallback(cb)
{
    historyHead = 0;
    //fInVolumeHistory.resize(history);
    // fOutVolumeHistory.resize(history);
    // fGainReductionHistory.resize(history);
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
    drawInput();
    drawOutput();
    drawGainReduction();
    historyHead++;
    historyHead %= history;
}

bool NanoHistogram::onScroll(const ScrollEvent &ev)
{
    if (!contains(ev.pos))
        return false;
    float delta = ev.delta.getY() * 1 / 200;
    fCallback->nanoHistogramValueChanged(this,delta);
    return true;
}

void NanoHistogram::drawOutput()
{
    const auto w = getWidth();
    const auto h = getHeight();
    const Paint bg = linearGradient(w / 2, 0, w / 2, h, Secondary1Shade0, Secondary1Shade4);
    beginPath();
    strokeColor(Secondary1Shade1);
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

    fillColor(0, 0, 0);
    fill();
    fillPaint(bg);
    fill();
    stroke();
    closePath();
}

void NanoHistogram::drawInput()
{
    const auto w = getWidth();
    const auto h = getHeight();
    const Paint bg = linearGradient(w / 2, 0, w / 2, h, PrimaryShade0, PrimaryShade4);
    beginPath();
    strokeColor(PrimaryShade1);
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

    fillColor(0, 0, 0);
    fill();
    fillPaint(bg);
    fill();
    stroke();
    closePath();
}
void NanoHistogram::drawGainReduction()
{
    const auto w = getWidth();
    const auto h = getHeight();
    const float r1 = Secondary2Shade0.red;
    const float g1 = Secondary2Shade0.green;
    const float b1 = Secondary2Shade0.blue;
    const float r2 = Secondary2Shade4.red;
    const float g2 = Secondary2Shade4.green;
    const float b2 = Secondary2Shade4.blue;
    const Color col1 = Color(r1, g1, b1, 0.8f);
    const Color col2 = Color(r2, g2, b2, 0.8f);

    const Paint bg = linearGradient(w / 2, 0, w / 2, h, col1, col2);
    beginPath();
    strokeColor(Secondary2Shade1);
    //  strokeColor(255,0,0);
    strokeWidth(1.0f);
    //   lineJoin(ROUND);
    moveTo(0, h - fGainReductionHistory[historyHead] * h);
    for (int i = 1, j; i < history; i++)
    {
        j = (i + historyHead) % history;
        lineTo(i, h - fGainReductionHistory[j] * h);
    }
    lineTo(w, 0);
    lineTo(0, 0);
    lineTo(0, h - fGainReductionHistory[historyHead] * h);

    //fillColor(255,255,255);
    fillPaint(bg);
    fill();
    stroke();

    closePath();
}
END_NAMESPACE_DISTRHO
