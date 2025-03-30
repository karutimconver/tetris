#include "game.hpp"

Game::Game() : grid() {
    // debug
    grid.print();
    
}

void Game::update() {
    WaitTime(1);
    grid.update();
    L.rotate();
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    L.draw(&grid);
    grid.draw();

    EndDrawing();
}