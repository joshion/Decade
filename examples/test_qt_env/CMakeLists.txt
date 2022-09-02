cmake_minimum_required(VERSION 3.19)

project(test_qt_env)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PUBLIC
    "main.cpp"
)

target_link_libraries("${PROJECT_NAME}" PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)

install(TARGETS ${PROJECT_NAME} RUNTIME)
