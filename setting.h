#pragma once
#include "raylib.h"

// Game settings
const char* GameName = "Pong";
const int Frame = 60;
const int ScreenWidth = 1280;
const int ScreenHeight = 800;
const int CountTime = 1;
const int InitCount = 3;

// Colors
const Color Mint = {72, 209, 204, 255};
const Color Gold = {255, 215, 0, 255};
const Color Snow = {255, 255, 240, 255};

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
