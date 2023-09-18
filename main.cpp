#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"
#include "enemy.h"

int main() {
    const int WINDOW_WIDTH {384};
    const int WINDOW_HEIGHT {384};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top Down Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 map_position {0.0, 0.0};
    const float map_scale {4.0f};
    
    Character knight(WINDOW_WIDTH, WINDOW_HEIGHT);

    Prop props[2] {
        Prop {Vector2 {600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop {Vector2 {400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}
    };
    

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        
        
        BeginDrawing();
        ClearBackground(WHITE);
        /* BEGIN LOGIC */
        
        map_position = Vector2Scale(knight.getWorldPosition(), -1.f);

        // Draw the map
        DrawTextureEx(map, map_position , 0, map_scale, WHITE);

        // Draw the props
        for (auto prop : props) {
            prop.Render(knight.getWorldPosition());
        }

        knight.tick(GetFrameTime());
        
        // Check map bounds
        if (knight.getWorldPosition().x < 0.f ||
            knight.getWorldPosition().y < 0.f ||
            knight.getWorldPosition().x + WINDOW_WIDTH > map.width * map_scale||
            knight.getWorldPosition().y + WINDOW_HEIGHT > map.height * map_scale) {
                knight.undoMovement();
        }

        // Check prop collisions
        for (auto prop : props) {
            if (CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPosition()), knight.getCollisionRec())) {
                knight.undoMovement();
            }
        }

        goblin.tick(GetFrameTime());
        
        /* END LOGIC */
        EndDrawing();
    }
    CloseWindow();
}