cmake_minimum_required(VERSION 3.17)
project(Example_01)

set(CMAKE_CXX_STANDARD 17)


find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
add_executable(Example_01 main.cpp)
target_include_directories(Example_01 PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries(Example_01 sfml-graphics)