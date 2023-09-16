#include "raylib.h"

class Prop{
    public:
        Prop(Vector2 pos, Texture2D tex);
    private:
        Texture2D texture {};
        Vector2 world_position {};
        float scale {4.f};
};