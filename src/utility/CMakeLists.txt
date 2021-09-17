cmake_minimum_required(VERSION 3.19)

# Header only utilities libraries

project(utility)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
