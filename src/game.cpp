#include "game.hpp"

Game::Game() {
    theme = LoadMusicStream("resources/music/Tetris.mp3");

    font = LoadFont("resources/font/Font.ttf");
}

void Game::start() {
    grid = Grid();

    PlayMusicStream(theme);
    occupiedCells.clear();

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
}

void Game::update() {
switch (gameState) {    
case GameState::MENU:
    if (IsKeyPressed(KEY_S)) {
        start();
        gameState = GameState::RUNNING;
    }
    break;

case GameState::LOST:
    // TO DO
    break;

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

    double a = (1.0/200.0);
    int m = 8;
    int c = 3;
    int b = 1;

    speed = b + m / (1 + std::exp(-(a * timer - c)));
    std::cout << speed << "\n";

    UpdateMusicStream(theme);
    
    grid.update(&occupiedCells);
    
    tetromino->update(dt, speed, &grid);
    if (tetromino->collided) {
        tetromino->storeCells(&occupiedCells);
        
        if (lose()) {
            grid.update(&occupiedCells);
            gameState = GameState::LOST;
            break;
        }

        newTetromino();
    }
}
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(DARKGRAY);
    
    if (gameState == GameState::MENU) {
        //DrawTextPro(font);
    }
    else if (gameState == GameState::RUNNING || gameState == GameState::LOST) {
        tetromino->draw(&grid);
        grid.draw();
    }

    EndDrawing();
}

bool Game::lose() {
    for (auto cell : occupiedCells) {
        if (cell[0] == 0) {
            return true;
        } 
    }

    return false;
}