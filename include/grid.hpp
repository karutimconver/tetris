#pragma once

#include "globals.hpp"
#include <iostream>
#include <array>


class Grid {
private:
    int CellSize;

    void clear();
public:
    std::array<std::array<unsigned short int, GRID_WIDTH>, GRID_HEIGHT> grid{};

    Grid();
    void print();
};