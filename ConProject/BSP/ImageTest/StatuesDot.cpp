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


int main() {

	int statuesImage[46][60] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,3,2,2,2,3,2,2,1,0,0,0,0,1,2,2,2,2,2,3,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,3,2,2,2,3,2,2,1,0,0,0,0,1,2,2,2,2,2,3,3,2,2,3,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,3,2,2,2,3,3,2,2,1,0,0,0,0,1,2,2,3,2,2,3,3,2,2,3,3,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,2,2,2,2,3,2,2,3,2,2,3,3,3,2,2,2,1,1,1,1,2,2,3,3,2,2,3,3,3,2,3,3,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,2,2,2,2,2,3,2,2,3,2,2,3,3,3,3,2,1,4,4,4,4,1,3,3,3,3,2,3,3,3,2,2,3,3,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,2,2,2,2,3,2,2,3,3,2,3,3,3,3,3,1,4,4,1,1,4,4,1,3,3,3,2,3,3,3,3,2,3,3,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,2,2,2,2,2,3,2,2,3,3,3,3,3,3,3,3,1,4,1,6,6,1,4,1,3,3,3,3,3,3,3,3,2,3,3,3,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,2,2,2,2,3,3,2,3,3,1,1,1,1,3,3,3,1,5,1,7,7,1,5,1,3,3,3,1,1,1,1,3,3,3,3,3,3,2,3,2,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,2,2,2,2,2,3,2,3,3,1,2,2,2,2,1,1,3,1,5,1,7,7,1,5,4,1,1,1,2,2,2,2,1,3,3,3,3,3,2,3,3,2,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,2,2,2,2,2,3,3,3,1,2,2,2,2,2,2,2,1,3,1,5,1,1,5,1,5,1,2,2,2,2,2,2,2,1,3,3,3,3,2,3,3,2,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,2,2,2,2,3,3,3,1,2,2,2,2,2,2,2,2,2,1,7,1,8,8,1,7,1,4,1,3,2,2,2,2,2,2,1,3,3,3,2,3,3,3,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,2,2,2,2,2,3,3,1,2,2,2,2,2,2,2,3,2,2,1,7,1,9,9,1,7,1,5,4,1,3,2,2,3,2,2,2,1,3,3,3,3,3,3,3,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,2,2,2,2,3,3,3,1,2,2,2,2,3,2,3,2,2,3,1,6,1,9,9,1,6,1,1,1,3,3,2,2,3,2,2,2,1,3,3,3,3,3,3,3,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,2,2,3,2,3,3,1,2,2,2,2,3,2,3,3,2,3,3,1,6,1,8,8,1,6,1,3,3,3,3,3,2,3,3,2,2,2,1,3,3,3,3,3,3,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,2,2,2,3,2,3,3,1,2,2,2,2,3,2,3,2,2,3,1,7,1,1,8,8,1,1,7,1,3,3,3,3,2,2,3,2,2,2,1,3,3,3,3,3,3,3,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,2,2,3,3,2,3,1,2,2,2,2,3,2,2,3,2,3,3,1,7,1,1,9,8,1,1,7,1,3,3,3,3,3,2,3,3,2,3,2,1,3,3,3,3,3,3,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,2,3,1,1,2,1,1,2,2,3,2,3,2,3,3,2,3,1,7,1,3,1,9,8,1,3,1,7,1,3,3,3,3,2,3,3,2,3,2,1,1,3,1,1,3,3,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,2,1,0,0,1,0,1,2,2,3,2,3,2,3,3,3,3,1,1,3,3,1,9,9,1,3,3,1,1,3,3,3,3,3,3,3,2,3,2,1,2,1,0,0,1,3,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,1,2,2,3,3,2,3,2,3,3,3,3,3,3,3,1,1,9,9,8,1,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,2,2,3,3,2,3,3,3,3,3,3,1,3,1,0,1,9,9,8,1,1,3,1,3,3,3,3,3,3,3,3,3,3,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,2,3,3,3,3,3,3,3,1,3,1,0,1,0,0,1,9,9,8,1,0,1,0,1,3,1,3,3,3,3,3,3,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,2,3,3,3,1,3,3,1,0,1,0,0,0,0,1,9,8,9,8,9,1,0,0,0,1,0,1,3,3,1,3,3,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,2,2,3,3,1,1,3,1,0,0,0,0,0,0,0,1,9,8,8,8,1,0,0,0,0,0,0,0,1,3,1,1,3,3,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,2,3,3,1,0,1,3,1,0,0,0,0,0,0,1,9,8,1,1,1,0,0,0,0,0,0,0,0,1,3,1,0,1,3,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,2,3,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,6,6,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	cout << "실행" << endl;

	for (int i = 0; i < 46; i++) {
		for (int j = 0; j < 60; j++) {
			switch (statuesImage[i][j])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "■";
				break;
			case 2:
				SetRGBColor(223, 246, 245);
				cout << "■";
				break;
			case 3:
				SetRGBColor(183, 217, 219);
				cout << "■";
				break;
			case 4:
				SetRGBColor(237,181,204);
				cout << "■";
				break;
			case 5:
				SetRGBColor(209, 126, 159);
				cout << "■";
				break;
			case 6:
				SetRGBColor(222, 170, 126);
				cout << "■";
				break;
			case 7:
				SetRGBColor(254, 224, 182);
				cout << "■";
				break;
			case 8:
				SetRGBColor(219, 213, 178);
				cout << "■";
				break;
			case 9:
				SetRGBColor(247, 241, 223);
				cout << "■";
				break;

			default:
				break;
			}
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			// 텍스트 색상 리셋 (기본)
			printf("\033[0m");
		}
		std::cout << endl;
	}
}