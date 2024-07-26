#pragma once

#include "raylib.h"
#include "grid.hpp"

class Game {
private:
    Grid grid;
public:
    Game();
    void update();
    void draw();
};