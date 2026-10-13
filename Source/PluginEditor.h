#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class TwistedBreaksAudioProcessorEditor : public juce::AudioProcessorEditor,
                                          private juce::Timer
{
public:
    explicit TwistedBreaksAudioProcessorEditor (TwistedBreaksAudioProcessor&);
    ~TwistedBreaksAudioProcessorEditor() override = default;
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void timerCallback() override;
    TwistedBreaksAudioProcessor& processor;
    juce::Label title, transport;
    std::array<juce::TextButton, 16> pads;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TwistedBreaksAudioProcessorEditor)
};
