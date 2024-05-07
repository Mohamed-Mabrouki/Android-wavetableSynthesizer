#include <jni.h>
#include <memory>
#include "Log.h"
#include "WavetableSynthesizer.h"


//this code will have c linkage specification so we will be allowed to write here c++ code
//that will later be compiled in a way that is compatible with c cause we need it in the call of
//jni

//and also here we gonna put the definitions of the missing funs
extern "C" {

//JJNIEXPORT is the declarations that this fun is exported
//jlong is the return type
//JNICALL is the way how this fun should be called

//the Java_com_... is the name that informs jvm that this is the fun that sdould be called from
// create fun in the nativeWave.. in kotlin code
JNIEXPORT jlong JNICALL
Java_com_example_jni_NativeWavetableSynthesizer_create(JNIEnv *env, jobject thiz) {
    auto synthesizer = std::make_unique<wavetablesynthesizer::WavetableSynthesizer>();

    if (not synthesizer) {
        LOGD("Failed to create the synthesizer")
        synthesizer.reset(nullptr);
    }

    return reinterpret_cast<jlong>(synthesizer.release());
}


JNIEXPORT void JNICALL
Java_com_example_jni_NativeWavetableSynthesizer_delete(JNIEnv *env, jobject thiz,
                                                       jlong synthesizerHandle) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer>(synthesizerHandle);

    if (not synthesizer) {
        LOGD("Attemted to destroyan unitialized synthesizer");
        return;
    }

    delete synthesizer;


}

JNIEXPORT void JNICALL
Java_com_example_jni_NativeWavetableSynthesizer_play(JNIEnv *env, jobject thiz,
                                                     jlong synthesizerHandle) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer>(synthesizerHandle);

    if(synthesizer){
        synthesizer->play();
    } else {
        LOGD("Synthesizer not created");
    }
}
JNIEXPORT void JNICALL
Java_com_example_jni_NativeWavetableSynthesizer_stop(JNIEnv *env, jobject thiz,
                                                     jlong synthesizerHandle) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer>(synthesizerHandle);

    if(synthesizer){
        synthesizer->stop();
    } else {
        LOGD("Synthesizer not created");
    }
}

JNIEXPORT jboolean JNICALL
Java_com_example_jni_NativeWavetableSynthesizer_isPlaying(JNIEnv *env, jobject thiz,
                                                          jlong synthesizerHandle) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer>(synthesizerHandle);

    if(synthesizer){
        synthesizer-isPlaying();
    } else {
        LOGD("Synthesizer not created");
    }

    return false;
}

JNIEXPORT void JNICALL
Java_com_example_jni_NativeWavetableSynthesizer_setFrequency(JNIEnv *env, jobject thiz,
                                                             jlong synthesizerHandle,
                                                             jfloat frequencyInHz) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer>(synthesizerHandle);

    if(synthesizer){
        synthesizer->setFrequency(static_cast<float >(frequencyInHz));
    } else {
        LOGD("Synthesizer not created");
    }
}

JNIEXPORT void JNICALL
Java_com_example_jni_NativeWavetableSynthesizer_setVolume(JNIEnv *env, jobject thiz,
                                                          jlong synthesizerHandle,
                                                          jfloat volumeInDb) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer>(synthesizerHandle);

    if(synthesizer){
        synthesizer->setVolume(static_cast<float >(volumeInDb));
    } else {
        LOGD("Synthesizer not created");
    }
}

JNIEXPORT void JNICALL
Java_com_example_jni_NativeWavetableSynthesizer_setWavetable(JNIEnv *env, jobject thiz,
                                                             jlong synthesizerHandle,
                                                             jint wavetable) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer>(synthesizerHandle);
    const auto  nativeWavetable = static_cast<wavetablesynthesizer::Wavetable>(wavetable);

    if(synthesizer){
        synthesizer->setWavetable(nativeWavetable);
    } else {
        LOGD("Synthesizer not created");
    }
}
}

//after all that we gonna create the inclute directory in cpp