#include "StatuesEvent.h"

StatuesEvent::StatuesEvent()
{
	isPray = false;
}

void StatuesEvent::EventStart()
{
	system("cls");

	if (isPray) {
		cout << "[�̹� �⵵�ϼ̽��ϴ�]" << endl;
		Sleep(2000);
		return;
	}

	EventUpdate();
}

void StatuesEvent::EventUpdate()
{
	RenderEvent();
}

void StatuesEvent::EventEnd()
{
	
}

void StatuesEvent::RenderEvent()
{
	int input = 0;
	bool isPlayerChoice = false;

	while (true) {
		system("cls");
		cout << "[�������� �߰��ߴ�] " << endl;

		for (int i = 0; i < 46; i++) {
			for (int j = 0; j < 60; j++) {
				switch (statuesImage[i][j])
				{
				case 0:
					cout << "  ";
					break;
				case 1:
					cout << "��";
					break;
				case 2:
					SetRGBColor(223, 246, 245);
					cout << "��";
					break;
				case 3:
					SetRGBColor(183, 217, 219);
					cout << "��";
					break;
				case 4:
					SetRGBColor(237, 181, 204);
					cout << "��";
					break;
				case 5:
					SetRGBColor(209, 126, 159);
					cout << "��";
					break;
				case 6:
					SetRGBColor(222, 170, 126);
					cout << "��";
					break;
				case 7:
					SetRGBColor(254, 224, 182);
					cout << "��";
					break;
				case 8:
					SetRGBColor(219, 213, 178);
					cout << "��";
					break;
				case 9:
					SetRGBColor(247, 241, 223);
					cout << "��";
					break;

				default:
					break;
				}
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// �ؽ�Ʈ ���� ���� (�⺻)
				printf("\033[0m");
			}
			std::cout << endl;
		}

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
					cout << "\t[õ�� ������ �⵵�Ͽ����ϴ�]\t\t\t\t��";
					isPray = true;
					break;
				case 10:
					cout << "\t[������ �⵵���� �ʾҽ��ϴ�]\t\t\t\t��";
					text[5][8] = 6;
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
			playHelper::getCommand();
			break;
		}

		input = playHelper::getCommand(); 

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
