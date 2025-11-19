#!/bin/bash

if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir -p build
fi

cmake -S . -B build
if [ $? -ne 0 ]; then
    echo "ERROR: CMake configuration failed!"
    exit 1
fi

cmake --build build
if [ $? -ne 0 ]; then
    echo "ERROR: Build failed!"
    exit 1
fi

EXE_PATH=""
if [ -f "build/Filme" ]; then
    EXE_PATH="build/Filme"
elif [ -f "build/Debug/Filme" ]; then
    EXE_PATH="build/Debug/Filme"
elif [ -f "build/Release/Filme" ]; then
    EXE_PATH="build/Release/Filme"
fi

if [ -n "$EXE_PATH" ]; then
    echo "Executable location: $EXE_PATH"
    echo ""
    read -p "Run the program? (Y/N): " run
    if [ "$run" = "Y" ] || [ "$run" = "y" ]; then
        echo ""
        echo "Running program..."
        echo ""
        ./$EXE_PATH
    fi
else
    echo "Executable not found. Check build directory."
fi