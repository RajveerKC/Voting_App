#include "main.h"
#include "screens.h"
#include "raygui.h"
void prScreen() {
	ClearBackground(GRAY);


	biggerbackgroundRect();
	// Banner Text
	const char* welcomeText = "PR Voting";
	int textWidth = MeasureText(welcomeText, 100);
	DrawText(welcomeText, SCREEN_WIDTH / 2 - textWidth / 2, SCREEN_WIDTH * 0.1 / 3, 100, RED);

	gridVote(12);
	const char* text3 = "DONE";
	textWidth = MeasureText(text3, 45);
	if (GuiButton((Rectangle) { SCREEN_WIDTH / 2 - (textWidth * 1.4) / 2, SCREEN_HEIGHT * 0.85, textWidth * 1.4, SCREEN_HEIGHT * 0.1 }, text3)) {
		currentPos = 0;
	}
}