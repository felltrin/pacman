#include "constants.h"
#include "maze.h"
#include "player.h"
#include <iostream>
#include <raylib.h>

int main(int, char **)
{
    InitWindow(screenWidth, screenHeight, "PacMan");
    Maze maze = Maze();
    Player player = Player();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        maze.Draw();
        player.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
