#pragma once
#include "RoomNode.h"
#include "StructureHelper.h"

using namespace StructureHelper;

class RoomGenerator
{
private:
	int maxIterations;
	int roomLengthMin;
	int roomWidthMin;

public:
    RoomGenerator(int maxIterations, int roomLengthMin, int roomWidthMin);

    /// <summary>
    /// 잎 노드를 받아서 방을 만드는 함수
    /// 잎 노드의 꼭지점(모서리)를 조정한다 (길을 낼 수 있을 간격 등으로)
    /// </summary>
    /// <param name="roomSpaces">잎 노드가 들어있는 리스트</param>
    /// <returns>꼭지점(모서리)가 재정의된 RoomNode리스트</returns>
    vector<RoomNode> GenerateRoomInGivenSpaces(
        vector<Node> roomSpaces, float roomBottomCornerModifier,
        float roomTopCornerModifier, int roomOffset);
};

