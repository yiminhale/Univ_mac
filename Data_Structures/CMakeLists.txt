cmake_minimum_required(VERSION 3.20)
project(Data_Structures)

set(CMAKE_C_STANDARD 11)

# Find all C files in the current directory
file(GLOB C_FILES "*.c")

# Create an executable for each C file
foreach(C_FILE ${C_FILES})
    # Get filename without extension
    get_filename_component(EXEC_NAME ${C_FILE} NAME_WE)
    # Add executable
    add_executable(${EXEC_NAME} ${C_FILE})
endforeach()

# Find all C files in Assg_4 directory
file(GLOB ASSG4_C_FILES "Assg_4/*.c")

# Create an executable for each C file in Assg_4
foreach(C_FILE ${ASSG4_C_FILES})
    # Get filename without extension
    get_filename_component(EXEC_NAME ${C_FILE} NAME_WE)
    # Add executable with prefix to avoid name conflicts
    add_executable(${EXEC_NAME} ${C_FILE})
    # Set include directories for header files in Assg_4
    target_include_directories(${EXEC_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Assg_4)
endforeach()

# Find all C files in before_Mid_Ex directory
file(GLOB BEFORE_MID_C_FILES "before_Mid_Ex/*.c")

# Create an executable for each C file in before_Mid_Ex
foreach(C_FILE ${BEFORE_MID_C_FILES})
    # Get filename without extension
    get_filename_component(EXEC_NAME ${C_FILE} NAME_WE)
    # Add executable with prefix to avoid name conflicts
    add_executable(before_mid_${EXEC_NAME} ${C_FILE})
    # Set include directories for header files in before_Mid_Ex
    target_include_directories(before_mid_${EXEC_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/before_Mid_Ex)
endforeach()