#pragma once

#include "raylib.h"
#include "globals.hpp"
#include <array>

class Tetriminos {
protected:
    int rotation_state;
    std::array<std::array<int, 2>, 4> cells;
    Vector2 position;
public:
    virtual void update() = 0;
    virtual void rotate() = 0;
    virtual void draw() = 0;
};

class LTetrimino : public Tetriminos {
public:
    void update() override;
};

