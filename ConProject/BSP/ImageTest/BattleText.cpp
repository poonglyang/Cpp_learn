#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

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

	std::vector<std::string> monsterName = {
		"������  ",
		"���  ",
		"��ũ    ",
		"���̷���",
		"Ʈ��    ",
		"�̹�    "
	};

	std::vector<std::string> hpBar = {
		"�����������",
		"����������  ",
		"���������    ",
		"��������      ",
		"�������        ",
		"������          ",
		"�����            ",
		"����              ",
		"���                ",
		"��                  ",
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
				std::cout << "��";
				break;
			case 2:
				SetRGBColor(255, 255, 255);
				std::cout << "\t��  [�����ϱ�]\t\t\t���\t\t    [������ ���]\t\t  ��";
				break;
			case 3:
				SetRGBColor(255, 255, 255);
				std::cout << "\t   [�����ϱ�] \t\t\t���\t\t��    [������ ���]\t\t  ��";
				break;
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// �ؽ�Ʈ ���� ���� (�⺻)
				printf("\033[0m");
			}
		}
		std::cout << std::endl;
	}
}