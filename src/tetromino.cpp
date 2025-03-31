#include "tetromino.hpp"

// grid coordinate system

// O---------- X 
// |0000000000
// |0000P00000
// |0000000000
// |0000000000
// Y
// P = (y, x) 
// Starts at block (0,0)

void Tetromino::rotate() {
    rotation_state += 1;
    if (rotation_state > 3)
        rotation_state = 0;
}

void Tetromino::controls() {
    
}

void Tetromino::fall(Grid* grid) {
    position.y += 1;
    if (collide(grid)) {
        collided = true;
        position.y -= 1;
    }
}

bool Tetromino::collide(Grid* grid) {
    for (auto& cell: cells[rotation_state]) {
        if (grid->grid[cell[0] + this->position.y][cell[1] + this->position.x] != 0
            || position.y + cell[0] >= GRID_HEIGHT)
            return true;
    }

    return false;
}

void Tetromino::storeCells(std::vector<std::array<unsigned short int, 3>>* occupiedCells) {
    for (auto& cell : cells[rotation_state]) {
        unsigned short y = cell[0] + this->position.y;
        unsigned short x = cell[1] + this->position.x;

        occupiedCells->push_back({y, x, this->color});
    }
}

void Tetromino::update(float dt, float speed, Grid* grid) {
    fall_timer += dt * speed;

    controls();

    if (fall_timer >= 1) {
        fall_timer = 0;
        fall(grid);
    }
}

void Tetromino::draw(Grid* grid) {
    for (auto& cell: cells[rotation_state])
        grid->grid[cell[0] + this->position.y][cell[1] + this->position.x] = this->color;
}

// ---------------------
// | L shape tetromino |
// ---------------------

LTetromino::LTetromino() {
    cells[0] = { { {0, -1}, {0, 0}, {0, 1}, {-1, 1} } };
    cells[1] = { { {-1, 0}, {0, 0}, {1, 0}, {1, 1} } };
    cells[2] = { { {0, 1}, {0, 0}, {0, -1}, {1, -1} } };
    cells[3] = { { {1, 0}, {0, 0}, {-1, 0}, {-1, -1} } };

    position.y = 1;
    position.x = 4;

    color = 2;
}

// -----------------------------
// | reverse L shape tetromino |
// -----------------------------

ReverseLTetromino::ReverseLTetromino() {
    cells[0] = { { {0, 1}, {0, 0}, {0, -1}, {-1, -1} } };
    cells[1] = { { {1, 0}, {0, 0}, {-1, 0}, {-1, 1} } };
    cells[2] = { { {0, -1}, {0, 0}, {0, 1}, {1, 1} } };
    cells[3] = { { {-1, 0}, {0, 0}, {1, 0}, {1, -1} } };

    position.y = 1;
    position.x = 4;

    color = 6;
}

// ---------------------
// | S shape tetromino |
// ---------------------

STetromino::STetromino() {
    cells[0] = { { {0, -1}, {0, 0}, {-1, 0}, {-1, 1} } };
    cells[1] = { { {-1, 0}, {0, 0}, {0, 1}, {1, 1} } };
    cells[2] = { { {1, -1}, {1, 0}, {0, 0}, {0, 1} } };
    cells[3] = { { {-1, -1}, {0, -1}, {0, 0}, {1, 0} } };

    position.y = 1;
    position.x = 4;

    color = 4;
}

// -----------------------------
// | reverse S shape tetromino |
// -----------------------------

ReverseSTetromino::ReverseSTetromino() {
    cells[0] = { { {-1, -1}, {-1, 0}, {0, 0}, {0, 1} } };
    cells[1] = { { {-1, 1}, {0, 1}, {0, 0}, {1, 0} } };
    cells[2] = { { {0, -1}, {0, 0}, {1, 0}, {1, 1} } };
    cells[3] = { { {1, -1}, {0, -1}, {0, 0}, {-1, 0} } };

    position.y = 1;
    position.x = 4;

    color = 1;
}

// ---------------------
// | I shape tetromino |
// ---------------------

ITetromino::ITetromino() {
    cells[0] = { { {0, -1}, {0, 0}, {0, 1}, {0, 2} } };
    cells[1] = { { {-1, 1}, {0, 1}, {1, 1}, {2, 1} } };
    cells[2] = { { {1, -1}, {1, 0}, {1, 1}, {1, 2} } };
    cells[3] = { { {-1, 0}, {0, 0}, {1, 0}, {2, 0} } };
    
    position.y = 1;
    position.x = 4;

    color = 5;
}

// ---------------------
// | T shape tetromino |
// ---------------------

TTetromino::TTetromino() {
    cells[0] = { { {0, -1}, {0, 0}, {-1, 0}, {0, 1} } };
    cells[1] = { { {-1, 0}, {0, 0}, {0, 1}, {1, 0} } };
    cells[2] = { { {0, -1}, {0, 0}, {1, 0}, {0, 1} } };
    cells[3] = { { {0, -1}, {0, 0}, {-1, 0}, {1, 0} } };
    
    position.y = 1;
    position.x = 4;

    color = 7;
}

// --------------------------
// | Sqaure shape tetromino |
// --------------------------

SquareTetromino::SquareTetromino() {
    cells[0] = { { {0, 0}, {1, 0}, {0, 1}, {1, 1} } };
    cells[1] = { { {0, 0}, {1, 0}, {0, 1}, {1, 1} } };
    cells[2] = { { {0, 0}, {1, 0}, {0, 1}, {1, 1} } };
    cells[3] = { { {0, 0}, {1, 0}, {0, 1}, {1, 1} } };
    
    position.y = 0;
    position.x = 4;

    color = 3;
}