#include "ChestEvent.h"

void ChestEvent::EventStart(Player* player)
{
	EventUpdate(player);
}

void ChestEvent::EventUpdate(Player* player)
{
	int input;
	bool EventEnd = false;
	text[5][8] == 6;
	while (!EventEnd) {
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
					std::cout << "■";
					break;
				case 2:
					SetConsoleColor(8);
					std::cout << "■";
					break;
				case 3:
					SetRGBColor(93, 148, 255);
					std::cout << "■";
					break;
				case 4:
					SetRGBColor(61, 61, 147);
					std::cout << "■";
					break;
				case 5:
					SetConsoleColor(6);
					std::cout << "[앞에 상자가 있다]\t\t\t\t";
					SetConsoleColor(15);
					std::cout << "■";
					break;
				case 6:
					SetConsoleColor(15);
					std::cout << "▶  ";
					SetRGBColor(99, 163, 35);
					std::cout << "[상자를 연다]\t\t\t[그냥 둔다]\t\t";
					SetConsoleColor(15);
					std::cout << "■";
					break;
				case 8:
					SetRGBColor(99, 163, 35);
					std::cout << "[상자를 연다]\t\t";
					SetConsoleColor(15);
					std::cout << "\t▶  ";
					SetRGBColor(99, 163, 35);
					std::cout << "[그냥 둔다]\t\t\t";
					SetConsoleColor(15);
					std::cout << "■";
					break;
				case 9:
					std::cout << "\t\t [상자를 열었다]\t\t\t\t■";
					isOpen = true;
					EventEnd = true;
					break;
				case 10:
					std::cout << "\t   [상자를 열지 않고 지나갔다]\t\t\t\t■";
					EventEnd = true;
					break;
				case 11:
					std::cout << "[상자안에 \t\t가 있다]\t■" << std::endl;
					break;
				case 12:
					SetConsoleColor(15);
					std::cout << "▶  ";
					SetRGBColor(99, 163, 35);
					std::cout << "[가져 간다]\t\t\t[그냥 둔다]\t\t\t";
					SetConsoleColor(15);
					std::cout << "■";
					break;
				case 13:
					SetRGBColor(99, 163, 35);
					std::cout << "[가져 간다]\t\t";
					SetConsoleColor(15);
					std::cout << "\t▶  ";
					SetRGBColor(99, 163, 35);
					std::cout << "[그냥 둔다]\t\t\t";
					SetConsoleColor(15);
					std::cout << "■";
					break;
				case 14:
					std::cout << "\t\t [~~~을 획득했다]\t\t\t\t■";
					break;
				case 15:
					std::cout << "\t [아이템을 가지지 않고 지나갔다]\t\t\t\t■";
					break;
				default:
					break;
				}
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}
			std::cout << std::endl;
		}

		if (EventEnd && text[5][8] == 9) {
			playHelper::getCommand();
			RenderEvent();
			if (isMimic) {
				std::cout << "\t\t\t미믹이 나타났습니다!!!" << std::endl;
				playHelper::getCommand();
				BattleEvent battleEvent = BattleEvent(5);
				battleEvent.EventStart(player);
				RenderEvent();
				std::cout << "\t\t\t왜 짜증나게 미믹이 나타나" << std::endl;
			}
			else {
				ItemBase* temp;

				if (rand() % 10 > 7) {
					temp = player->inventory->itemManager.GetEquipableItemByIndex(rand() % player->inventory->itemManager.GetEquipVectorSize());
					player->inventory->PushItem(temp);
					std::cout<<std::endl << std::endl<< "\t\t" << temp->GetItemName() << "을 얻었습니다" << std::endl;
				}
				else {
					int id = player->inventory->itemManager.GetRandomItemId();
					int count = rand() % 3;

					player->inventory->PushItem(id, count);
					std::cout << std::endl << std::endl << "\t\t아이템 획득" << std::endl;

				}
			}
			playHelper::getCommand();
			continue;
			break;
		}
		else if (EventEnd && text[5][8] == 10) {
			continue;
			break;
		}

		input = playHelper::getCommand();

		switch (input) {
		case 100:
		case 77:
			std::cout << "오른쪽으로 선택키 이동" << std::endl;
			if (isOpen) {
				text[5][8] = 13;
				break;
			}
			text[5][8] = 8;
			break;
		case 97:
		case 75:
			std::cout << "왼쪽으로 선택키 이동" << std::endl;
			if (isOpen) {
				text[5][8] = 12;
				break;
			}
			text[5][8] = 6;
			break;
		case 13:
			if (text[5][8] == 6 && !isOpen) {
				text[5][8] = 9;
				std::cout << "상자 이벤트 넣어줘야함" << std::endl;
				isOpen = true;
			}
			else if (text[5][8] == 8 && !isOpen) {
				text[5][8] = 10;
				std::cout << "이벤트 없음" << std::endl;
			}
			else if (text[5][8] == 12 && isOpen) {
				text[5][8] = 14;
			}
			else if (text[5][8] == 13 && isOpen) {
				text[5][8] = 15;
			}
			break;
		};
	}
}

void ChestEvent::EventEnd()
{
}

void ChestEvent::RenderEvent()
{
	system("cls");
	std::cout << "[상자를 발견했다] " << std::endl;

	if (!isOpen) {
		for (int i = 0; i < 29; i++) {
			for (int j = 0; j < 40; j++) {
				switch (chestClose[i][j]) {
				case 0:
					std::cout << "  ";
					break;
				case 1:
					SetRGBColor(67, 4, 7);
					std::cout << "■";
					break;
				case 2:
					SetRGBColor(106, 107, 125);
					std::cout << "■";
					break;
				case 3:
					SetRGBColor(154, 156, 169);
					std::cout << "■";
					break;
				case 4:
					SetRGBColor(255, 255, 255);
					std::cout << "■";
					break;
				case 5:
					SetRGBColor(237, 159, 1);
					std::cout << "■";
					break;
				case 6:
					SetRGBColor(179, 89, 1);
					std::cout << "■";
					break;
				case 7:
					SetRGBColor(255, 210, 129);
					std::cout << "■";
					break;
				case 8:
					SetRGBColor(241, 134, 4);
					std::cout << "■";
					break;
				case 9:
					SetRGBColor(153, 69, 0);
					std::cout << "■";
					break;
				}

				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}
			std::cout << std::endl;
		}
	}
	else {
		if (isPickUpItem) {
			for (int i = 0; i < 40; i++) {
				for (int j = 0; j < 40; j++) {
					switch (chestOpen[i][j]) {
					case 0:
						std::cout << "  ";
						break;
					case 1:
						SetRGBColor(67, 4, 7);
						std::cout << "■";
						break;
					case 2:
						SetRGBColor(106, 107, 125);
						std::cout << "■";
						break;
					case 3:
						SetRGBColor(154, 156, 169);
						std::cout << "■";
						break;
					case 4:
						SetRGBColor(255, 255, 255);
						std::cout << "■";
						break;
					case 5:
						SetRGBColor(237, 159, 1);
						std::cout << "■";
						break;
					case 6:
						SetRGBColor(179, 89, 1);
						std::cout << "■";
						break;
					case 7:
						SetRGBColor(255, 210, 129);
						std::cout << "■";
						break;
					case 8:
						SetRGBColor(241, 134, 4);
						std::cout << "■";
						break;
					case 9:
						SetRGBColor(153, 69, 0);
						std::cout << "■";
						break;
					}

					SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					// 텍스트 색상 리셋 (기본)
					printf("\033[0m");
				}
				std::cout << std::endl;
			}
		}
		else {
			for (int i = 0; i < 40; i++) {
				for (int j = 0; j < 40; j++) {
					switch (chestOpenAndItem[i][j]) {
					case 0:
						std::cout << "  ";
						break;
					case 1:
						SetRGBColor(67, 4, 7);
						std::cout << "■";
						break;
					case 2:
						SetRGBColor(106, 107, 125);
						std::cout << "■";
						break;
					case 3:
						SetRGBColor(154, 156, 169);
						std::cout << "■";
						break;
					case 4:
						SetRGBColor(255, 255, 255);
						std::cout << "■";
						break;
					case 5:
						SetRGBColor(237, 159, 1);
						std::cout << "■";
						break;
					case 6:
						SetRGBColor(179, 89, 1);
						std::cout << "■";
						break;
					case 7:
						SetRGBColor(255, 210, 129);
						std::cout << "■";
						break;
					case 8:
						SetRGBColor(241, 134, 4);
						std::cout << "■";
						break;
					case 9:
						SetRGBColor(153, 69, 0);
						std::cout << "■";
						break;
					case 10:
						SetRGBColor(252, 248, 112);
						std::cout << "■";
						break;
					case 11:
						SetRGBColor(239, 157, 21);
						std::cout << "■";
						break;
					case 12:
						SetRGBColor(252, 204, 16);
						std::cout << "■";
						break;
					case 13:
						SetRGBColor(229, 20, 200);
						std::cout << "■";
						break;
					case 14:
						SetRGBColor(20, 213, 244);
						std::cout << "■";
						break;
					case 15:
						SetRGBColor(216, 1, 16);
						std::cout << "■";
						break;
					}

					SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					// 텍스트 색상 리셋 (기본)
					printf("\033[0m");
				}
				std::cout << std::endl;
			}
		}
	}
}

ChestEvent::ChestEvent()
{
	isOpen = false;
	isPickUpItem = false;

	int randValue = rand() % 10;

	if (randValue < 2) {
		isMimic = true;
	}
	else {
		isMimic = false;
		false;
	}
}
