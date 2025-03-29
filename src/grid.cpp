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

// debug function
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
    StartingPoint.x = GetScreenWidth() / 2 - GRID_WIDTH * CELL_SIZE / 2 - CellSpacing * GRID_WIDTH / 2 + 1; 
    StartingPoint.y = GetScreenHeight() / 2 - GRID_HEIGHT * CELL_SIZE / 2 - CellSpacing * GRID_HEIGHT / 2 + 1;

    DrawRectangle(StartingPoint.x - 3, StartingPoint.y - 3, (CELL_SIZE + CellSpacing) * GRID_WIDTH + 3, (CELL_SIZE + CellSpacing) * GRID_HEIGHT + 3, DARKGRAY);

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            DrawRectangle(StartingPoint.x + CELL_SIZE * j + CellSpacing * j, StartingPoint.y + CELL_SIZE * i + CellSpacing * i, CELL_SIZE, CELL_SIZE, colors[grid[i][j]]);
        }
    }
}