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

	srand(time(0));

	DungeonGenerator dg = DungeonGenerator(100, 100);

	vector<Node*> rooms = dg.CalculateDungeon(20, 20, 20, 0.1f, 0.95f, 2, 4);
	  
	int count = 1;

	int testPrint[101][101] = {0};



	for (Node* room : rooms) {
		cout << "[방 " << count << "]좌하단 모서리 좌표 ("
			<< room->GetBottomLeftCorner().x  << "," << room->GetBottomLeftCorner().y
			<< "), 우상단 모서리 좌표 (" << room->GetTopRightCorner().x << "," << room->GetTopRightCorner().y
			<< ")" << endl;

		for (int i = room->GetBottomLeftCorner().x; i <= room->GetBottomRightCorner().x; i++) {
			testPrint[room->GetBottomLeftCorner().y][i] = 7;
			testPrint[room->GetTopLeftCorner().y][i] = 7;
		}

		for (int j = room->GetBottomLeftCorner().y; j <= room->GetTopLeftCorner().y; j++) {
			testPrint[j][room->GetBottomLeftCorner().x] = 7;
			testPrint[j][room->GetBottomRightCorner().x] = 7;

		}
		count++;
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
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
}