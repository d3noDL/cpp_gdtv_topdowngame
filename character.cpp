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
    
    if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_D)) velocity.x += 1.0;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0;

    BaseCharacter::tick(deltaTime);
    
}

