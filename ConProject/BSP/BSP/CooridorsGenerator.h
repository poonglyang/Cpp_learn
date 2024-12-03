#pragma once
#include "RoomNode.h"
#include "CorridorNode.h"
#include <queue>
#include <algorithm>
class CooridorsGenerator
{
    bool compareByTreeIndex(const Node& n1, const Node& n2);

public:
    /// <summary>
    /// ������ �ش��ϴ� ��带 ������ �� ����Ʈ�� ��ȯ�ϴ� �Լ�
    /// </summary>
    /// <param name="allNodesCollection">������ ��� ���</param>
    /// <param name="corridorWidth">���� ����</param>
    /// <returns>���� ��� ����Ʈ</returns>
    std::vector<Node*> CreateCooridoer(std::vector<RoomNode*> allNodesCollection, int corridorWidth);

};

