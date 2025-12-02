#!/usr/bin/env bash

set -e

BUILD_DIR="build"

cmake -S . -B "$BUILD_DIR"
cmake --build "$BUILD_DIR"

if [[ -f "$BUILD_DIR/EffectiveCppDemo" ]]; then
  "$BUILD_DIR/EffectiveCppDemo"
elif [[ -f "$BUILD_DIR/EffectiveCppDemo.exe" ]]; then
  "$BUILD_DIR/EffectiveCppDemo.exe"
elif [[ -f "$BUILD_DIR/Debug/EffectiveCppDemo.exe" ]]; then
  "$BUILD_DIR/Debug/EffectiveCppDemo.exe"
elif [[ -f "$BUILD_DIR/Release/EffectiveCppDemo.exe" ]]; then
  "$BUILD_DIR/Release/EffectiveCppDemo.exe"
else
  echo "Nu am gasit executabilul EffectiveCppDemo in folderul build."
  echo "Verifica ce subfolder a generat CMake si ruleaza manual de acolo."
fi