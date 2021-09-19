cmake_minimum_required(VERSION 3.19)

project(utility_test)

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE utility)
target_link_libraries(${PROJECT_NAME} PRIVATE catch2)

target_sources(${PROJECT_NAME} PUBLIC
    "main.cpp"
)

install(TARGETS ${PROJECT_NAME} RUNTIME)

# add_test(NAME ${PROJECT_NAME} COMMAND utility_test)
add_test(NAME ${PROJECT_NAME} COMMAND utility_test WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX})
