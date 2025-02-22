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
	int boxOpenAndItem[40][40] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 1, 8, 6, 3, 3, 2, 3, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 3, 3, 2, 3, 6, 8, 1, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 1, 8, 6, 4, 3, 3, 3, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 4, 3, 3, 3, 6, 8, 1, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 1, 7, 6, 4, 3, 4, 3, 6, 7, 7, 7, 7, 7, 5, 5, 5, 5, 5, 5, 6, 4, 3, 4, 3, 6, 7, 1, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 1, 7, 6, 4, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 6, 7, 1, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 1, 1, 6, 6, 4, 4, 4, 4, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 5, 5, 6, 4, 4, 4, 4, 6, 6, 1, 1, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 1, 3, 1, 7, 6, 4, 4, 4, 4, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 4, 4, 4, 4, 6, 7, 1, 3, 1, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 1, 4, 1, 8, 6, 4, 4, 4, 4, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 4, 4, 4, 4, 6, 8, 1, 4, 1, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 1, 3, 1, 8, 6, 3, 4, 3, 4, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6, 3, 4, 3, 4, 6, 8, 1, 3, 1, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 1, 3, 1, 8, 6, 3, 3, 3, 4, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6, 3, 3, 3, 4, 6, 8, 1, 3, 1, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 1, 8, 6, 3, 3, 3, 3, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6, 3, 3, 3, 3, 6, 8, 1, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 1, 6, 6, 3, 3, 2, 3, 6, 8, 8, 8, 6, 6, 6, 6, 6, 8, 8, 8, 6, 3, 3, 2, 3, 6, 6, 1, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 1, 5, 5, 6, 2, 3, 2, 3, 6, 8, 8, 8, 6, 4, 4, 3, 6, 8, 8, 8, 6, 2, 3, 2, 2, 6, 5, 5, 1, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 1, 5, 6, 6, 2, 2, 2, 2, 6, 6, 6, 6, 6, 3, 0, 3, 6, 6, 6, 6, 6, 2, 2, 2, 2, 6, 6, 5, 1, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 3, 0, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 6, 1, 1, 1, 1, 1, 1, 1,10,11,10,10,12, 1, 1, 1, 1, 1, 1, 1, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 6, 1, 1, 1, 1,11,15,10,10,11, 1,12,12,12,10,10, 1, 1, 1, 1, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 6, 1, 1,12,12,12,11,11,11,12,12, 1,10,10,14,11,10,10, 1, 1, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 6, 1,12,11,14,12,10,10,13,12,11,10,10,11,10,10,11,10,10,10, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 6, 1,12,11,11,14,10,11,10,13,11,11,10,11,11,15,11,10,11,11, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 6,12,11,10,11,12,11,11,10,10,10,11,10,11,15,10,12,11,12,11, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 6,11,12,11,13,12,12,10,12,11, 6,11,10,10,12,10,12,10,12,11, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 6,11,12,12,11,11,11,11,12,12,12,12,11,11,11,11,12,12,12,11, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 3, 0, 3, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 3, 3, 3, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
	};

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			switch (boxOpenAndItem[i][j]) {
			case 0:
				std::cout << "  ";
				break;
			case 1:
				SetRGBColor(67, 4, 7);
				std::cout << "■";
				break;
			case 2:
				SetRGBColor(106, 107, 125);
				std::cout << "■";
				break;
			case 3:
				SetRGBColor(154, 156, 169);
				std::cout << "■";
				break;
			case 4:
				SetRGBColor(255, 255, 255);
				std::cout << "■";
				break;
			case 5:
				SetRGBColor(237, 159, 1);
				std::cout << "■";
				break;
			case 6:
				SetRGBColor(179, 89, 1);
				std::cout << "■";
				break;
			case 7:
				SetRGBColor(255, 210, 129);
				std::cout << "■";
				break;
			case 8:
				SetRGBColor(241, 134, 4);
				std::cout << "■";
				break;
			case 9:
				SetRGBColor(153, 69, 0);
				std::cout << "■";
				break;
			case 10:
				SetRGBColor(252, 248, 112);
				std::cout << "■";
				break;
			case 11:
				SetRGBColor(239, 157, 21);
				std::cout << "■";
				break;
			case 12:
				SetRGBColor(252, 204, 16);
				std::cout << "■";
				break;
			case 13:
				SetRGBColor(229, 20, 200);
				std::cout << "■";
				break;
			case 14:
				SetRGBColor(20, 213, 244);
				std::cout << "■";
				break;
			case 15:
				SetRGBColor(216, 1, 16);
				std::cout << "■";
				break;
			}

			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			// 텍스트 색상 리셋 (기본)
			printf("\033[0m");
		}
		std::cout << std::endl;
	}

	std::cout << "1 : ";
	SetRGBColor(67, 4, 7);
	std::cout << "■, 2 : ";
	SetRGBColor(106, 107, 125);
	std::cout << "■, 3 : ";
	SetRGBColor(154, 156, 169);
	std::cout << "■, 4 : ";
	SetRGBColor(255, 255, 255);
	std::cout << "■, 5 : ";
	SetRGBColor(237, 159, 1);
	std::cout << "■, 6 : ";
	SetRGBColor(179, 89, 1);
	std::cout << "■, 7 : ";
	SetRGBColor(255, 210, 129);
	std::cout << "■, 8 : ";
	SetRGBColor(241, 134, 4);
	std::cout << "■, 9 : ";
	SetRGBColor(153, 69, 0);
	std::cout << "■";
}