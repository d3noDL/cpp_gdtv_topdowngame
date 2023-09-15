#include "raylib.h"

int main() {
    const int WINDOW_WIDTH {384};
    const int WINDOW_HEIGHT {384};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top Down Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");


    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        /* BEGIN LOGIC */
        
        Vector2 map_position {0.0, 0.0};
        DrawTextureEx(map, map_position , 0, 4, WHITE);
        
        /* END LOGIC */
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow()
}