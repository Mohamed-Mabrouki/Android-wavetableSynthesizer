#include "Log.h"
#include "include/WavetableSynthesizer.h"
#include "OboeAudioPlayer.h"
#include "WavetableOscillator.h"


namespace wavetablesynthesizer {
    WavetableSynthesizer::WavetableSynthesizer()
            : _oscillator{std::make_shared<A4Oscillator>(samplingRate)},
              _audioPlayer{std::make_unique<OboeAudioPlayer>(_oscillator, samplingRate)} {}

    WavetableSynthesizer:: ~WavetableSynthesizer() = default;

    void WavetableSynthesizer::play() {
        LOGD("play() called");
        const auto result = _audioPlayer ->play();

        if(result == 0){
            _isPlaying = true;
        }else{
            LOGD("could not start playback.");
        }
    }

    void WavetableSynthesizer::stop() {
        LOGD("stop() called");

        _audioPlayer->stop();

        _isPlaying = false;
    }

    bool WavetableSynthesizer::isPlaying() const {
        LOGD("isPlaying() called");
        return _isPlaying;
    }

    void WavetableSynthesizer::setFrequency(float frequencyInHz) {
        LOGD("setFrequency() called with %.2f HZ", frequencyInHz);
    }

    void WavetableSynthesizer::setVolume(float volumeInDb) {
        LOGD("setVolume() called with %.2f DB", volumeInDb);

    }

    void WavetableSynthesizer::setWavetable(Wavetable wavetable) {
        LOGD("setWavetable() called");

    }
}