#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "globals.hpp"
#include <array>
#include <unordered_map>

class Tetromino {
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


class LTetromino : public Tetromino {
public:
    LTetromino();
};

class ReverseLTetromino : public Tetromino {
public:
    ReverseLTetromino();
};

class STetromino : public Tetromino {
public:
    STetromino();
};

class ReverseSTetromino : public Tetromino {
public:
    ReverseSTetromino();
};

class ITetromino : public Tetromino {
public:
    ITetromino();
};