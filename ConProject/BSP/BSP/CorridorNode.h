#pragma once

#include "Node.h"
#include "StructureHelper.h"
#include <algorithm>
#include <iterator>
#include <cmath>

class CorridorNode : public Node
{
private:
    Node* structure1;
    Node* structure2;
    
    /// <summary>
    /// 복도 넓이
    /// </summary>
    int corridorWidth;

    /// <summary>
    /// 객체와 벽 사이의 거리
    /// </summary>
    int modifierDistanceFromWall = 1;

    void GenerateCorridor();

    /// <summary>
    /// 방을 비교해 방이 상하좌우측에 있는지 반환하는 함수
    /// </summary>
    /// <returns>방의 방향</returns>
    StructureHelper::RelativePosition CheckPositionStructure2AgainstStructure1();

    double CalcuateAngle(Vector2 middlePointStructure1Temp, Vector2 middlePointStructure2Temp);
    
    bool CompareByTopRightCornerX(const Node* node1, const Node* node2);

    bool CompareByBottomRightCornerX(const Node* node1, const Node* node2);
    
    void ProcessRoomInRelationRightOrLeft(Node* structure1, Node* structure2);

    /// <summary>
    /// CorridorNode_GetValidYFroNeighourLeftRight.png에 해당하는지 확인하는 함수
    /// </summary>
    /// <param name="leftNodeUp">왼쪽 방의 좌 또는 우 상단 좌표</param>
    /// <param name="leftNodeDown">왼쪽 방의 좌 또는 우 하단 좌표</param>
    /// <param name="rightNodeUp">오른쪽 방의 좌 또는 우 상단 좌표</param>
    /// <param name="rightNodeDown">오른쪽 방의 좌 또는 우 하단 좌표</param>
    /// <returns>-1이 아니면 해당함, -1이면 해당 안함(길못만든다고 해석)</returns>
    int GetValidYForNeighourLeftRight(Vector2Int leftNodeUp, Vector2Int leftNodeDown, Vector2Int rightNodeUp, Vector2Int rightNodeDown);

    bool CompareByTopRightCornerY(const Node* node1, const Node* node2);

    bool COmpareByBottomRightCornerY(const Node* node1, const Node* node2);

    void ProcessRoomInRelationUpOrDown(Node* structure1, Node* structure2);

    int GetValidYForNeighourUpDown(Vector2Int bottomNodeLeft, Vector2Int bottomNodeRight, Vector2Int topNodeLeft, Vector2Int topNodeRight);
public:
    CorridorNode() {};

    CorridorNode(Node* node1, Node* node2, int corridorWidth);

};

