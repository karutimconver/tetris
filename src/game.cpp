#include "game.hpp"

Game::Game() : grid() {
    theme = LoadMusicStream("resources/music/Tetris.mp3");
    PlayMusicStream(theme);

    newTetromino();
}

void Game::newTetromino() {
    unsigned short int n = rand() % 7 + 1;

    switch (n) {
        case 1:
            this->tetromino = std::make_unique<LTetromino>();
            break;
        case 2:
            this->tetromino = std::make_unique<ReverseLTetromino>();   
            break;
        case 3:
            this->tetromino = std::make_unique<STetromino>();
            break;
        case 4:
            this->tetromino = std::make_unique<ReverseSTetromino>();   
            break;
        case 5:
            this->tetromino = std::make_unique<ITetromino>();   
            break;
        case 6:
            this->tetromino = std::make_unique<TTetromino>();   
            break;
        case 7:
            this->tetromino = std::make_unique<SquareTetromino>();   
            break;
    }

    if (tetromino->collide(&grid))
        gameState = GameState::LOST;
}

void Game::update() {
switch (gameState) {    
case GameState::MENU:
    // TO DO

case GameState::LOST:
    // TO DO

case GameState::PAUSED:
    if (IsKeyPressed(KEY_P))
        gameState = GameState::RUNNING;
    break;

case GameState::RUNNING:
    if (IsKeyPressed(KEY_P)) {
        gameState = GameState::PAUSED;
        break;
    }

    float dt = GetFrameTime();
    timer += dt;
    
    UpdateMusicStream(theme);
    
    grid.update(&occupiedCells);
    
    tetromino->update(dt, speed, &grid);
    if (tetromino->collided) {
        tetromino->storeCells(&occupiedCells);
        
        newTetromino();
    }
}
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    tetromino->draw(&grid);
    grid.draw();

    EndDrawing();
}