#include "main.h"
#include "screens.h"
#include "raygui.h"
void loginScreen() {
	ClearBackground(GRAY);

	backgroundRect();
	static char voterid[10] = { 0 };
	static char pin[10] = { 0 };
	static int letterCount1 = 0;
	static int letterCount2 = 0;

	// Banner Text
	const char *welcomeText = "LOGIN";
	int textWidth = MeasureText(welcomeText, 100);
	DrawText(welcomeText, SCREEN_WIDTH / 2 - textWidth / 2, SCREEN_WIDTH * 0.1, 100, RED);

	const char* incorrectText = "Incorrect Credentials Entered";
	textWidth = MeasureText(incorrectText, 25);
	if (incorrectLogin) {
		DrawText(incorrectText, SCREEN_WIDTH / 2 - textWidth / 2, SCREEN_HEIGHT * 0.3 + 50, 25, RED);
	}

	// Voter ID Input
	const char* text1 = "Voter ID";
	int inputBoxWidth = MeasureText("000000", 45);
	textWidth = MeasureText(text1, 45);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 45);
	Rectangle textBox1 = { SCREEN_WIDTH/2, SCREEN_HEIGHT * 0.45 + 8, inputBoxWidth - 5, inputBoxWidth * 6 / 16 };
	DrawText(text1, (SCREEN_WIDTH / 2 - (textWidth * 1.4) / 2) - (textBox1.width / 2), SCREEN_HEIGHT * 0.45 + textBox1.height / 4, 45, BLACK);
	numInputBox(textBox1, voterid, &letterCount1, 6);

	// Pin Input
	const char* text2 = "Pin";
	int inputBoxWidth2 = MeasureText("8888", 45);
	textWidth = MeasureText(text2, 45);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 45);
	Rectangle textBox2 = { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.6 + 8, inputBoxWidth2, inputBoxWidth2 * 9 / 16 };
	DrawText(text2, (SCREEN_WIDTH / 2 - (textWidth * 1.4) / 2) - (textBox2.width / 2), SCREEN_HEIGHT * 0.6 + textBox2.height / 4, 45, BLACK);
	numInputBox(textBox2, pin, &letterCount2, 4);


	const char* text3 = "Continue";
	textWidth = MeasureText(text3, 45);
	if (GuiButton((Rectangle) { SCREEN_WIDTH / 2 - (textWidth * 1.4) / 2, SCREEN_HEIGHT * 0.75, textWidth * 1.4, SCREEN_HEIGHT * 0.1 }, text3)) {
		if (checkLogin(voterid, pin) == 0) {
			currentPos = 2;
		}
	}
}