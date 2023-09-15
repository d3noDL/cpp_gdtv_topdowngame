#include "raylib.h"
#include "raymath.h"

int main() {
    const int WINDOW_WIDTH {384};
    const int WINDOW_HEIGHT {384};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top Down Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 map_position {0.0, 0.0};
    float speed {4.0};

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        /* BEGIN LOGIC */

        Vector2 direction {};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0) 
            map_position = Vector2Subtract(
                map_position, 
                Vector2Scale(
                    Vector2Normalize(direction), 
                    speed
                    )
                );
        
        
        
        DrawTextureEx(map, map_position , 0, 4, WHITE);
        
        /* END LOGIC */
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}