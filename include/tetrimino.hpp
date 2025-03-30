#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "globals.hpp"
#include <array>
#include <unordered_map>

class Tetrimino {
protected:
    unsigned short int color;
    unsigned short int rotation_state = 0;
    std::unordered_map<int, std::array<std::array<int, 2>, 4>> cells;
    Vector2 position;
public:
    void update();
    void rotate();
    void draw(Grid* grid);
};


class LTetrimino : public Tetrimino {
public:
    LTetrimino();
};

class ReverseLTetrimino : public Tetrimino {
public:
    ReverseLTetrimino();
};

class STetrimino : public Tetrimino {
public:
    STetrimino();
};

class ReverseSTetrimino : public Tetrimino {
public:
    ReverseSTetrimino();
};