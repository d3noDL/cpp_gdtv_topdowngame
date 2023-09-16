#include "raylib.h"
#include "raymath.h"

int main() {
    const int WINDOW_WIDTH {384};
    const int WINDOW_HEIGHT {384};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top Down Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 map_position {0.0, 0.0};
    float speed {4.0};

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knight_position {
        (float)WINDOW_WIDTH / 2.0f - (0.5f * (float)knight.width/6.0f) * 4.0f,
        (float)WINDOW_HEIGHT / 2.0f - (0.5f * (float)knight.height) * 4.0f
    };

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
        
        // Draw the map
        DrawTextureEx(map, map_position , 0, 4, WHITE);
        
        // Draw the character
        Rectangle source {0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
        Rectangle destination {
            knight_position.x, knight_position.y, 
            (float)knight.width/6.f * 4.f, (float)knight.height * 4.f};
        DrawTexturePro(knight, source, destination, Vector2{}, 0.f, WHITE);
        
        /* END LOGIC */
        EndDrawing();
    }
    UnloadTexture(map);
    UnloadTexture(knight);
    CloseWindow();
}