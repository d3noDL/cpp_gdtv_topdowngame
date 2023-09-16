#include "enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex) {
        world_position = pos;
        texture = idle_tex;
        run = run_tex;
        
        width = texture.width / max_frames;
        height = texture.height;
}

void Enemy::tick(float deltaTime){
    world_position_last_frame = world_position;

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
