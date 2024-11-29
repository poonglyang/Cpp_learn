#include <iostream>

#include "DungeonGenerator.h"

int main() {
	srand(time(0));

	DungeonGenerator dg = DungeonGenerator(100, 100);

	vector<Node*> rooms = dg.CalculateDungeon(10, 15, 15, 0.1f, 0.95f, 2, 2);
	
	int count = 1;

	int testPrint[101][101] = {};

	for (Node* room : rooms) {
		/*cout << "[방 " << count << "]좌하단 모서리 좌표 ("
			<< room->GetBottomLeftCorner().x  << "," << room->GetBottomLeftCorner().y
			<< "), 우상단 모서리 좌표 (" << room->GetTopRightCorner().x << "," << room->GetTopRightCorner().y
			<< ")" << endl;*/

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
}