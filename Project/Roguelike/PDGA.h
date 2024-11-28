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
	/// Ÿ���� ũ�⿡ �°� ���� ��ġ�� �ٲ��ִ� �Լ�
	/// </summary>
	/// <param name="n">���� ��ġ</param>
	/// <param name="m">Ÿ���� ũ��</param>
	/// <returns>���� ��ġ�� ���� �ٲ� Ÿ���� ��ġ</returns>
    double roundM(double n, double m);

	/// <summary>
	/// �� �ȿ� �������� ���� ����� �Լ�
	/// </summary>
	/// <param name="radius">������</param>
	/// <returns>������ �� Vector2Int ��ǥ</returns>
	Vector2Int GetRandomPointInCircle(int radius);
	
	/// <summary>
	/// Ÿ�� �ȿ� ������ ���� ����� �Լ�
	/// </summary>
	/// <param name="width">Ÿ�� ����</param>
	/// <param name="height">Ÿ�� ����</param>
	/// <returns>Vector2Int�� �̷���� ������ ��</returns>
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
	/// ������ ����� ��ġ�� �ʰ� �а� ��Ѹ��� �Լ�
	/// </summary>
	/// <param name="rooms">������ ��</param>
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
    /// ���� �Ȱ�ġ�� �ϴ� �Լ�
    /// </summary>
    /// <param name="agent">�Ȱ�ġ�� �� ��</param>
    /// <param name="rooms">���</param>
    /// <returns>�Ȱ�ġ�� �߾� ��</returns>
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
    /// ��� ���� ���� �����ϵ��� �ϴ� ��ǥ���� ��ȯ�ϴ� �Լ�
    /// </summary>
    /// <param name="room">��</param>
    /// <param name="agent">�ٸ� ��</param>
    /// <param name="type">��ǥ ����</param>
    /// <returns></returns>
    double Difference(Room room, Room agent, int type);

	/// <summary>
	/// �� ����
	/// </summary>
	void GeneratorDungeon();


    void PrintDungeon();
};

