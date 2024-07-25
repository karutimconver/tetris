#include "raylib.h"
#include "globals.hpp"
#include "grid.hpp"

void update();
void draw();

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetris");

    Grid grid;
    grid.print();

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
    ClearBackground(DARKBLUE);

    
    EndDrawing();
}