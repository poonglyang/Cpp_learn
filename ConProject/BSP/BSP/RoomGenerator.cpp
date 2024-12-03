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
            roomBottomCornerModifier, roomOffset);     // ���� ���ο� ���ϴ� �ڳ� ��ǥ�� ��ȯ

        Vector2Int newTopRightPoint = StructureHelper::GenerateTopRightCornerBetween(
            space->GetBottomLeftCorner(), space->GetTopRightCorner(),
            roomTopCornerModifier, roomOffset);     // ���� ���ο� ���� �ڳ� ��ǥ�� ��ȯ

        // �� �𼭸� ��ǥ ����
        space->SetBottomLeftCorner(newBottomLeftPoint);
        space->SetTopRightCorner(newTopRightPoint);
        space->SetBottomRightCorner(Vector2Int(newTopRightPoint.x, newBottomLeftPoint.y));
        space->SetTopLeftCorner(Vector2Int(newBottomLeftPoint.x, newTopRightPoint.y));


        vectorToReturn.push_back(static_cast<RoomNode*>(space));  // �� ������ �־�
    }

    return vectorToReturn;
}
