#include "enemy.h"
#include "raymath.h"


Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex) {
        world_position = pos;
        texture = idle_tex;
        run = run_tex;
        width = texture.width / max_frames;
        height = texture.height;
        speed = 3.5f;
}

void Enemy::tick(float deltaTime){
    
    velocity = Vector2Subtract(target->getScreenPosition(), screen_position);
    screen_position = Vector2Subtract(world_position, target->getWorldPosition());

    BaseCharacter::tick(deltaTime);
}
