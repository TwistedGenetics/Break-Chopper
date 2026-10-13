#include "PluginProcessor.h"
#include "PluginEditor.h"

TwistedBreaksAudioProcessor::TwistedBreaksAudioProcessor()
    : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true))
{
}

void TwistedBreaksAudioProcessor::prepareToPlay (double, int) {}

bool TwistedBreaksAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

void TwistedBreaksAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                                 juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;
    buffer.clear();

    if (auto* playHead = getPlayHead())
        if (auto position = playHead->getPosition())
        {
            if (auto bpm = position->getBpm()) hostBpm.store (*bpm);
            if (auto ppq = position->getPpqPosition()) hostPpq.store (*ppq);
            hostPlaying.store (position->getIsPlaying());
        }
}

void TwistedBreaksAudioProcessor::getStateInformation (juce::MemoryBlock&) {}
void TwistedBreaksAudioProcessor::setStateInformation (const void*, int) {}

juce::AudioProcessorEditor* TwistedBreaksAudioProcessor::createEditor()
{
    return new TwistedBreaksAudioProcessorEditor (*this);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TwistedBreaksAudioProcessor();
}
