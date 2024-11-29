#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include "Room.h"

using namespace std;

class PDGA
{
protected:
	int tile_size;

	int minRoomWidth;

	int minRoomHeight;

	int maxRoomWidth;

	int maxRoomHeight;

    vector<Room> dungeonRoom;

public:
	PDGA(int tile_size, 
        int minRoomWidth, int minRoomHeight, 
        int maxRoomWidth, int maxRoomHeight);


	/// <summary>
	/// 타일의 크기에 맞게 점의 위치를 바꿔주는 함수
	/// </summary>
	/// <param name="n">점의 위치</param>
	/// <param name="m">타일의 크기</param>
	/// <returns>점의 위치에 따라 바뀐 타일의 위치</returns>
    double roundM(double n, double m);

	/// <summary>
	/// 원 안에 무작위의 점을 만드는 함수
	/// </summary>
	/// <param name="radius">반지름</param>
	/// <returns>무작위 점 Vector2Int 좌표</returns>
	Vector2Int GetRandomPointInCircle(int radius);
	
	/// <summary>
	/// 타원 안에 무작위 점을 만드는 함수
	/// </summary>
	/// <param name="width">타원 가로</param>
	/// <param name="height">타원 세로</param>
	/// <returns>Vector2Int로 이루어진 무작위 점</returns>
	Vector2Int GetRandomPointInCircle(int width, int height);

    
	/// <summary>
	/// 생성된 방들을 겹치지 않게 넓게 흩뿌리는 함수
	/// </summary>
	/// <param name="rooms">생성된 방</param>
	void SeparateRooms(vector<Room>& rooms);



    /// <summary>
    /// 방을 안겹치게 하는 함수
    /// </summary>
    /// <param name="agent">안겹치게 할 방</param>
    /// <param name="rooms">방들</param>
    /// <returns>안겹치는 중앙 점</returns>
    Vector2Int computeSeparation(Room& agent, vector<Room>& rooms);

    /// <summary>
    /// 방과 방이 방을 조정하도록 하는 좌표값을 반환하는 함수
    /// </summary>
    /// <param name="room">방</param>
    /// <param name="agent">다른 방</param>
    /// <param name="type">좌표 지정</param>
    /// <returns></returns>
    double Difference(Room room, Room agent, int type);

	bool SeperateRooms2(std::vector<Room>& rooms) const;

	/// <summary>
	/// 맵 생성
	/// </summary>
	void GeneratorDungeon();


    void PrintDungeon();

	void PrintDungeon(vector<Room> rooms);
};

