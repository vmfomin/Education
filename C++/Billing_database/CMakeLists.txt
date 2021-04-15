cmake_minimum_required(VERSION 3.17)
project(Billing_database)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(Billing_database main.c Billing_database.c)
# add_executable(Billing_database example.c)