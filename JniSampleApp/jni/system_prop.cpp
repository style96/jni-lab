#include <sys/system_properties.h>  // Android system property API
#include <jni.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_android_jnisampleapp_MainActivity_getAndroidVersion(JNIEnv* env, jobject /* this */) {
    char version[PROP_VALUE_MAX] = {0};
    __system_property_get("ro.build.version.release", version);
    return env->NewStringUTF(version);
}
