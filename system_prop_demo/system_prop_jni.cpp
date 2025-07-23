#include <sys/system_properties.h>  // Android system property API
#include <android/log.h>

extern "C" void Java_systemprop_SystemPropJNI_getAndroidVersion() {
    char version[PROP_VALUE_MAX] = {0};
    __system_property_get("ro.build.version.release", version);
    __android_log_print(ANDROID_LOG_INFO, "HelloJNI", "Android version: %s", version);
}