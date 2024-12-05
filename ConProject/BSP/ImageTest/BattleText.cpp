#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

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

	std::vector<std::string> monsterName = {
		"슬라임  ",
		"고블린  ",
		"오크    ",
		"스켈레톤",
		"트롤    ",
		"미믹    "
	};

	std::vector<std::string> hpBar = {
		"■■■■■■■■■■",
		"■■■■■■■■■  ",
		"■■■■■■■■    ",
		"■■■■■■■      ",
		"■■■■■■        ",
		"■■■■■          ",
		"■■■■            ",
		"■■■              ",
		"■■                ",
		"■                  ",
		"                    ",
	};

	int BattleImage[10][50] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,2},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};


	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 50; j++) {

			switch (BattleImage[i][j]) {

			case 0:
				std::cout << "  ";
				break;
			case 1:
				SetRGBColor(255, 255, 255);
				std::cout << "■";
				break;
			case 2:
				SetRGBColor(255, 255, 255);
				std::cout << "\t▶  [공격하기]\t\t\t■■\t\t    [아이템 사용]\t\t  ■";
				break;
			case 3:
				SetRGBColor(255, 255, 255);
				std::cout << "\t   [공격하기] \t\t\t■■\t\t▶    [아이템 사용]\t\t  ■";
				break;
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}
		}
		std::cout << std::endl;
	}
}