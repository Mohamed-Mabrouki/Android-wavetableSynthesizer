#pragma  once

namespace wavetablesynthesizer{
    enum class Wavetable{
        SINE,TRIANGLE,SQUARE,SAW
    };

    class WavetableSynthesizer{
    public:
        void play();
        void stop();
        void isPlaying();
        void setFrequency(float frequencyInHz);
        void setVolume(float volumeInDb);
        void setWavetable(Wavetable wavetable);

//a dummy impl
    private:
        bool _isPlaying = false;
    };



}