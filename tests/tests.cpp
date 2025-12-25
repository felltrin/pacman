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
    int counter = player.getCounter();

    REQUIRE(player.getXPos() == 450.0f);
    REQUIRE(player.getYPos() == 663.0f);
    REQUIRE(player.getPlayerDirection() == 0);
    REQUIRE(counter == 0);
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

TEST_CASE("The checkPosition function is working as intended", "[Player]")
{
    Player p = Player();
    Maze m = Maze();
    p.setCenterXPos(13.0f);
    p.setCenterYPos(437.0f);
    p.setPlayerDirection(1);
    p.checkPosition();
    REQUIRE(p.turnsAllowed[0] == true);
    REQUIRE(p.turnsAllowed[3] == false);
}

TEST_CASE("The checkCollisions function works as intended", "[Player]")
{
    Player p = Player();
    Maze m = Maze();
    p.setXPos(790.0f);
    p.setYPos(663.0f);
    p.setCenterXPos(811.0f);
    p.setCenterYPos(687.0f);
    p.checkPosition();
    int curScore = p.checkCollisions();
    REQUIRE(curScore == 50);
    REQUIRE(curScore != 10);
}
