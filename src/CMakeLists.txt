project(PacManMainLib)
file (GLOB_RECURSE GAME_HEADERS CONFIGURE_DEPENDS "./*.h")
file (GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "./*.cpp")

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

add_library(${PROJECT_NAME} STATIC
	${GAME_HEADERS}
	${GAME_SOURCES}
)

target_include_directories (${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)


find_package(raylib CONFIG REQUIRED)
add_executable(letthisbefinal main.cpp ${GAME_SOURCES})

target_link_libraries(letthisbefinal PRIVATE raylib)
target_link_libraries(PacManMainLib PRIVATE raylib)
