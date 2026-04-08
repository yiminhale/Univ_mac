cmake_minimum_required(VERSION 3.10)
project(DataStructure_Assg5 C)

set(CMAKE_C_STANDARD 11)

add_executable(hw5_link
        hw5_link.c
        Queue_Link.h
)

add_executable(hw5_array
        hw5_array.c
        Queue_Array.h
)
