cmake_minimum_required(VERSION 3.20)
project(before_mid_ex C)

# C 표준 설정
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 실행 파일 생성
add_executable(main
        main.c
        Customer_Array.h
        Table_Link.h
        Func.h
)

# 컴파일 경고 옵션 추가 (선택사항)
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(main PRIVATE -Wall -Wextra)
endif()
