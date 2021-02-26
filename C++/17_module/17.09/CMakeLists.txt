cmake_minimum_required(VERSION 3.17)
project(17_09)

set(CMAKE_CXX_STANDARD 17)

file(GLOB HEADERS "src/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(17_09 main.cpp ${HEADERS} ${SOURCES})

# set(FLTK_SKIP_FLUID true)
# find_package(FLTK REQUIRED)
# include_directories(${FLTK_INCLUDE_DIR})
# target_link_libraries(${PROJECT_NAME} ${FLTK_BASE_LIBRARY} ${FLTK_PLATFORM_DEPENDENT_LIBS})