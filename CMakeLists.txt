cmake_minimum_required(VERSION 3.17)
project(Sequence_table_array C)

set(CMAKE_C_STANDARD 99)

include_directories(include) #增加头文件目录

file(GLOB SOURCE "src/*.c" "main.c") #源文件

add_executable(${PROJECT_NAME} ${SOURCE})