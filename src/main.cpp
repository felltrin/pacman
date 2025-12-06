#include <iostream>
#include <raylib.h>
#include "maze.h"
#include "constants.h"

//!
//! Call this for the main game loop to initialize the game
//!
int main(int, char **)
{
    InitWindow(screenWidth, screenHeight, "PacMan");

    //!
    //! This is the initial position of the player on the screen
    //!
    Vector2 ballPosition = {(float)500 / 2, (float)620 / 2};
    Maze maze = Maze();
    // maze.Print();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        //!
        //! This is capture the player inputs + updates the player position
        //!
        if (IsKeyDown(KEY_RIGHT))
            ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT))
            ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP))
            ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN))
            ballPosition.y += 2.0f;

        BeginDrawing();
        ClearBackground(BLACK);
        maze.Draw();

        // DrawText("Hello, from raylib", 10, 10, 20, RAYWHITE);
        //!
        //! Drawing the player
        //!
        // DrawCircleV(ballPosition, 50, YELLOW);
        // DrawFPS(10, 40);
        EndDrawing();
    }

    CloseWindow();
    std::cout << "Hello, from pacman!\n";
    return 0;
}
