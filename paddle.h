#pragma once
#include "raylib.h"

class Paddle {
protected:
    void LimitMovement()
    {
        y = y <= 0 ? 0 : y;
        y = y + height >= GetScreenHeight() ? GetScreenHeight() - height : y;
    }

public:
    float x, y;
    float width, height;
    int speed;

    void Draw() {
        DrawRectangle(x, y, width, height, Snow);
    }

    void Update() {
        y = IsKeyDown(KEY_UP) ? y - speed : IsKeyDown(KEY_DOWN) ? y + speed : y;

        LimitMovement();
    }
};
