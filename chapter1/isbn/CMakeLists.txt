cmake_minimum_required(VERSION 3.17)

# Get name of parent folder
get_filename_component(NAME ../fahrenheit NAME)

# Set project name to name of parent folder
project(${NAME} C)

set(CMAKE_C_STANDARD 11)

# Add an executable with the same name as parent folder
add_executable(${NAME} ${NAME}.c)

# Set a variable for the CS50 library directory
set(CS50_LIB_DIR ../../cs50)
include_directories(${CS50_LIB_DIR})
add_library(cs50_lib STATIC ${CS50_LIB_DIR}/cs50.c)

# Link cs50 lib and the project
target_link_libraries(${NAME} cs50_lib)