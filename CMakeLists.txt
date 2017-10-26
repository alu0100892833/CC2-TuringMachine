cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Transition.cpp Transition.h Tape.cpp Tape.h Status.cpp Status.h TuringMachine.cpp TuringMachine.h)
add_executable(untitled ${SOURCE_FILES})