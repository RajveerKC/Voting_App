#include "main.h"
#include "screens.h"
#include "raygui.h"

void backgroundRect() {
	Rectangle backgroundRec = { WELCOME_PADDING, WELCOME_PADDING, SCREEN_WIDTH - WELCOME_PADDING * 2, SCREEN_HEIGHT - WELCOME_PADDING * 2 };
	DrawRectangleRec(backgroundRec, LIGHTGRAY);
	DrawRectangleLines(backgroundRec.x, backgroundRec.y, backgroundRec.width, backgroundRec.height, BLACK);
}

void biggerbackgroundRect() {
	Rectangle backgroundRec = { WELCOME_PADDING / 2, WELCOME_PADDING / 2, SCREEN_WIDTH - WELCOME_PADDING, SCREEN_HEIGHT - WELCOME_PADDING };
	DrawRectangleRec(backgroundRec, LIGHTGRAY);
	DrawRectangleLines(backgroundRec.x, backgroundRec.y, backgroundRec.width, backgroundRec.height, BLACK);
}

void drawGridRect(Rectangle gridRect, Texture2D img, int n) {
	DrawRectangleRec(gridRect, SKYBLUE);

	Rectangle avatarSrc = { 0, 0, img.width, img.height };
	int imgW = 75;
	int imgH = 75;
	Rectangle avatarDest = { gridRect.x + (gridRect.width / 2) - (imgW / 2), gridRect.y + 10, imgW, imgH};
	Vector2 origin = { 0, 0 };
	DrawTexturePro(img, avatarSrc, avatarDest, origin, 0, WHITE);

	const char* name = "Test A";
	int textSize = 20;
	int textWidth = MeasureText(name, textSize);
	DrawText(name, gridRect.x + (gridRect.width / 2) - (textWidth / 2), avatarDest.y + avatarDest.height + 10, textSize, BLACK);

	const char* text3 = "VOTE";
	textWidth = MeasureText(text3, textSize);
	if (GuiButton((Rectangle) { gridRect.x + (gridRect.width / 2) / 2 - (textWidth) / 2, avatarDest.y + avatarDest.height + 50, textWidth * 2.4, gridRect.height * 0.25 }, text3)) {
		currentPos = 0;
	}

	DrawRectangleLines(gridRect.x, gridRect.y, gridRect.width, gridRect.height, BLUE);
}

void gridVote(int n, int row) {
	int i;
	Texture2D temp = LoadTexture("assets/Default Avatar.png");
	if (temp.id == 0) {
		printf("\n\nFailed to import Image.");
	}
 	Rectangle avatarSrc = { 0, 0, temp.width, temp.height };
	Rectangle avatarDest = { WELCOME_PADDING / 2 + 100, 100, 75, 75 };
	Vector2 origin = { 0, 0 };
	Rectangle GridPos = { WELCOME_PADDING, WELCOME_PADDING * 3.5 , 175, 200}; // 150W
	for (i = 0; i < n; i++) {
		if (i % 6 == 0 && i != 0) {
			GridPos.x = WELCOME_PADDING;
			GridPos.y += GridPos.height + 10;
		}
		else if (i != 0 ){
			GridPos.x += GridPos.width + 25; // 55
		}
		drawGridRect(GridPos, temp, i);
	}
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