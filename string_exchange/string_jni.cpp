#include <jni.h>
#include <string>
#include "com_example_jni_StringJNI.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jni_StringJNI_processString(JNIEnv* env, jobject, jstring input) {
    // Java string → C++ string dönüşümü
    const char* inputStr = env->GetStringUTFChars(input, 0);
    std::string result = std::string(inputStr) + " AOSP";
    env->ReleaseStringUTFChars(input, inputStr);

    // C++ string → Java string dönüşümü
    return env->NewStringUTF(result.c_str());
}
