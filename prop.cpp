#include "prop.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex) : world_position(pos), texture(tex) {
    
}

void Prop::Render(Vector2 knightPos){
    Vector2 screen_pos { Vector2Subtract(world_position, knightPos)};
    DrawTextureEx(texture, screen_pos, 0.f, scale, WHITE);
}