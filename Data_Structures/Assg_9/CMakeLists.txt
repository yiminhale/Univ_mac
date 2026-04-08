cmake_minimum_required(VERSION 3.10)
project(Assg_9 C)

# C 표준 설정
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 컴파일 옵션 설정 (컴파일러별로 다르게)
if(MSVC)
    # Visual Studio (Windows)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
else()
    # GCC/Clang (macOS/Linux)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
endif()

# 각 C 파일을 독립적인 실행 파일로 빌드
add_executable(Q1 Q1.c)
add_executable(Q2 Q2.c)
add_executable(Q3 Q3.c)
add_executable(main main.c)

# 헤더 파일이 같은 디렉토리에 있으므로 include 디렉토리 설정
target_include_directories(Q1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Q2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Q3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
