#include "constants.h"
#include "maze.h"
#include "player.h"
#include <raylib.h>

int main(int, char **)
{
    InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "PacMan");
    Maze maze = Maze();
    maze.setMazeColor(RED);
    Player player = Player();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        maze.Draw();
        player.Draw();
        EndDrawing();

        player.checkPosition(player.getCenterXPos(), player.getCenterYPos(), maze.maze, player.getPlayerDirection());
        player.Update();
    }

    CloseWindow();
    return 0;
}
