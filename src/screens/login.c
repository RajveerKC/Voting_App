#include "main.h"
#include "screens.h"
#include "raygui.h"
void loginScreen() {
	ClearBackground(GRAY);

	backgroundRect();

	const char *welcomeText = "LOGIN";
	int textWidth = MeasureText(welcomeText, 100);
	DrawText(TextFormat(welcomeText), SCREEN_WIDTH / 2 - textWidth / 2, SCREEN_WIDTH * 0.1, 100, RED);
	const char* text1 = "VOTE NOW";
	textWidth = MeasureText(text1, 45);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 45);
	if (GuiButton((Rectangle) { SCREEN_WIDTH / 2 - (textWidth * 1.4) / 2, SCREEN_HEIGHT * 0.45, textWidth * 1.4, SCREEN_HEIGHT * 0.1 }, text1)) {
		currentPos = 1;
	}
	const char* text2 = "EXIT";
	textWidth = MeasureText(text2, 45);
	if (GuiButton((Rectangle) { SCREEN_WIDTH / 2 - (textWidth * 1.4) / 2, SCREEN_HEIGHT * 0.6, textWidth * 1.4, SCREEN_HEIGHT * 0.1 }, text2)) {
		windowClosed = true;
	}
}