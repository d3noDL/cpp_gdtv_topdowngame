#include "basecharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter() {

}

void BaseCharacter::tick(float deltaTime){
    world_position_last_frame = world_position;

    // Update animation frame
    running_time += deltaTime;
    if (running_time >= update_time) {
        frame++;
        running_time = 0.f;
        if (frame > max_frames) frame = 0;
    }

    if (Vector2Length(velocity) != 0.0) {
        world_position = Vector2Add(world_position, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? right_left = -1.f : right_left = 1.f;
        texture = run;
    }
    else {
        texture = idle;
    }
    velocity = {};

    Rectangle source {width * frame, 0.f, right_left * width, height};
    Rectangle destination {screen_position.x, screen_position.y, width * scale, height * scale};
    DrawTexturePro(texture, source, destination, Vector2 {}, 0.f, WHITE);
}

void BaseCharacter::undoMovement(){
    world_position = world_position_last_frame;
}

Rectangle BaseCharacter::getCollisionRec() {
    return Rectangle {
        screen_position.x,
        screen_position.y,
        width * scale,
        height * scale
    };
}