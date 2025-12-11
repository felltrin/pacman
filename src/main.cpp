#include "constants.h"
#include "game.h"
#include "maze.h"
#include "player.h"
#include <iostream>
#include <raylib.h>
#include <sstream>
#include <string>

int main(int, char **)
{
    InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "PacMan");

    Font font = LoadFont(ASSETS_PATH "sprite_fonts/pixantiqua.png");

    const int spacing = 4;

    Vector2 position;

    Color color = WHITE;

    Maze maze = Maze();
    maze.setMazeColor(RED);
    Player player = Player();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        player.checkPosition(maze.maze);
        player.Update();
        player.checkCollisions(maze.maze);

        std::stringstream ss;
        ss << "Score: " << Game::instance().getScore();
        std::string score = ss.str();
        const char *c = score.c_str();

        const char *message = c;

        position = {UI::SCREEN_WIDTH / 2.0f -
                        MeasureTextEx(font, message, font.baseSize * 2.0f, (float)spacing).x / 2.0f,
                    860.0f + font.baseSize + 45.0f};

        BeginDrawing();
        ClearBackground(BLACK);
        maze.Draw();
        player.Draw();
        DrawTextEx(font, message, position, font.baseSize * 2.0f, (float)spacing, color);
        EndDrawing();
        ss.clear();
    }

    UnloadFont(font);
    CloseWindow();
    return 0;
}
