#include "raylib.h"
#include "globals.hpp"

void update();
void draw();

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetris");

    while (!WindowShouldClose()) {
        update();
        draw();
    }

    CloseWindow();
}

void update() {

}

void draw() {
    BeginDrawing();
    
    
    EndDrawing();
}