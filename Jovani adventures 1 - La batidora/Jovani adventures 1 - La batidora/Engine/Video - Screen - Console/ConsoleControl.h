#pragma once

#define KB_W 87
#define KB_A 65
#define KB_S 83
#define KB_D 68
#define KB_R 82

#define KB_W_mini 119
#define KB_A_mini 97
#define KB_S_mini 115
#define KB_D_mini 100
#define KB_R_mini 114

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77

#define KB_SPACE 32
#define KB_ESCAPE 27

enum ConsoleColor {
	BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA, DARKYELLOW, LIGHTGREY,
	DARKGREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
};

void ConsoleSetColor(ConsoleColor ForeColor, ConsoleColor BackColor);
void ConsoleXY(short int x, short int y);
void ConsoleClear();
void ConsoleClearCharacter(char character, ConsoleColor ForeColor, ConsoleColor BackColor);
int ConsoleInKey();
void ConsoleWait(unsigned long milisecons);