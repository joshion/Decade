cmake_minimum_required(VERSION 3.19)

project(1_factorymethod)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    "main.cpp"
    "app.cpp"
    "concreteapp.cpp"
    "product.cpp"
    "producta.cpp"
)

install(TARGETS ${PROJECT_NAME} RUNTIME)
