#include "StatuesEvent.h"

StatuesEvent::StatuesEvent()
{
	isPray = false;
}

void StatuesEvent::EventStart(Player* player)
{
	system("mode con: cols=150 lines=130");
	system("cls");

	if (isPray) {
		std::cout << "[�̹� �⵵�ϼ̽��ϴ�]" << std::endl;
		Sleep(2000);
		return;
	}

	EventUpdate(player);
}

void StatuesEvent::EventUpdate(Player* player)
{
	RenderEvent();
	if (isPray) {
		switch (rand()  % 6)
		{
		case 0:
			player->SetMaxHp(10 + rand() % 30, true);
			break;
		case 1:
			player->SetMaxMp(10 + rand() % 30, true);
			break;
		case 2:
			player->SetAtk(10 + rand() % 30, true);
			break;
		case 3:
			player->SetDef(10 + rand() % 30, true);
			break;
		case 4:
			player->SetCritialDamage(10 + rand() % 30, true);
			break;
		case 5:
			player->SetBehaviorSpeed(1 + rand() % 4, true);
			break;
		default:
			break;
		}
		//player.set
	}
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
		std::cout << "[�������� �߰��ߴ�] " << std::endl;

		for (int i = 0; i < 46; i++) {
			for (int j = 0; j < 60; j++) {
				switch (statuesImage[i][j])
				{
				case 0:
					std::cout << "  ";
					break;
				case 1:
					std::cout << "��";
					break;
				case 2:
					SetRGBColor(223, 246, 245);
					std::cout << "��";
					break;
				case 3:
					SetRGBColor(183, 217, 219);
					std::cout << "��";
					break;
				case 4:
					SetRGBColor(237, 181, 204);
					std::cout << "��";
					break;
				case 5:
					SetRGBColor(209, 126, 159);
					std::cout << "��";
					break;
				case 6:
					SetRGBColor(222, 170, 126);
					std::cout << "��";
					break;
				case 7:
					SetRGBColor(254, 224, 182);
					std::cout << "��";
					break;
				case 8:
					SetRGBColor(219, 213, 178);
					std::cout << "��";
					break;
				case 9:
					SetRGBColor(247, 241, 223);
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
					std::cout << "\t[õ�� ������ �⵵�Ͽ����ϴ�]\t\t\t\t��";
					
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
