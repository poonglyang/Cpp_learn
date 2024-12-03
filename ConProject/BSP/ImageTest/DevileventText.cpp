#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

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

	int input;

	bool isPlayerChoice = false;
	while (true) {
		//system("cls");


		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 41; j++) {
				switch (text[i][j])
				{
				case 0:
					cout << "  ";
					break;
				case 7:
					SetRGBColor(255, 255, 255);
					cout << "��";
					break;
				case 2:
					SetConsoleColor(8);
					cout << "��";
					break;
				case 3:
					SetRGBColor(93, 148, 255);
					cout << "��";
					break;
				case 4:
					SetRGBColor(61, 61, 147);
					cout << "��";
					break;
				case 5:
					SetConsoleColor(9);
					cout << "[�������� ���δ�] ";
					break;
				case 6:
					SetConsoleColor(15);
					cout << "��  ";
					SetConsoleColor(9);
					cout << "[�⵵�Ѵ�]\t\t\t[�⵵���� �ʴ´�]\t\t";
					SetConsoleColor(15);
					cout << "��";
					break;
				case 8:
					SetConsoleColor(9);
					cout << "[�⵵�Ѵ�]\t\t";
					SetConsoleColor(15);
					cout << "\t��  ";
					SetConsoleColor(9);
					cout << "[�⵵���� �ʴ´�]\t\t";
					SetConsoleColor(15);
					cout << "��";
					break;
				case 9:
					cout << "\t[�Ǹ� ������ �⵵�Ͽ����ϴ�]\t\t\t\t��";
					break;
				case 10:
					cout << "\t[������ �⵵���� �ʾҽ��ϴ�]\t\t\t\t��";
					break;
				default:
					break;
				}
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// �ؽ�Ʈ ���� ���� (�⺻)
				printf("\033[0m");
			}
			cout << endl;
		}

		if (isPlayerChoice) {
			cout << "[����ҷ��� �ƹ�Ű ������]" << endl;
			GetCommand();
			break;
		}

		input = GetCommand();

		switch (input) {
		case 100:
		case 77:
			cout << "���������� ����Ű �̵�" << endl;
			text[5][8] = 8;
			break;
		case 97:
		case 75:
			cout << "�������� ����Ű �̵�" << endl;
			text[5][8] = 6;
			break;
		case 13:
			if (text[5][8] == 6) {
				text[5][8] = 9;
				cout << "������ �⵵ �̺�Ʈ �־������" << endl;
				isPlayerChoice = true;
			}
			else if (text[5][8] == 8) {
				text[5][8] = 10;
				cout << "�̺�Ʈ ����" << endl;
				isPlayerChoice = true;
			}
			break;
		};
	}

}