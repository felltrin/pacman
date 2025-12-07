#pragma once
#include "raylib.h"
#include <cmath>
#include <iostream>
#include <vector>

/**
 * @class Maze
 * @brief Manages the loading and drawing the maze.
 *
 * The Maze class abstracts the maze loading drawing away. It is in charge
 * of selecting and loading the right level depending on the user.
 *
 */
class Maze
{
  public:
    /**
     * @brief Constructs a Maze instance for the generic level.
     */
    Maze();
    /**
     * @brief Initilaizes a Maze instance for the specified level.
     */
    void Initialize();
    /**
     * @brief Prints the current maze grid layout.
     */
    void Print();
    /**
     * @brief Draws the maze to how the grid was initilized.
     */
    void Draw();
    /**
     * @brief The maze grid that represents the current game state.
     */
    int maze[33][30];
    /**
     * @brief Getter function to get the number of rows.
     */
    int getNumRows();
    /**
     * @brief A getter function to get the number of columns.
     */
    int getNumCols();
    /**
     * @brief A getter function to get the current color of the maze.
     */
    Color getMazeColor();
    /**
     * @brief A setter function to set the current color of the maze.
     */
    void setMazeColor(Color color);

  private:
    int numRows;     /**< Rows number used for initialized the maze grid and drawing said grid */
    int numCols;     /**< Columns number used for initialized the maze grid and drawing said grid */
    Color mazeColor; /**< The color that the grid is drawn in */
};