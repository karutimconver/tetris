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

bool Grid::hasFullLines(std::vector<int>* fullLines) {
    unsigned short int c = 0;

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[y][x] == 0) {
                break;
            }
            c++;
        }

        if (c == GRID_WIDTH)
            fullLines->push_back(y);
            
        c = 0;
    }

    if (fullLines->size() > 0)
        return true;
    else 
        return false;
}

void Grid::clearLines(std::vector<int>* lines, std::vector<std::array<unsigned short int, 3>>* occupiedCells) {
    for (auto y : *lines) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = 0;
        }

        occupiedCells->erase(std::remove_if(occupiedCells->begin(), occupiedCells->end(), [&](std::array<unsigned short int, 3> cell) {
            return (cell[0] == y);
        }), occupiedCells->end());
    }
}

void Grid::update(std::vector<std::array<unsigned short int, 3>>* occupiedCells) {
    this->clear();

    for (auto& cell : *occupiedCells)
        this->grid[cell[0]][cell[1]] = cell[2];

    std::vector<int> fullLines;
    if (hasFullLines(&fullLines)) {
        clearLines(&fullLines, occupiedCells);
    }
}

void Grid::draw() {
    Vector2 StartingPoint;
    StartingPoint.x = GetScreenWidth() / 2 - GRID_WIDTH * CELL_SIZE / 2 - CellSpacing * GRID_WIDTH / 2 + 1; 
    StartingPoint.y = GetScreenHeight() / 2 - GRID_HEIGHT * CELL_SIZE / 2 - CellSpacing * GRID_HEIGHT / 2 + 1;

    DrawRectangle(StartingPoint.x - CellSpacing, StartingPoint.y - CellSpacing, (CELL_SIZE + CellSpacing) * GRID_WIDTH + CellSpacing, (CELL_SIZE + CellSpacing) * GRID_HEIGHT + CellSpacing, LIGHTGRAY);

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            DrawRectangle(StartingPoint.x + CELL_SIZE * j + CellSpacing * j, StartingPoint.y + CELL_SIZE * i + CellSpacing * i, CELL_SIZE, CELL_SIZE, colors[grid[i][j]]);
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