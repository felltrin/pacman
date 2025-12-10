#include "game.h"
#include "maze.h"
#include "player.h"
#include <catch2/catch_test_macros.hpp>
#include <memory>

TEST_CASE("Maze constructor initializes correctly", "[Maze]")
{
    Maze maze = Maze();

    REQUIRE(maze.getNumCols() == 30);
    REQUIRE(maze.getNumRows() == 33);

    REQUIRE(maze.maze[0][0] == 6);
    REQUIRE(maze.maze[0][29] == 5);
    REQUIRE(maze.maze[32][0] == 7);
    REQUIRE(maze.maze[13][15] == 9);
}

TEST_CASE("Player constructor initializes correctly", "[Player]")
{
    Player player = Player();

    REQUIRE(player.getXPos() == 450.0f);
    REQUIRE(player.getYPos() == 663.0f);
    REQUIRE(player.getPlayerDirection() == 0);
    REQUIRE(player.counter == 0);
}

TEST_CASE("State should persist across calls to setFlicker()", "[Game]")
{
    Game sOne = Game::instance();
    Game sTwo = Game::instance();
    sOne.setFlicker(new bool(true));
    REQUIRE(sOne.getFlicker() == sTwo.getFlicker());
}

TEST_CASE("the instance method should return the same object", "[Game]")
{
    auto &sOne = Game::instance();
    auto &sTwo = Game::instance();
    REQUIRE(&sOne == &sTwo);
}
