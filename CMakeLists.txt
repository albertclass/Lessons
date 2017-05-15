cmake_minimum_required(VERSION 3.1)

project(Lessons)

set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

configure_file(
    "${PROJECT_SOURCE_DIR}/advance c++/framework/config.in.h"
    "${PROJECT_SOURCE_DIR}/advance c++/framework/config.h"
)

set (OUT_DIR ${CMAKE_BINARY_DIR}/Bin)
set (OBJ_DIR ${CMAKE_BINARY_DIR}/Obj)

message("${OUT_DIR}")
message("${OBJ_DIR}")

include_directories("curses")

link_directories("curses/win32a")

# add the binary tree to the search path for include files  
# so that we will find TutorialConfig.h  
add_subdirectory("advance c++")