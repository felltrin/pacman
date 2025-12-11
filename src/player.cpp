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

    this->xPos = 450.0f;
    this->yPos = 663.0f;
    this->centerX = this->xPos + 23.0f;
    this->centerY = this->yPos + 24.0f;
    this->direction = 0;
    this->directionCommand = 0;
    this->counter = 0;
    this->playerSpeed = 2;
    Initialize();
}

void Player::Initialize()
{
    for (int i = 0; i < 4; i++)
    {
        this->turnsAllowed[i] = false;
        // loading in the player textures
        std::stringstream ss;
        int index = i + 1;
        ss << ASSETS_PATH "player_images/" << index << ".png";
        std::string fileName = ss.str();
        const char *c = fileName.c_str();
        Texture2D texture = LoadTexture(c);
        this->playerTextures[i] = texture;
    }
}

void Player::Draw()
{
    Texture2D texture;
    double value;
    int index;
    float x, y, rotation;
    float scaling = 0.09f;

    if (direction == 0)
    {
        value = (double)(this->counter / 5);
        index = static_cast<int>(floor(value));
        texture = this->playerTextures[index];
        x = this->getXPos();
        y = this->getYPos();
        rotation = 0.0f;
        DrawTextureEx(texture, {x, y}, rotation, scaling, WHITE);
    }
    else if (direction == 1)
    {
        value = (double)(this->counter / 5);
        index = static_cast<int>(floor(value));
        texture = this->playerTextures[index];
        x = this->getXPos() + 45.0f;
        y = this->getYPos() + 45.0f;
        rotation = 180.0f;
        DrawTextureEx(texture, {x, y}, rotation, scaling, WHITE);
    }
    else if (direction == 2)
    {
        value = (double)(this->counter / 5);
        index = static_cast<int>(floor(value));
        texture = this->playerTextures[index];
        x = this->getXPos();
        y = this->getYPos() + 45.0f;
        rotation = -90.0f;
        DrawTextureEx(texture, {x, y}, rotation, scaling, WHITE);
    }
    else if (direction == 3)
    {
        value = (double)(this->counter / 5);
        index = static_cast<int>(floor(value));
        texture = this->playerTextures[index];
        x = this->getXPos() + 45.0f;
        y = this->getYPos();
        rotation = 90.0f;
        DrawTextureEx(texture, {x, y}, rotation, scaling, WHITE);
    }
}

void Player::Update()
{
    float x = this->getXPos();
    float y = this->getYPos();
    this->setCenterXPos(x + 23.0f);
    this->setCenterYPos(y + 24.0f);

    if (this->counter < 19)
    {
        this->counter++;
        if (this->counter > 3)
        {
            Game::instance().setFlicker(!Game::instance().getFlicker());
        }
    }
    else
    {
        this->counter = 0;
        Game::instance().setFlicker(new bool(true));
    }

    Vector2 newPos = this->movePlayer(this->getXPos(), this->getYPos());
    this->setXPos(newPos.x);
    this->setYPos(newPos.y);

    if (IsKeyDown(KEY_D))
        this->directionCommand = 0;
    if (IsKeyDown(KEY_A))
        this->directionCommand = 1;
    if (IsKeyDown(KEY_W))
        this->directionCommand = 2;
    if (IsKeyDown(KEY_S))
        this->directionCommand = 3;
    if (IsKeyUp(KEY_D) && this->directionCommand == 0)
        this->directionCommand = this->direction;
    if (IsKeyUp(KEY_A) && this->directionCommand == 1)
        this->directionCommand = this->direction;
    if (IsKeyUp(KEY_W) && this->directionCommand == 2)
        this->directionCommand = this->direction;
    if (IsKeyUp(KEY_S) && this->directionCommand == 3)
        this->directionCommand = this->direction;

    for (int i = 0; i < 4; i++)
    {
        if (this->directionCommand == i && this->turnsAllowed[i])
        {
            this->direction = i;
        }
    }

    if (Player::getXPos() > 900.0f)
    {
        this->setXPos(-47.0f);
    }
    else if (this->getXPos() < -50.0f)
    {
        this->setXPos(897.0f);
    }
}

float Player::getXPos()
{
    return this->xPos;
}

float Player::getYPos()
{
    return this->yPos;
}

int Player::getPlayerDirection()
{
    return this->direction;
}

void Player::setXPos(float x)
{
    this->xPos = x;
}

void Player::setYPos(float y)
{
    this->yPos = y;
}

void Player::setCenterXPos(float x)
{
    this->centerX = x;
};

void Player::setCenterYPos(float y)
{
    this->centerY = y;
};

float Player::getCenterXPos()
{
    return this->centerX;
};

float Player::getCenterYPos()
{
    return this->centerY;
};

void Player::checkPosition(int level[33][30])
{
    static bool turns[4] = {false, false, false, false};

    float numberOne = std::floor((UI::SCREEN_HEIGHT - 50) / 32);
    float numberTwo = std::floor(UI::SCREEN_WIDTH / 30);
    float numberThree = 15.0f;

    if (std::floor(this->getCenterXPos() / 30) < 29)
    {
        if (this->direction == 0)
        {
            int row = std::floor(this->getCenterYPos() / numberOne);
            int column = std::floor((this->getCenterXPos() - numberThree) / numberTwo);
            if (level[row][column] < 3)
            {
                turns[1] = true;
            }
            else
            {
                turns[1] = false;
            }
        }
        if (this->direction == 1)
        {
            int row = std::floor(this->getCenterYPos() / numberOne);
            int column = std::floor((this->getCenterXPos() + numberThree) / numberTwo);
            if (level[row][column] < 3)
            {
                turns[0] = true;
            }
            else
            {
                turns[0] = false;
            }
        }
        if (this->direction == 2)
        {
            int row = std::floor((this->getCenterYPos() + numberThree) / numberOne);
            int column = std::floor(this->getCenterXPos() / numberTwo);
            if (level[row][column] < 3)
            {
                turns[3] = true;
            }
            else
            {
                turns[3] = false;
            }
        }
        if (this->direction == 3)
        {
            int row = std::floor((this->getCenterYPos() - numberThree) / numberOne);
            int column = std::floor(this->getCenterXPos() / numberTwo);
            if (level[row][column] < 3)
            {
                turns[2] = true;
            }
            else
            {
                turns[2] = false;
            }
        }

        if (this->direction == 2 || this->direction == 3)
        {
            int row, column;
            if (((int)this->centerX % (int)numberTwo >= 12) && ((int)this->centerX % (int)numberTwo <= 18))
            {
                row = std::floor((this->centerY + numberThree) / numberOne);
                column = std::floor(this->centerX / numberTwo);
                if (level[row][column] < 3)
                {
                    turns[3] = true;
                }
                else
                {
                    turns[3] = false;
                }
                row = std::floor((this->centerY - numberThree) / numberOne);
                column = std::floor(this->centerX / numberTwo);
                if (level[row][column] < 3)
                {
                    turns[2] = true;
                }
                else
                {
                    turns[2] = false;
                }
            }
            if (((int)this->centerY % (int)numberOne >= 12) && ((int)this->centerY % (int)numberOne <= 18))
            {
                row = std::floor(this->centerY / numberOne);
                column = std::floor((this->centerX - numberTwo) / numberTwo);
                if (level[row][column] < 3)
                {
                    turns[1] = true;
                }
                else
                {
                    turns[1] = false;
                }
                row = std::floor(this->centerY / numberOne);
                column = std::floor((this->centerX + numberTwo) / numberTwo);
                if (level[row][column] < 3)
                {
                    turns[0] = true;
                }
                else
                {
                    turns[0] = false;
                }
            }
        }

        if (this->direction == 0 || this->direction == 1)
        {
            int row, column;
            if (((int)this->centerX % (int)numberTwo >= 12) && ((int)this->centerX % (int)numberTwo <= 18))
            {
                row = std::floor((this->centerY + numberOne) / numberOne);
                column = std::floor(this->centerX / numberTwo);
                if (level[row][column] < 3)
                {
                    turns[3] = true;
                }
                else
                {
                    turns[3] = false;
                }
                row = std::floor((this->centerY - numberOne) / numberOne);
                column = std::floor(this->centerX / numberTwo);
                if (level[row][column] < 3)
                {
                    turns[2] = true;
                }
                else
                {
                    turns[2] = false;
                }
            }
            if (((int)this->centerY % (int)numberOne >= 12) && ((int)this->centerY % (int)numberOne <= 18))
            {
                row = std::floor(this->centerY / numberOne);
                column = std::floor((this->centerX - numberThree) / numberTwo);
                if (level[row][column] < 3)
                {
                    turns[1] = true;
                }
                else if (row != 15 && column != -1)
                {
                    turns[1] = false;
                }
                row = std::floor(centerY / numberOne);
                column = std::floor((centerX + numberThree) / numberTwo);
                if (level[row][column] < 3)
                {
                    turns[0] = true;
                }
                else if (row != 15 && column != -1)
                {
                    turns[0] = false;
                }
            }
        }
    }
    else
    {
        turns[0] = true;
        turns[1] = true;
    }
    this->setTurnsAllowed(turns);
}

void Player::setTurnsAllowed(bool turns[4])
{
    for (int i = 0; i < 4; i++)
    {
        this->turnsAllowed[i] = turns[i];
    }
}

Vector2 Player::movePlayer(float playX, float playY)
{
    if (this->direction == 0 && this->turnsAllowed[0])
    {
        playX += this->playerSpeed;
    }
    else if (this->direction == 1 && this->turnsAllowed[1])
    {
        playX -= this->playerSpeed;
    }
    if (this->direction == 2 && this->turnsAllowed[2])
    {
        playY -= this->playerSpeed;
    }
    else if (this->direction == 3 && this->turnsAllowed[3])
    {
        playY += this->playerSpeed;
    }
    return {playX, playY};
}

int Player::getCounter()
{
    return this->counter;
}

void Player::setPlayerDirection(int d)
{
    this->direction = d;
}
