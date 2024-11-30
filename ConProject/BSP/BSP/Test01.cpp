#include <iostream>
#include <windows.h>
#include "DungeonGenerator.h"

void SetConsoleFullscreen() {
	// �ڵ� ��������
	HWND consoleWindow = GetConsoleWindow();

	// ��ü ȭ�� ����
	DWORD dwStyle = GetWindowLong(consoleWindow, GWL_STYLE);
	SetWindowLong(consoleWindow, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW); // �⺻ â ��Ÿ�� ����

	// ȭ�� ũ�� ��������
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);

	// �ܼ� â ũ�� ����
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
		cout << "[�� " << count << "]���ϴ� �𼭸� ��ǥ ("
			<< room->GetBottomLeftCorner().x  << "," << room->GetBottomLeftCorner().y
			<< "), ���� �𼭸� ��ǥ (" << room->GetTopRightCorner().x << "," << room->GetTopRightCorner().y
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
				cout << "��";
				break;
			case 7:
				cout << "��";
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