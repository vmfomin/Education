cmake_minimum_required(VERSION 3.17)
project(UserVector)

set(CMAKE_CXX_STANDARD 17)

add_executable(UserVector test_vector.cpp UserVector.cpp)