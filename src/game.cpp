#include "game.hpp"

Game::Game() : grid() {
    grid.print();
}

void Game::update() {

}

void Game::draw() {
    BeginDrawing();
    ClearBackground(DARKBLUE);

    grid.draw();

    EndDrawing();
}