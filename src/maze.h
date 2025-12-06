#pragma once
#include <vector>
#include <raylib.h>

class Maze
{
public:
    Maze();
    void Initialize();
    void Print();
    void Draw();

private:
    int pacDots;
    int energizers;
};