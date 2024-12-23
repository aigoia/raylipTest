#pragma once
#include "raylib.h"
#include "setting.h"

class Ball {
public:
    float x, y;
    int speedX, speedY;
    int radius;
    int playerScore = 0;
    int cpuScore = 0;

    void Draw() {
        DrawCircle(x, y, radius, Yellow);
    }

    void Update() {
        x += speedX;
        y += speedY;

        speedY = y + radius >= GetScreenHeight() || y - radius <= 0 ? speedY * -1 : speedY;
        cpuScore = x + radius >= GetScreenWidth() ? ResetBall(cpuScore) : cpuScore;
        playerScore = x - radius <= 0 ? ResetBall(playerScore) + 1 : playerScore;
    }

    int ResetBall(int score) {
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;

        int speedChoices[2] = {-1, 1};
        speedX *= speedChoices[GetRandomValue(0, 1)];
        speedY *= speedChoices[GetRandomValue(0, 1)];

        return score + 1;
    }
};
