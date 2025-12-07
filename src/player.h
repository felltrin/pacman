#pragma once
#include "raylib.h"

/**
 * @file player.h
 * @brief Contains the information related to drawing the player and player logic.
 */

class Player
{
  public:
    /**
     * @brief Constructs a Player object at the default starting position.
     */
    Player();
    void Initialize();
    void Print();
    void Draw();
    void Update();
    int counter;

  private:
    Texture2D playerTextures[4];
    float xPos;
    float yPos;
    int direction;
};