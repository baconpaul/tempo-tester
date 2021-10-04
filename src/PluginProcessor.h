/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <set>


class TempoTesterAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    TempoTesterAudioProcessor();
    ~TempoTesterAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    std::atomic<double> bpm{0};
    std::atomic<int> timeSigNumerator{4}, timeSigDenominator{4};
    std::atomic<int64_t> timeInSamples{0};
    std::atomic<double> timeInSeconds{0};
    std::atomic<double> ppqPosition{0}, ppqPositionOfLastBarStart{0}, ppqLoopStart{0}, ppqLoopEnd{0};
    std::atomic<bool> isPlaying{false}, isRecording{false}, isLooping{false};

private:

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TempoTesterAudioProcessor)
};
