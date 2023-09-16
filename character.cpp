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
    
    BaseCharacter::tick(deltaTime);
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
}

