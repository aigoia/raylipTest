#pragma once
#include "raylib.h"
#include "setting.h"
#include <vector>

using namespace std;

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
        x = x + speedX;
        y = y + speedY;

        speedY = y + radius >= GetScreenHeight() || y - radius <= 0 ? speedY * -1 : speedY;
        cpuScore = x + radius >= GetScreenWidth() ? ResetBall(cpuScore) : cpuScore;
        playerScore = x - radius <= 0 ? ResetBall(playerScore) + 1 : playerScore;
    }

    int ResetBall(int score) {
        vector<int> positions = {
            (GetScreenWidth() * 2) / 4,
        };

        positions.insert(positions.begin(), (GetScreenWidth() * 1) / 4);
        positions.insert(positions.end(), GetScreenWidth() * 2);

        x = GetScreenHeight() / 2;
        y = positions[GetRandomValue(0, positions.size() -1)];
        
        int speedChoices[2] = {-1, 1};
        speedX = speedX * speedChoices[GetRandomValue(0, 1)];
        speedY = speedX * speedChoices[GetRandomValue(0, 1)];

        return score + 1;
    }
};
