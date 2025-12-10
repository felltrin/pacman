#include "game.h"

Game::Game()
{
    flicker_ = new bool(false);
}

Game &Game::instance()
{
    static Game instance_;
    return instance_;
}

bool &Game::getFlicker()
{
    return *flicker_;
}

void Game::setFlicker(bool flicker)
{
    *flicker_ = flicker;
}
