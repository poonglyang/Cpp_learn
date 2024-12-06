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
		{0,0,0,71,71,0,0,0,0,0,0,0,0,0,0,71,71,0,0,0},
		{0,0,71,74,72,71,71,71,71,71,71,71,71,71,71,72,74,71,0,0},
		{0,0,71,72,74,73,73,73,73,73,73,73,73,73,73,74,72,71,0,0},
		{0,0,71,72,72,76,73,73,73,73,73,73,73,73,76,72,72,71,0,0},
		{0,0,71,74,72,76,73,76,73,73,73,73,76,73,76,72,74,71,0,0},
		{0,0,71,72,74,76,73,76,73,73,73,73,76,73,76,74,72,71,0,0},
		{0,0,71,72,74,76,73,76,6,6,6,6,76,73,76,74,72,71,0,0},
		{0,0,71,74,74,0,0,6,77,71,71,77,6,0,0,74,74,71,0,0},
		{0,0,0,71,71,79,71,0,6,6,6,6,0,71,79,71,71,0,0,0},
		{0,0,0,71,0,77,71,79,71,79,79,71,79,71,77,0,71,0,0,0},
		{0,0,0,71,0,0,77,79,71,77,77,71,79,77,0,0,71,0,0,0},
		{0,0,0,71,77,0,79,71,77,71,71,77,71,79,0,77,71,0,0,0},
		{0,0,0,71,79,0,0,0,79,0,0,79,0,0,0,79,71,0,0,0},
		{0,0,0,71,74,76,78,76,78,78,78,78,76,78,76,74,71,0,0,0},
		{0,0,0,71,74,76,78,76,78,78,78,78,76,78,76,74,71,0,0,0},
		{0,0,0,71,74,76,78,76,78,78,78,78,76,78,76,74,71,0,0,0},
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
			case 1:
				SetRGBColor(250, 250, 250);
				std::cout << "■";
				break;
			case 71:
				SetRGBColor(50, 50, 50);
				std::cout << "■";
				break;
			case 72:
				SetRGBColor(106, 120, 163);
				std::cout << "■";
				break;
			case 73:
				SetRGBColor(201, 117, 88);
				std::cout << "■";
				break;
			case 74:
				SetRGBColor(119, 138, 177);
				std::cout << "■";
				break;
			case 75:
				SetRGBColor(150, 79, 66);
				std::cout << "■";
				break;
			case 76:
				SetRGBColor(211, 52, 69);
				std::cout << "■";
				break;
			case 77:
				SetRGBColor(255, 244, 164);
				std::cout << "■";
				break;
			case 78:
				SetRGBColor(150, 79, 66);
				std::cout << "■";
				break;
			case 79:
				SetRGBColor(232, 197, 131);
				std::cout << "■";
				break;

				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}
			
		}
		std::cout << std::endl;
	}
}