package com.example.jni

//the whole purpose of that class is to only be the bridge between c++ and kotlin
//so we move the execution out (things like synthesizerHandle synthesizerMutex are used to
//maintain the information about the native object

import androidx.lifecycle.DefaultLifecycleObserver
import androidx.lifecycle.LifecycleOwner
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext


class NativeWavetableSynthesizer : WavetableSynthesizer, DefaultLifecycleObserver {
    //will hold the memory address
    private var synthesizerHandle: Long = 0

    //to make WavetableSynthesize thread safe so with it we make sure that we dont use it when it's
    //being destroyed cause tht will lead to corrupting the memory
    private var synthesizerMutex = Object()

    private external fun create(): Long

    //we pass the synthesizerHandle in order to know what syn to delete(it's the memory address)
    private external fun delete(synthesizerHandle: Long)

    private external fun play(synthesizerHandle: Long)

    private external fun stop(synthesizerHandle: Long)

    private external fun isPlaying(synthesizerHandle: Long): Boolean

    private external fun setFrequency(synthesizerHandle: Long, frequencyInHz: Float)

    private external fun setVolume(synthesizerHandle: Long, volumeInDb: Float)

    private external fun setWavetable(synthesizerHandle: Long, wavetable: Int)

    //here we need to load out native library

    companion object {
        init {
            System.loadLibrary("jni")
        }
    }

    override fun onResume(owner: LifecycleOwner) {
        super.onResume(owner)

        synchronized(synthesizerMutex) {
            createNativeHandleIfNotExists()
        }

    }

    override fun onPause(owner: LifecycleOwner) {
        super.onPause(owner)

        synchronized(synthesizerMutex) {
            if (synthesizerHandle == 0L) return

            delete(synthesizerHandle)

            //setting it to 0L so it tells us later that we delelted the handle and
            //we will need to create it again if we needed
            synthesizerHandle = 0L
        }
    }

    //this dun is not sync so it should be always called in synchronized block
    private fun createNativeHandleIfNotExists() {
        if (synthesizerHandle != 0L) return

        synthesizerHandle = create()

    }


    override suspend fun play() =
        withContext(Dispatchers.Default) {

            synchronized(synthesizerMutex) {
                createNativeHandleIfNotExists()
                play(synthesizerHandle)
            }

        }

    override suspend fun stop() =
        withContext(Dispatchers.Default) {
            createNativeHandleIfNotExists()
            stop(synthesizerHandle)
        }

    override suspend fun isPlaying(): Boolean =
        withContext(Dispatchers.Default) {
            synchronized(synthesizerMutex) {
                createNativeHandleIfNotExists()
                return@withContext isPlaying(synthesizerHandle)
            }
        }

    override suspend fun setFrequency(frequencyInHz: Float) =
        withContext(Dispatchers.Default) {
            createNativeHandleIfNotExists()
            setFrequency(synthesizerHandle, frequencyInHz)
        }

    override suspend fun setVolume(volumeInDb: Float) =
        withContext(Dispatchers.Default) {
            createNativeHandleIfNotExists()
            setVolume(synthesizerHandle, volumeInDb)
        }

    override suspend fun setWavetable(wavetable: Wavetable) =
        withContext(Dispatchers.Default) {
            createNativeHandleIfNotExists()
            setWavetable(synthesizerHandle, wavetable.ordinal)
        }

}