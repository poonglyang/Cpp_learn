#include "RoomGenerator.h"

RoomGenerator::RoomGenerator(int maxIterations, int roomLengthMin, int roomWidthMin)
    : maxIterations(maxIterations), roomLengthMin(roomLengthMin), roomWidthMin(roomWidthMin)
{

}

std::vector<RoomNode*> RoomGenerator::GenerateRoomInGivenSpaces(std::vector<Node*> roomSpaces, float roomBottomCornerModifier, float roomTopCornerModifier, int roomOffset)
{
    std::vector<RoomNode*> vectorToReturn;

    for(auto space : roomSpaces)
    {
        Vector2Int newBottomLeftPoint = StructureHelper::GenerateBottomLeftCornerBetween(
            space->GetBottomLeftCorner(), space->GetTopRightCorner(),
            roomBottomCornerModifier, roomOffset);     // 방의 새로운 좌하단 코너 좌표를 반환

        Vector2Int newTopRightPoint = StructureHelper::GenerateTopRightCornerBetween(
            space->GetBottomLeftCorner(), space->GetTopRightCorner(),
            roomTopCornerModifier, roomOffset);     // 방의 새로운 우상단 코너 좌표를 반환

        // 각 모서리 좌표 지정
        space->SetBottomLeftCorner(newBottomLeftPoint);
        space->SetTopRightCorner(newTopRightPoint);
        space->SetBottomRightCorner(Vector2Int(newTopRightPoint.x, newBottomLeftPoint.y));
        space->SetTopLeftCorner(Vector2Int(newBottomLeftPoint.x, newTopRightPoint.y));


        vectorToReturn.push_back(static_cast<RoomNode*>(space));  // 다 했으면 넣어
    }

    return vectorToReturn;
}
