#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "tetrimino.hpp"

class Game {
private:
    Grid grid;
    STetrimino L;
public:
    Game();
    void update();
    void draw();
};