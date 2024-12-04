#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "DungeonGenerator.h"
#include "EventManager.h"
#include "ItemManager.h"
#include "Player.h"
#include "ViewInventory.h"


using namespace playHelper;

class Game
{
private:

	Player* player;

	ItemManager itemManager;

	bool isGameOver;

	EventManager eventManager;

	std::vector< EventManager> eventManagers;

	/// <summary>
	/// ������ ����
	/// </summary>
	int dungeonFloor;

	/// <summary>
	/// ���� ���� �ִ� ��
	/// </summary>
	int currentFloor;

	static const int dungeonSize = 51;

	/// <summary>
	/// ���� ��, ����, ���� ����ִ� ����ü ����
	/// </summary>
	std::vector<DungeonFloor> dungeon;

	/// <summary>
	/// ���� �÷��̾� ��ġ
	/// </summary>
	std::vector<Vector2Int> playerLocation;

	/// <summary>
	/// �÷��̾� ���� ��ġ
	/// </summary>
	Vector2Int oldPlayerLoc;

	/// <summary>
	/// ���� �ö󰡴� ��� ��ġ
	/// </summary>
	std::vector<Vector2Int> upStairs;
	
	std::vector<int> upStairsRoomIndex;

	/// <summary>
	/// ���� �������� ��� ��ġ
	/// </summary>
	std::vector<std::pair<Vector2Int, Vector2Int>> downStairs;

	/// <summary>
	/// ������ �߾� ��ġ (���� ���� x�� ��� 0,0)
	/// </summary>
	std::vector<Vector2Int> shopPos;
	
	std::vector<int> shopPosRoomIndex;

	std::vector<int> wellPosRoomIndex;

	std::vector<Vector2Int> statusPoint;

	std::vector<int> statusPosRoomIndex;

	void deleteConsolCursor();

	void SetConsoleColor(int color);

	void SetMonster();

	void SetChest();

	void SetStatues();

	void SetWell();

	void SetStairAndShop();

	void CreateMap();
	
	bool CheckPlayerMeetMonster();

	bool CheckPlayerGetBox();

	bool CheckPlayerGoDevilStatues();

	bool CheckPlayerGoAngelStatues();

	bool CheckPlayerGoWell();

	bool CheckPlayerGoShop();

	void EventCheck();

	void RenderScene();

	void PlayerMove();

	void UnitMove();
	
	void GoUp();

	void GoDown();

	void GoShop();

	void GoWell();

	void GoDevilStatues();

	void GoAngelStatues();

	void GoChest();

	void GoMonster();
public:
	Game(int dungeonFloor);

	void GameStart();
};

