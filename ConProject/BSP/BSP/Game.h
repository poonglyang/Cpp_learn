#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "DungeonGenerator.h"

using namespace std;
using namespace playHelper;

class Game
{
private:
	bool isGameOver;

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
	vector<DungeonFloor> dungeon;

	/// <summary>
	/// ���� �÷��̾� ��ġ
	/// </summary>
	vector<Vector2Int> playerLocation;

	/// <summary>
	/// �÷��̾� ���� ��ġ
	/// </summary>
	Vector2Int oldPlayerLoc;

	/// <summary>
	/// ���� �ö󰡴� ��� ��ġ
	/// </summary>
	vector<Vector2Int> upStairs;
	
	vector<int> upStairsRoomIndex;

	/// <summary>
	/// ���� �������� ��� ��ġ
	/// </summary>
	vector<pair<Vector2Int, Vector2Int>> downStairs;

	/// <summary>
	/// ������ �߾� ��ġ (���� ���� x�� ��� 0,0)
	/// </summary>
	vector<Vector2Int> shopPos;
	
	vector<int> shopPosRoomIndex;

	vector<int> wellPosRoomIndex;

	vector<Vector2Int> statusPoint;

	vector<int> statusPosRoomIndex;

	int getCommand();

	void deleteConsolCursor();

	void SetConsoleColor(int color);

	void SetMonster();

	void SetBox();

	void SetStatues();

	void SetWell();

	void SetStairAndShop();

	void CreateMap();
	
	bool CheckPlayerGoShop();

	void EventCheck();

	void RenderScene();

	void PlayerMove();

	void UnitMove();
	
	void GoUp();

	void GoDown();

	void GoShop();
public:
	Game(int dungeonFloor);

	void GameStart();
};

