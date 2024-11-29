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

    
	/// <summary>
	/// ������ ����� ��ġ�� �ʰ� �а� ��Ѹ��� �Լ�
	/// </summary>
	/// <param name="rooms">������ ��</param>
	void SeparateRooms(vector<Room>& rooms);



    /// <summary>
    /// ���� �Ȱ�ġ�� �ϴ� �Լ�
    /// </summary>
    /// <param name="agent">�Ȱ�ġ�� �� ��</param>
    /// <param name="rooms">���</param>
    /// <returns>�Ȱ�ġ�� �߾� ��</returns>
    Vector2Int computeSeparation(Room& agent, vector<Room>& rooms);

    /// <summary>
    /// ��� ���� ���� �����ϵ��� �ϴ� ��ǥ���� ��ȯ�ϴ� �Լ�
    /// </summary>
    /// <param name="room">��</param>
    /// <param name="agent">�ٸ� ��</param>
    /// <param name="type">��ǥ ����</param>
    /// <returns></returns>
    double Difference(Room room, Room agent, int type);

	bool SeperateRooms2(std::vector<Room>& rooms) const;

	/// <summary>
	/// �� ����
	/// </summary>
	void GeneratorDungeon();


    void PrintDungeon();

	void PrintDungeon(vector<Room> rooms);
};

