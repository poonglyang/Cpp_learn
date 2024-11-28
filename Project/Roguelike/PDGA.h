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

	/*
	void SeparateRooms(){

        foreach (Room room in rooms) {

            //Debug.Log (room);
            Vector3 oldPos = room.GetPosition ();
            Vector3 separation = computeSeparation (room);
            //Debug.Log (separation);
            Vector3 newPos = new Vector3 
                (oldPos.x += separation.x, oldPos.y, 
                oldPos.z += separation.z);
            room.SetPosition (newPos);
            //Debug.Log (room);

        }

    }
    */
    
	/// <summary>
	/// 생성된 방들을 겹치지 않게 넓게 흩뿌리는 함수
	/// </summary>
	/// <param name="rooms">생성된 방</param>
	void SeparateRooms(vector<Room>& rooms);


    /*
    Vector3 computeSeparation(Room agent) {

        int neighbours = 0;
        Vector3 v = new Vector3 ();

        foreach (Room room in rooms) {
            if (room != agent) {
                if (agent.TooCloseTo (room)) {
                    v.x += Difference(room, agent, "x");
                    v.z += Difference(room, agent, "z");
                    neighbours++;
                }
            }
        }
        if (neighbours == 0)
            return v;

        v.x /= neighbours;
        v.z /= neighbours;
        v.x *= -1;
        v.z *= -1;
        v.Normalize ();
        return v;

    }
    */

    /// <summary>
    /// 방을 안겹치게 하는 함수
    /// </summary>
    /// <param name="agent">안겹치게 할 방</param>
    /// <param name="rooms">방들</param>
    /// <returns>안겹치는 중앙 점</returns>
    Vector2Int computeSeparation(Room& agent, vector<Room>& rooms);

    /*
    float Difference(Room room, Room agent, string type){

        switch (type) {

        case "x":
            float xBottom = 
                (room.GetPosition ().x + room.GetSize ().x / 2) 
                - (agent.GetPosition ().x - agent.GetSize ().x / 2);

            float xTop = 
            (agent.GetPosition ().x + agent.GetSize ().x / 2) 
            - (room.GetPosition ().x - room.GetSize ().x / 2);

            return xBottom > 0 ? xBottom : xTop;
            break;

        case "z":
            float xRight= (room.GetPosition ().z + room.GetSize ().z / 2) 
            - (agent.GetPosition ().z - agent.GetSize ().z / 2);
            float xLeft= (agent.GetPosition ().z + agent.GetSize ().z / 2) 
            - (room.GetPosition ().z - room.GetSize ().z / 2);
            return xRight > 0 ? xRight : xLeft;
        default:
            return 0;
            break;

        }
    }
	*/

    /// <summary>
    /// 방과 방이 방을 조정하도록 하는 좌표값을 반환하는 함수
    /// </summary>
    /// <param name="room">방</param>
    /// <param name="agent">다른 방</param>
    /// <param name="type">좌표 지정</param>
    /// <returns></returns>
    double Difference(Room room, Room agent, int type);

	/// <summary>
	/// 맵 생성
	/// </summary>
	void GeneratorDungeon();


    void PrintDungeon();
};

