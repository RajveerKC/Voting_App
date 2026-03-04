#include "main.h"
#include "screens.h"
#include "raygui.h"

void backgroundRect() {
	Rectangle backgroundRec = { WELCOME_PADDING, WELCOME_PADDING, SCREEN_WIDTH - WELCOME_PADDING * 2, SCREEN_HEIGHT - WELCOME_PADDING * 2 };
	DrawRectangleRec(backgroundRec, LIGHTGRAY);
	DrawRectangleLines(backgroundRec.x, backgroundRec.y, backgroundRec.width, backgroundRec.height, BLACK);
}

