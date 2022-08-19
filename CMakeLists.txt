cmake_minimum_required(VERSION 3.19)

project(Decade)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(DC_3RDLIBS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/3rdlibs)

add_subdirectory(examples)
add_subdirectory(src)
if (DC_ENABLE_UNITTEST)
    enable_testing()
    add_subdirectory(unittest)
endif(DC_ENABLE_UNITTEST)

