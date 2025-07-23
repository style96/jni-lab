#!/bin/bash
set -e

# === Ayarlar ===
JAVA_NAME="StructJNI"
JAVA_SRC="Person.java StructJNI.java"
CPP_SRC="struct_jni.cpp"
CLASS_DIR="classes"
LIB_NAME="struct_jni"
PACKAGE="structpass"

# === JAVA_HOME tanımı (otomatik) ===
if [ -z "$JAVA_HOME" ]; then
  export JAVA_HOME=$(dirname $(dirname $(readlink -f $(which javac))))
fi

echo "JAVA_HOME = $JAVA_HOME"

# === Derleme dizini oluştur ===
mkdir -p "$CLASS_DIR"

# === 1. Java kodunu derle ve JNI header üret ===
javac -h . -d "$CLASS_DIR" $JAVA_SRC

# === 2. C++ kodunu derle ve .so dosyası oluştur ===
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" \
    -fPIC -shared -o "lib${LIB_NAME}.so" "$CPP_SRC"

# === 3. Çalıştır ===
echo "Çalıştırılıyor..."
java -Djava.library.path=. -cp "$CLASS_DIR" "$PACKAGE.$JAVA_NAME"
