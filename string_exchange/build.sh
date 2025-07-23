#!/bin/bash
set -e

# === Ayarlar ===
JAVA_NAME="StringJNI"
JAVA_SRC="StringJNI.java"
CPP_SRC="string_jni.cpp"
CLASS_DIR="classes"
LIB_NAME="string_jni"
PACKAGE="stringexchange"

# === JAVA_HOME tanımı (otomatik) ===
if [ -z "$JAVA_HOME" ]; then
  export JAVA_HOME=$(dirname $(dirname $(readlink -f $(which javac))))
fi

echo "JAVA_HOME = $JAVA_HOME"

# === Derleme dizini oluştur ===
mkdir -p "$CLASS_DIR"

# === 1. Java kodunu derle ve JNI header üret ===
javac -h . -d "$CLASS_DIR" "$JAVA_SRC"

# === 2. C++ kodunu derle ve .so dosyası oluştur ===
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" \
    -fPIC -shared -o "lib${LIB_NAME}.so" "$CPP_SRC"

# === 3. Çalıştır ===
echo "Çalıştırılıyor..."
java -Djava.library.path=. -cp "$CLASS_DIR" "$PACKAGE.$JAVA_NAME"
