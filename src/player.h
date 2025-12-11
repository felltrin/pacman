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
     * @brief Sets the player's direction
     */
    void setPlayerDirection(int d);
    /**
     * @brief Setter function to set the player's x position
     */
    void setXPos(float x);
    /**
     * @brief Setter function to set the player's y position
     */
    void setYPos(float y);
    /**
     * @brief Setter function to set the player's center x position
     */
    void setCenterXPos(float x);
    /**
     * @brief Setter function to set the player's center y position
     */
    void setCenterYPos(float y);
    /**
     * @brief Getter function to retreive the player's center x position
     */
    float getCenterXPos();
    /**
     * @brief Getter function to retreive the player's center y position
     */
    float getCenterYPos();
    /**
     * @brief A helper function to set the booleans in turns into turnsAllowed for collision detection
     */
    void setTurnsAllowed(bool turns[4]);
    /**
     * @brief Checks the current player position to their surroundings to figure out which directions the player can
     * turn
     */
    void checkPosition(int level[33][30]);
    /**
     * @brief Moves the player by player speed in the direction they want to go and are able to
     */
    Vector2 movePlayer(float playX, float playY);
    /**
     * @brief Getter function to retreive the counter variable value
     */
    int getCounter();
    /**
     * @brief An array to keep track of where the player is allowed to go
     */
    bool turnsAllowed[4];
    /**
     * @brief Checks if the current player has interacted with the pacdots
     */
    void checkCollisions(int level[33][30]);

  private:
    Texture2D playerTextures[4]; /**< All the player textures for each direction the player is facing */
    float xPos;                  /**< The x-coordinate starting position */
    float yPos;                  /**< The y-coordinate starting position */
    int direction;               /**< The direction that the player is facing represented as an integer. */
    float centerX;               /**< The center x-coordinate of the player's current position */
    float centerY;               /**< The center y-coordinate of the player's current position */
    int directionCommand;        /**< This handles joystick-like player input with delaying the turns */
    int playerSpeed;             /**< The speed to which the player travels in */
    int counter;                 /**< Field that updates for the player to be animated. */
};