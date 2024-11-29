#pragma once
#include "BSP.h"
#include "CooridorsGenerator.h"

class DungeonGenerator
{
private:
    vector<RoomNode*> allNodesCollection;

    int dungeonWidth;
    int dungeonLength;

public:
    DungeonGenerator(int dungeonWidth, int dungeonLength) : dungeonWidth(dungeonWidth), dungeonLength(dungeonLength) {};
    /// <summary>
    /// 던전 노드 생성
    /// </summary>
    /// <param name="maxIterations"></param>
    /// <param name="roomWidthMin"></param>
    /// <param name="roomLengthMin"></param>
    /// <returns></returns>
    vector<Node*> CalculateDungeon(int maxIterations, int roomWidthMin, int roomLengthMin, float roomBottomCornerModifier, float roomTopCornerModifier, int roomOffset, int corridorWidth);
};

