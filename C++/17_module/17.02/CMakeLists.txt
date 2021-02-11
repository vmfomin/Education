cmake_minimum_required(VERSION 3.17)
project(17_02)

set(CMAKE_CXX_STANDARD 17)

file(GLOB HEADERS "src/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(17_02 main.cpp ${HEADERS} ${SOURCES})