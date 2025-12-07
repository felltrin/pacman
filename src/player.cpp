#include "player.h"
#include "constants.h"
#include <iostream>
#include <raylib.h>
#include <sstream>
#include <string>

Player::Player()
{

    Texture2D playerTextures[4];
    Initialize();
}

void Player::Initialize()
{
    for (int i = 0; i < 4; i++)
    {
        std::stringstream ss;
        int index = i + 1;
        ss << ASSETS_PATH "player_images/" << index << ".png";
        std::string fileName = ss.str();
        const char *c = fileName.c_str();
        Texture2D texture = LoadTexture(c);
        playerTextures[i] = texture;
    }
}

void Player::Print()
{
}

void Player::Draw()
{
    // for (int i = 0; i < 4; i++)
    // {
    //     Texture2D texture = playerTextures[i];
    //     DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);
    // }
    Texture2D texture = playerTextures[0];
    DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);
}
