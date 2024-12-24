#include "raylib.h"
#include "helper.h"
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <coroutine>

#include "ball.h"
#include "paddle.h"
#include "cpu_paddle.h"
#include "setting.h"

using namespace std;

Ball ball;
Paddle player;
CpuPaddle cpu;

class CountdownTask {
public:
    class promise_type {
        public:
        CountdownTask get_return_object() { return CountdownTask{}; }
        suspend_never initial_suspend() { return {}; }
        suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { terminate(); }
    };
};

CountdownTask Countdown(int start, int screenWidth, int screenHeight) {
    for (int i = start; i > 0; --i) {
        BeginDrawing();
        ClearBackground(Snow);

        DrawText(TextFormat("%i", ball.cpuScore), screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, Mint);
        DrawText(TextFormat("%i", ball.playerScore), 3 *  screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, Mint);

        EndDrawing();
        this_thread::sleep_for(chrono::seconds(1)); 
        co_await suspend_always{}; 
    }
}

void InitGame(int screenWidth, int screenHeight) {
    InitWindow(screenWidth, screenHeight, GameName);
    SetTargetFPS(Frame);

    ball.radius = BallSize;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = BallSpeed;
    ball.speedY = BallSpeed;

    player.width = PaddleWidth;
    player.height = PaddleHeight;
    player.x = screenWidth - player.width - PaddleMargin;
    player.y = screenHeight / 2 - player.height / 2;
    player.speed = PlayerSpeed;

    cpu.width = PaddleWidth;
    cpu.height = PaddleHeight;
    cpu.x = PaddleMargin;
    cpu.y = screenHeight / 2 - cpu.height / 2;
    cpu.speed = CpuSpeed;

    auto countdown = Countdown(InitCount, screenWidth, screenHeight);
}


void UpdateGame() {
    ball.Update();
    player.Update();
    cpu.Update(ball.y);

    ball.speedX = CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}) ?
        ball.speedX * -1 : ball.speedX;
    ball.speedX = CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}) ?
        ball.speedX * -1 : ball.speedX;
}

void DrawGame(int screenWidth, int screenHeight) {
    BeginDrawing();
    ClearBackground(Mint);
    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, Snow);

    ball.Draw();
    player.Draw();
    cpu.Draw();

    DrawText(TextFormat("%i", ball.cpuScore), screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, Snow);
    DrawText(TextFormat("%i", ball.playerScore), 3 *  screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, Snow);

    EndDrawing();
}

int main() {
    print("Hello World!");

    InitGame(ScreenWidth, ScreenHeight);

    while (WindowShouldClose() == false) {
        UpdateGame();
        DrawGame(ScreenWidth, ScreenHeight);
    }

    CloseWindow();
    return 0;
}