#include "main.h"
#include "screens.h"
#include "raygui.h"

void backgroundRect() {
	Rectangle backgroundRec = { WELCOME_PADDING, WELCOME_PADDING, SCREEN_WIDTH - WELCOME_PADDING * 2, SCREEN_HEIGHT - WELCOME_PADDING * 2 };
	DrawRectangleRec(backgroundRec, LIGHTGRAY);
	DrawRectangleLines(backgroundRec.x, backgroundRec.y, backgroundRec.width, backgroundRec.height, BLACK);
}

void numInputBox(Rectangle textBox, char *input, int *letterCount, int maxChars) {
	if (CheckCollisionPointRec(GetMousePosition(), textBox)) {
		mouseOnText = true;
		int key = GetCharPressed();

		while (key > 0) {
			if (key >= '0' && key <= '9' && (*letterCount < maxChars)) {
				input[*letterCount] = (char)key;
				input[*letterCount + 1] = '\0';
				*letterCount = *letterCount + 1;
				printf("%s\n", input);
			}
			key = GetCharPressed();
		}
		if (IsKeyPressed(KEY_BACKSPACE)) {
			*letterCount = *letterCount - 1;
			if (*letterCount < 0) {
				*letterCount = 0;
			}
			input[*letterCount] = '\0';
		}
	}
	else {
		mouseOnText = false;
	}
	
	DrawRectangleRec(textBox, LIGHTGRAY);
	if ((mouseOnText)) {
		DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
	}
	else {
		DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, WHITE);
	}

	DrawText(input, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
}