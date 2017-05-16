cmake_minimum_required(VERSION 3.1)

project(Lessons)

set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

configure_file(
    "${PROJECT_SOURCE_DIR}/advance c++/framework/config.in.h"
    "${PROJECT_SOURCE_DIR}/advance c++/framework/config.h"
)

set (RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin/$<$<CONFIG>>)
set (LIBARAY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib/$<$<CONFIG>>)

message("${RUNTIME_OUTPUT_DIRECTORY}")
message("${LIBARAY_OUTPUT_DIRECTORY}")

include_directories("curses")

link_directories("curses/win32a")

# add the binary tree to the search path for include files  
# so that we will find TutorialConfig.h  
add_subdirectory("advance c++")