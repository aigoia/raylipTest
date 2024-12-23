#include "raylib.h"
#include <cstdio>
#include "ball.h"
#include "paddle.h"
#include "cpu_paddle.h"
#include "setting.h"

Ball ball;
Paddle player;
CpuPaddle cpu;

int main() {
    printf("Hello world!\n");

    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "Pong");
    SetTargetFPS(60);

    ball.radius = 12;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 12;

    cpu.width = 25;
    cpu.height = 120;
    cpu.x = 10;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;

    while (WindowShouldClose() == false) {
        BeginDrawing();

        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        ball.speed_x = CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}) ?
            ball.speed_x * -1 : ball.speed_x;
        ball.speed_x = CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}) ?
            ball.speed_x * -1 : ball.speed_x;

        ClearBackground(Green);
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
        ball.Draw();
        player.Draw();
        cpu.Draw();
        DrawText(TextFormat("%i", ball.cpu_score), screen_width/4 -20, 20, 80, WHITE);
        DrawText(TextFormat("%i", ball.player_score), 3*screen_width/4 -20, 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}