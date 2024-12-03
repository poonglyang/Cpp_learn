#include "DungeonGenerator.h"

bool DungeonGenerator::IsRoomOverlap(const Node* node1, const Node* node2)
{
    return !(node1->GetBottomRightCorner().x < node2->GetTopLeftCorner().x
        || node1->GetTopLeftCorner().x > node2->GetBottomRightCorner().x
        || node1->GetBottomRightCorner().y > node2->GetTopLeftCorner().y
        || node1->GetTopLeftCorner().y < node2->GetBottomRightCorner().y);
}

bool DungeonGenerator::IsInternalOverlap(Node* node1, Node* node2)
{
    return !(node1->GetBottomRightCorner().x <= node2->GetBottomLeftCorner().x || // node1�� node2�� ���ʿ� ����
        node1->GetBottomLeftCorner().x >= node2->GetBottomRightCorner().x || // node1�� node2�� �����ʿ� ����
        node1->GetTopRightCorner().y <= node2->GetBottomLeftCorner().y ||    // node1�� node2�� �Ʒ��� ����
        node1->GetBottomLeftCorner().y >= node2->GetTopRightCorner().y);     // node1�� node2�� ���� ����
}

DungeonGenerator::~DungeonGenerator()
{
    
}

std::vector<Node*> DungeonGenerator::CalculateDungeon(int maxIterations, int roomWidthMin, int roomLengthMin, float roomBottomCornerModifier, float roomTopCornerModifier, int roomOffset, int corridorWidth)
{

    BSP bsp = BSP(dungeonWidth, dungeonLength);
    allNodesCollection = bsp.PrepareNodesCollection(maxIterations, roomWidthMin, roomLengthMin);

    /*int count = 0;
    for (Node* room : allNodesCollection) {
        cout << "[�� " << count << "]���ϴ� �𼭸� ��ǥ ("
            << room->GetBottomLeftCorner().x << "," << room->GetBottomLeftCorner().y
            << "), ���� �𼭸� ��ǥ (" << room->GetTopRightCorner().x << "," << room->GetTopRightCorner().y
            << "), �ڽļ� : " << room->childrenNode.size() << endl;

        count++;
    }*/

    std::vector<Node*> roomSpaces = StructureHelper::TraverseGraphToExtractLowestLeafes(bsp.GetRootNode());
    RoomGenerator roomGenerator = RoomGenerator(maxIterations, roomLengthMin, roomWidthMin);
    std::vector<RoomNode*> roomList = roomGenerator.GenerateRoomInGivenSpaces(roomSpaces, roomBottomCornerModifier, roomTopCornerModifier, roomOffset);

    CooridorsGenerator cooridorsGenerator = CooridorsGenerator();
    cooridorVector = cooridorsGenerator.CreateCooridoer(allNodesCollection, corridorWidth);
    //auto cooridorList = cooridorsGenerator.CreateCooridoer(allNodesCollection, corridorWidth);

    std::vector<Node*> returnVector;
    for (auto roomNode : roomList) {
        returnVector.push_back(roomNode);
    }

    //for (Node* node : cooridorList) {
    //    
    //    // �Ȱ�ġ�� �游 �����ϴ� ������ ����
    //    // �׷� ���� �Ȱ�ġ�� ���� ���ö����� ��� ������ ���� ������?
    //    /*bool isOverlap = false;

    //    for (auto roomNode : roomList) {
    //        if (IsInternalOverlap(node, roomNode)) {
    //            isOverlap = true;
    //            break;
    //        }
    //    }

    //    if (!isOverlap) {
    //        returnVector.push_back(node);
    //    }*/

    //    returnVector.push_back(node);
    //}

    return returnVector;
}

std::vector<Node*> DungeonGenerator::GetCooridorVector()
{
    return cooridorVector;
}
