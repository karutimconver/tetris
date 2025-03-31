#include "raylib.h"
#include "globals.hpp"
#include "grid.hpp"
#include "game.hpp"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetris");
    InitAudioDevice();

    Game game;

    while (!WindowShouldClose()) {
        game.update();
        game.draw();
    }

    CloseWindow();
}

