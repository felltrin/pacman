#include "maze.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Maze board setup correct", "[maze]")
{
    Maze maze = Maze();
    REQUIRE(maze.maze[0][0] == 6);
}
