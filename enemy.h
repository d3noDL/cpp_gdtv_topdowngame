#include "raylib.h"
#include "basecharacter.h"

class Enemy : public BaseCharacter {
    public:
        Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex);
        Vector2 getWorldPosition() {return world_position;}
        void tick(float deltaTime);
        void undoMovement();
        Rectangle getCollisionRec();
    private:
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
};