cmake_minimum_required(VERSION 3.31.1)
project(letthisbefinal VERSION 0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

find_package(raylib CONFIG REQUIRED)
add_executable(letthisbefinal src/main.cpp)
find_package(Catch2 CONFIG REQUIRED)
add_executable(tests tests/tests.cpp)

target_link_libraries(letthisbefinal PRIVATE raylib)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)