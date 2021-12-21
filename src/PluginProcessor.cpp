/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace juce;

//==============================================================================
TempoTesterAudioProcessor::TempoTesterAudioProcessor()
    : AudioProcessor (BusesProperties()
                      .withOutput ("Output", AudioChannelSet::stereo(), true)
        )
{
}

TempoTesterAudioProcessor::~TempoTesterAudioProcessor()
{
}

//==============================================================================
const String TempoTesterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TempoTesterAudioProcessor::acceptsMidi() const
{
    return true;
}

bool TempoTesterAudioProcessor::producesMidi() const
{
    return false;
}

bool TempoTesterAudioProcessor::isMidiEffect() const
{
    return false;
}

double TempoTesterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TempoTesterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TempoTesterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TempoTesterAudioProcessor::setCurrentProgram (int index)
{
}

const String TempoTesterAudioProcessor::getProgramName (int index)
{
    return {};
}

void TempoTesterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TempoTesterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void TempoTesterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

bool TempoTesterAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;

    return true;
}

void TempoTesterAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
   auto playhead = getPlayHead();
   if (playhead)
   {
      juce::AudioPlayHead::CurrentPositionInfo cp;
      playhead->getCurrentPosition(cp);

      bpm = cp.bpm;
      timeSigNumerator = cp.timeSigNumerator;
      timeSigDenominator = cp.timeSigDenominator;
      timeInSamples = cp.timeInSamples;
      timeInSeconds = cp.timeInSeconds;
      ppqPosition = cp.ppqPosition;
      ppqPositionOfLastBarStart = cp.ppqPositionOfLastBarStart;
      ppqLoopStart = cp.ppqLoopStart;
      ppqLoopEnd = cp.ppqLoopEnd;
      isPlaying = cp.isPlaying;
      isLooping = cp.isLooping;
      isRecording = cp.isRecording;
#if HAS_CLAP_JUCE_EXTENSIONS
      isClap = is_clap;
      if (clap_transport)
        barNumber = clap_transport->bar_number;
#else
      isClap = false;
      barNumber = 0;
#endif
   }
}

//==============================================================================
bool TempoTesterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TempoTesterAudioProcessor::createEditor()
{
    return new TempoTesterAudioProcessorEditor (*this);
}

//==============================================================================
void TempoTesterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
}

void TempoTesterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TempoTesterAudioProcessor();
}
