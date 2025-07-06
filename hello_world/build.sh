#!/bin/bash

set -e

# Derlenecek Java dosyasının yeri
SRC_JAVA="hello_world/HelloJNI.java"
LIB_NAME="hello"
CPP_SRC="hello_jni.cpp"

# JAVA_HOME tanımlı değilse, sistemdeki varsayılan yoldan bul
if [ -z "$JAVA_HOME" ]; then
  export JAVA_HOME=$(dirname $(dirname $(readlink -f $(which javac))))
fi

echo "Using JAVA_HOME=$JAVA_HOME"

# Derleme
mkdir -p classes

# 1. Java derlemesi
javac -h . -d classes $SRC_JAVA

# 2. C++ kodunu .so dosyasına derle
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" \
    -fPIC -shared -o lib${LIB_NAME}.so $CPP_SRC

# 3. Çalıştırma
echo "Running..."
java -Djava.library.path=. -cp classes hello_world/HelloJNI
