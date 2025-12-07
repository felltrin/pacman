#include "maze.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Maze contstructor initializes correctly", "[Maze]")
{
    Maze maze = Maze();

    REQUIRE(maze.getNumCols() == 30);
    REQUIRE(maze.getNumRows() == 33);

    REQUIRE(maze.maze[0][0] == 6);
    REQUIRE(maze.maze[0][29] == 5);
    REQUIRE(maze.maze[32][0] == 7);
    REQUIRE(maze.maze[13][15] == 9);
}
