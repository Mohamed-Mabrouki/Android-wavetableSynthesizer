#pragma once

#include <cstdint>

namespace wavetablesynthesizer{
    //c++ equivalent of an interface
    class AudioPlayer{
    public:
        virtual ~AudioPlayer() = default;

        //play will return an int indicating if the play was successful or not

        //also giving stop 0 value means that this fun is absctarcted an not implemented
        //and this class can't be instantiated

        virtual int32_t play() = 0;

        virtual void stop() = 0;

    };
}