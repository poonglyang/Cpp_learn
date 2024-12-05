#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int GetCommand()
{
	while (true) {
		if (_kbhit()) { // 키 입력 감지
			int input = _getch(); // 키 입력 읽기
			if (input == 224) { // 방향키의 첫 번째 바이트 (224)
				input = _getch(); // 두 번째 바이트 (방향키에 해당하는 값)
				std::cout << "입력된 값: " << input << std::endl;
				return input;
			}
			std::cout << "입력된 값: " << input << std::endl;
			return input;
			// break; // 루프 종료
		}
	}

	return -1;
}


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

	int buySellOutSeleteText[8][70] = {
		{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,4},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
	};

	int input;

	bool isPlayerChoice = false;
	while (true) {
		//system("cls");


		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 70; j++) {
				switch (buySellOutSeleteText[i][j])
				{
				case 0:
					cout << "  ";
					break;
				case 7:
					SetRGBColor(255, 255, 255);
					cout << "■";
					break;
				case 2:
					SetRGBColor(255, 255, 255);
					cout << "▶    [구매한다]\t    ■\t\t    [판매한다]\t\t    ■\t\t    [나간다]\t\t■";
					break;
				case 3:
					SetRGBColor(255, 255, 255);
					cout << "      [구매한다]\t    ■\t\t▶  [판매한다]\t\t    ■\t\t    [나간다]\t\t■";
					break;
				case 4:
					SetRGBColor(255, 255, 255);
					cout << "      [구매한다]\t    ■\t\t    [판매한다]\t\t    ■\t\t▶  [나간다]\t\t■";
					break;
				default:
					break;
				}
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}
			cout << endl;
		}

		if (isPlayerChoice) {
			cout << "[계속할려면 아무키 누르기]" << endl;
			GetCommand();
			break;
		}

		input = GetCommand();

		switch (input) {
		case 100:
		case 77:
			cout << "오른쪽으로 선택키 이동" << endl;
			text[5][8] = 8;
			break;
		case 97:
		case 75:
			cout << "왼쪽으로 선택키 이동" << endl;
			text[5][8] = 6;
			break;
		case 13:
			if (text[5][8] == 6) {
				text[5][8] = 9;
				cout << "마시기 이벤트 넣어야함" << endl;
				isPlayerChoice = true;
			}
			else if (text[5][8] == 8) {
				text[5][8] = 10;
				cout << "우물에 든 물을 마시지 않았습니다" << endl;
				isPlayerChoice = true;
			}
			break;
		};
	}

}