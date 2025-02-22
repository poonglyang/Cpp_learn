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
	int signboard[60][45] = {
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,4 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,4 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1} ,
		{0 ,0 ,0 ,0 ,1 ,2 ,1 ,2 ,2 ,2 ,2 ,1 ,4 ,1 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,1 ,4 ,1 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2} ,
		{0 ,0 ,0 ,0 ,1 ,2 ,1 ,3 ,3 ,3 ,3 ,1 ,4 ,1 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,1 ,4 ,1 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3} ,
		{0 ,0 ,0 ,0 ,1 ,3 ,1 ,1 ,1 ,1 ,1 ,4 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,4 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1} ,
		{0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,4 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0} ,
		{0 ,0 ,1 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,1 ,1 ,0 ,1 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,1 ,5 ,5 ,5 ,5 ,5 ,1 ,0 ,0} ,
		{0 ,0 ,1 ,5 ,6 ,6 ,6 ,7 ,7 ,7 ,7 ,7 ,7 ,6 ,6 ,7 ,6 ,6 ,6 ,5 ,5 ,7 ,1 ,5 ,7 ,7 ,7 ,7 ,7 ,6 ,6 ,6 ,7 ,7 ,7 ,7 ,7 ,5 ,5 ,1 ,1 ,0 ,0 ,0} ,
		{0 ,0 ,1 ,5 ,6 ,5 ,7 ,8 ,8 ,8 ,8 ,8 ,8 ,7 ,7 ,8 ,7 ,5 ,5 ,5 ,7 ,8 ,7 ,7 ,8 ,8 ,8 ,8 ,8 ,7 ,5 ,7 ,8 ,8 ,8 ,8 ,8 ,7 ,1 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,1 ,5 ,5 ,7 ,8 ,10,10,10,10,10,10,8 ,7 ,8 ,7 ,5 ,5 ,5 ,7 ,8 ,7 ,8 ,10,10,10,10,10,8 ,7 ,8 ,10,10,10,10,10,8 ,7 ,1 ,1 ,0 ,0 ,0} ,
		{0 ,0 ,1 ,5 ,5 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,7 ,10,7 ,8 ,7 ,5 ,5 ,5 ,7 ,8 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,8 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,8 ,7 ,9 ,9 ,1 ,0 ,0} ,
		{0 ,1 ,9 ,9 ,5 ,7 ,8 ,7 ,9 ,9 ,9 ,9 ,9 ,7 ,7 ,8 ,7 ,9 ,9 ,9 ,7 ,8 ,7 ,8 ,7 ,9 ,9 ,9 ,7 ,8 ,7 ,8 ,7 ,9 ,9 ,9 ,7 ,8 ,7 ,9 ,9 ,1 ,0 ,0} ,
		{0 ,1 ,9 ,9 ,9 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,7 ,9 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,8 ,7 ,8 ,7 ,9 ,9 ,9 ,7 ,8 ,7 ,8 ,7 ,11,11,11,7 ,8 ,7 ,11,1 ,0 ,0 ,0} ,
		{0 ,1 ,11,11,9 ,7 ,10,8 ,8 ,8 ,8 ,8 ,8 ,7 ,7 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,7 ,8 ,7 ,11,11,11,7 ,8 ,7 ,8 ,8 ,7 ,7 ,7 ,7 ,8 ,7 ,1 ,0 ,0 ,0 ,0} ,
		{0 ,1 ,1 ,1 ,11,1 ,7 ,10,10,10,10,10,10,8 ,7 ,8 ,10,10,10,10,10,8 ,7 ,8 ,7 ,1 ,1 ,1 ,7 ,8 ,7 ,8 ,10,8 ,8 ,8 ,8 ,10,7 ,5 ,1 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,1 ,5 ,5 ,7 ,7 ,7 ,7 ,7 ,7 ,8 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,8 ,7 ,8 ,7 ,5 ,5 ,5 ,7 ,8 ,7 ,8 ,7 ,10,10,10,10,7 ,6 ,5 ,1 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,1 ,5 ,5 ,7 ,6 ,6 ,6 ,6 ,6 ,7 ,8 ,7 ,8 ,7 ,6 ,6 ,6 ,7 ,8 ,7 ,8 ,7 ,6 ,6 ,5 ,7 ,8 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,5 ,5 ,5 ,1 ,0 ,0 ,0} ,
		{0 ,0 ,1 ,5 ,5 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,7 ,8 ,7 ,8 ,7 ,5 ,5 ,5 ,7 ,8 ,7 ,8 ,7 ,7 ,7 ,7 ,7 ,8 ,7 ,8 ,7 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,1 ,0 ,0 ,0} ,
		{0 ,0 ,1 ,5 ,5 ,7 ,10,8 ,8 ,8 ,8 ,8 ,8 ,10,7 ,8 ,7 ,5 ,5 ,5 ,7 ,8 ,7 ,10,8 ,8 ,8 ,8 ,8 ,10,7 ,8 ,7 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,9 ,1 ,0 ,0} ,
		{0 ,0 ,1 ,5 ,5 ,5 ,7 ,10,10,10,10,10,10,7 ,7 ,10,7 ,9 ,9 ,9 ,7 ,10,7 ,7 ,10,10,10,10,10,7 ,7 ,8 ,7 ,5 ,5 ,5 ,5 ,5 ,5 ,9 ,9 ,1 ,0 ,0} ,
		{0 ,0 ,1 ,9 ,9 ,9 ,9 ,7 ,7 ,7 ,7 ,7 ,7 ,9 ,9 ,7 ,9 ,9 ,9 ,9 ,9 ,7 ,9 ,9 ,7 ,7 ,7 ,7 ,7 ,5 ,5 ,7 ,5 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,1} ,
		{0 ,1 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,11,11,11,11,11,11,11,9 ,9 ,5 ,5 ,5 ,5 ,5 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,11,11,1} ,
		{1 ,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,1 ,1 ,1 ,1 ,1 ,1 ,11,11,9 ,5 ,5 ,5 ,5 ,9 ,9 ,9 ,11,11,11,11,11,11,11,1 ,1} ,
		{0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,11,9 ,9 ,9 ,9 ,9 ,11,11,11,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,9 ,9 ,9 ,9 ,11,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,11,11,11,11,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
		{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0} ,
	};

	for (int i = 0; i < 60; i++) {

		for (int j = 0; j < 45; j++) {

			switch (signboard[i][j]) {

			case 0:
				std::cout << "  ";
				break;
			case 1:
				SetRGBColor(50, 50, 50);
				std::cout << "■";
				break;
			case 2:
				SetRGBColor(160, 160, 160);
				std::cout << "■";
				break;
			case 3:
				SetRGBColor(130, 130, 130);
				std::cout << "■";
				break;
			case 4:
				SetRGBColor(109, 109, 109);
				std::cout << "■";
				break;
			case 5:
				SetRGBColor(193, 111, 18);
				std::cout << "■";
				break;
			case 6:
				SetRGBColor(236, 134, 19);
				std::cout << "■";
				break;
			case 7:
				SetRGBColor(246, 221, 221);
				std::cout << "■";
				break;
			case 8:
				SetRGBColor(177, 8, 8);
				std::cout << "■";
				break;
			case 9:
				SetRGBColor(102, 56, 5);
				std::cout << "■";
				break;
			case 10:
				SetRGBColor(105, 7, 7);
				std::cout << "■";
				break;
			case 11:
				SetRGBColor(69, 37, 2);
				std::cout << "■";
				break;
			}

			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			// 텍스트 색상 리셋 (기본)
			printf("\033[0m");
		}
		std::cout << std::endl;
	}
}