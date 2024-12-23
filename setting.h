#pragma once
#include "raylib.h"

// Game settings
const char* GameName = "Pong";
const int Frame = 60;
const int ScreenWidth = 1280;
const int ScreenHeight = 800;

// Colors
const Color Green = {38, 185, 154, 255};
const Color Yellow = {243, 213, 91, 255};

// Margins 
const int PaddleMargin = 10;
const int ScoreMargin = 20;

// Sizes
const int ScoreSize = 80;
const int PaddleWidth = 25;
const int PaddleHeight = 120;
const int BallSize = 12;

// Speeds
const int PlayerSpeed = 12;
const int CpuSpeed = 6;
const int BallSpeed = 7;
