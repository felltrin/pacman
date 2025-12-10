#include "player.h"
#include "constants.h"
#include "game.h"
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
        DrawTextureEx(texture, {xPos + 45.0f, yPos + 45.0f}, 180.0f, 0.09f, WHITE);
    }
    else if (direction == 2)
    {
        value = (double)(counter / 5);
        index = static_cast<int>(floor(value));
        texture = playerTextures[index];
        DrawTextureEx(texture, {xPos, yPos + 45.0f}, -90.0f, 0.09f, WHITE);
    }
    else if (direction == 3)
    {
        value = (double)(counter / 5);
        index = static_cast<int>(floor(value));
        texture = playerTextures[index];
        DrawTextureEx(texture, {xPos + 45.0f, yPos}, 90.0f, 0.09f, WHITE);
    }
}

void Player::Update()
{
    if (counter < 19)
    {
        counter++;
        if (counter > 3)
        {
            Game::instance().setFlicker(!Game::instance().getFlicker());
        }
    }
    else
    {
        counter = 0;
        Game::instance().setFlicker(new bool(true));
    }
    if (IsKeyDown(KEY_D))
        direction = 0;
    else if (IsKeyDown(KEY_A))
        direction = 1;
    else if (IsKeyDown(KEY_W))
        direction = 2;
    else if (IsKeyDown(KEY_S))
        direction = 3;
}

float Player::getXPos()
{
    return xPos;
}

float Player::getYPos()
{
    return yPos;
}

int Player::getPlayerDirection()
{
    return direction;
}
