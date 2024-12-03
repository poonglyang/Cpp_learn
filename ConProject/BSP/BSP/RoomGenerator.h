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
    /// �� ��带 �޾Ƽ� ���� ����� �Լ�
    /// �� ����� ������(�𼭸�)�� �����Ѵ� (���� �� �� ���� ���� ������)
    /// </summary>
    /// <param name="roomSpaces">�� ��尡 ����ִ� ����Ʈ</param>
    /// <returns>������(�𼭸�)�� �����ǵ� RoomNode����Ʈ</returns>
    std::vector<RoomNode*> GenerateRoomInGivenSpaces(
        std::vector<Node*> roomSpaces, float roomBottomCornerModifier,
        float roomTopCornerModifier, int roomOffset);
};

