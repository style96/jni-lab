#include <jni.h>
#include <iostream>
#include "com_example_jni_HelloJNI.h"

JNIEXPORT void JNICALL Java_com_example_jni_HelloJNI_sayHello(JNIEnv *, jobject) {
    std::cout << "Hello from C++ !!" << std::endl;
}