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
    return !(node1->GetBottomRightCorner().x <= node2->GetBottomLeftCorner().x || // node1이 node2의 왼쪽에 있음
        node1->GetBottomLeftCorner().x >= node2->GetBottomRightCorner().x || // node1이 node2의 오른쪽에 있음
        node1->GetTopRightCorner().y <= node2->GetBottomLeftCorner().y ||    // node1이 node2의 아래에 있음
        node1->GetBottomLeftCorner().y >= node2->GetTopRightCorner().y);     // node1이 node2의 위에 있음
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
        cout << "[방 " << count << "]좌하단 모서리 좌표 ("
            << room->GetBottomLeftCorner().x << "," << room->GetBottomLeftCorner().y
            << "), 우상단 모서리 좌표 (" << room->GetTopRightCorner().x << "," << room->GetTopRightCorner().y
            << "), 자식수 : " << room->childrenNode.size() << endl;

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
    //    // 안겹치는 방만 추출하니 문제가 생김
    //    // 그럼 전부 안겹치는 방이 나올때까지 계속 돌리면 되지 않을까?
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
