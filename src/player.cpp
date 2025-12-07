#include "player.h"
#include "constants.h"
#include <cmath>
#include <iostream>
#include <raylib.h>
#include <sstream>
#include <string>

Player::Player()
{

    Texture2D playerTextures[4];
    xPos = 450.0f;
    yPos = 663.0f;
    direction = 0;
    counter = 0;
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
    Texture2D texture;
    double value;
    int index;

    if (direction == 0)
    {
        value = (double)(counter / 5);
        index = static_cast<int>(floor(value));
        texture = playerTextures[index];
        DrawTextureEx(texture, {xPos, yPos}, 0.0f, 0.09f, WHITE);
    }
    else if (direction == 1)
    {
        value = (double)(counter / 5);
        index = static_cast<int>(floor(value));
        texture = playerTextures[index];
        DrawTextureEx(texture, {xPos, yPos}, 180.0f, 0.09f, WHITE);
    }
    else if (direction == 2)
    {
        value = (double)(counter / 5);
        index = static_cast<int>(floor(value));
        texture = playerTextures[index];
        DrawTextureEx(texture, {xPos, yPos}, 90.0f, 0.09f, WHITE);
    }
    else if (direction == 3)
    {
        value = (double)(counter / 5);
        index = static_cast<int>(floor(value));
        texture = playerTextures[index];
        DrawTextureEx(texture, {xPos, yPos}, 270.0f, 0.09f, WHITE);
    }
}

void Player::Update()
{
    if (counter < 19)
    {
        counter++;
    }
    else
    {
        counter = 0;
    }
}
