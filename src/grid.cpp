#include "grid.hpp"

Grid::Grid() {
    clear();
}

void Grid::clear() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = 0;
        }
    }
}

void Grid::print() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}