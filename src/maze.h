#pragma once
#include <vector>
#include <raylib.h>
#include <cmath>
#include <iostream>

class Maze
{
public:
    Maze();
    void Initialize();
    void Print();
    void Draw();
    int maze[33][30];

private:
    int numRows;
    int numCols;
};