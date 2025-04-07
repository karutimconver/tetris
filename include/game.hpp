#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "tetromino.hpp"
#include <memory>
#include <cstdlib>

enum class GameState {RUNNING, MENU, PAUSED};


class Game {
private:
    GameState gameState = GameState::RUNNING;
    Grid grid;
    std::unique_ptr<Tetromino> tetromino;
    std::vector<std::array<unsigned short int, 3>> occupiedCells;
    float timer = 0;
    float speed = 2.0f;
    Music theme;
public:
    Game();
    void update();
    void newTetromino();
    void draw();
};