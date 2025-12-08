#pragma once
#include "raylib.h"

/**
 * @class Player
 * @brief Manages the loading and drawing of the player.
 *
 * The Player class is responsible for all the things that relate to the Player.
 * It contains the fields and functions to draw and animate the player on the screen.
 *
 */

class Player
{
  public:
    /**
     * @brief Constructs a Player object at the default starting position.
     */
    Player();
    /**
     * @brief Initializes the player textures array to download and fill the assets folder.
     */
    void Initialize();
    /**
     * @brief Draws the player according to which direction they pressed on their keyboard.
     */
    void Draw();
    /**
     * @brief Updates the counter to get the player animated.
     */
    void Update();
    /**
     * @brief Getter function to return the starting x position
     */
    float getXPos();
    /**
     * @brief Getter function to return the starting y position
     */
    float getYPos();
    /**
     * @brief Getter function to retreive the player's direction
     */
    int getPlayerDirection();
    /**
     * @brief Field that updates for the player to be animated.
     */
    int counter;

  private:
    Texture2D playerTextures[4]; /**< All the player textures for each direction the player is facing */
    float xPos;                  /**< The x-coordinate starting position */
    float yPos;                  /**< The y-coordinate starting position */
    int direction;               /**< The direction that the player is facing represented as an integer. */
};