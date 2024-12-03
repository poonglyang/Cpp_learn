#include "CooridorsGenerator.h"

bool CooridorsGenerator::compareByTreeIndex(const Node& n1, const Node& n2)
{
    return n1.GetTreeIndex() > n2.GetTreeIndex();
}

std::vector<Node*> CooridorsGenerator::CreateCooridoer(std::vector<RoomNode*> allNodesCollection, int corridorWidth)
{
    std::vector<Node*> corridorList;

    //compareByTreeIndex를 기준으로 allNodesCollection을 정렬함
    sort(allNodesCollection.begin(), 
        allNodesCollection.end(), 
        [](const Node* node1, const Node* node2) {
            return node1->GetTreeIndex() > node2->GetTreeIndex();
        });

    std::queue<RoomNode*> structuresToCheck;     // allNodesCollection의 구성원을 TreeLayerIndex을 기준으로 내림차순으로 넣음

    for (RoomNode* roomNode : allNodesCollection) {
        structuresToCheck.push(roomNode);   // 큐에  (잎부터 넣음)
    }   

    while (!structuresToCheck.empty()) {
        // 큐에 노드가 있는 경우
        auto node = structuresToCheck.front();  // 노드를 꺼냄
        structuresToCheck.pop();

        if (node->childrenNode.empty()) {
            // 노드에 자식 노드가 없으면
            continue;   // 복도 만들 수가 없음
        }

        CorridorNode* corridor = new CorridorNode(node->childrenNode[0], node->childrenNode[1], corridorWidth);    // 복도 노드 만들어서
        corridorList.push_back(corridor);     // 리스트에 넣음
    }

    return corridorList;        // 리스트 반환
}
