cmake_minimum_required(VERSION 3.10)

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.11 CACHE STRING "Build for 10.11")

project(tempo-tester VERSION 0.9.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 14)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  # Any Clang or any GCC
  add_compile_options(
          -Wno-multichar
          -Werror
          -fvisibility=hidden
           $<$<AND:$<NOT:$<BOOL:${WIN32}>>,$<COMPILE_LANGUAGE:CXX>>:-fvisibility-inlines-hidden>
  )
endif()

add_subdirectory(lib/JUCE)

if (CLAP_EXTENSIONS)
  add_subdirectory(${CLAP_EXTENSIONS} clap-extensions)
endif()

juce_add_plugin(tempo-tester
    PRODUCT_NAME "TempoTester"
    COMPANY_NAME "Surge Synth Team"  
    BUNDLE_ID "org.surge-synth-team.tempo-tester"
    PLUGIN_MANUFACTURER_CODE VmbA
    PLUGIN_CODE TmTS

    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE

    COPY_PLUGIN_AFTER_BUILD TRUE
    
    FORMATS AU VST3 Standalone
)

if (CLAP_EXTENSIONS)
  clap_juce_extensions_plugin(TARGET tempo-tester
          CLAP_ID "org.surge-synth-team.tempo-tester")
endif()

juce_generate_juce_header( tempo-tester )

target_include_directories(tempo-tester 
  PUBLIC
  src
)

target_sources(tempo-tester PRIVATE
  src/PluginEditor.cpp
  src/PluginProcessor.cpp
)

target_compile_definitions(tempo-tester PUBLIC
    JUCE_ALLOW_STATIC_NULL_VARIABLES=0
    JUCE_STRICT_REFCOUNTEDPOINTER=1

    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_USE_CURL=0
    JUCE_WEB_BROWSER=0

    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_REPORT_APP_USAGE=0

    JUCE_ALSA=1
    JUCE_JACK=1

    DONT_SET_USING_JUCE_NAMESPACE=1
)

target_link_libraries(tempo-tester PRIVATE
        juce::juce_audio_processors
        juce::juce_audio_utils
        juce::juce_audio_devices
)
