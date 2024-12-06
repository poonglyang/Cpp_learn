#include "WellEvent.h"

WellEvent::WellEvent()
{
	isDrink = false;
}

void WellEvent::EventStart(Player* player)
{
	system("cls");

	if (isDrink) {
		std::cout << "[�̹� �칰�� �ִ� ���� ���̽��ϴ�]" << std::endl;
		Sleep(2000);
		return;
	}

	EventUpdate(player);
}

void WellEvent::EventUpdate(Player* player)
{
	int input;
	bool WellEventEnd = false;
	text[5][8] = 6;
	while (!WellEventEnd) {
		RenderEvent();

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
				case 5:
					SetConsoleColor(9);
					std::cout << "[�տ� �칰�� �ִ�]";
					break;
				case 6:
					SetConsoleColor(15);
					std::cout << "��  ";
					SetConsoleColor(9);
					std::cout << "[���Ŵ�]\t\t\t\t[�ȸ��Ŵ�]\t\t";
					SetConsoleColor(15);
					std::cout << "��";
					break;
				case 8:
					SetConsoleColor(9);
					std::cout << "[���Ŵ�]\t\t\t";
					SetConsoleColor(15);
					std::cout << "    ��  ";
					SetConsoleColor(9);
					std::cout << "[�ȸ��Ŵ�]\t\t";
					SetConsoleColor(15);
					std::cout << "��";
					break;
				case 9:
					std::cout << "\t   [�칰�� �� ���� ���̽��ϴ�]\t\t\t\t��";
					isDrink = true;
					WellEventEnd = true;
					
					break;
				case 10:
					std::cout  << "\t[�칰�� �� ���� ������ �ʾҽ��ϴ�]\t\t\t��";
					text[5][8] = 10;
					WellEventEnd = true;
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

		if (WellEventEnd && text[5][8] == 9) {
			playHelper::getCommand();
			RenderEvent();
			if (myMath::Mathf::Random::Value() < 0.7) {
				int delta = myMath::Mathf::Random::Range(30, player->GetMaxHp());
				std::cout << std::endl << std::endl << "\t\t\t���� ���� ���̽��ϴ�" << std::endl << "\t\tä���� " << delta << " ȸ���Ǿ����ϴ�" << std::endl;
				player->SetHp(delta, true);
			}
			else {
				int delta = myMath::Mathf::Random::Range(30, player->GetMaxHp());
				std::cout << std::endl << std::endl << "\t\t\t������ ���� ���̽��ϴ�" << std::endl << "\t\t�ߵ��Ǿ����ϴ�. " << delta << " ��ŭ �ߵ� ���ظ� ���߽��ϴ�" << std::endl;
				player->SetHp(-delta, true);
			}
			playHelper::getCommand();
			continue;
		}
		else if(WellEventEnd && text[5][8] == 10) {
			continue;
		}

		input = playHelper::getCommand();

		switch (input) {
		case 100:
		case 77:
			//std::cout << "���������� ����Ű �̵�" << std::endl;
			text[5][8] = 8;
			break;
		case 97:
		case 75:
			//std::cout << "�������� ����Ű �̵�" << std::endl;
			text[5][8] = 6;
			break;
		case 13:
			if (text[5][8] == 6) {
				text[5][8] = 9;
				//std::cout << "���ñ� �̺�Ʈ �־����" << std::endl;
				
			}
			else if (text[5][8] == 8) {
				text[5][8] = 10;
				//std::cout << "�칰�� �� ���� ������ �ʾҽ��ϴ�" << std::endl;
				
			}
			break;
		};
	}

	


}

void WellEvent::EventEnd()
{

}

void WellEvent::RenderEvent()
{
	system("cls");
	std::cout << "[�칰�� �߰��ߴ�] " << std::endl;
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			switch (wellImage[i][j])
			{
			case 0:
				std::cout << "  ";
				break;
			case 1:
				SetConsoleColor(7);
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
			default:
				break;
			}
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			// �ؽ�Ʈ ���� ���� (�⺻)
			printf("\033[0m");
		}
		std::cout << std::endl;
	}

	
}

