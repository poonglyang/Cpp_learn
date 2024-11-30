#pragma once
#include "BSP.h"
#include "CooridorsGenerator.h"

class DungeonGenerator
{
private:
    vector<RoomNode*> allNodesCollection;

    int dungeonWidth;
    int dungeonLength;

    /// <summary>
    /// �Ű������� ���� �ٸ� ���̶� ��ġ���� Ȯ���ϴ� �Լ�
    /// </summary>
    /// <param name="otherRoom">�ٸ� ��</param>
    /// <returns>true�� ��ħ, false�� �Ȱ�ģ��</returns>
    bool IsRoomOverlap(const Node* node1, const Node* node2);

    bool IsInternalOverlap(Node* node1, Node* node2);

public:
    DungeonGenerator(int dungeonWidth, int dungeonLength) : dungeonWidth(dungeonWidth), dungeonLength(dungeonLength) {};
    
    ~DungeonGenerator();
    /// <summary>
    /// ���� ��� ����
    /// </summary>
    /// <param name="maxIterations"></param>
    /// <param name="roomWidthMin"></param>
    /// <param name="roomLengthMin"></param>
    /// <returns></returns>
    vector<Node*> CalculateDungeon(int maxIterations, int roomWidthMin, int roomLengthMin, float roomBottomCornerModifier, float roomTopCornerModifier, int roomOffset, int corridorWidth);
};

