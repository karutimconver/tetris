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
    std::cout << std::endl;
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Grid::draw() {
    Vector2 StartingPoint;
    StartingPoint.x = GetScreenWidth() / 2 - GRID_WIDTH * CellSize / 2 - CellSpacing * GRID_WIDTH / 2 + 1;
    StartingPoint.y = GetScreenHeight() / 2 - GRID_HEIGHT * CellSize / 2 - CellSpacing * GRID_HEIGHT / 2 + 1;

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            DrawRectangle(StartingPoint.x + CellSize * j + CellSpacing * j, StartingPoint.y + CellSize * i + CellSpacing * i, CellSize, CellSize, colors[grid[i][j]]);
        }
    }
}