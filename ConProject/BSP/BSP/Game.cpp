#include "Game.h"

void Game::deleteConsolCursor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void Game::SetConsoleColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
	SetConsoleTextAttribute(hConsole, color);         // ���� ����
}

void Game::SetMonster()
{
	// ���� ����
	for (int i = 0; i < dungeon.size(); i++) {
		int roomIndex = -1;
		for (Node* room : dungeon[i].rooms) {
			roomIndex++;
			if (roomIndex == shopPosRoomIndex[i]) {
				continue;
			}
			
			int monsterCount = GetMonsterCount(room);	// ������ ���� ����

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

void Game::SetChest()
{
	for (int i = 0; i < dungeon.size(); i++) {
		int roomIndex = -1;
		for (Node* room : dungeon[i].rooms) {
			roomIndex++;
			if (roomIndex == shopPosRoomIndex[i] || roomIndex == statusPosRoomIndex[i]) {
				continue;
			}

			int boxCount = 1 + rand() % 2;	// ������ ���� ����

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
		std::vector<Node*> canPlaceStatues;	// �������� ���� �� �ִ� ���� ����
		for (Node* room : dungeon[i].rooms) {
			if (room->GetTopRightCorner().x - room->GetBottomLeftCorner().x > 5
				&& room->GetTopRightCorner().y - room->GetBottomLeftCorner().y > 5
				&& dungeon[i].rooms[upStairsRoomIndex[i]] != room	// ���� �ö󰡴� ��� ���� ��
				&& dungeon[i].rooms[0] != room						// �Ʒ��� �������� ��� ���� ��
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
				dungeon[i].map.mapArr[statuesPoint.y - 1][statuesPoint.x] = 57;
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
		// �Ʒ������� �������� ��� ���� (�÷��̾��� ���� ��ġ �ֺ��� �������� ����� ����)
		if (dungeon[i].map.mapArr[playerLocation[i].x][playerLocation[i].y + 1] == 0) {
			dungeon[i].map.mapArr[playerLocation[i].x][playerLocation[i].y + 1] = 2;
			downStairs.push_back(std::pair(
				Vector2Int(playerLocation[i].x, playerLocation[i].y + 1),
				playerLocation[i])
			);
		}
		else if (dungeon[i].map.mapArr[playerLocation[i].x - 1][playerLocation[i].y] == 0) {
			dungeon[i].map.mapArr[playerLocation[i].x - 1][playerLocation[i].y] = 2;
			downStairs.push_back(std::pair(
				Vector2Int(playerLocation[i].x - 1, playerLocation[i].y),
				playerLocation[i])
			);
		}
		else if (dungeon[i].map.mapArr[playerLocation[i].x + 1][playerLocation[i].y] == 0) {
			dungeon[i].map.mapArr[playerLocation[i].x + 1][playerLocation[i].y] = 2;
			downStairs.push_back(std::pair(
				Vector2Int(playerLocation[i].x + 1, playerLocation[i].y),
				playerLocation[i])
			);
		}
		else {
			dungeon[i].map.mapArr[playerLocation[i].x][playerLocation[i].y - 1] = 2;
			downStairs.push_back(
				std::pair(Vector2Int(playerLocation[i].x, playerLocation[i].y - 1),
					playerLocation[i])
			);
		}

		// �� ������ �ö󰡴� ��� ��ġ ����
		int upStairsRoomIndex = Mathf::Random::Range(1, dungeon[i].rooms.size());
		Vector2Int upStairsPos = PlaceStructuresInRoom(dungeon[i].rooms[upStairsRoomIndex]);
		dungeon[i].map.mapArr[upStairsPos.x][upStairsPos.y] = 3;
		upStairs.push_back(upStairsPos);
		this->upStairsRoomIndex.push_back(upStairsRoomIndex);

		// ���� ����
		// Ʈ�� �ε����� ���� ū ��(���� �ϳ��ۿ� ���� ��)�� ������ ��������
		int treeIndex = 0;
		for (Node* room : dungeon[i].rooms) {		// Ʈ�� �ε����� ���� ū ���� ����
			if (room->GetTreeIndex() > treeIndex) {
				treeIndex = room->GetTreeIndex();
			}
		}

		std::vector<Node*> canPlaceShopNode;	// ������ ��ġ�� �� �ִ� ����� ����
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
	// ���� ������ ����

	// ���� ����
}

void Game::CreateMap()
{
	DungeonGenerator dg = DungeonGenerator(50, 50);

	std::vector<Node*> rooms = dg.CalculateDungeon(15, 10, 10, 0.1f, 0.95f, 2, 3);

	std::vector<Node*> cooridorVector = dg.GetCooridorVector();
	
	int testPrint[dungeonSize][dungeonSize] = { 0 };

	// ���� ù ��° �濡�� �÷��̾��� ���� ��ġ�� �����Ѵ�
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

bool Game::CheckPlayerGoDevilStatues()
{
	if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 50
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 51
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 52
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 53

		) {
		return true;
	}
	return false;
}

bool Game::CheckPlayerGoAngelStatues()
{
	if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 50
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 54
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 55
		|| dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] == 56
		) {
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
	else if (CheckPlayerGoAngelStatues()) {
		GoAngelStatues();
	}
	else if (CheckPlayerGoDevilStatues()) {
		GoDevilStatues();
	}
	else if (CheckPlayerGetBox()) {
		GoChest();
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

	std::cout << "[ " << currentFloor << "�� ]" << std::endl;

	// ȭ�鿡 ����� �ӽ� �迭 (��)
	int tempArr[dungeonSize][dungeonSize] = { 0 };

	// �ӽ� �迭�� �Ű� ����
	for (int i = 0; i < dungeonSize; i++) {
		for (int j = 0; j < dungeonSize; j++) {
			tempArr[i][j] = dungeon[currentFloor - 1].map.mapArr[i][j];
		}
	}

	// �÷��̾� ��ġ�� ������ ����
	tempArr[playerLocation[currentFloor-1].x][playerLocation[currentFloor-1].y] = 9;
	

	/*cout << "�÷��̾� ��ġ : (" << playerLocation[currentFloor - 1].x
		<< ", " << playerLocation[currentFloor - 1].y << ")" << endl;*/


	// ���
	for (int i = 0; i < dungeonSize; i++) {
		for (int j = 0; j < dungeonSize; j++) {
			switch (tempArr[i][j]) {
			case 0:
				std::cout << "  ";
				break;
			case 2:
				SetConsoleColor(FOREGROUND_GREEN);
				std::cout << "��";
				break;
			case 3:
				SetConsoleColor(FOREGROUND_GREEN);
				std::cout << "��";
				break;
			case 4:
				SetConsoleColor(FOREGROUND_RED);
				std::cout << "��";
				break;
			case 7:
				std::cout << "��";
				break;
			case 9:
				SetConsoleColor(11);
				std::cout << "��";
				break;
			case 12:
				SetConsoleColor(FOREGROUND_BLUE);
				std::cout << "��";
				break;
			case 50:
				std::cout << "�Ŧ�";
				break;
			case 57:
			case 51:
				std::cout << "��";
				break;
			case 52:
				std::cout << " ����";
				break;
			case 53:
				std::cout << "��";
				break;
			case 54:
				std::cout << "��";
				break;
			case 55:
				std::cout << " ��";
				break;
			case 56:
				std::cout << "��";
				break;
			case 60:
				SetConsoleColor(14);
				std::cout << "��";
				break;
			case 110:
				std::cout << "��";
				break;
			case 111:
				std::cout << "��";
				break;
			case 112:
				std::cout << "��";
				break;
			case 113:
				std::cout << "| ";
				break;
			case 114:
				std::cout << " |";
				break;
			case 115:
				SetConsoleColor(6);
				std::cout << "��";
				break;
			case 116:
				std::cout << "��";
				break;
			}

			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		std::cout << std::endl;
	}

	EventCheck();
}

void Game::PlayerMove()
{
	oldPlayerLoc = playerLocation[currentFloor - 1];

	int key = playHelper::getCommand();

	switch (key) {
	case 119:	// �� �Ǵ� w
	case 72:
		if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x - 1][playerLocation[currentFloor - 1].y] != 7) {
			playerLocation[currentFloor - 1].x -= 1;
		}
		break;
	case 115:	// �Ʒ� ����Ű �Ǵ� s
	case 80:
		if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x + 1][playerLocation[currentFloor - 1].y] != 7) {
			playerLocation[currentFloor - 1].x += 1;
		}
		break;
	case 100:	// ������ ����Ű �Ǵ� a
	case 77:
		if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y + 1] != 7) {
			playerLocation[currentFloor - 1].y += 1;
		}
		break;
	case 97:	// ���� ����Ű �Ǵ� d
	case 75:
		if (dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y - 1] != 7) {
			playerLocation[currentFloor - 1].y += -1;
		}
		break;
	case 105:	// i Ű
		InventoryView::ViewInventory(player);
		break;
	case 117:
		InventoryView::ViewState(player);
		break;
	}
}

void Game::GoUp()
{
	if (currentFloor >= dungeonFloor) {
		std::cout << "���̻� �ö� �� �����ϴ�" << std::endl;
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
		std::cout << "���̻� ������ �� �����ϴ�" << std::endl;
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
	eventManagers[currentFloor - 1].EventStart(EventEnum::SHOP_EVENT, player);
	
	playerLocation[currentFloor - 1] = oldPlayerLoc;
}

void Game::GoWell()
{
	/*cout << "�칰�� �����߽��ϴ� �̿� �´� �̺�Ʈ�� ������ּ���" << endl;
	cout << "�칰 �̺�Ʈ ����" << endl;*/
	eventManagers[currentFloor-1].EventStart(EventEnum::WELL_EVENT, player);
	Sleep(500);
	playerLocation[currentFloor - 1] = oldPlayerLoc;
}

void Game::GoDevilStatues()
{
	std::cout << "������ �����߽��ϴ� �̿� �´� �̺�Ʈ�� ������ּ���" << std::endl;
	std::cout << "������ �̺�Ʈ ����" << std::endl;
	eventManagers[currentFloor - 1].EventStart(EventEnum::DEVIL_STATUES_EVENT, player);
	Sleep(500);
	playerLocation[currentFloor - 1] = oldPlayerLoc;
}

void Game::GoAngelStatues()
{
	std::cout << "������ �����߽��ϴ� �̿� �´� �̺�Ʈ�� ������ּ���" << std::endl;
	std::cout << "������ �̺�Ʈ ����" << std::endl;
	eventManagers[currentFloor - 1].EventStart(EventEnum::ANGEL_STATUES_EVENT, player);
	Sleep(500);
	playerLocation[currentFloor - 1] = oldPlayerLoc;
}

void Game::GoChest()
{
	std::cout << "���ڸ� �߰��ߴ�" << std::endl;
	std::cout << "���� �̺�Ʈ ����" << std::endl;
	int count = 0;
	eventManagers[currentFloor - 1].EventStart(playHelper::EventEnum::BOX_EVENT, player);
	dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] = 0;
	Sleep(500);
	//playerLocation[currentFloor - 1] = oldPlayerLoc;
}

void Game::GoMonster()
{
	std::cout << "���� �̺�Ʈ ����" << std::endl;
	eventManagers[currentFloor - 1].EventStart(playHelper::EventEnum::MONSTER_EVENT, player);
	Sleep(500);
	dungeon[currentFloor - 1].map.mapArr[playerLocation[currentFloor - 1].x][playerLocation[currentFloor - 1].y] = 0;
}



Game::Game(int dungeonFloor) :dungeonFloor(dungeonFloor)
{
	itemManager = ItemManager();

	player = new Player(
		100,	// hp
		100,	// maxHp
		50,		// mp
		50,		// maxMp
		10,		// atk
		20,		// ũ��Ȯ�� 
		1.2f,	// ũ�� ����
		0,		// �湫
		10,		// ����
		0.8f,	// ���߷�
		0.2f,	// ȸ����
		0.3f,	// ���� ���� Ȯ��
		5,		// �ൿ��
		itemManager
	);
	Item_Equipable* tempItem = itemManager.GetEquipableItem(1);
	Item_Equipable* tempItem2 = itemManager.GetEquipableItem(2);
	player->inventory->PushItem(tempItem);
	player->inventory->PushItem(tempItem2);
	player->inventory->PushItem(100001, 5);
	player->inventory->PushItem(100002, 5);
	player->inventory->PushItem(100003, 5);
	player->inventory->PushItem(100004, 5);
	player->inventory->PushItem(100005, 5);
	player->inventory->PushItem(100006, 5);
	player->inventory->SetMoney(1000, false);
	deleteConsolCursor();

	isGameOver = false;
	currentFloor = 1;

	for (int i = 0; i < dungeonFloor; i++) {
		CreateMap();
	}

	SetStairAndShop();
	SetWell();
	SetStatues();
	SetChest();
	SetMonster();

	for (int i = 0; i < dungeonFloor; i++) {
		eventManagers.push_back(EventManager());
	}

	
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
