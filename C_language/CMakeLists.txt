cmake_minimum_required(VERSION 3.10)
project(C_language)

set(CMAKE_C_STANDARD 11)

# Practice files in root directory
add_executable(practice practice.c)

# Add subdirectories for each assignment
add_subdirectory(Assg_1)
add_subdirectory(Assg_2)
add_subdirectory(Assg_3)
add_subdirectory(Assg_4)