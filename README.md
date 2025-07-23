# JNI Lab – Java Native Interface Playground

This repository contains practical JNI examples, from hello world to system-level AOSP integrations.

## Projects
- **hello_world/**: Basic JNI method call
- **string_exchange/**: Passing strings from Java to C++
- **array_sum/**: Passing and summing int arrays
- **struct_pass/**: Passing a Java object to native code

## 🛠️ Prerequisites

Make sure you have the following installed:

- Java JDK 11+ (e.g. OpenJDK 17)
- g++ (e.g. via `build-essential` or `mingw-w64`)
- Linux or WSL (recommended for Windows)
- Bash shell (for `build.sh`)

## Build & Run
From each inside of each project folder run:
(Example of hello_world)
```bash
cd hello_world
chmod +x build.sh
./build.sh
```
## Expected Output
Example of Hello_World
JAVA_HOME = /usr/lib/jvm/java-17-openjdk-amd64
Çalıştırılıyor...
Hello from native C++!
