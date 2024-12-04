#include <iostream>
#include <windows.h>
#include <conio.h>

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
	int changeShowArr[7][31] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,2},
		{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,5,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,6,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	while (true) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 31; j++) {
				switch (changeShowArr[i][j]) {
				case 0:
					std::cout << "  ";
					break;
				case 1:
					std::cout << "■";
					break;
				case 2:
					std::cout << "[재료]\t■\t    [장비]\t    ■\t  [소비]    ■";
					break;
				case 3:
					std::cout << "[장비]\t■\t    [소비]\t    ■\t  [재료]    ■";
					break;
				case 4:
					std::cout << "[소비]\t■\t    [재료]\t    ■\t  [장비]    ■";
					break;
				case 5:
					std::cout << "Ｑ";
					break;
				case 6:
					std::cout << "Ｅ";
					break;
				}
			}
			std::cout << std::endl;
		}

		GetCommand();
	}
}