project(APCS C)
cmake_minimum_required(VERSION 3.16)

enable_testing()

MACRO(SUBDIRLIST result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

MACRO(ADD_CHAPTER directory)
    subdirlist(SUBDIRS ${directory})

    foreach(NAME ${SUBDIRS})
        if(EXISTS "${directory}/${NAME}/${NAME}.c")
            add_executable(${NAME} ${directory}/${NAME}/${NAME}.c)
            target_link_libraries(${NAME} cs50_lib)
            target_link_libraries(${NAME} m)
#            add_test(
#                    NAME ${NAME}
#                    COMMAND check50 cs50/problems/2019/ap/${NAME}
#                    WORKING_DIRECTORY ${directory}/${NAME}
#            )
        else()
            message(WARNING "Skipping ${directory}/${NAME} because no C file file was found")
        endif()
    endforeach()
ENDMACRO()

MACRO(ADD_C_FILE file NAME)
    # Get file name
#    get_filename_component(NAME ${file} NAME)
    add_executable(${NAME} ${file})
    target_link_libraries(${NAME} cs50_lib)
    target_link_libraries(${NAME} m)
ENDMACRO()

# Set a variable for the CS50 library directory
set(CS50_LIB_DIR cs50)
include_directories(${CS50_LIB_DIR})
add_library(cs50_lib STATIC ${CS50_LIB_DIR}/cs50.c)

# Add the chapters
ADD_CHAPTER(${CMAKE_CURRENT_SOURCE_DIR}/chapter1)

ADD_CHAPTER(${CMAKE_CURRENT_SOURCE_DIR}/chapter2)
ADD_C_FILE(${CMAKE_CURRENT_SOURCE_DIR}/chapter2/friends/hello.c friends_hello)
ADD_C_FILE(${CMAKE_CURRENT_SOURCE_DIR}/chapter2/friends/fahrenheit.c friends_fahrenheit)
ADD_C_FILE(${CMAKE_CURRENT_SOURCE_DIR}/chapter2/friends/pennies.c friends_pennies)
