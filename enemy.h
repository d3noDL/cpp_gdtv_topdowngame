#include "raylib.h"
#include "basecharacter.h"
#include "character.h"

class Enemy : public BaseCharacter {
    public:
        Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex);
        virtual void tick(float deltaTime) override; // Overriding BaseCharacter tick function
        void setTarget(Character* character) { target = character;};
    private:
        Character* target;
};