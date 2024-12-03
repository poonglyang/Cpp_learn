#include "WellEvent.h"

WellEvent::WellEvent()
{
	isDrink = false;
}

void WellEvent::EventStart()
{
	system("cls");

	if (isDrink) {
		cout << "[이미 우물에 있는 물을 마셨습니다]" << endl;
		Sleep(2000);
		return;
	}

	EventUpdate();
}

void WellEvent::EventUpdate()
{
	RenderEvent();
}

void WellEvent::EventEnd()
{

}

void WellEvent::RenderEvent()
{
	int input = 0;
	bool isPlayerChoice = false;
	
	while (true) {
		system("cls");
		cout << "[우물을 발견했다] " << endl;
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 40; j++) {
				switch (wellImage[i][j])
				{
				case 0:
					cout << "  ";
					break;
				case 1:
					SetConsoleColor(7);
					cout << "■";
					break;
				case 2:
					SetConsoleColor(8);
					cout << "■";
					break;
				case 3:
					SetRGBColor(93, 148, 255);
					cout << "■";
					break;
				case 4:
					SetRGBColor(61, 61, 147);
					cout << "■";
					break;
				default:
					break;
				}
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}
			cout << endl;
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
					cout << "■";
					break;
				case 5:
					SetConsoleColor(9);
					cout << "[앞에 우물이 있다]";
					break;
				case 6:
					SetConsoleColor(15);
					cout << "▶  ";
					SetConsoleColor(9);
					cout << "[마신다]\t\t\t\t[안마신다]\t\t";
					SetConsoleColor(15);
					cout << "■";
					break;
				case 8:
					SetConsoleColor(9);
					cout << "[마신다]\t\t\t";
					SetConsoleColor(15);
					cout << "    ▶  ";
					SetConsoleColor(9);
					cout << "[안마신다]\t\t";
					SetConsoleColor(15);
					cout << "■";
					break;
				case 9:
					cout << "\t   [우물에 든 물을 마셨습니다]\t\t\t\t■";
					isDrink = true;
					break;
				case 10:
					cout << "\t[우물에 든 물을 마시지 않았습니다]\t\t\t■";
					text[5][8] = 6;
					break;
				default:
					break;
				}
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				// 텍스트 색상 리셋 (기본)
				printf("\033[0m");
			}
			cout << endl;
		}

		input = playHelper::getCommand();

		if (isPlayerChoice) {
			cout << "\t\t\t[계속할려면 아무키 누르기]" << endl;
			playHelper::getCommand();
			break;
		}


		switch (input) {
		case 100:
		case 77:
			//cout << "오른쪽으로 선택키 이동" << endl;
			text[5][8] = 8;
			break;
		case 97:
		case 75:
			//cout << "왼쪽으로 선택키 이동" << endl;
			text[5][8] = 6;
			break;
		case 13:
			if (text[5][8] == 6) {
				text[5][8] = 9;
				//cout << "마시기 이벤트 넣어야함" << endl;
				isPlayerChoice = true;
			}
			else if (text[5][8] == 8) {
				text[5][8] = 10;
				//cout << "우물에 든 물을 마시지 않았습니다" << endl;
				isPlayerChoice = true;
			}
			break;
		};
	}
	


}
