#include <iostream>

extern "C" void Java_systemprop_SystemPropJNI_getAndroidVersion();

int main() {
    std::cout << "Calling native JNI-style function..." << std::endl;
    Java_systemprop_SystemPropJNI_getAndroidVersion();
    return 0;
}