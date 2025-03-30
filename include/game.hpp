#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "tetromino.hpp"

class Game {
private:
    Grid grid;
    SquareTetromino L;
public:
    Game();
    void update();
    void draw();
};