#include "game.h"

Game::Game()
{
    this->flicker_ = new bool(false);
    this->score_ = 0;
}

Game &Game::instance()
{
    static Game instance_;
    return instance_;
}

bool &Game::getFlicker()
{
    return *this->flicker_;
}

void Game::setFlicker(bool flicker)
{
    *this->flicker_ = flicker;
}

int Game::getScore() const
{
    return this->score_;
}

void Game::setScore(int score)
{
    this->score_ = score;
}

void Game::setMaze(int row, int col, int val)
{
    maze_[row][col] = val;
}

std::vector<int> Game::getMaze()
{
    std::vector<int> res;

    for (int i = 0; i < 33; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            res.push_back(maze_[i][j]);
        }
    }

    return res;
}
