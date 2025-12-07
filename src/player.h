#pragma once
#include "raylib.h"
#include <vector>

class Player
{
  public:
    Player();
    void Initialize();
    void Print();
    void Draw();

  private:
    Texture2D playerTextures[4];
};