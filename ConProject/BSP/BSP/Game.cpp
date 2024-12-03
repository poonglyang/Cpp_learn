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

void Game::deleteConsolCursor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void Game::SetConsoleColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	SetConsoleTextAttribute(hConsole, color);         // 색상 변경
}

void Game::SetMonster()
{
	// 몬스터 세팅
	for (int i = 0; i < dungeon.size(); i++) {
		int roomIndex = -1;
		for (Node* room : dungeon[i].rooms) {
			roomIndex++;
			if (roomIndex == shopPosRoomIndex[i]) {
				continue;
			}
			
			int monsterCount = GetMonsterCount(room);	// 생성할 몬스터 갯수

			int count = 0;

			while (count <= monsterCount ) {
				int monsterPosX = Mathf::Random::Range(
					room->GetBottomLeftCorner().x + 1, 
					room->GetBottomRightCorner().x
				);
				int monsterPosy = Mathf::Random::Range(
					room->GetBottomLeftCorner().y + 1, 
					room->GetTopLeftCorner().y
				);

				if (dungeon[i].map.mapArr[monsterPosy][monsterPosX] == 0) {
					dungeon[i].map.mapArr[monsterPosy][monsterPosX] = 4;
					count++;
				}
			}
		}
	}
}

void Game::SetBox()
{
	for (int i = 0; i < dungeon.size(); i++) {
		int roomIndex = -1;
		for (Node* room : dungeon[i].rooms) {
			roomIndex++;
			if (roomIndex == shopPosRoomIndex[i] || roomIndex == statusPosRoomIndex[i]) {
				continue;
			}

			int boxCount = 1 + rand() % 2;	// 생성할 몬스터 갯수

			int count = 0;

			while (count <= boxCount) {
				int boxPosX = Mathf::Random::Range(
					room->GetBottomLeftCorner().x + 1,
					room->GetBottomRightCorner().x
				);
				int boxPosy = Mathf::Random::Range(
					room->GetBottomLeftCorner().y + 1,
					room->GetTopLeftCorner().y
				);

				if (dungeon[i].map.mapArr[boxPosy][boxPosX] == 0) {
					dungeon[i].map.mapArr[boxPosy][boxPosX] = 60;
					count++;
				}
			}
		}
	}
}

void Game::SetStatues()
{
	for (int i = 0; i < dungeon.size(); i++) {
		vector<Node*> canPlaceStatues;	// 조각상을 놓을 수 있는 방을 뽑음
		for (Node* room : dungeon[i].rooms) {
			if (room->GetTopRightCorner().x - room->GetBottomLeftCorner().x > 5
				&& room->GetTopRightCorner().y - room->GetBottomLeftCorner().y > 5
				&& dungeon[i].rooms[upStairsRoomIndex[i]] != room	// 위로 올라가는 계단 없는 방
				&& dungeon[i].rooms[0] != room						// 아래로 내려가는 계단 없는 방
				&& dungeon[i].rooms[wellPosRoomIndex[i]] != room) {
				if (shopPosRoomIndex[i] != -999 && dungeon[i].rooms[shopPosRoomIndex[i]] != room ) {
					canPlaceStatues.push_back(room);
				}
			}
		}

		if (canPlaceStatues.size() > 0) {
			int roomIndex = Mathf::Random::Range(0, canPlaceStatues.size());

			Vector2Int statuesPoint = canPlaceStatues[roomIndex]->GetNodeMiddlePoint();

			statusPoint.push_back(statuesPoint);
			statusPosRoomIndex.push_back(roomIndex);

			if (rand() % 2) {
				dungeon[i].map.mapArr[statuesPoint.y - 1][statuesPoint.x - 1] = 50;
				dungeon[i].map.mapArr[statuesPoint.y - 1][statuesPoint.x] = 51;
				dungeon[i].map.mapArr[statuesPoint.y - 1][statuesPoint.x + 1] = 52;
				dungeon[i].map.mapArr[statuesPoint.y][statuesPoint.x] = 53;
				dungeon[i].map.mapArr[statuesPoint.y + 1][statuesPoint.x] = 53;
			}
			else {
				dungeon[i].map.mapArr[statuesPoint.y - 1][statuesPoint.x - 1] = 54;
				dungeon[i].map.mapArr[statuesPoint.y - 1][statuesPoint.x] = 51;
				dungeon[i].map.mapArr[statuesPoint.y - 1][statuesPoint.x + 1] = 55;
				dungeon[i].map.mapArr[statuesPoint.y][statuesPoint.x] = 56;
				dungeon[i].map.mapArr[statuesPoint.y + 1][statuesPoint.x] = 56;
			}
		}
		else {
			statusPoint.push_back(Vector2Int::zero());
			statusPosRoomIndex.push_back(-999);
		}
	}
}

void Game::SetWell()
{
	for (int i = 0; i < dungeonFloor; i++) {
		int wellRoomIndex;
		while (true) {
			wellRoomIndex = Mathf::Random::Range(1, dungeon[i].rooms.size());
			if (wellRoomIndex != shopPosRoomIndex[i]) {
				wellPosRoomIndex.push_back(wellRoomIndex);
				break;
			}
		}
	
		Vector2Int shopPoint = dungeon[i].rooms[wellRoomIndex]->GetNodeMiddlePoint();
		if (dungeon[i].map.mapArr[shopPoint.y][shopPoint.x] == 0) {
			dungeon[i].map.mapArr[shopPoint.y][shopPoint.x] = 12;
		}
	}
}

void Game::SetStairAndShop()
{	
	for (int i = 0; i < dungeon.size(); i++) {
		// 아래층으로 내려가는 계단 세팅 (플레이어의 시작 위치 주변에 내려가는 계단이 있음)
		if (dungeon[i].map.mapArr[playerLocation[i].x][playerLocation[i].y + 1] == 0) {
			dungeon[i].map.mapArr[playerLocation[i].x][playerLocation[i].y + 1] = 2;
			downStairs.push_back(pair(
				Vector2Int(playerLocation[i].x, playerLocation[i].y + 1),
				playerLocation[i])
			);
		}
		else if (dungeon[i].map.mapArr[playerLocation[i].x - 1][playerLocation[i].y] == 0) {
			dungeon[i].map.mapArr[playerLocation[i].x - 1][playerLocation[i].y] = 2;
			downStairs.push_back(pair(
				Vector2Int(playerLocation[i].x - 1, playerLocation[i].y),
				playerLocation[i])
			);
		}
		else if (dungeon[i].map.mapArr[playerLocation[i].x + 1][playerLocation[i].y] == 0) {
			dungeon[i].map.mapArr[playerLocation[i].x + 1][playerLocation[i].y] = 2;
			downStairs.push_back(pair(
				Vector2Int(playerLocation[i].x + 1, playerLocation[i].y),
				playerLocation[i])
			);
		}
		else {
			dungeon[i].map.mapArr[playerLocation[i].x][playerLocation[i].y - 1] = 2;
			downStairs.push_back(
				pair(Vector2Int(playerLocation[i].x, playerLocation[i].y - 1),
					playerLocation[i])
			);
		}

		// 윗 층으로 올라가는 계단 위치 세팅
		int upStairsRoomIndex = Mathf::Random::Range(1, dungeon[i].rooms.size());
		Vector2Int upStairsPos = PlaceStructuresInRoom(dungeon[i].rooms[upStairsRoomIndex]);
		dungeon[i].map.mapArr[upStairsPos.x][upStairsPos.y] = 3;
		upStairs.push_back(upStairsPos);
		this->upStairsRoomIndex.push_back(upStairsRoomIndex);

		// 상점 세팅
		// 트리 인덱스가 가장 큰 곳(길이 하나밖에 없는 곳)에 상점을 놓기위해
		int treeIndex = 0;
		for (Node* room : dungeon[i].rooms) {		// 트리 인덱스가 가장 큰 것을 뽑음
			if (room->GetTreeIndex() > treeIndex) {
				treeIndex = room->GetTreeIndex();
			}
		}

		vector<Node*> canPlaceShopNode;	// 상점을 배치할 수 있는 방들을 뽑음
		for (Node* room : dungeon[i].rooms) {
			if (room->GetTreeIndex() == treeIndex
				&& room->GetTopRightCorner().x - room->GetBottomLeftCorner().x > 5
				&& room->GetTopRightCorner().y - room->GetBottomLeftCorner().y > 5
				&& dungeon[i].rooms[upStairsRoomIndex] != room
				&& dungeon[i].rooms[0] != room) {
				canPlaceShopNode.push_back(room);
			}
		}

		if (canPlaceShopNode.size() > 0) {
			int roomIndex = Mathf::Random::Range(0, canPlaceShopNode.size());
			
			Vector2Int shopPoint = canPlaceShopNode[roomIndex]->GetNodeMiddlePoint();

			shopPos.push_back(shopPoint);
			shopPosRoomIndex.push_back(roomIndex);

			dungeon[i].map.mapArr[shopPoint.y - 1][shopPoint.x] = 110;
			dungeon[i].map.mapArr[shopPoint.y][shopPoint.x - 1] = 111;
			dungeon[i].map.mapArr[shopPoint.y][shopPoint.x] = 115;
			dungeon[i].map.mapArr[shopPoint.y][shopPoint.x + 1] = 112;
			dungeon[i].map.mapArr[shopPoint.y + 1][shopPoint.x - 1] = 113;
			dungeon[i].map.mapArr[shopPoint.y + 1][shopPoint.x] = 116;
			dungeon[i].map.mapArr[shopPoint.y + 1][shopPoint.x + 1] = 114;
		}
		else {
			shopPos.push_back(Vector2Int::zero());
			shopPosRoomIndex.push_back(-999);
		}
	}
	// 랜덤 음수대 세팅

	// 상자 세팅
}

void Game::CreateMap()
{
	DungeonGenerator dg = DungeonGenerator(50, 50);

	vector<Node*> rooms = dg.CalculateDungeon(15, 10, 10, 0.1f, 0.95f, 2, 3);

	vector<Node*> cooridorVector = dg.GetCooridorVector();
	
	int testPrint[dungeonSize][dungeonSize] = { 0 };

	// 맵의 첫 번째 방에서 플레이어의 시작 위치를 세팅한다
	Vector2Int playerloc = Vector2Int(
		Mathf::Random::Range(
			rooms[0]->GetBottomLeftCorner().y + 1,
			rooms[0]->GetTopLeftCorner().y)
		,
		Mathf::Random::Range(
			rooms[0]->GetBottomLeftCorner().x + 1,
			rooms[0]->GetBottomRightCorner().x)
	);

	playerLocation.push_back(playerloc);

	DungeonFloor dungeonFloor;

	Map map = playHelper::CreateMap(rooms, cooridorVector);


	dungeonFloor.rooms = rooms;
	dungeonFloor.cooridorVector = cooridorVector;
	dungeonFloor.map = map;

	dungeon.push_back(dungeonFloor);
}

bool Game::CheckPlayerMeetMonster()
{
	if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 4) {
		return true;
	}
	return false;
}

bool Game::CheckPlayerGetBox()
{
	if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 60) {
		return true;
	}
	return false;
}

bool Game::CheckPlayerGoStatues()
{
	if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 50
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 51
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 52
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 53
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 54
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 55
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 56) {
		return true;
	}
	return false;
}

bool Game::CheckPlayerGoWell()
{
	if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 12) {
		return true;
	}
	return false;
}

bool Game::CheckPlayerGoShop()
{
	if (shopPos[currentFloor - 1] == Vector2Int::zero()) {
		return false;
	}
	else if (
				(
					shopPos[currentFloor - 1].x == playerLocation[currentFloor - 1].y
					&&
					shopPos[currentFloor - 1].y - 1 == playerLocation[currentFloor - 1].x
			)
			||	(
				shopPos[currentFloor - 1].x - 1 == playerLocation[currentFloor - 1].y
				&&
				shopPos[currentFloor - 1].y == playerLocation[currentFloor-1].x
			)  
			|| (
				shopPos[currentFloor - 1].x == playerLocation[currentFloor - 1].y
				&&
				shopPos[currentFloor - 1].y == playerLocation[currentFloor - 1].x
			)
			|| (
				shopPos[currentFloor - 1].x + 1 == playerLocation[currentFloor - 1].y
				&&
				shopPos[currentFloor - 1].y == playerLocation[currentFloor - 1].x
			)
			|| (
				shopPos[currentFloor - 1].x - 1 == playerLocation[currentFloor - 1].y
				&&
				shopPos[currentFloor - 1].y + 1 == playerLocation[currentFloor - 1].x
			)
			|| (
				shopPos[currentFloor - 1].x == playerLocation[currentFloor - 1].y
				&&
				shopPos[currentFloor - 1].y + 1 == playerLocation[currentFloor - 1].x
			)
			|| (
				shopPos[currentFloor - 1].x + 1 == playerLocation[currentFloor - 1].y
				&&
				shopPos[currentFloor - 1].y + 1 == playerLocation[currentFloor - 1].x
			)
		)
	{
		return true;
	}
	return false;
}

void Game::EventCheck()
{
	if (downStairs[currentFloor - 1].first == playerLocation[currentFloor - 1]) {
		//ChangeFloor();
		GoDown();
	}
	else if (upStairs[currentFloor - 1] == playerLocation[currentFloor - 1]) {
		GoUp();
	}
	else if (CheckPlayerGoShop()) {
		GoShop();
	}
	else if (CheckPlayerGoWell()) {
		GoWell();
	}
	else if (CheckPlayerGoStatues()) {
		GoStatues();
	}
	else if (CheckPlayerGetBox()) {
		GoBox();
	}
	else if(CheckPlayerMeetMonster()) {
		GoMonster();
	}
 	else {
		PlayerMove();
	}
}

void Game::RenderScene()
{
	system("cls");

	cout << "[ " << currentFloor << "층 ]" << endl;

	// 화면에 출력할 임시 배열 (맵)
	int tempArr[dungeonSize][dungeonSize] = { 0 };

	// 임시 배열에 옮겨 놓기
	for (int i = 0; i < dungeonSize; i++) {
		for (int j = 0; j < dungeonSize; j++) {
			tempArr[i][j] = dungeon[currentFloor - 1].map.mapArr[i][j];
		}
	}

	// 플레이어 위치를 가져와 놓기
	tempArr[playerLocation[currentFloor-1].x][playerLocation[currentFloor-1].y] = 9;
	

	/*cout << "플레이어 위치 : (" << playerLocation[currentFloor - 1].x
		<< ", " << playerLocation[currentFloor - 1].y << ")" << endl;*/


	// 출력
	for (int i = 0; i < dungeonSize; i++) {
		for (int j = 0; j < dungeonSize; j++) {
			switch (tempArr[i][j]) {
			case 0:
				cout << "  ";
				break;
			case 2:
				SetConsoleColor(FOREGROUND_GREEN);
				cout << "▧";
				break;
			case 3:
				SetConsoleColor(FOREGROUND_GREEN);
				cout << "▨";
				break;
			case 4:
				SetConsoleColor(FOREGROUND_RED);
				cout << "♤";
				break;
			case 7:
				cout << "■";
				break;
			case 9:
				SetConsoleColor(11);
				cout << "◎";
				break;
			case 12:
				SetConsoleColor(FOREGROUND_BLUE);
				cout << "Ħ";
				break;
			case 50:
				cout << "┖━";
				break;
			case 51:
				cout << "━";
				break;
			case 52:
				cout << " ━┚";
				break;
			case 53:
				cout << "◇";
				break;
			case 54:
				cout << "⊂";
				break;
			case 55:
				cout << " ⊃";
				break;
			case 56:
				cout << "◆";
				break;
			case 60:
				SetConsoleColor(14);
				cout << "▣";
				break;
			case 110:
				cout << "▲";
				break;
			case 111:
				cout << "↙";
				break;
			case 112:
				cout << "↘";
				break;
			case 113:
				cout << "| ";
				break;
			case 114:
				cout << " |";
				break;			
			case 115:
				SetConsoleColor(6);
				cout << "＄";
				break;			
			case 116:
				cout << "＿";
				break;
			}

			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		cout << endl;
	}

	EventCheck();
}

void Game::PlayerMove()
{
	oldPlayerLoc = playerLocation[currentFloor - 1];

	int key = getCommand();

	switch (key) {
	case 119:
		if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x - 1][playerLocation[currentFloor - 1].y] != 7) {
			playerLocation[currentFloor - 1].x -= 1;
		}
		break;
	case 115:
		if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x + 1][playerLocation[currentFloor - 1].y] != 7) {
			playerLocation[currentFloor - 1].x += 1;
		}
		break;
	case 100:
		if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y + 1] != 7) {
			playerLocation[currentFloor - 1].y += 1;
		}
		break;
	case 97:
		if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y - 1] != 7) {
			playerLocation[currentFloor - 1].y += -1;
		}
		break;
	}
}

void Game::GoUp()
{
	if (currentFloor >= dungeonFloor) {
		cout << "더이상 올라갈 수 없습니다" << endl;
		Sleep(500);
		playerLocation[currentFloor - 1] = oldPlayerLoc;
	}
	else {
		playerLocation[currentFloor - 1] = oldPlayerLoc;
		currentFloor += 1;
		playerLocation[currentFloor - 1] = downStairs[currentFloor - 1].second;
	}
}

void Game::GoDown()
{
	if (currentFloor - 1 <= 0) {
		cout << "더이상 내려갈 수 없습니다" << endl;
		Sleep(500);
		playerLocation[currentFloor - 1] = oldPlayerLoc;
	}
	else {
		playerLocation[currentFloor - 1] = oldPlayerLoc;
		currentFloor -= 1;
	}
}

void Game::GoShop()
{
	cout << "상점에 들어왔습니다" << endl;
	cout << "상점에 나왔습니다" << endl;
	Sleep(500);
	playerLocation[currentFloor - 1] = oldPlayerLoc;
}

void Game::GoWell()
{
	/*cout << "우물에 접근했습니다 이에 맞는 이벤트를 만들어주세요" << endl;
	cout << "우물 이벤트 실행" << endl;*/
	eventManager.EventStart(EventEnum::WELL_EVENT);
	Sleep(500);
	playerLocation[currentFloor - 1] = oldPlayerLoc;
}

void Game::GoStatues()
{
	cout << "조각상에 접근했습니다 이에 맞는 이벤트를 만들어주세요" << endl;
	cout << "조각상 이벤트 실행" << endl;
	eventManager.EventStart(EventEnum::STATUES_EVENT);
	Sleep(500);
	playerLocation[currentFloor - 1] = oldPlayerLoc;
}

void Game::GoBox()
{
	cout << "상자를 발견했다" << endl;
	cout << "상자 이벤트 실행" << endl;
	cout << "상자의 아이템을 먹었다" << endl;
	dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] = 0;
	Sleep(500);
	playerLocation[currentFloor - 1] = oldPlayerLoc;
}

void Game::GoMonster()
{
	cout << "몬스터에 접근했습니다 이에 맞는 이벤트를 만들어주세요" << endl;
	cout << "몬스터 이벤트 실행" << endl;
	Sleep(500);
	playerLocation[currentFloor - 1] = oldPlayerLoc;
}



Game::Game(int dungeonFloor) :dungeonFloor(dungeonFloor)
{
	deleteConsolCursor();

	eventManager = EventManager();

	isGameOver = false;
	currentFloor = 1;

	for (int i = 0; i < dungeonFloor; i++) {
		CreateMap();
	}

	SetStairAndShop();
	SetWell();
	SetStatues();
	SetBox();
	SetMonster();
}

void Game::GameStart()
{
	while (true) {
		if (isGameOver) {
			break;
		}

		RenderScene();
	}
}
