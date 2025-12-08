#include "maze.h"
#include "constants.h"
#include "levels.h"
#include <raylib.h>

Maze::Maze()
{
    numRows = 33;
    numCols = 30;
    mazeColor = DARKBLUE;
    Initialize();
}

void Maze::Initialize()
{
    int board[33][30] = {{6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
                         {3, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 3},
                         {3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3},
                         {3, 3, 1, 6, 4, 4, 5, 1, 6, 4, 4, 4, 5, 1, 3, 3, 1, 6, 4, 4, 4, 5, 1, 6, 4, 4, 5, 1, 3, 3},
                         {3, 3, 2, 3, 0, 0, 3, 1, 3, 0, 0, 0, 3, 1, 3, 3, 1, 3, 0, 0, 0, 3, 1, 3, 0, 0, 3, 2, 3, 3},
                         {3, 3, 1, 7, 4, 4, 8, 1, 7, 4, 4, 4, 8, 1, 7, 8, 1, 7, 4, 4, 4, 8, 1, 7, 4, 4, 8, 1, 3, 3},
                         {3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3},
                         {3, 3, 1, 6, 4, 4, 5, 1, 6, 5, 1, 6, 4, 4, 4, 4, 4, 4, 5, 1, 6, 5, 1, 6, 4, 4, 5, 1, 3, 3},
                         {3, 3, 1, 7, 4, 4, 8, 1, 3, 3, 1, 7, 4, 4, 5, 6, 4, 4, 8, 1, 3, 3, 1, 7, 4, 4, 8, 1, 3, 3},
                         {3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3},
                         {3, 7, 4, 4, 4, 4, 5, 1, 3, 7, 4, 4, 5, 0, 3, 3, 0, 6, 4, 4, 8, 3, 1, 6, 4, 4, 4, 4, 8, 3},
                         {3, 0, 0, 0, 0, 0, 3, 1, 3, 6, 4, 4, 8, 0, 7, 8, 0, 7, 4, 4, 5, 3, 1, 3, 0, 0, 0, 0, 0, 3},
                         {3, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 3},
                         {8, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 6, 4, 4, 9, 9, 4, 4, 5, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 7},
                         {4, 4, 4, 4, 4, 4, 8, 1, 7, 8, 0, 3, 0, 0, 0, 0, 0, 0, 3, 0, 7, 8, 1, 7, 4, 4, 4, 4, 4, 4},
                         {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                         {4, 4, 4, 4, 4, 4, 5, 1, 6, 5, 0, 3, 0, 0, 0, 0, 0, 0, 3, 0, 6, 5, 1, 6, 4, 4, 4, 4, 4, 4},
                         {5, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 7, 4, 4, 4, 4, 4, 4, 8, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 6},
                         {3, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 3},
                         {3, 0, 0, 0, 0, 0, 3, 1, 3, 3, 0, 6, 4, 4, 4, 4, 4, 4, 5, 0, 3, 3, 1, 3, 0, 0, 0, 0, 0, 3},
                         {3, 6, 4, 4, 4, 4, 8, 1, 7, 8, 0, 7, 4, 4, 5, 6, 4, 4, 8, 0, 7, 8, 1, 7, 4, 4, 4, 4, 5, 3},
                         {3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3},
                         {3, 3, 1, 6, 4, 4, 5, 1, 6, 4, 4, 4, 5, 1, 3, 3, 1, 6, 4, 4, 4, 5, 1, 6, 4, 4, 5, 1, 3, 3},
                         {3, 3, 1, 7, 4, 5, 3, 1, 7, 4, 4, 4, 8, 1, 7, 8, 1, 7, 4, 4, 4, 8, 1, 3, 6, 4, 8, 1, 3, 3},
                         {3, 3, 2, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 2, 3, 3},
                         {3, 7, 4, 5, 1, 3, 3, 1, 6, 5, 1, 6, 4, 4, 4, 4, 4, 4, 5, 1, 6, 5, 1, 3, 3, 1, 6, 4, 8, 3},
                         {3, 6, 4, 8, 1, 7, 8, 1, 3, 3, 1, 7, 4, 4, 5, 6, 4, 4, 8, 1, 3, 3, 1, 7, 8, 1, 7, 4, 5, 3},
                         {3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3},
                         {3, 3, 1, 6, 4, 4, 4, 4, 8, 7, 4, 4, 5, 1, 3, 3, 1, 6, 4, 4, 8, 7, 4, 4, 4, 4, 5, 1, 3, 3},
                         {3, 3, 1, 7, 4, 4, 4, 4, 4, 4, 4, 4, 8, 1, 7, 8, 1, 7, 4, 4, 4, 4, 4, 4, 4, 4, 8, 1, 3, 3},
                         {3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3},
                         {3, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 3},
                         {7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8}};

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            maze[i][j] = board[i][j];
        }
    }
}

void Maze::Print()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Maze::Draw()
{
    int numberOne = std::floor((UI::SCREEN_HEIGHT - 50) / 32);
    int numberTwo = std::floor(UI::SCREEN_WIDTH / 30);

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            Vector2 center;
            Vector2 startPos;
            Vector2 endPos;

            Rectangle rect;
            float radiusX;
            float radiusY;
            float startAngleDeg;
            float endAngleDeg;

            switch (maze[i][j])
            {
            case 1: {
                center = {(float)(j * numberTwo + (0.5 * numberTwo)), (float)(i * numberOne + (0.5 * numberOne))};
                DrawCircleV(center, 4, RAYWHITE);
                break;
            }

            case 2: {
                // if (!flicker)
                // {
                center = {(float)(j * numberTwo + (0.5 * numberTwo)), (float)(i * numberOne + (0.5 * numberOne))};
                DrawCircleV(center, 10, RAYWHITE);
                // }
                break;
            }

            case 3: {
                center = {(float)(j * numberTwo + (0.5 * numberTwo)), (float)(i * numberOne + (0.5 * numberOne))};
                startPos = {center.x, (float)(i * numberOne)};
                endPos = {center.x, (float)(i * numberOne + numberOne)};
                DrawLineEx(startPos, endPos, 3, mazeColor);
                break;
            }

            case 4: {
                center = {(float)(j * numberTwo + (0.5 * numberTwo)), (float)(i * numberOne + (0.5 * numberOne))};
                startPos = {(float)(j * numberTwo), center.y};
                endPos = {(float)(j * numberTwo + numberTwo), center.y};
                DrawLineEx(startPos, endPos, 3, mazeColor);
                break;
            }

            case 5: {
                // Calculate center and radii from the rectangle
                rect = {(float)((j * numberTwo - (numberTwo * 0.4)) - 2), (float)(i * numberOne + (0.5f * numberOne)),
                        (float)numberTwo, (float)numberOne};

                center = {(rect.x + rect.width / 2) - 1, (rect.y + rect.height / 2) + 1};
                radiusX = rect.width / 2.0f;
                radiusY = rect.height / 2.0f;

                startAngleDeg = (3 * (PI / 2.0f)) * RAD2DEG;
                endAngleDeg = (PI * 2.0f) * RAD2DEG;

                DrawRing({center.x, center.y}, 13, 16, startAngleDeg, endAngleDeg,
                         6000, // segments (increase for smoother arc)
                         mazeColor);
                break;
            }

            case 6: {
                // Calculate center and radii from the rectangle
                rect = {(float)((j * numberTwo + (numberTwo * 0.5))), (float)(i * numberOne + (0.5f * numberOne)),
                        (float)numberTwo, (float)numberOne};

                center = {rect.x + rect.width / 2, (rect.y + rect.height / 2) + 1};
                radiusX = rect.width / 2.0f;
                radiusY = rect.height / 2.0f;

                startAngleDeg = (PI)*RAD2DEG;
                endAngleDeg = (3 * (PI / 2.0f)) * RAD2DEG;

                DrawRing({center.x, center.y}, 13, 16, startAngleDeg, endAngleDeg,
                         600, // segments (increase for smoother arc)
                         mazeColor);
                break;
            }
            case 7: {
                // Calculate center and radii from the rectangle
                rect = {(float)((j * numberTwo + (numberTwo * 0.5f))), (float)(i * numberOne - (0.4f * numberOne)),
                        (float)numberTwo, (float)numberOne};

                center = {rect.x + rect.width / 2, (rect.y + rect.height / 2) - 3};
                radiusX = rect.width / 2.0f;
                radiusY = rect.height / 2.0f;

                startAngleDeg = (PI / 2.0f) * RAD2DEG;
                endAngleDeg = ((PI)*RAD2DEG) + 1;

                DrawRing({center.x, center.y}, 13, 16, startAngleDeg, endAngleDeg,
                         600, // segments (increase for smoother arc)
                         mazeColor);
                break;
            }
            case 8: {
                // Calculate center and radii from the rectangle
                rect = {(float)((j * numberTwo - (numberTwo * 0.4f)) - 2), (float)(i * numberOne - (0.4f * numberOne)),
                        (float)numberTwo, (float)numberOne};

                center = {(rect.x + rect.width / 2) - 1, (rect.y + rect.height / 2) - 3};
                radiusX = rect.width / 2.0f;
                radiusY = rect.height / 2.0f;

                startAngleDeg = 0.0f;
                endAngleDeg = (PI / 2.0f) * RAD2DEG;

                DrawRing({center.x, center.y}, 13, 16, startAngleDeg, endAngleDeg,
                         600, // segments (increase for smoother arc)
                         mazeColor);
                break;
            }
            case 9: {
                center = {(float)(j * numberTwo + (0.5 * numberTwo)), (float)(i * numberOne + (0.5 * numberOne))};
                startPos = {(float)(j * numberTwo), center.y};
                endPos = {(float)(j * numberTwo + numberTwo), center.y};
                DrawLineEx(startPos, endPos, 3, RAYWHITE);
                break;
            }
            default: {
                std::cout << "lol!" << std::endl;
                break;
            }
            }
        }
    }
}

int Maze::getNumCols()
{
    return numCols;
}

int Maze::getNumRows()
{
    return numRows;
}

Color Maze::getMazeColor()
{
    return mazeColor;
}

void Maze::setMazeColor(Color color)
{
    mazeColor = color;
}
