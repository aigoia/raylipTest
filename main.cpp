#include "raylib.h"
#include "helper.h"
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <memory> // 스마트 포인터를 위해 추가

#include "ball.h"
#include "paddle.h"
#include "cpu_paddle.h"
#include "setting.h"

using namespace std;
using namespace helper;

bool initDone = false;

auto ball = make_shared<Ball>();
auto player = make_shared<Paddle>();
auto cpu = make_shared<CpuPaddle>();

void Countdown(int start, int screenWidth, int screenHeight) {
    for (auto& i = start; i > 0; --i) {
        BeginDrawing();
        ClearBackground(Snow);

        DrawText(TextFormat("%d", i), GetScreenWidth() / 2 - ScoreMargin, GetScreenHeight() / 2 - ScoreMargin * 2, ScoreSize, Mint);

        if (initDone) {
            DrawText(TextFormat("%i", ball->cpuScore), screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, Mint);
            DrawText(TextFormat("%i", ball->playerScore), 3 * screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, Mint);
        }
        
        EndDrawing();
        chrono::duration<float> duration(CountTime); 
        this_thread::sleep_for(duration);
    }
}

void CheckGame() {
    if (ball->CheckOutOfBounds()) {
        ball->out = false;
        Countdown(InitCount, GetScreenWidth(), GetScreenHeight());
    }
}

void InitGame(int screenWidth, int screenHeight) {
    InitWindow(screenWidth, screenHeight, GameName);
    SetTargetFPS(Frame);

    ball->radius = BallSize;
    ball->x = screenWidth / 2;
    ball->y = screenHeight / 2;
    ball->speedX = BallSpeed;
    ball->speedY = BallSpeed;

    player->width = PaddleWidth;
    player->height = PaddleHeight;
    player->x = screenWidth - player->width - PaddleMargin;
    player->y = screenHeight / 2 - player->height / 2;
    player->speed = PlayerSpeed;

    cpu->width = PaddleWidth;
    cpu->height = PaddleHeight;
    cpu->x = PaddleMargin;
    cpu->y = screenHeight / 2 - cpu->height / 2;
    cpu->speed = CpuSpeed;

    Countdown(InitCount, ScreenWidth, ScreenHeight);
    initDone = true;
}

void UpdateGame() {
    ball->Update();
    player->Update();
    cpu->Update(ball->y);

    ball->speedX = CheckCollisionCircleRec(Vector2{ball->x, ball->y}, ball->radius, Rectangle{player->x, player->y, player->width, player->height}) ?
        ball->speedX * -1 : ball->speedX;
    ball->speedX = CheckCollisionCircleRec(Vector2{ball->x, ball->y}, ball->radius, Rectangle{cpu->x, cpu->y, cpu->width, cpu->height}) ?
        ball->speedX * -1 : ball->speedX;
}

void DrawGame(int screenWidth, int screenHeight) {
    BeginDrawing();
    ClearBackground(Mint);
    DrawLine(screenWidth / 2, 0, screenWidth / 2 - 1, screenHeight, Snow);
    DrawLine(screenWidth / 2, 0, screenWidth / 2 + 1, screenHeight, Snow);

    ball->Draw();
    player->Draw();
    cpu->Draw();

    DrawText(TextFormat("%i", ball->cpuScore), screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, Snow);
    DrawText(TextFormat("%i", ball->playerScore), 3 * screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, Snow);

    EndDrawing();
}

int main() {
    print("hello pong!");

    InitGame(ScreenWidth, ScreenHeight);

    while (!WindowShouldClose()) {
        CheckGame();
        UpdateGame();
        DrawGame(ScreenWidth, ScreenHeight);
    }

    CloseWindow();
    return 0;
}
