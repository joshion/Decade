cmake_minimum_required(VERSION 3.19)

add_library(catch2 INTERFACE)
target_include_directories(catch2 INTERFACE ${DC_3RDLIBS_ROOT}/catch2/v2.13.7/single_include)

add_subdirectory(utility_test)
