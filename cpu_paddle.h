#pragma once
#include "paddle.h"

class CpuPaddle : public Paddle {
public:
    void Update(int ball_y) {
        y = y + height/2 > ball_y ? y - speed :  y;
        y = y + height/2 <= ball_y ? y + speed :  y;

        LimitMovement();
    }
};
