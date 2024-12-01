#include "Game.h"

int Game::getCommand()
{
	while (true) {
		if (_kbhit()) { // 키 입력 감지
			int input = _getch(); // 키 입력 읽기
			std::cout << "입력된 값: " << input << std::endl;
			return input;
			// break; // 루프 종료
		}
	}

	return -1;
}

void Game::SetConsoleColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	SetConsoleTextAttribute(hConsole, color);         // 색상 변경
}

void Game::CreateMap()
{
	DungeonGenerator dg = DungeonGenerator(50, 50);

	vector<Node*> rooms = dg.CalculateDungeon(15, 10, 10, 0.1f, 0.95f, 2, 3);

	vector<Node*> cooridorVector = dg.GetCooridorVector();
	
	int testPrint[dungeonSize][dungeonSize] = { 0 };

	Map map;

	playerLocation.push_back(
		Vector2Int(
			Mathf::Random::Range(
				rooms[0]->GetBottomLeftCorner().y + 1, 
				rooms[0]->GetTopLeftCorner().y)
			, 
			Mathf::Random::Range(
				rooms[0]->GetBottomLeftCorner().x + 1,
				rooms[0]->GetBottomRightCorner().x)
		)
	);

	for (Node* cooridor : cooridorVector) {
		for (int i = cooridor->GetBottomLeftCorner().x; i <= cooridor->GetBottomRightCorner().x; i++) {
			map.mapArr[cooridor->GetBottomLeftCorner().y][i] = 7;
			map.mapArr[cooridor->GetTopLeftCorner().y][i] = 7;
		}

		for (int j = cooridor->GetBottomLeftCorner().y; j <= cooridor->GetTopLeftCorner().y; j++) {
			map.mapArr[j][cooridor->GetBottomLeftCorner().x] = 7;
			map.mapArr[j][cooridor->GetBottomRightCorner().x] = 7;
		}
	}

	for (Node* room : rooms) {

		vector<pair<int, int>> notWall;

		// 가로 벽 치기
		for (int i = room->GetBottomLeftCorner().x; i <= room->GetBottomRightCorner().x; i++) {

			if (map.mapArr[room->GetBottomLeftCorner().y][i] == 7) {
				// 만약 기존에 벽이였으면
				notWall.push_back(pair<int, int>(room->GetBottomLeftCorner().y, i)); // 벽이 아님에 넣어주고 (길이랑 겹쳤기 때문)
				map.mapArr[room->GetBottomLeftCorner().y][i] = 0;	// 
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
					map.mapArr[room->GetBottomLeftCorner().y][i] = 7;
				}
			}

			if (map.mapArr[room->GetTopLeftCorner().y][i] == 7) {
				notWall.push_back(pair<int, int>(room->GetTopLeftCorner().y, i));
				map.mapArr[room->GetTopLeftCorner().y][i] = 0;
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
					map.mapArr[room->GetTopLeftCorner().y][i] = 7;
				}

			}
		}


		// 세로 벽 치기
		for (int j = room->GetBottomLeftCorner().y; j <= room->GetTopLeftCorner().y; j++) {
			if (map.mapArr[j][room->GetBottomLeftCorner().x] == 7) {
				notWall.push_back(pair<int, int>(j, room->GetBottomLeftCorner().x));
				map.mapArr[j][room->GetBottomLeftCorner().x] = 0;

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
					map.mapArr[j][room->GetBottomLeftCorner().x] = 7;
				}
			}

			if (map.mapArr[j][room->GetBottomRightCorner().x] == 7) {
				notWall.push_back(pair<int, int>(j, room->GetBottomRightCorner().x));
				map.mapArr[j][room->GetBottomRightCorner().x] = 0;
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
					map.mapArr[j][room->GetBottomRightCorner().x] = 7;
				}
			}

			map.mapArr[room->GetBottomLeftCorner().y][room->GetBottomLeftCorner().x] = 7;
			map.mapArr[room->GetBottomRightCorner().y][room->GetBottomRightCorner().x] = 7;
			map.mapArr[room->GetTopLeftCorner().y][room->GetTopLeftCorner().x] = 7;
			map.mapArr[room->GetTopRightCorner().y][room->GetTopRightCorner().x] = 7;
		}



		// 가로 길이 이상하게 방 안에 있는 경우가 있으므로 방안의 것을 0으로 초기화
		for (int i = room->GetBottomLeftCorner().x + 1; i < room->GetBottomRightCorner().x; i++) {
			for (int j = room->GetBottomLeftCorner().y + 1; j < room->GetTopLeftCorner().y; j++) {
				map.mapArr[j][i] = 0;
			}
		}
	}

	for (Node* cooridor : cooridorVector) {
		for (int i = cooridor->GetBottomLeftCorner().x + 1; i < cooridor->GetBottomRightCorner().x; i++) {
			for (int j = cooridor->GetBottomLeftCorner().y + 1; j < cooridor->GetTopLeftCorner().y; j++) {
				map.mapArr[j][i] = 0;
			}
		}
	}

	allRooms.push_back(rooms);
	allcooridorVector.push_back(cooridorVector);
	allMapArr.push_back(map);

	//allMapArr.push_back(&testPrint);
}

void Game::RenderScene()
{
	system("cls");

	int tempArr[dungeonSize][dungeonSize] = { 0 };

	for (int i = 0; i < dungeonSize; i++) {
		for (int j = 0; j < dungeonSize; j++) {
			tempArr[i][j] = allMapArr[currentFloor - 1].mapArr[i][j];
		}
	}

	tempArr[playerLocation[currentFloor-1].x][playerLocation[currentFloor-1].y] = 9;
	cout << "플레이어 위치 : (" << playerLocation[currentFloor - 1].x
		<< ", " << playerLocation[currentFloor - 1].y << ")" << endl;

	for (int i = 0; i < dungeonSize; i++) {
		for (int j = 0; j < dungeonSize; j++) {
			switch (tempArr[i][j]) {
			case 0:
				cout << "□";
				break;
			case 7:
				cout << "■";
				break;
			case 9:
				SetConsoleColor(FOREGROUND_RED);
				cout << "◎";
				break;
			}

			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		cout << endl;
	}
}

Game::Game(int dungeonFloor) :dungeonFloor(dungeonFloor)
{
	currentFloor = 1;
	CreateMap();
	CreateMap();
	CreateMap();
	CreateMap();
	CreateMap();
}

void Game::GameStart()
{
	

	bool isGameOver = false;

	while (true) {
		if (isGameOver) {
			break;
		}

		RenderScene();

		int key = getCommand();

		switch (key) {
		case 119:
			if (allMapArr[currentFloor - 1].mapArr[playerLocation[currentFloor - 1].x - 1 ][playerLocation[currentFloor - 1].y] == 0) {
				playerLocation[currentFloor - 1].x -= 1;
			}
			break;
		case 115:
			if (allMapArr[currentFloor - 1].mapArr[playerLocation[currentFloor - 1].x + 1][playerLocation[currentFloor - 1].y] == 0) {
				playerLocation[currentFloor - 1].x += 1;
			}
			break;
		case 100:
			if (allMapArr[currentFloor - 1].mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y + 1] == 0) {
				playerLocation[currentFloor - 1].y += 1;
			}
			break;
		case 97:
			if (allMapArr[currentFloor - 1].mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y - 1] == 0) {
				playerLocation[currentFloor - 1].y += -1;
			}
			break;
		}


		/*int select;
		cout << "[몇층으로 이동하시겠습니까? (현재 " << currentFloor << "층]" << endl;
		cout << "1. 위로, 2. 아래로, 3. 종료 : ";

		cin >> select;

		switch (select) {
		case 1:
			if (currentFloor - 1 >= 4) {
				cout << "더이상 올라거나 내려갈 수 없습니다" << endl;
			}
			else {
				currentFloor += 1;
			}
			break;
		case 2:
			if (currentFloor - 1 <= 0) {
				cout << "더이상 올라거나 내려갈 수 없습니다" << endl;
			}
			else {
				currentFloor -= 1;
			}
			break;

		case 3:
			isGameOver = true;
			break;

		defalut :
			cout << "유효한 값이 아닙니다 " << endl;
			break;
		}*/
	}
}
