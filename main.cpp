#include "raylib.h"
#include <cstdio>
#include "ball.h"
#include "paddle.h"
#include "cpuPaddle.h"
#include "setting.h"

Ball ball;
Paddle player;
CpuPaddle cpu;

void InitGame(int screenWidth, int screenHeight) {
    InitWindow(screenWidth, screenHeight, "Pong");
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
    ClearBackground(Green);
    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

    ball.Draw();
    player.Draw();
    cpu.Draw();

    DrawText(TextFormat("%i", ball.cpuScore), screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, WHITE);
    DrawText(TextFormat("%i", ball.playerScore), 3 *  screenWidth / 4 - ScoreMargin, ScoreMargin, ScoreSize, WHITE);

    EndDrawing();
}

int main() {
    printf("Hello world!\n");

    InitGame(ScreenWidth, ScreenHeight);

    while (WindowShouldClose() == false) {
        UpdateGame();
        DrawGame(ScreenWidth, ScreenHeight);
    }

    CloseWindow();
    return 0;
}