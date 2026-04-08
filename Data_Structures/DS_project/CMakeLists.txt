cmake_minimum_required(VERSION 3.20)
project(DS_Assignment C)

# C 표준 설정
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 컴파일러 경고 설정
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 실행 파일 생성
add_executable(stack_queue_program
    ds_project.c
    Link.h
)

# 디버그 빌드 시 디버그 심볼 추가
if(CMAKE_BUILD_TYPE MATCHES Debug)
    if(MSVC)
        add_compile_options(/Zi)
    else()
        add_compile_options(-g)
    endif()
endif()
