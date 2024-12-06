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
    /// ���� ����
    /// </summary>
    int corridorWidth;

    /// <summary>
    /// ��ü�� �� ������ �Ÿ�
    /// </summary>
    int modifierDistanceFromWall = 1;

    void GenerateCorridor();

    /// <summary>
    /// ���� ���� ���� �����¿����� �ִ��� ��ȯ�ϴ� �Լ�
    /// </summary>
    /// <returns>���� ����</returns>
    StructureHelper::RelativePosition CheckPositionStructure2AgainstStructure1();

    double CalcuateAngle(myMath::Vector2 middlePointStructure1Temp, myMath::Vector2 middlePointStructure2Temp);
    
    bool CompareByTopRightCornerX(const Node* node1, const Node* node2);

    bool CompareByBottomRightCornerX(const Node* node1, const Node* node2);
    
    void ProcessRoomInRelationRightOrLeft(Node* structure1, Node* structure2);

    /// <summary>
    /// CorridorNode_GetValidYFroNeighourLeftRight.png�� �ش��ϴ��� Ȯ���ϴ� �Լ�
    /// </summary>
    /// <param name="leftNodeUp">���� ���� �� �Ǵ� �� ��� ��ǥ</param>
    /// <param name="leftNodeDown">���� ���� �� �Ǵ� �� �ϴ� ��ǥ</param>
    /// <param name="rightNodeUp">������ ���� �� �Ǵ� �� ��� ��ǥ</param>
    /// <param name="rightNodeDown">������ ���� �� �Ǵ� �� �ϴ� ��ǥ</param>
    /// <returns>-1�� �ƴϸ� �ش���, -1�̸� �ش� ����(�������ٰ� �ؼ�)</returns>
    int GetValidYForNeighourLeftRight(myMath::Vector2Int leftNodeUp, myMath::Vector2Int leftNodeDown, myMath::Vector2Int rightNodeUp, myMath::Vector2Int rightNodeDown);

    bool CompareByTopRightCornerY(const Node* node1, const Node* node2);

    bool COmpareByBottomRightCornerY(const Node* node1, const Node* node2);

    void ProcessRoomInRelationUpOrDown(Node* structure1, Node* structure2);

    int GetValidYForNeighourUpDown(myMath::Vector2Int bottomNodeLeft, myMath::Vector2Int bottomNodeRight, myMath::Vector2Int topNodeLeft, myMath::Vector2Int topNodeRight);
public:
    CorridorNode() {};


    CorridorNode(Node* node1, Node* node2, int corridorWidth);

    ~CorridorNode();
};

