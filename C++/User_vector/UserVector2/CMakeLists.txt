cmake_minimum_required(VERSION 3.17)
project(UserVector2)

set(CMAKE_CXX_STANDARD 17)

add_executable(UserVector2 test_vector2.cpp UserVector.cpp UserVector2.cpp)