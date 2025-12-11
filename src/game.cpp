#include "game.h"

Game::Game()
{
    this->flicker_ = new bool(false);
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
