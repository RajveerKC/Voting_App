#include "main.h"
#include "screens.h"
#include "db.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int currentPos = 0;
bool windowClosed = false;
bool mouseOnText = false;
struct Candidate readCandidates[CANDIDATE_NUM];
Texture2D CandidatePfp[CANDIDATE_NUM];

int main() {
	int z, counter = 0;
	if ((z = readCandidateData()) == 1) {
		return 1;
	}
	
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Voting App");
	SetTargetFPS(TARGET_FPS);
	while (!WindowShouldClose() && !windowClosed) {
		BeginDrawing();
		if (counter == 0) {
			if ((z = readCandidatePfps()) == 1) {
				return 1;
			}
			counter++;
		}
		switch (currentPos) {
			case 0:
				welcomeScreen();
				break;
			case 1:
				loginScreen();
				break;
			case 2:
				fptpScreen();
				break;
			case 3:
				prScreen();
				break;
		}
		if (mouseOnText) {
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
		}
		else {
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}