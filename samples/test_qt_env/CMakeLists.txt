cmake_minimum_required(VERSION 3.19)

project(test_qt_env)

set(Qt5_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5")
set(Qt5Core_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Core")
set(Qt5Gui_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Gui")
set(Qt5Widgets_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Widgets")

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PUBLIC
    "main.cpp"
)

target_link_libraries("${PROJECT_NAME}" PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)

install(TARGETS ${PROJECT_NAME} RUNTIME)
