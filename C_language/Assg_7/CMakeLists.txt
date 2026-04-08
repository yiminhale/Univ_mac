cmake_minimum_required(VERSION 3.21)
project(Assg_7 C)

# C23 표준 설정
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 컴파일러 경고 옵션 설정
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall           # 기본 경고 활성화
        -Wextra         # 추가 경고 활성화
        -Wpedantic      # 표준 준수 경고
        -Werror         # 경고를 에러로 처리 (선택사항)
    )
endif()

# 실행 파일 생성
add_executable(hw7 hw7.c)

# 디버그 빌드 타입 설정 (개발 중에는 유용함)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 디버그 심볼 및 최적화 옵션
target_compile_options(hw7 PRIVATE
    $<$<CONFIG:Debug>:-g -O0>          # 디버그: 심볼 포함, 최적화 없음
    $<$<CONFIG:Release>:-O3 -DNDEBUG>  # 릴리스: 최대 최적화
)
