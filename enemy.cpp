#include "enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex) {
        world_position = pos;
        texture = idle_tex;
        run = run_tex;
        
        width = texture.width / max_frames;
        height = texture.height;
}

void Enemy::tick(float deltaTime){
    BaseCharacter::tick(deltaTime);
}
