cmake_minimum_required(VERSION 3.17)
project(Sequence_table_array)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

include_directories(include) #增加头文件目录

file(GLOB SOURCE "src/*.cpp" "main.cpp") #源文件

add_executable(${PROJECT_NAME} ${SOURCE})