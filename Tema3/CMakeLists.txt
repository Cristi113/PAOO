cmake_minimum_required(VERSION 3.10)

project(EffectiveCppItems13_14 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(EffectiveCppDemo
    src/main.cpp
    src/FilmList.cpp
)

target_include_directories(EffectiveCppDemo
    PRIVATE
        src
)