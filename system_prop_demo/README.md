
# JNI Native Property Demo (main.cpp + .so test on Android)


This module demonstrates how to access Android system properties via C++ using `__system_property_get()` and log the result with `__android_log_print()`. The native shared library is tested using a `main.cpp` binary and deployed to a Cuttlefish emulator running AOSP.

---

## 🛠️ How to Build (AOSP Environment)

copy folder system_prop_demo to aosp/packages/ and then
```bash
source build/envsetup.sh
lunch aosp_cf_x86_64_phone-userdebug
cd packages/system_prop_demo
mm
```
This builds:

libsystem_prop_jni.so in system/lib64/

system_prop_demo binary in system/bin/


## 📦 Deploy to Cuttlefish

Go to the project directory

```bash
adb root
adb remount

adb push out/target/product/vsoc_x86_64/system/lib64/libsystem_prop_jni.so /system/lib64/
adb push out/target/product/vsoc_x86_64/system/bin/system_prop_demo /system/bin/ 
adb shell chmod +x /system/bin/system_prop_demo

```

## 🚀 Run and Observe Logs
```bash
adb shell system_prop_demo
adb logcat | grep HelloJNI

```

## ✅ Expected Output

Terminal output
```bash
Calling native JNI-style function...
```

Logcat output
```bash
I/HelloJNI: Android version: 13
```
## 🧠 How It Works

The function Java_systemprop_SystemPropJNI_getAndroidVersion() is defined in system_prop_jni.cpp

main.cpp directly declares and calls this function via:

```cpp
extern "C" void Java_systemprop_SystemPropJNI_getAndroidVersion();
```
The function reads ro.build.version.release and logs it via logcat.
## 📌 Notes

This setup is ideal for low-level JNI and system API testing

No Java code is involved — purely native

Useful for validating system access before integrating with Android Framework or Java apps