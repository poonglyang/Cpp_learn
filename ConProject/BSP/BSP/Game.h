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
	/// 던전의 층수
	/// </summary>
	int dungeonFloor;

	/// <summary>
	/// 지금 내가 있는 층
	/// </summary>
	int currentFloor;

	static const int dungeonSize = 51;

	/// <summary>
	/// 층별 방, 복도, 맵이 들어있는 구조체 백터
	/// </summary>
	std::vector<DungeonFloor> dungeon;

	/// <summary>
	/// 층별 플레이어 위치
	/// </summary>
	std::vector<Vector2Int> playerLocation;

	/// <summary>
	/// 플레이어 이전 위치
	/// </summary>
	Vector2Int oldPlayerLoc;

	/// <summary>
	/// 층별 올라가는 계단 위치
	/// </summary>
	std::vector<Vector2Int> upStairs;
	
	std::vector<int> upStairsRoomIndex;

	/// <summary>
	/// 층별 내려가는 계단 위치
	/// </summary>
	std::vector<std::pair<Vector2Int, Vector2Int>> downStairs;

	/// <summary>
	/// 상점의 중앙 위치 (상점 생성 x일 경우 0,0)
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

