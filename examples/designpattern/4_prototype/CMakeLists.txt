cmake_minimum_required(VERSION 3.19)

project(4_prototype)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    "main.cpp"
    "prototype.hpp"
    "prototype.cpp"
    "producta.hpp"
    "producta.cpp"
    "productb.hpp"
    "productb.cpp"
    "client.hpp"
    "client.cpp"
)

install(TARGETS ${PROJECT_NAME} RUNTIME)
