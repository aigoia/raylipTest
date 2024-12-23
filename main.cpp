#include "raylib.h"
#include <cstdio>
#include "ball.h"
#include "paddle.h"
#include "cpuPaddle.h"
#include "setting.h"

const int screenWidth = 1280;
const int screenHeight = 800;

Ball ball;
Paddle player;
CpuPaddle cpu;

void InitGame(int screenWidth, int screenHeight) {
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    ball.radius = 12;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 7;
    ball.speedY = 7;

    player.width = 25;
    player.height = 120;
    player.x = screenWidth - player.width - 10;
    player.y = screenHeight / 2 - player.height / 2;
    player.speed = 12;

    cpu.width = 25;
    cpu.height = 120;
    cpu.x = 10;
    cpu.y = screenHeight / 2 - cpu.height / 2;
    cpu.speed = 6;
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

    DrawText(TextFormat("%i", ball.cpuScore), screenWidth/4 -20, 20, 80, WHITE);
    DrawText(TextFormat("%i", ball.playerScore), 3*screenWidth/4 -20, 20, 80, WHITE);

    EndDrawing();
}

int main() {
    printf("Hello world!\n");

    InitGame(screenWidth, screenHeight);

    while (WindowShouldClose() == false) {
        UpdateGame();
        DrawGame(screenWidth, screenHeight);
    }

    CloseWindow();
    return 0;
}