/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace juce;

//==============================================================================
TempoTesterAudioProcessorEditor::TempoTesterAudioProcessorEditor (TempoTesterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 300);
    idleTimer = std::make_unique<IdleTimer>(this);
    idleTimer->startTimerHz(30);
}

TempoTesterAudioProcessorEditor::~TempoTesterAudioProcessorEditor()
{
   idleTimer->stopTimer();
}

//==============================================================================
void TempoTesterAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour(juce::Colours::white);
    g.setFont(18);
    int xp = 10, yp = 10, w = (getWidth() - xp * 4) / 2, h = 20, c = 0;
    auto addF = [&](const std::string &lab, const std::string &val)
    {
         auto r = juce::Rectangle<int>(xp + c * 20, yp, w, h);
         if (c == 0)
         {
            xp += w;
         }
         else
         {
            yp += h + 3; xp = 10;
         }
         c = c + 1;
         c = c % 2;
         g.setColour(juce::Colours::white);
         g.drawText(lab, r, juce::Justification::centredLeft);
         g.setColour(juce::Colours::yellow);
         g.drawText(val, r, juce::Justification::centredRight);
    };

    addF("bpm", std::to_string(processor.bpm));
    addF( "", "" );
    addF( "num", std::to_string(processor.timeSigNumerator));
    addF( "den", std::to_string(processor.timeSigDenominator));
    addF( "timeSamp", std::to_string(processor.timeInSamples));
    addF( "timeSec", std::to_string(processor.timeInSeconds));
    addF( "ppqPos", std::to_string(processor.ppqPosition));
    addF( "ppqPosMsr", std::to_string(processor.ppqPositionOfLastBarStart));
    addF( "isPlaying", processor.isPlaying ? "TRUE" : "FALSE" );
    addF( "isRecording", processor.isRecording ? "TRUE" : "FALSE" );
    addF( "isClap", processor.isClap ? "TRUE" : "FALSE" );
    addF( "barNumber", std::to_string(processor.barNumber));
}

void TempoTesterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void TempoTesterAudioProcessorEditor::idle()
{
   repaint();
}
