#include "raylib.h"
#include "raymath.h"

class Character {
    public:
        Vector2 getWorldPosition() {return world_position;}
        void setScreenPosition(int winWidth, int winHeight);
        void tick(float deltaTime);
    private:
        Texture2D texture {LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D idle {LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D run {LoadTexture("characters/knight_run_spritesheet.png")};
        Vector2 screen_position {};
        Vector2 world_position {};
        float right_left{1.f};
        float running_time {};
        float frame {};
        const int max_frames {6};
        const float update_time {1.f/12.f};
        const float speed {4.f};
};

void Character::setScreenPosition(int winWidth, int winHeight){
    screen_position = {
        (float)winWidth / 2.0f - (0.5f * (float)texture.width/6.0f) * 4.0f,
        (float)winHeight / 2.0f - (0.5f * (float)texture.height) * 4.0f
    };
}

void Character::tick(float deltaTime){
    // Input
    Vector2 direction {};
    if (IsKeyDown(KEY_A)) direction.x -= 1.0;
    if (IsKeyDown(KEY_D)) direction.x += 1.0;
    if (IsKeyDown(KEY_W)) direction.y -= 1.0;
    if (IsKeyDown(KEY_S)) direction.y += 1.0;
    if (Vector2Length(direction) != 0.0) {
        world_position = Vector2Add(world_position, Vector2Scale(Vector2Normalize(direction), speed));
        // Terenary operator
        // Condition      ? True              : False
        direction.x < 0.f ? right_left = -1.f : right_left = 1.f;
        texture = run;
    }
    else {
        texture = idle;
    }

    // Update animation frame
    running_time += deltaTime;
    if (running_time >= update_time) {
        frame++;
        running_time = 0.f;
        if (frame > max_frames) frame = 0;
    }

    Rectangle source {(float)texture.width/6.f * frame, 0.f, right_left * (float)texture.width/6.f, (float)texture.height};
    Rectangle destination {screen_position.x, screen_position.y, (float)texture.width/6.f * 4.f, (float)texture.height * 4.f};
    DrawTexturePro(texture, source, destination, Vector2{}, 0.f, WHITE);
}

int main() {
    const int WINDOW_WIDTH {384};
    const int WINDOW_HEIGHT {384};
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top Down Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 map_position {0.0, 0.0};
    
    Character knight;
    knight.setScreenPosition(WINDOW_WIDTH, WINDOW_HEIGHT);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        /* BEGIN LOGIC */
        
        map_position = Vector2Scale(knight.getWorldPosition(), -1.f);

        // Draw the map
        DrawTextureEx(map, map_position , 0, 4, WHITE);
        knight.tick(GetFrameTime());
        
        /* END LOGIC */
        EndDrawing();
    }
    CloseWindow();
}