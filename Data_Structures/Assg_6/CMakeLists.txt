cmake_minimum_required(VERSION 4.0)
project(Assg_6 C)

set(CMAKE_C_STANDARD 23)

# Array 기반 리스트 실행파일
add_executable(List_Array List_Array.c List_Array.h)

# Link 기반 리스트 실행파일
add_executable(List_Link List_Link.c List_Link.h)
