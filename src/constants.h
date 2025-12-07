#pragma once
#include <raylib.h>
#include <raymath.h>

/**
 * @file constants.h
 * @brief Contains global constants for game logic and UI configuration.
 */

/// @namespace GameConst
/// @brief Contains general game constants.
namespace GameConst
{
/**
 * @brief Time interval for each game tick (in seconds).
 */
constexpr float GameTick = 0.15F;
} // namespace GameConst

/// @namespace UI
/// @brief Contains constants for user interface layout and scaling.
namespace UI
{
/**
 * @brief Width of the game screen in pixels.
 */
// inline constexpr int SCREEN_WIDTH = 900;
constexpr int SCREEN_WIDTH = 900;
/**
 * @brief Height of the game screen in pixels.
 */
// inline constexpr int SCREEN_HEIGHT = 950;
constexpr int SCREEN_HEIGHT = 950;
} // namespace UI