#pragma once

#include "globals.hpp"
#include "raylib.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>


class Grid {
private:
    unsigned short int CellSpacing = 2;
    void clear();
    void clearLines(std::vector<int>* Lines, std::vector<std::array<unsigned short int, 3>>* occupiedCells);
    bool hasFullLines(std::vector<int>* lines);
public:
    std::array<std::array<unsigned short int, GRID_WIDTH>, GRID_HEIGHT> grid;

    Grid();
    void print();
    void update(std::vector<std::array<unsigned short int, 3>>* occupiedCells);
    void draw();
};