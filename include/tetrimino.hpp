#pragma once

#include "raylib.h"
#include "grid.hpp"
#include "globals.hpp"
#include <array>
#include <unordered_map>

class Tetrimino {
protected:
    unsigned short int y = 0;
    unsigned short int x = 0;
    unsigned short int rotation_state;
    std::unordered_map<int, std::array<std::array<int, 2>, 4>> cells;
    Vector2 position;
public:
    Tetrimino();
    virtual void update() = 0;
    virtual void rotate() = 0;
    virtual void draw(Grid* grid) = 0;
};

class LTetrimino : public Tetrimino {
protected:
    unsigned short int color = 3; // Orange
public:
    LTetrimino();
    void update() override;
    void rotate() override;
    void draw(Grid* grid) override;
};

