#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "setting.h"

class Ball {
public:
    float x, y;
    int speed_x, speed_y;
    int radius;
    int player_score = 0;
    int cpu_score = 0;

    void Draw() {
        DrawCircle(x, y, radius, Yellow);
    }

    void Update() {
        x += speed_x;
        y += speed_y;

        speed_y = y + radius >= GetScreenHeight() || y - radius <= 0 ? speed_y * -1 : speed_y;
        cpu_score = x + radius >= GetScreenWidth() ? ResetBall(cpu_score) : cpu_score;
        player_score = x - radius <= 0 ? ResetBall(player_score) + 1 : player_score;
    }

    int ResetBall(int score) {
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;

        int speed_choices[2] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0, 1)];
        speed_y *= speed_choices[GetRandomValue(0, 1)];

        return score + 1;
    }
};

#endif