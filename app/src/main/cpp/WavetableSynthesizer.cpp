#include "android/log.h"
#include "include/WavetableSynthesizer.h"

namespace wavetablesynthesizer{
    void WavetableSynthesizer::play(){

    }
    void WavetableSynthesizer::stop();
    void WavetableSynthesizer::isPlaying();
    void WavetableSynthesizer::setFrequency(float frequencyInHz);
    void WavetableSynthesizer::setVolume(float volumeInDb);
    void WavetableSynthesizer::setWavetable(Wavetable wavetable);
}