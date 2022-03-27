cmake_minimum_required(VERSION 3.19)

project(samples)

if(WIN32)
    add_subdirectory(test_qt_env)
endif()
add_subdirectory(samples_1)
