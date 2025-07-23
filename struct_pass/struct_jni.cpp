#include <jni.h>
#include <iostream>
#include "structpass_StructJNI.h"

extern "C" JNIEXPORT void JNICALL
Java_structpass_StructJNI_printPerson(JNIEnv* env, jobject, jobject personObj) {
    jclass personClass = env->GetObjectClass(personObj);

    // Field id'leri al
    jfieldID nameField = env->GetFieldID(personClass, "name", "Ljava/lang/String;");
    jfieldID ageField = env->GetFieldID(personClass, "age", "I");

    // Değerleri oku
    jstring name = (jstring) env->GetObjectField(personObj, nameField);
    jint age = env->GetIntField(personObj, ageField);

    const char* nameChars = env->GetStringUTFChars(name, nullptr);

    std::cout << "Kişi: " << nameChars << ", Yaş: " << age << std::endl;

    env->ReleaseStringUTFChars(name, nameChars);
}
