#include "main.h"
#include "screens.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int currentPos = 0;
bool windowClosed = false;

int main() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Voting App");
	SetTargetFPS(TARGET_FPS);
	while (!WindowShouldClose() && !windowClosed) {
		BeginDrawing();
		switch (currentPos) {
			case 0:
				welcomeScreen();
				break;
			case 1:
				loginScreen();
				break;
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}