cmake_minimum_required(VERSION 3.19)

project(dynamic_library)

add_library(${PROJECT_NAME} SHARED)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    DC_DYNAMIC_LIBRARY_BUILD
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    utility
)

target_sources(${PROJECT_NAME} PRIVATE
    "dynamic_library.hpp"
    "dynamic_library.cpp"
)

install(TARGETS ${PROJECT_NAME} RUNTIME)
