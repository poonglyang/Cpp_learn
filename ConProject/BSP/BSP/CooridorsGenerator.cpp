#include "CooridorsGenerator.h"

bool CooridorsGenerator::compareByTreeIndex(const Node& n1, const Node& n2)
{
    return n1.GetTreeIndex() > n2.GetTreeIndex();
}

std::vector<Node*> CooridorsGenerator::CreateCooridoer(std::vector<RoomNode*> allNodesCollection, int corridorWidth)
{
    std::vector<Node*> corridorList;

    //compareByTreeIndex�� �������� allNodesCollection�� ������
    sort(allNodesCollection.begin(), 
        allNodesCollection.end(), 
        [](const Node* node1, const Node* node2) {
            return node1->GetTreeIndex() > node2->GetTreeIndex();
        });

    std::queue<RoomNode*> structuresToCheck;     // allNodesCollection�� �������� TreeLayerIndex�� �������� ������������ ����

    for (RoomNode* roomNode : allNodesCollection) {
        structuresToCheck.push(roomNode);   // ť��  (�ٺ��� ����)
    }   

    while (!structuresToCheck.empty()) {
        // ť�� ��尡 �ִ� ���
        auto node = structuresToCheck.front();  // ��带 ����
        structuresToCheck.pop();

        if (node->childrenNode.empty()) {
            // ��忡 �ڽ� ��尡 ������
            continue;   // ���� ���� ���� ����
        }

        CorridorNode* corridor = new CorridorNode(node->childrenNode[0], node->childrenNode[1], corridorWidth);    // ���� ��� ����
        corridorList.push_back(corridor);     // ����Ʈ�� ����
    }

    return corridorList;        // ����Ʈ ��ȯ
}
