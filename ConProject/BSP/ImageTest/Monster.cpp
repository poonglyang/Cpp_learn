#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void SetConsoleColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	SetConsoleTextAttribute(hConsole, color);         // 색상 변경
}

void SetRGBColor(int r, int g, int b) {
	// ANSI escape code로 RGB 색상 설정
	printf("\033[38;2;%d;%d;%dm", r, g, b);
}

void SetConsolePalette(COLORREF bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX csbiex;
	csbiex.cbSize = sizeof(csbiex);

	GetConsoleScreenBufferInfoEx(hConsole, &csbiex);

	// 팔레트의 색상을 변경 (16개의 슬롯 중 하나를 사용)
	csbiex.ColorTable[0] = bgColor; // 예: 슬롯 0에 새로운 색상 설정

	SetConsoleScreenBufferInfoEx(hConsole, &csbiex);

	// 슬롯 0(검정)을 배경으로 사용
	SetConsoleTextAttribute(hConsole, 0);
}

int main() {
	int Monster1[20][20] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,21,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,21,21,21,21,21,22,21,0,0,0,0},
		{0,0,0,0,0,0,0,21,21,22,22,24,24,24,23,21,0,0,0,0},
		{0,0,0,0,0,0,21,22,23,23,24,25,25,24,22,21,0,0,0,0},
		{0,0,0,0,0,21,22,23,23,22,24,24,25,25,24,22,21,0,0,0},
		{0,0,0,0,21,22,22,23,23,22,24,24,24,25,25,24,22,21,0,0},
		{0,0,0,0,21,22,22,22,22,24,24,24,24,25,25,24,22,21,0,0},
		{0,0,0,0,21,22,23,21,24,24,24,21,24,25,25,25,24,21,0,0},
		{0,0,0,0,21,22,24,21,24,24,24,21,24,25,25,25,24,21,0,0},
		{0,0,0,0,21,22,24,24,24,24,24,24,24,25,25,25,25,21,0,0},
		{0,0,0,0,0,21,25,26,26,26,26,26,26,26,26,25,21,0,0,0},
		{0,0,0,0,0,0,21,21,26,26,26,26,26,26,21,21,0,0,0,0},
		{0,0,0,0,0,0,0,0,21,21,21,21,21,21,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {

			switch (Monster1[i][j]) {

			case 0:
				std::cout << "  ";
				break;
			case 21:
				SetRGBColor(50, 50, 50);
				std::cout << "■";
				break;
			case 22:
				SetRGBColor(255, 175, 163);
				std::cout << "■";
				break;
			case 23:
				SetRGBColor(255, 255, 163);
				std::cout << "■";
				break;
			case 24:
				SetRGBColor(249, 136, 163);
				std::cout << "■";
				break;
			case 25:
				SetRGBColor(230, 89, 105);
				std::cout << "■";
				break;
			case 26:
				SetRGBColor(172, 20, 75);
				std::cout << "■";
				break;

			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			// 텍스트 색상 리셋 (기본)
			printf("\033[0m");
		}
		std::cout << std::endl;
	}
}