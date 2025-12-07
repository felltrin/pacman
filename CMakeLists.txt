cmake_minimum_required(VERSION 3.31.1)
project(letthisbefinal VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(./src)
add_subdirectory(./tests)


# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")
