cmake_minimum_required(VERSION 3.17)
project(xz_compress)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

include_directories(
        src
        src/xz
        libs/lzma/include
        libs/lzma/include/lzma
)

link_directories(
        ./libs/lzma/bin
)

add_executable(xz_compress main.cpp src/xz/decode.cpp src/xz/encode.cpp)

target_link_libraries(xz_compress
        liblzma.a
        )