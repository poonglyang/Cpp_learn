#include "StructureHelper.h"

vector<Node> StructureHelper::TraverseGraphToExtractLowestLeafes(Node parentNode)
{
    queue<Node> nodesToCheck;
    vector<Node> listToReturn;

    if (parentNode.childrenNode.size() == 0) {
        listToReturn.push_back(parentNode);
        return listToReturn;
    }

    for (auto& child : parentNode.childrenNode) {
        nodesToCheck.push(child);
    }

    while (nodesToCheck.size() > 0) {
        Node currentNode = nodesToCheck.front();
        nodesToCheck.pop();
        if (currentNode.childrenNode.size() == 0) {
            listToReturn.push_back(currentNode);
        }
        else {
            for (auto& child : parentNode.childrenNode) {
                nodesToCheck.push(child);
            }
        }
    }

    return listToReturn;
}

Vector2Int StructureHelper::GenerateBottomLeftCornerBetween(Vector2Int boundrayLeftPoint, Vector2Int boundrayRightPoint, float pointModifire, int offset)
{
    int minX = boundrayLeftPoint.x + offset;
    int maxX = boundrayRightPoint.x - offset;

    int minY = boundrayLeftPoint.y + offset;
    int maxY = boundrayRightPoint.y - offset;

    return Vector2Int(
        rand() % (minX, (int)(minX + (maxX - minX) * pointModifire)),
        rand() % (minY, (int)(minY + (maxY - minY) * pointModifire))
    );
}

Vector2Int StructureHelper::GenerateTopRightCornerBetween(Vector2Int boundrayLeftPoint, Vector2Int boundrayRightPoint, float pointModifire, int offset)
{
    int minX = boundrayLeftPoint.x + offset;
    int maxX = boundrayRightPoint.x - offset;

    int minY = boundrayLeftPoint.y + offset;
    int maxY = boundrayRightPoint.y - offset;

    return Vector2Int(
        rand() % ((int)(minX + (maxX - minX) * pointModifire), maxX),
        rand() % ((int)(minY + (maxY - minY) * pointModifire), maxY)
    );
}

Vector2Int StructureHelper::CalculateMiddlePoint(Vector2Int v1, Vector2Int v2)
{
    Vector2 sum = v1 + v2;             // 두 백터 더하고~
    Vector2 tempVector = sum * 0.5;   // 두 백터 나누고~
    return Vector2Int((int)tempVector.x, (int)tempVector.y);    // 그 값 반환 하기~
}
