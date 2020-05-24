cmake_minimum_required(VERSION 3.14)
project(Pascal_Compiler)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "/usr/bin/c++")
set(CMAKE_CXX_FLAGS "-Wno-narrowing")
set(CMAKE_EXE_LINKER_FLAGS "-lcurses")

set(LLVM_DIR /home/lianjiayi/llvm)
find_package( LLVM REQUIRED CONFIG)

if (NOT LLVM_FOUND)
    message(FATAL_ERROR "LLVM Not Found!")
endif (NOT LLVM_FOUND)

include_directories( ${LLVM_INCLUDE_DIRS} )
link_directories(${LLVM_LIBRARY_DIRS})

add_subdirectory(src)