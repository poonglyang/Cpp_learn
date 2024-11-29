#include "DungeonGenerator.h"

vector<Node*> DungeonGenerator::CalculateDungeon(int maxIterations, int roomWidthMin, int roomLengthMin, float roomBottomCornerModifier, float roomTopCornerModifier, int roomOffset, int corridorWidth)
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
    vector<Node*> roomSpaces = StructureHelper::TraverseGraphToExtractLowestLeafes(bsp.GetRootNode());
    RoomGenerator roomGenerator = RoomGenerator(maxIterations, roomLengthMin, roomWidthMin);
    vector<RoomNode*> roomList = roomGenerator.GenerateRoomInGivenSpaces(roomSpaces, roomBottomCornerModifier, roomTopCornerModifier, roomOffset);

    CooridorsGenerator cooridorsGenerator = CooridorsGenerator();
    auto cooridorList = cooridorsGenerator.CreateCooridoer(allNodesCollection, corridorWidth);

    /*vector<Node> returnVector;
    for (auto& roomNode : roomList) {
        returnVector.push_back(static_cast<Node>(roomNode));
    }*/


    vector<Node*> returnVector;
    for (auto roomNode : roomList) {
        returnVector.push_back(roomNode);
    }

    for (Node* node : cooridorList) {
        returnVector.push_back(node);
    }

    return returnVector;

    //return returnVector;
}
