#include "basecharacter.h"

BaseCharacter::BaseCharacter() {

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