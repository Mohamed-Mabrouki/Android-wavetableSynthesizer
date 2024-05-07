#include "Log.h"
#include "include/WavetableSynthesizer.h"

namespace wavetablesynthesizer {
    void WavetableSynthesizer::play() {
        LOGD("play() called");
    }

    void WavetableSynthesizer::stop() {

    }

    bool WavetableSynthesizer::isPlaying() {
        LOGD("isPlaying() called");
        return _isPlaying;
    }

    void WavetableSynthesizer::setFrequency(float frequencyInHz) {
        LOGD("setFrequency() called with %.2f HZ",frequencyInHz);
    }

    void WavetableSynthesizer::setVolume(float volumeInDb) {
        LOGD("setVolume() called with %.2f DB",volumeInDb);

    }

    void WavetableSynthesizer::setWavetable(Wavetable wavetable) {
        LOGD("setWavetable() called");

    }
}