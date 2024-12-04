#include <iostream>
#include <windows.h>
#include <conio.h>

int GetCommand()
{
	while (true) {
		if (_kbhit()) { // Ű �Է� ����
			int input = _getch(); // Ű �Է� �б�
			if (input == 224) { // ����Ű�� ù ��° ����Ʈ (224)
				input = _getch(); // �� ��° ����Ʈ (����Ű�� �ش��ϴ� ��)
				std::cout << "�Էµ� ��: " << input << std::endl;
				return input;
			}
			std::cout << "�Էµ� ��: " << input << std::endl;
			return input;
			// break; // ���� ����
		}
	}

	return -1;
}


void SetConsoleColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
	SetConsoleTextAttribute(hConsole, color);         // ���� ����
}

void SetRGBColor(int r, int g, int b) {
	// ANSI escape code�� RGB ���� ����
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
					std::cout << "��";
					break;
				case 2:
					std::cout << "[���]\t��\t    [���]\t    ��\t  [�Һ�]    ��";
					break;
				case 3:
					std::cout << "[���]\t��\t    [�Һ�]\t    ��\t  [���]    ��";
					break;
				case 4:
					std::cout << "[�Һ�]\t��\t    [���]\t    ��\t  [���]    ��";
					break;
				case 5:
					std::cout << "��";
					break;
				case 6:
					std::cout << "��";
					break;
				}
			}
			std::cout << std::endl;
		}

		GetCommand();
	}
}