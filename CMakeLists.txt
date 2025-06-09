cmake_minimum_required(VERSION 3.10)
project(escape-from-aliens C)
set(CMAKE_C_STANDARD 11)

include_directories(include)

file(GLOB SOURCES "src/*.c")
add_executable(escape-from-aliens ${SOURCES})