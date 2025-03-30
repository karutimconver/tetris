#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "tetromino.hpp"

class Game {
private:
    Grid grid;
    ITetromino L;
public:
    Game();
    void update();
    void draw();
};