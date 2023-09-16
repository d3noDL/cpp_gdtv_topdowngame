#include "raylib.h"
#include "raymath.h"

class Character {
    public:
        Vector2 getWorldPosition() {return world_position;}
        
        
    private:
        Texture2D texture;
        Texture2D idle;
        Texture2D run;
        Vector2 screen_position;
        Vector2 world_position;
        float right_left{1.f};
        float running_time {};
        float frame {};
        const int max_frames {6};
        const float update_time {1.f/12.f};
};

int main() {
    const int WINDOW_WIDTH {384};
    const int WINDOW_HEIGHT {384};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top Down Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 map_position {0.0, 0.0};
    float speed {4.0};

    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("Characters/knight_run_spritesheet.png");
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knight_position {
        (float)WINDOW_WIDTH / 2.0f - (0.5f * (float)knight.width/6.0f) * 4.0f,
        (float)WINDOW_HEIGHT / 2.0f - (0.5f * (float)knight.height) * 4.0f
    };
    // 1 : facing right, -1 : facing left
    float right_left{1.f};

    // Animation variables
    float running_time {};
    float frame {};
    const int max_frames {6};
    const float update_time { 1.f/ 12.f};

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
        if (Vector2Length(direction) != 0.0) {
            map_position = Vector2Subtract(map_position, Vector2Scale(Vector2Normalize(direction), speed));
            // Terenary operator
            // Condition      ? True              : False
            direction.x < 0.f ? right_left = -1.f : right_left = 1.f;
            knight = knight_run;
        }
        else {
            knight = knight_idle;
        }
            
        
        // Draw the map
        DrawTextureEx(map, map_position , 0, 4, WHITE);

        // Update animation frame
        running_time += GetFrameTime();
        if (running_time >= update_time) {
            frame++;
            running_time = 0.f;
            if (frame > max_frames) frame = 0;
        }
        
        // Draw the character
        Rectangle source {(float)knight.width/6.f * frame, 0.f, right_left * (float)knight.width/6.f, (float)knight.height};
        Rectangle destination {knight_position.x, knight_position.y, (float)knight.width/6.f * 4.f, (float)knight.height * 4.f};
        DrawTexturePro(knight, source, destination, Vector2{}, 0.f, WHITE);
        
        /* END LOGIC */
        EndDrawing();
    }
    UnloadTexture(map);
    UnloadTexture(knight);
    CloseWindow();
}