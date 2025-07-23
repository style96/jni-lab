#include <jni.h>
#include <iostream>
#include "helloworld_HelloJNI.h"

JNIEXPORT void JNICALL Java_helloworld_HelloJNI_sayHello(JNIEnv *, jobject) {
    std::cout << "Hello from C++ !!" << std::endl;
}