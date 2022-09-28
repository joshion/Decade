cmake_minimum_required(VERSION 3.19)

project(2_abstractfactory)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    "main.cpp"
    "client.hpp"
    "client.cpp"
    "abstractfactory.hpp"
    "abstractfactory.cpp"
    "keyboard.hpp"
    "keyboard.cpp"
    "mouse.hpp"
    "mouse.cpp"
    "logifactory.hpp"
    "logifactory.cpp"
    "logikeyboard.hpp"
    "logikeyboard.cpp"
    "logimouse.hpp"
    "logimouse.cpp"
)

install(TARGETS ${PROJECT_NAME} RUNTIME)
