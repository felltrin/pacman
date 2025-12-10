#pragma once

/**
 * @class Game
 * @brief Handles the variables of the game state
 *
 * The Game class is a Singleton class that stores variables that are
 * used throughout the game.
 *
 */
class Game
{
  public:
    static Game &instance();
    bool &getFlicker();
    void setFlicker(bool flicker);

  private:
    Game();
    static Game instance_;
    bool *flicker_;
};
