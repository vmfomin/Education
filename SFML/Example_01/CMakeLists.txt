cmake_minimum_required(VERSION 3.17)
project(Example_01)

set(CMAKE_CXX_STANDARD 17)

add_executable(Example_01 main.cpp)

find_package(SFML 2.5 REQUIRED system window graphics network audio )
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(Example_01 sfml-graphics ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
