#pragma  once
#include <memory>

namespace wavetablesynthesizer{
    enum class Wavetable{
        SINE,TRIANGLE,SQUARE,SAW
    };

    class AudioSource;
    class AudioPlayer;

    constexpr auto samplingRate = 480000;

    class WavetableSynthesizer{

    public:
        WavetableSynthesizer();
        ~WavetableSynthesizer() ;
        void play();
        void stop();
        bool isPlaying() const;
        void setFrequency(float frequencyInHz);
        void setVolume(float volumeInDb);
        void setWavetable(Wavetable wavetable);

//a dummy impl
    private:
        bool _isPlaying = false;
        std::shared_ptr<AudioSource> _oscillator;
        std::unique_ptr<AudioPlayer> _audioPlayer;
    };



}