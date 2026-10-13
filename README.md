# Twisted Breaks

A jungle / drum & bass break-chopping performance instrument for Ableton Live.

## Phase 1
This initial scaffold provides:
- JUCE 8 + CMake project
- macOS VST3 and AU targets (plus Standalone for testing)
- stereo instrument output
- MIDI-capable processor
- Ableton/host BPM, PPQ and transport-state reading
- initial 4x4 16-pad interface

The pads are UI placeholders in Phase 1; sample playback, slicing, routing and FX arrive in subsequent phases.

## Build on macOS
Requirements: Xcode command-line tools, CMake, Git, and internet access for CMake to fetch JUCE.

```bash
git clone https://github.com/TwistedGenetics/Break-Chopper.git
cd Break-Chopper
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release -j
```

Build products are under `build/TwistedBreaks_artefacts/Release/`.

## Roadmap
1. Working JUCE VST3/AU scaffold and host sync
2. One complete sample pad and waveform
3. Expand to 16 pads
4. Transient/equal slicing
5. Four group buses
6. 16 performance FX
7. 32-step sequencer/live capture
8. Snapshots and robust state management

## Real-time design
The audio callback will remain allocation/file-I/O/UI free. Sample loading and analysis will run away from the real-time audio thread; DSP buffers will be preallocated and parameters smoothed.
