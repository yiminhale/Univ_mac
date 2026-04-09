cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 및 언어 설정
project(Assg_8 C)

# C 표준 설정 (C23)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 컴파일 옵션 설정
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# 실행 파일 생성 - Q2 List 버전
add_executable(Q2_List
        Q2_List.c
)

# 실행 파일 생성 - Q2 Matrix 버전
add_executable(Q2_Matrix
        Q2_Matrix.c
)

# 실행 파일 생성 - Q3 List 버전
add_executable(Q3_List
        Q3_List.c
)

# 실행 파일 생성 - Q3 Matrix 버전
add_executable(Q3_Matrix
        Q3_Matrix.c
)

# include 디렉토리 설정 (현재 디렉토리)
target_include_directories(Q2_List PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Q2_Matrix PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Q3_List PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Q3_Matrix PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 테스트 파일들을 빌드 디렉토리로 복사
configure_file(test1.txt ${CMAKE_CURRENT_BINARY_DIR}/test1.txt COPYONLY)
configure_file(test2.txt ${CMAKE_CURRENT_BINARY_DIR}/test2.txt COPYONLY)
configure_file(test3.txt ${CMAKE_CURRENT_BINARY_DIR}/test3.txt COPYONLY)
configure_file(test4.txt ${CMAKE_CURRENT_BINARY_DIR}/test4.txt COPYONLY)
configure_file(readme.txt ${CMAKE_CURRENT_BINARY_DIR}/readme.txt COPYONLY)
