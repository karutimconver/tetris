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

Tetrimino::Tetrimino() {

}

// ---------------------
// | L shape tetrimino |
// ---------------------

LTetrimino::LTetrimino() {
    cells[0] = { { {0, 1}, {0, 0}, {0, -1}, {-1, -1} } };
    cells[1] = { { {1, 0}, {0, 0}, {1, 0}, {1, -1} } };
    cells[2] = { { {0, -1}, {0, 0}, {0, 1}, {1, 1} } };
    cells[3] = { { {-1, 0}, {0, 0}, {1, 0}, {-1, -1} } };
    std::cout << cells[0][0][1];
    position.y = 1;
    position.x = 5;
}

void LTetrimino::rotate() {
    rotation_state += 1;
    if (rotation_state > 3)
        rotation_state = 0;
}

void LTetrimino::update() {
    
}

void LTetrimino::draw(Grid* grid) {
    grid->grid[cells[rotation_state][0][0] + this->position.y][cells[rotation_state][0][1] + this->position.x] = this->color;
    grid->grid[cells[rotation_state][1][0] + this->position.y][cells[rotation_state][1][1] + this->position.x] = this->color;
    grid->grid[cells[rotation_state][2][0] + this->position.y][cells[rotation_state][2][1] + this->position.x] = this->color;
    grid->grid[cells[rotation_state][3][0] + this->position.y][cells[rotation_state][3][1] + this->position.x] = this->color;

    //std::cout << "(" << cells[rotation_state][0][0] + this->position.y << ", " << cells[rotation_state][0][1] + this->position.x << ")\n";
    //std::cout << "(" << cells[rotation_state][1][0] + this->position.y << ", " << cells[rotation_state][1][1] + this->position.x << ")\n";
    //std::cout << "(" << cells[rotation_state][2][0] + this->position.y << ", " << cells[rotation_state][2][1] + this->position.x << ")\n";
    //std::cout << "(" << cells[rotation_state][3][0] + this->position.y << ", " << cells[rotation_state][3][1] + this->position.x << ")\n";
}
