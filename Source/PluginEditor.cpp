#include "PluginEditor.h"

TwistedBreaksAudioProcessorEditor::TwistedBreaksAudioProcessorEditor (TwistedBreaksAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    title.setText ("TWISTED BREAKS", juce::dontSendNotification);
    title.setJustificationType (juce::Justification::centred);
    title.setFont (juce::Font (28.0f, juce::Font::bold));
    addAndMakeVisible (title);

    transport.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (transport);

    for (size_t i = 0; i < pads.size(); ++i)
    {
        pads[i].setButtonText ("PAD " + juce::String ((int) i + 1));
        addAndMakeVisible (pads[i]);
    }

    setSize (820, 620);
    startTimerHz (15);
}

void TwistedBreaksAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour (0xff080b10));
    g.setColour (juce::Colour (0xff232b35));
    g.drawRoundedRectangle (getLocalBounds().toFloat().reduced (12.0f), 12.0f, 1.0f);
}

void TwistedBreaksAudioProcessorEditor::resized()
{
    auto area = getLocalBounds().reduced (24);
    title.setBounds (area.removeFromTop (52));
    transport.setBounds (area.removeFromTop (32));
    area.removeFromTop (18);

    auto grid = area.removeFromTop (430);
    const int gap = 8;
    const int w = (grid.getWidth() - gap * 3) / 4;
    const int h = (grid.getHeight() - gap * 3) / 4;

    for (int i = 0; i < 16; ++i)
        pads[(size_t) i].setBounds (grid.getX() + (i % 4) * (w + gap),
                                    grid.getY() + (i / 4) * (h + gap), w, h);
}

void TwistedBreaksAudioProcessorEditor::timerCallback()
{
    transport.setText ("HOST  " + juce::String (processor.getHostBpm(), 2) + " BPM   |   PPQ " +
                       juce::String (processor.getHostPpq(), 2) +
                       (processor.getHostPlaying() ? "   PLAY" : "   STOP"),
                       juce::dontSendNotification);
}
