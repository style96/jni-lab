#include <jni.h>
#include "com_example_jni_ArrayJNI.h"

extern "C" JNIEXPORT jint JNICALL
Java_com_example_jni_ArrayJNI_sumArray(JNIEnv* env, jobject, jintArray values) {
    jint* array = env->GetIntArrayElements(values, nullptr);
    jsize length = env->GetArrayLength(values);

    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    env->ReleaseIntArrayElements(values, array, 0);
    return sum;
}
