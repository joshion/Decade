cmake_minimum_required(VERSION 3.19)

project(executable)

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE
    dynamic_library
    utility
)

target_sources(${PROJECT_NAME} PRIVATE
    "main.cpp"
)

install(TARGETS ${PROJECT_NAME} RUNTIME)
