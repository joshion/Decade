cmake_minimum_required(VERSION 3.19)

project(samples)

if(DC_ENABLE_QT)
    add_subdirectory(test_qt_env)
endif()
add_subdirectory(dceg_1)
add_subdirectory(dceg_2)
add_subdirectory(dceg_3)
add_subdirectory(designpattern)