cmake_minimum_required(VERSION 3.20)
project(Assg_7 C)

# C 표준 설정
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 컴파일러 경고 옵션 추가
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# 실행 파일 생성
add_executable(hw7
        Binary_Tree.c
        Binary_Tree.h
        Tree_Queue.h
)
