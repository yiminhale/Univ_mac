cmake_minimum_required(VERSION 3.20)
project(Assg_4)

set(CMAKE_C_STANDARD 11)

# Add executables for each C file
add_executable(Calculator Calculator.c Stack_Array.h Stack_Link.h
        Stack_Link2.h
        Stack_Array2.h)
add_executable(Convert Convert.c Stack_Array.h Stack_Link.h)
add_executable(Reverse Reverse.c Stack_Array.h Stack_Link.h)
