#include <iostream>
#include <raylib.h>

//! Call this for the main game loop to initialize the game
int main(int, char **)
{
    InitWindow(600, 800, "PacMan");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello, from raylib", 10, 10, 20, BLACK);

        DrawFPS(10, 40);
        EndDrawing();
    }

    CloseWindow();
    std::cout << "Hello, from pacman!\n";
    return 0;
}
