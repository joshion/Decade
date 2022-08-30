cmake_minimum_required(VERSION 3.19)

project(dceg_3)

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE utility)

target_sources(${PROJECT_NAME} PRIVATE
    "main.cpp"
    "command.hpp"
    "command.cpp"
    "generalcommand.hpp"
    "generalcommand.cpp"
    "application.hpp"
    "application.cpp"
    "coreapplication.hpp"
    "coreapplication.cpp"
)

install(TARGETS ${PROJECT_NAME} RUNTIME)
