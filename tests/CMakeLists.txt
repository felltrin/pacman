list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

find_package(Catch2 CONFIG REQUIRED)
add_executable(tests tests.cpp)


target_link_libraries(tests
    PRIVATE Catch2::Catch2WithMain
    PRIVATE PacManMainLib
)

include(CTest)
include(Catch)
catch_discover_tests(tests)
