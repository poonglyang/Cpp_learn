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

	bool isOpen = false;

	bool isPickUpItem = false;

	bool isMimic = false;

	int text[10][41] = {
		{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,6},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
		{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
	};

	while (true) {
		int input;

		bool isEventEnd = false;
		while (true) {
			//system("cls");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 41; j++) {
					switch (text[i][j])
					{
					case 0:
						std::cout << "  ";
						break;
					case 7:
						SetRGBColor(255, 255, 255);
						std::cout << "��";
						break;
					case 2:
						SetConsoleColor(8);
						std::cout << "��";
						break;
					case 3:
						SetRGBColor(93, 148, 255);
						std::cout << "��";
						break;
					case 4:
						SetRGBColor(61, 61, 147);
						std::cout << "��";
						break;
					case 5:
						SetConsoleColor(6);
						std::cout << "[�տ� ���ڰ� �ִ�]";
						break;
					case 6:
						SetConsoleColor(15);
						std::cout << "��  ";
						SetRGBColor(99, 163, 35);
						std::cout << "[���ڸ� ����]\t\t\t[�׳� �д�]\t\t";
						SetConsoleColor(15);
						std::cout << "��";
						break;
					case 8:
						SetRGBColor(99, 163, 35);
						std::cout << "[���ڸ� ����]\t\t";
						SetConsoleColor(15);
						std::cout << "\t��  ";
						SetRGBColor(99, 163, 35);
						std::cout << "[�׳� �д�]\t\t\t";
						SetConsoleColor(15);
						std::cout << "��";
						break;
					case 9:
						std::cout << "\t\t [���ڸ� ������]\t\t\t\t��";
						if (isMimic) {

						}
						else {

						}
						break;
					case 10:
						std::cout << "\t   [���ڸ� ���� �ʰ� ��������]\t\t\t\t��";
						isEventEnd = true;
						break;
					default:
						break;
					}
					SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					// �ؽ�Ʈ ���� ���� (�⺻)
					printf("\033[0m");
				}
				std::cout << std::endl;
			}

			if (isEventEnd) {
				std::cout << "[����ҷ��� �ƹ�Ű ������]" << std::endl;
				GetCommand();
				break;
			}

			input = GetCommand();

			switch (input) {
			case 100:
			case 77:
				std::cout << "���������� ����Ű �̵�" << std::endl;
				text[5][8] = 8;
				break;
			case 97:
			case 75:
				std::cout << "�������� ����Ű �̵�" << std::endl;
				text[5][8] = 6;
				break;
			case 13:
				if (text[5][8] == 6) {
					text[5][8] = 9;
					std::cout << "���� �̺�Ʈ �־������" << std::endl;
					isEventEnd = true;
				}
				else if (text[5][8] == 8) {
					text[5][8] = 10;
					std::cout << "�̺�Ʈ ����" << std::endl;
					isEventEnd = true;
				}
				break;
			};
		}
	}

	

}