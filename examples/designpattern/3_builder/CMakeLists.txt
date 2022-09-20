cmake_minimum_required(VERSION 3.19)

project(3_builder)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    "main.cpp"
)

install(TARGETS ${PROJECT_NAME} RUNTIME)
