cmake_minimum_required(VERSION 3.10)
project(Data_Structures)

set(CMAKE_C_STANDARD 99)

# 모든 .c 파일을 자동으로 찾아서 개별 실행파일로 생성
file(GLOB C_FILES "*.c")
foreach(C_FILE ${C_FILES})
    get_filename_component(EXEC_NAME ${C_FILE} NAME_WE)
    add_executable(${EXEC_NAME} ${C_FILE})
endforeach()

# 디버그 정보 포함
set(CMAKE_BUILD_TYPE Debug)