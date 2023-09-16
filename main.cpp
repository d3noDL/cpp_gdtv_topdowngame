#include "raylib.h"
#include "raymath.h"
#include "character.h"

int main() {
    const int WINDOW_WIDTH {384};
    const int WINDOW_HEIGHT {384};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top Down Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 map_position {0.0, 0.0};
    const float map_scale {4.0f};
    
    Character knight;
    knight.setScreenPosition(WINDOW_WIDTH, WINDOW_HEIGHT);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        /* BEGIN LOGIC */
        
        map_position = Vector2Scale(knight.getWorldPosition(), -1.f);

        // Draw the map
        DrawTextureEx(map, map_position , 0, map_scale, WHITE);
        knight.tick(GetFrameTime());
        // Check map bounds
        if (knight.getWorldPosition().x < 0.f ||
            knight.getWorldPosition().y < 0.f ||
            knight.getWorldPosition().x + WINDOW_WIDTH > map.width * map_scale||
            knight.getWorldPosition().y + WINDOW_HEIGHT > map.height * map_scale) {
                knight.undoMovement();
            }
        
        /* END LOGIC */
        EndDrawing();
    }
    CloseWindow();
}