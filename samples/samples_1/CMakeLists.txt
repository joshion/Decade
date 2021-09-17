cmake_minimum_required(VERSION 3.19)

project(samples_1)

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE utility)

target_sources(${PROJECT_NAME} PUBLIC
    "main.cpp"
)

install(TARGETS ${PROJECT_NAME} RUNTIME)
