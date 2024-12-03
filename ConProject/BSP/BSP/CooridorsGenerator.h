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
    /// 복도에 해당하는 노드를 생성한 뒤 리스트로 반환하는 함수
    /// </summary>
    /// <param name="allNodesCollection">분할한 모든 노드</param>
    /// <param name="corridorWidth">복도 넓이</param>
    /// <returns>복도 노드 리스트</returns>
    std::vector<Node*> CreateCooridoer(std::vector<RoomNode*> allNodesCollection, int corridorWidth);

};

