/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TempoTesterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TempoTesterAudioProcessorEditor (TempoTesterAudioProcessor&);
    ~TempoTesterAudioProcessorEditor();

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    struct IdleTimer : juce::Timer {
        IdleTimer(TempoTesterAudioProcessorEditor *ed) : ed(ed) {}
        ~IdleTimer() = default;
        void timerCallback() override { ed->idle(); }
        TempoTesterAudioProcessorEditor *ed;
    };
    void idle();
private:
    std::unique_ptr<IdleTimer> idleTimer;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TempoTesterAudioProcessor& processor;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TempoTesterAudioProcessorEditor)
};
