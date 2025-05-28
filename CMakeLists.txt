cmake_minimum_required(VERSION 3.10)
project(shoot_game C)
set(CMAKE_C_STANDARD 11)

include_directories(include)

file(GLOB SOURCES "src/*.c")
add_executable(shoot_game ${SOURCES} "src/test_enemy.c" "include/test_enemy.h")