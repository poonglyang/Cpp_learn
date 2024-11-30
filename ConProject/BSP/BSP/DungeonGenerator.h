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
    /// 매개변수로 받은 다른 방이랑 겹치는지 확인하는 함수
    /// </summary>
    /// <param name="otherRoom">다른 방</param>
    /// <returns>true면 겹침, false면 안겹친다</returns>
    bool IsRoomOverlap(const Node* node1, const Node* node2);

    bool IsInternalOverlap(Node* node1, Node* node2);

public:
    DungeonGenerator(int dungeonWidth, int dungeonLength) : dungeonWidth(dungeonWidth), dungeonLength(dungeonLength) {};
    
    ~DungeonGenerator();
    /// <summary>
    /// 던전 노드 생성
    /// </summary>
    /// <param name="maxIterations"></param>
    /// <param name="roomWidthMin"></param>
    /// <param name="roomLengthMin"></param>
    /// <returns></returns>
    vector<Node*> CalculateDungeon(int maxIterations, int roomWidthMin, int roomLengthMin, float roomBottomCornerModifier, float roomTopCornerModifier, int roomOffset, int corridorWidth);
};

