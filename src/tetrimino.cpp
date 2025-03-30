#include "tetrimino.hpp"

// grid coordinate system

// O---------- X 
// |0000000000
// |0000P00000
// |0000000000
// |0000000000 
// Y
// P = (y, x) 
// Starts at block (0,0)

void Tetrimino::rotate() {
    rotation_state += 1;
    if (rotation_state > 3)
        rotation_state = 0;
}

void Tetrimino::update() {
    
}

void Tetrimino::draw(Grid* grid) {
    for (auto& cell: cells[rotation_state])
        grid->grid[cell[0] + this->position.y][cell[1] + this->position.x] = this->color;
}


// ---------------------
// | L shape tetrimino |
// ---------------------

LTetrimino::LTetrimino() {
    cells[0] = { { {0, -1}, {0, 0}, {0, 1}, {-1, 1} } };
    cells[1] = { { {-1, 0}, {0, 0}, {1, 0}, {1, 1} } };
    cells[2] = { { {0, 1}, {0, 0}, {0, -1}, {1, -1} } };
    cells[3] = { { {1, 0}, {0, 0}, {-1, 0}, {-1, -1} } };

    position.y = 1;
    position.x = 5;

    color = 2;
}


// -----------------------------
// | reverse L shape tetrimino |
// -----------------------------

ReverseLTetrimino::ReverseLTetrimino() {
    cells[0] = { { {0, 1}, {0, 0}, {0, -1}, {-1, -1} } };
    cells[1] = { { {1, 0}, {0, 0}, {-1, 0}, {-1, 1} } };
    cells[2] = { { {0, -1}, {0, 0}, {0, 1}, {1, 1} } };
    cells[3] = { { {-1, 0}, {0, 0}, {1, 0}, {1, -1} } };

    position.y = 1;
    position.x = 5;

    color = 6;
}

// ---------------------
// | S shape tetrimino |
// ---------------------

STetrimino::STetrimino() {
    cells[0] = { { {0, -1}, {0, 0}, {-1, 0}, {-1, 1} } };
    cells[1] = { { {-1, 0}, {0, 0}, {0, 1}, {1, 1} } };
    cells[2] = { { {1, -1}, {1, 0}, {0, 0}, {0, 1} } };
    cells[3] = { { {-1, -1}, {0, -1}, {0, 0}, {1, 0} } };

    position.y = 1;
    position.x = 5;

    color = 4;
}

// -----------------------------
// | reverse S shape tetrimino |
// -----------------------------

ReverseSTetrimino::ReverseSTetrimino() {
    
}