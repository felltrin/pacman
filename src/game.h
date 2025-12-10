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
    /**
     * @brief Constructs an instance of the Game Singleton object.
     */
    static Game &instance();
    /**
     * @brief Retrieves the current value of the dereferenced flicker pointer.
     */
    bool &getFlicker();
    /**
     * @brief Sets the current value of the dereferenced flicker pointer.
     */
    void setFlicker(bool flicker);

  private:
    Game();                /**< Private constructor to ensure that there is only one instance of the class. */
    static Game instance_; /**< Instance varible to access methods and fields */
    bool *flicker_;        /**< This is in charge of holding the value of whether to flicker the energizer or not */
};
