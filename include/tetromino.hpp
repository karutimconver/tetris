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
    float speed = 1.0f;
    std::unordered_map<int, std::array<std::array<int, 2>, 4>> cells;
    Vector2 position;

    void controls(Grid* grid);
    void rotate(Grid* grid);
    void fall(Grid* grid);
public:
    bool collided = false;
    
    void update(float dt, float speed, Grid* grid);
    bool collide(Grid* grid);
    void storeCells(std::vector<std::array<unsigned short int, 3>>* occupiedCells);
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