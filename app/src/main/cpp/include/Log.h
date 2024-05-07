#pragma once

#include <android/log.h>

// only available in debug thanks to ifndef NDEBUG

#ifndef NDEBUG
#define LOGD(args...) \
__android_log_print(android_LogPriority::ANDROID_LOG_DEBUG, "WavetableSynthesizer", args)
#else
#define LOGD(args...)
#endif