#include <iostream>
#include <windows.h>
#include "DungeonGenerator.h"

void SetConsoleFullscreen() {
	// 핸들 가져오기
	HWND consoleWindow = GetConsoleWindow();

	// 전체 화면 설정
	DWORD dwStyle = GetWindowLong(consoleWindow, GWL_STYLE);
	SetWindowLong(consoleWindow, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW); // 기본 창 스타일 제거

	// 화면 크기 가져오기
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);

	// 콘솔 창 크기 설정
	SetWindowPos(consoleWindow, HWND_TOP, 0, 0, desktop.right, desktop.bottom, SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
}

int main() {

	//SetConsoleFullscreen();

	//system("mode con:cols=300 lines=240");

	srand(time(0));
	
	while (true) {
		DungeonGenerator dg = DungeonGenerator(50, 50);

		vector<Node*> rooms = dg.CalculateDungeon(15, 10, 10, 0.1f, 0.95f, 2, 3);

		vector<Node*> cooridorVector = dg.GetCooridorVector();

		int count = 1;

		const int dungeonSize = 51;


		int testPrint[dungeonSize][dungeonSize] = { 0 };

		for (Node* cooridor : cooridorVector) {
			for (int i = cooridor->GetBottomLeftCorner().x; i <= cooridor->GetBottomRightCorner().x; i++) {
				testPrint[cooridor->GetBottomLeftCorner().y][i] = 7;
				testPrint[cooridor->GetTopLeftCorner().y][i] = 7;
			}

			for (int j = cooridor->GetBottomLeftCorner().y; j <= cooridor->GetTopLeftCorner().y; j++) {
				testPrint[j][cooridor->GetBottomLeftCorner().x] = 7;
				testPrint[j][cooridor->GetBottomRightCorner().x] = 7;
			}
		}


		for (Node* room : rooms) {
			/*cout << "[방 " << count << "]좌하단 모서리 좌표 ("
				<< room->GetBottomLeftCorner().x  << "," << room->GetBottomLeftCorner().y
				<< "), 우상단 모서리 좌표 (" << room->GetTopRightCorner().x << "," << room->GetTopRightCorner().y
				<< ")" << endl;*/

			vector<pair<int, int>> notWall;

			// 가로 벽 치기
			for (int i = room->GetBottomLeftCorner().x; i <= room->GetBottomRightCorner().x; i++) {

				if (testPrint[room->GetBottomLeftCorner().y][i] == 7) {
					// 만약 기존에 벽이였으면
					notWall.push_back(pair<int, int>(room->GetBottomLeftCorner().y, i)); // 벽이 아님에 넣어주고 (길이랑 겹쳤기 때문)
					testPrint[room->GetBottomLeftCorner().y][i] = 0;	// 
				}
				else
				{
					bool canWall = true;
					for (pair<int, int> point : notWall) {
						if (point.first == room->GetBottomLeftCorner().y && point.second == i) {
							canWall = false;
							break;
						}
					}
					if (canWall) {
						testPrint[room->GetBottomLeftCorner().y][i] = 7;
					}
				}

				if (testPrint[room->GetTopLeftCorner().y][i] == 7) {
					notWall.push_back(pair<int, int>(room->GetTopLeftCorner().y, i));
					testPrint[room->GetTopLeftCorner().y][i] = 0;
				}
				else {
					bool canWall = true;
					for (pair<int, int> point : notWall) {
						if (point.first == room->GetTopLeftCorner().y && point.second == i) {
							canWall = false;
							break;
						}
					}
					if (canWall) {
						testPrint[room->GetTopLeftCorner().y][i] = 7;
					}

				}
			}


			// 세로 벽 치기
			for (int j = room->GetBottomLeftCorner().y; j <= room->GetTopLeftCorner().y; j++) {
				if (testPrint[j][room->GetBottomLeftCorner().x] == 7) {
					notWall.push_back(pair<int, int>(j, room->GetBottomLeftCorner().x));
					testPrint[j][room->GetBottomLeftCorner().x] = 0;

				}
				else {
					bool canWall = true;
					for (pair<int, int> point : notWall) {
						if (point.first == j && point.second == room->GetBottomLeftCorner().x) {
							canWall = false;
							break;
						}
					}
					if (canWall) {
						testPrint[j][room->GetBottomLeftCorner().x] = 7;
					}
				}

				if (testPrint[j][room->GetBottomRightCorner().x] == 7) {
					notWall.push_back(pair<int, int>(j, room->GetBottomRightCorner().x));
					testPrint[j][room->GetBottomRightCorner().x] = 0;
				}
				else {
					bool canWall = true;
					for (pair<int, int> point : notWall) {
						if (point.first == j && point.second == room->GetBottomRightCorner().x) {
							canWall = false;
							break;
						}
					}
					if (canWall) {
						testPrint[j][room->GetBottomRightCorner().x] = 7;
					}
				}

				testPrint[room->GetBottomLeftCorner().y][room->GetBottomLeftCorner().x] = 7;
				testPrint[room->GetBottomRightCorner().y][room->GetBottomRightCorner().x] = 7;
				testPrint[room->GetTopLeftCorner().y][room->GetTopLeftCorner().x] = 7;
				testPrint[room->GetTopRightCorner().y][room->GetTopRightCorner().x] = 7;
			}



			// 가로 길이 이상하게 방 안에 있는 경우가 있으므로 방안의 것을 0으로 초기화
			for (int i = room->GetBottomLeftCorner().x + 1; i < room->GetBottomRightCorner().x; i++) {
				for (int j = room->GetBottomLeftCorner().y + 1; j < room->GetTopLeftCorner().y; j++) {
					testPrint[j][i] = 0;
				}
			}

			count++;
		}

		for (Node* cooridor : cooridorVector) {
			for (int i = cooridor->GetBottomLeftCorner().x + 1; i < cooridor->GetBottomRightCorner().x; i++) {
				for (int j = cooridor->GetBottomLeftCorner().y + 1; j < cooridor->GetTopLeftCorner().y; j++) {
					testPrint[j][i] = 0;
				}
			}
		}


		for (int i = 0; i < dungeonSize; i++) {
			for (int j = 0; j < dungeonSize; j++) {
				switch (testPrint[i][j]) {
				case 0:
					cout << "□";
					break;
				case 7:
					cout << "■";
					break;
				}
			}
			cout << endl;
		}

		for (auto& room : rooms) {
			delete room;
			room = nullptr;
		}

		int temp;
		cin >> temp;

		if (temp == 1) {
			break;
		}
	}

	
}