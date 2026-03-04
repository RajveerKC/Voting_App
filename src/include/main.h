#include "raylib.h"
#include<stdio.h>

#ifndef GLOBALS
#define GLOBALS
extern int currentPos;
extern bool windowClosed;
extern bool mouseOnText;
#endif

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TARGET_FPS 100

#define WELCOME_PADDING 50