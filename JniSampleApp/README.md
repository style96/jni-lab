# Sample JNI APP (MainActivity.java + .so commmunication on Android)


This module demonstrates how to access Android system properties via C++ using `__system_property_get()`. The native shared library is tested using a `MainActivity.java` as system application and deployed to a Cuttlefish emulator running AOSP.

---

## 🛠️ How to Build (AOSP Environment)

copy folder system_prop_demo to aosp/packages/ and then
```bash
source build/envsetup.sh
lunch aosp_cf_x86_64_phone-userdebug
cd packages/apps/JniSampleApp
mm
```
This builds:

libJniSampleApp.so in system/lib64/

JniSampleApp.apk in system/priv-app/JniSampleApp/

example of my out folder path: /aosp/out/target/product/vsoc_x86_64/system/priv-app/JniSampleApp


## 📦 Deploy to Cuttlefish

Go to the project directory

```bash
adb root
adb remount

adb push out/target/product/vsoc_x86_64/system/lib64/libJniSampleApp.so /system/lib64/
adb push out/target/product/vsoc_x86_64/system/priv-app/JniSampleApp/JniSampleApp.apk /system/priv-app/JniSampleApp/JniSampleApp.apk
adb shell chmod 644 /system/priv-app/JniSampleApp/JniSampleApp.apk

```

## 🚀 Run and Observe Logs
```bash
Open JniSampleApp from UI.
Click get android version button.
And check on the UI whether Android version visible or not.
```

## ✅ Expected Output

Logcat output
```bash
I/HelloJNI: Android version: 13
```

## 🧠 How It Works

The function Java_com_android_jnisampleapp_MainActivity_getAndroidVersion() is defined in system_prop_jni.cpp

JniSampleApp.apk directly declares and calls this function via:

```cpp
extern "C" void Java_com_android_jnisampleapp_MainActivity_getAndroidVersion();
```
The function reads ro.build.version.release and logs it via logcat.
## 📌 Notes

This setup is ideal for low-level JNI and system API testing

Useful for validating system access before integrating with Android Framework or Java apps