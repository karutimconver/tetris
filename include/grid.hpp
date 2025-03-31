#pragma once

#include "globals.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>
#include <array>


class Grid {
private:
    unsigned short int CellSpacing = 2;    
    void clear();
public:
    std::array<std::array<unsigned short int, GRID_WIDTH>, GRID_HEIGHT> grid;

    Grid();
    void print();
    void update();
    void draw();
};