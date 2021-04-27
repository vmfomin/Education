cmake_minimum_required(VERSION 3.17)
project(16_05)

set(CMAKE_CXX_STANDARD 17)


find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
add_executable(16_05 main.cpp)
target_include_directories(16_05 PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries(16_05 sfml-graphics)