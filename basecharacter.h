#ifndef BASE_CHARACTER_H // If basecharacter.h is not defined 
#define BASE_CHARACTER_H // Defining basecharacter.h
#include "raylib.h"

class BaseCharacter {
    public:
        BaseCharacter();
        Vector2 getWorldPosition() {return world_position;}
        void undoMovement();
        Rectangle getCollisionRec();
        virtual void tick(float deltaTime); // Virtual == can be overridden
        virtual Vector2 getScreenPosition() = 0; // Pure Virtal function
    protected:
        Texture2D texture {LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D idle {LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D run {LoadTexture("characters/knight_run_spritesheet.png")};
        Vector2 screen_position {};
        Vector2 world_position {};
        Vector2 world_position_last_frame {};
        float right_left{1.f};
        float running_time {};
        float frame {};
        int max_frames {6};
        float update_time {1.f/12.f};
        float speed {4.f};
        float width {};
        float height {};
        float scale {4.f};
        Vector2 velocity {};

};

#endif