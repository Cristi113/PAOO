cmake_minimum_required(VERSION 3.10)
project(Filme LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")


add_executable(Filme
    src/main.cpp
    src/filme.cpp
)
target_include_directories(Filme PRIVATE src)

set_target_properties(Filme PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)