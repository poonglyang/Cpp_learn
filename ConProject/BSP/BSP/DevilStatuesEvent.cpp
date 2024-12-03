#include "DevilStatuesEvent.h"

DevilStatuesEvent::DevilStatuesEvent()
{
	isPray = false;
}

void DevilStatuesEvent::EventStart()
{
	system("cls");

	if (isPray) {
		std::cout << "[�̹� �⵵�ϼ̽��ϴ�]" << std::endl;
		Sleep(2000);
		return;
	}

	EventUpdate();
}

void DevilStatuesEvent::EventUpdate()
{
	RenderEvent();
}

void DevilStatuesEvent::EventEnd()
{
}

void DevilStatuesEvent::RenderEvent()
{
	int input = 0;
	bool isPlayerChoice = false;

	while (true) {
		system("cls");
		std::cout << "[�������� �߰��ߴ�] " << std::endl;

		for (int i = 0; i < 43; i++) {
			for (int j = 0; j < 64; j++) {
				switch (statuesImage[i][j])
				{
				case 0:
					std::cout << "  ";
					break;
				case 1:
					SetRGBColor(0, 0, 0);
					std::cout << "��";
					break;
				case 2:
					SetRGBColor(61, 63, 88);
					std::cout << "��";
					break;
				case 3:
					SetRGBColor(147, 120, 165);
					std::cout << "��";
					break;
				case 4:
					SetRGBColor(190, 165, 204);
					std::cout << "��";
					break;
				case 5:
					SetRGBColor(111, 87, 123);
					std::cout << "��";
					break;
				case 6:
					SetRGBColor(117, 102, 123);
					std::cout << "��";
					break;
				case 7:
					SetRGBColor(89, 76, 93);
					std::cout << "��";
					break;
				case 8:
					SetRGBColor(233, 227, 227);
					std::cout << "��";
					break;
				case 9:
					SetRGBColor(218, 207, 207);
					std::cout << "��";
					break;
				case 10:
					SetRGBColor(174, 164, 175);
					std::cout << "��";
					break;
				case 11:
					SetRGBColor(255, 0, 0);
					std::cout << "��";
					break;
				case 12:
					SetRGBColor(95, 98, 131);
					std::cout << "��";
					break;
				case 13:
					SetRGBColor(58, 59, 87);
					std::cout << "��";
					break;
				case 14:
					SetRGBColor(139, 149, 198);
					std::cout << "��";
					break;
				case 15:
					SetRGBColor(164, 194, 218);
					std::cout << "��";
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
					SetConsoleColor(9);
					std::cout << "[�������� ���δ�] ";
					break;
				case 6:
					SetConsoleColor(15);
					std::cout << "��  ";
					SetConsoleColor(9);
					std::cout << "[�⵵�Ѵ�]\t\t\t[�⵵���� �ʴ´�]\t\t";
					SetConsoleColor(15);
					std::cout << "��";
					break;
				case 8:
					SetConsoleColor(9);
					std::cout << "[�⵵�Ѵ�]\t\t";
					SetConsoleColor(15);
					std::cout << "\t��  ";
					SetConsoleColor(9);
					std::cout << "[�⵵���� �ʴ´�]\t\t";
					SetConsoleColor(15);
					std::cout << "��";
					break;
				case 9:
					std::cout << "\t[�Ǹ� ������ �⵵�Ͽ����ϴ�]\t\t\t\t��";
					isPray = true;
					break;
				case 10:
					std::cout << "\t[������ �⵵���� �ʾҽ��ϴ�]\t\t\t\t��";
					text[5][8] = 6;
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

		if (isPlayerChoice) {
			std::cout << "[����ҷ��� �ƹ�Ű ������]" << std::endl;
			playHelper::getCommand();
			break;
		}

		input = playHelper::getCommand();

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
				std::cout << "������ �⵵ �̺�Ʈ �־������" << std::endl;
				isPlayerChoice = true;
			}
			else if (text[5][8] == 8) {
				text[5][8] = 10;
				std::cout << "�̺�Ʈ ����" << std::endl;
				isPlayerChoice = true;
			}
			break;
		};
	}
}
