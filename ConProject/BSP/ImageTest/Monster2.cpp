#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void SetConsoleColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
	SetConsoleTextAttribute(hConsole, color);         // ���� ����
}

void SetRGBColor(int r, int g, int b) {
	// ANSI escape code�� RGB ���� ����
	printf("\033[38;2;%d;%d;%dm", r, g, b);
}

void SetConsolePalette(COLORREF bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX csbiex;
	csbiex.cbSize = sizeof(csbiex);

	GetConsoleScreenBufferInfoEx(hConsole, &csbiex);

	// �ȷ�Ʈ�� ������ ���� (16���� ���� �� �ϳ��� ���)
	csbiex.ColorTable[0] = bgColor; // ��: ���� 0�� ���ο� ���� ����

	SetConsoleScreenBufferInfoEx(hConsole, &csbiex);

	// ���� 0(����)�� ������� ���
	SetConsoleTextAttribute(hConsole, 0);
}

int main() {
	int Monster1[20][20] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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
			case 1:
				SetRGBColor(50, 50, 50);
				std::cout << "��";
				break;
			case 2:
				SetRGBColor(255, 175, 163);
				std::cout << "��";
				break;
			case 3:
				SetRGBColor(255, 255, 163);
				std::cout << "��";
				break;
			case 4:
				SetRGBColor(249, 136, 163);
				std::cout << "��";
				break;
			case 5:
				SetRGBColor(230, 89, 105);
				std::cout << "��";
				break;
			case 6:
				SetRGBColor(172, 20, 75);
				std::cout << "��";
				break;

				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// �ؽ�Ʈ ���� ���� (�⺻)
				printf("\033[0m");
			}
			std::cout << std::endl;
		}
	}
}