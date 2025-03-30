#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "tetromino.hpp"

class Game {
private:
    Grid grid;
    SquareTetromino L;
    float timer = 0;
    float speed = 1.0f;
public:
    Game();
    void update();
    void draw();
};