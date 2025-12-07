project(PacManMain)
file (GLOB_RECURSE GAME_HEADERS CONFIGURE_DEPENDS "./*.h")
file (GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "./*.cpp")

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

find_package(raylib CONFIG REQUIRED)
add_executable(letthisbefinal main.cpp ${GAME_SOURCES})

target_link_libraries(letthisbefinal PRIVATE raylib)