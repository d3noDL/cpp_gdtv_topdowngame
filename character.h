#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "basecharacter.h"

class Character : public BaseCharacter {
    public:
        Character(int winWidth, int winHeight);
        Vector2 getScreenPosition() { return screen_position;}
        virtual void tick(float deltaTime) override; // Overriding BaseCharacter tick function
    
};

#endif