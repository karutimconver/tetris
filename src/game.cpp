#include "game.hpp"

Game::Game() : grid() {
    // debug
    grid.print();
    
}

void Game::update() {
    float dt = GetFrameTime();
    timer += dt;
    std::cout << timer << "\n";
    //WaitTime(1);
    grid.update();
    L.update(dt, speed, &grid);
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    L.draw(&grid);
    grid.draw();

    EndDrawing();
}