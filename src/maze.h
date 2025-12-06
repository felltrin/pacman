#pragma once
#include <cmath>
#include <iostream>
#include <raylib.h>
#include <vector>

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