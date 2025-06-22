# JNI Lab – Java Native Interface Playground

This repository contains practical JNI examples, from hello world to system-level AOSP integrations.

## Projects
- **hello_world/**: Basic JNI method call
- **string_exchange/**: Passing strings from Java to C++
- **array_sum/**: Passing and summing int arrays
- **struct_pass/**: Passing a Java object to native code

## Build & Run

### array_jni
javac -h . com/example/jni/ArrayJNI.java
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -fPIC -shared -o libarray_jni.so array_jni.cpp
java -Djava.library.path=. -cp . com.example.jni.ArrayJNI

### struct_jni
javac -h . com/example/jni/StructJNI.java
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -fPIC -shared -o libstruct_jni.so struct_jni.cpp
java -Djava.library.path=. -cp . com.example.jni.StructJNI
