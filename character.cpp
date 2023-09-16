#include "character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight){
    width = texture.width / max_frames;
    height = texture.height;

    screen_position = {
        static_cast<float>(winWidth) / 2.0f - (0.5f * width) * scale,
        static_cast<float>(winHeight) / 2.0f - (0.5f * height) * scale
    };
}

void Character::tick(float deltaTime){
    
    world_position_last_frame = world_position;
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

    Rectangle source {width * frame, 0.f, right_left * width, height};
    Rectangle destination {screen_position.x, screen_position.y, width * scale, height * scale};
    DrawTexturePro(texture, source, destination, Vector2 {}, 0.f, WHITE);
}

