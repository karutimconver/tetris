#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "tetrimino.hpp"

class Game {
private:
    Grid grid;
    LTetrimino L;
public:
    Game();
    void update();
    void draw();
};