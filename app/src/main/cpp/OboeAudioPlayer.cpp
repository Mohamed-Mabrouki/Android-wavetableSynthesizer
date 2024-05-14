#include "OboeAudioPlayer.h"
#include "AudioSource.h"

using namespace oboe;

namespace wavetablesynthesizer{

    OboeAudioPlayer::OboeAudioPlayer(std::shared_ptr<AudioSource> source, int samplingRate)
    :_source{sdt::move(source)},_samplingRate{samplingRate}{

    }

    OboeAudioPlayer::~OboeAudioPlayer(){
        OboeAudioPlayer::stop();
    }

    int32_t OboeAudioPlayer::play(){

        AudioSteamBuilder builder;

        const auto result = builder.setPerformanceMode(PerformanceMode::LowLatency)
                -> setDirection(Direction::Output)

    }

    void OboeAudioPlayer::stop() {}

    oboe::DataCallback OboeAudioPlayer::onAudioReady(oboe::AudioStream* audioStream,
                                    void *audiodata,
                                    int32_t framesCount
    ) {}

}