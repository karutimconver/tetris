#pragma once

#include "raylib.h"
#include "globals.hpp"
#include <array>
#include <unordered_map>

class Tetrimino {
protected:
    unsigned short int rotation_state;
    Color color;
    std::unordered_map<int, std::array<std::array<int, 2>, 4>> cells;
    Vector2 position;
public:
    Tetrimino();
    virtual void update() = 0;
    virtual void rotate() = 0;
    void draw();
};

class LTetrimino : public Tetrimino {
protected:

public:
    LTetrimino();
    void update() override;
    void rotate() override;
};

