#include "tetrimino.hpp"

// grid coordinate system

// 
// O----------> X 
// |0000000000
// |0000P00000
// |0000000000
// |0000000000 
// Y
// P = (y, x) 
// Starts at block (0,0)

Tetrimino::Tetrimino() {

}

// ---------------------
// | L shape tetrimino |
// ---------------------

LTetrimino::LTetrimino() {
    cells[0] = { { {0, -1}, {0, 0}, {0, 1}, {1, 1} } };
    cells[1] = { { {1, 0}, {0, 0}, {-1, 0}, {-1, 1} } };
    cells[2] = { { {0, 1}, {0, 0}, {0, -1}, {-1, -1} } };
    cells[3] = { { {1, 0}, {0, 0}, {-1, 0}, {1, 1} } };
}

void LTetrimino::rotate() {
    
}

void LTetrimino::update() {
    
}

void LTetrimino::draw(Grid* grid) {
    grid->grid[cells[rotation_state][0][0] + this->y][cells[rotation_state][0][0] + this->x] = this->color;
}
