# CMake 최소 버전 요구사항
cmake_minimum_required(VERSION 3.21)

# 프로젝트 이름과 사용 언어
project(Assg_6_real C)

# C 표준 설정 (C23 사용)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

# 경고 옵션 활성화 (좋은 코딩 습관을 위해)
if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_C_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 실행 파일 생성
add_executable(hw6 hw6.c)

# 빌드 타입별 컴파일 옵션 (선택사항)
if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Debug mode enabled")
    add_compile_options(-g)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    message(STATUS "Release mode enabled")
    add_compile_options(-O2)
endif()