cmake_minimum_required(VERSION 3.21)
project(in_lecture C)

set(CMAKE_C_STANDARD 23)

# 현재 디렉토리의 모든 .c 파일을 찾아서 각각 실행 파일로 생성
file(GLOB SOURCES "*.c")

foreach(SOURCE_FILE ${SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE_FILE})
endforeach()