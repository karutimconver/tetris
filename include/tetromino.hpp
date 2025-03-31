#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "globals.hpp"
#include <unordered_map>

class Tetromino {
protected:
    unsigned short int color;
    unsigned short int rotation_state = 0;
    float fall_timer = 0;
    std::unordered_map<int, std::array<std::array<int, 2>, 4>> cells;
    Vector2 position;
public:
    bool collided = false;

    void rotate();
    void update(float dt, float speed, Grid* frid);
    void storeCells(std::vector<std::array<unsigned short int, 3>>* occupiedCells);
    void fall(Grid* grid);
    bool collide(Grid* grid);
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

class TTetromino : public Tetromino {
public:
    TTetromino();
};

class SquareTetromino : public Tetromino {
public:
    SquareTetromino();
};