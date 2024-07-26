#include "game.hpp"

Game::Game() : grid() {

}

void Game::update() {

}

void Game::draw() {
    BeginDrawing();
    ClearBackground(DARKBLUE);

    grid.draw();

    EndDrawing();
}