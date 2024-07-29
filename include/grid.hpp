#pragma once

#include "globals.hpp"
#include "raylib.h"
#include <iostream>
#include <array>


class Grid {
private:
    int CellSize = 24;
    unsigned short int CellSpacing = 3;
    std::array<Color, 7> colors = {BLACK, RED, ORANGE, YELLOW, GREEN, BLUE, MAGENTA};
    
    void clear();
public:
    std::array<std::array<unsigned short int, GRID_WIDTH>, GRID_HEIGHT> grid;

    Grid();
    void print();
    void draw();
};