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

    foreach(SUBDIR ${SUBDIRS})
        if(EXISTS "${directory}/${SUBDIR}/${SUBDIR}.c")
            add_executable(${SUBDIR} ${directory}/${SUBDIR}/${SUBDIR}.c)
            target_link_libraries(${SUBDIR} cs50_lib)
        else()
            message(WARNING "Skipping ${directory}/${SUBDIR} because no C file file was found")
        endif()
    endforeach()
ENDMACRO()

#ADD_ALL_SUBDIRECTORIES(chapter1)
project(APCS C)
cmake_minimum_required(VERSION 3.17)

# Set a variable for the CS50 library directory
set(CS50_LIB_DIR cs50)
include_directories(${CS50_LIB_DIR})
add_library(cs50_lib STATIC ${CS50_LIB_DIR}/cs50.c)

ADD_CHAPTER(${CMAKE_CURRENT_SOURCE_DIR}/chapter1)
