cmake_minimum_required(VERSION 3.22)
project(TwistedBreaks VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(JUCE
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG 8.0.10)
FetchContent_MakeAvailable(JUCE)

juce_add_plugin(TwistedBreaks
  COMPANY_NAME "Twisted Genetics"
  BUNDLE_ID "com.twistedgenetics.twistedbreaks"
  PLUGIN_MANUFACTURER_CODE TwGn
  PLUGIN_CODE TwBr
  FORMATS AU VST3 Standalone
  PRODUCT_NAME "Twisted Breaks"
  IS_SYNTH TRUE
  NEEDS_MIDI_INPUT TRUE
  NEEDS_MIDI_OUTPUT FALSE)

target_sources(TwistedBreaks PRIVATE
  Source/PluginProcessor.cpp
  Source/PluginProcessor.h
  Source/PluginEditor.cpp
  Source/PluginEditor.h)

target_compile_definitions(TwistedBreaks PUBLIC
  JUCE_WEB_BROWSER=0
  JUCE_USE_CURL=0
  JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(TwistedBreaks PRIVATE
  juce::juce_audio_utils
  juce::juce_dsp
  PUBLIC juce::juce_recommended_config_flags
         juce::juce_recommended_lto_flags
         juce::juce_recommended_warning_flags)
