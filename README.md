# TempoTester

This is a little AU/VST3/CLAP which just puts all the playhead information on the screen, 
useful for debugging DAWs.

Standard instructions build the VST3 and so forth.

```shell
clone
git submodule updste --init --recursive
cmake -Bbuild
cmake --build build --target tempo-tester_VST3
```

## Building a clap with the 'branchless clap extensions'

Week of Dec 21 I am working on 'branchless' JUCE extensions for clap which allow you
to use JUCE plugins against a production juce 6 / cmake without a fork. As of Dec 21
it is mac tested only but

```shell
mkdir clap-tempo-tester
cd clap-tempo-tester
git clone https://github.com/free-qudio/clap
git clone https://github.com/free-qudio/clap-helpers
git clone https://github.com/baconpaul/clap-juce-extensions  # will move to freeaudio soon
git clone https://github.com/baconpaul/tempo-tester
cd tempo-tester
git submodule update --init --recursive
cmake -Bbuild -DCMAKE_BUILD_TYPE=Debug -GNinja -DCLAP_EXTENSIONS=${PWD}/../clap-juce-extensions -DCLAP_ROOT=${PWD}/..
cmake --build build --target tempo-tester_CLAP

```