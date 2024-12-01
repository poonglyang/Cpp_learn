#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "DungeonGenerator.h"

using namespace std;

struct Map {
	int mapArr[51][51] = { 0 };
};

class Game
{
private:
	int dungeonFloor;

	int currentFloor;

	static const int dungeonSize = 51;

	vector<vector<Node*>> allRooms;

	vector<vector<Node*>> allcooridorVector;

	vector<Map> allMapArr;

	vector<Vector2Int> playerLocation;

	// 이게 문제가 됨
	//vector<int(*)[51][51]> allMapArr;

	int getCommand();

	void SetConsoleColor(int color);

	void CreateMap();

	void RenderScene();

public:
	Game(int dungeonFloor);

	void GameStart();
};

