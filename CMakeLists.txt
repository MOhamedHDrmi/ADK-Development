cmake_minimum_required(VERSION 3.14)
project(InitProgram C)

set(CMAKE_C_STANDARD 99)

add_executable(InitProgram main.c include/connection.h include/queries.h)
target_link_libraries(InitProgram odbc32)