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

    double CalcuateAngle(Vector2 middlePointStructure1Temp, Vector2 middlePointStructure2Temp);
    
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
    int GetValidYForNeighourLeftRight(Vector2Int leftNodeUp, Vector2Int leftNodeDown, Vector2Int rightNodeUp, Vector2Int rightNodeDown);

    bool CompareByTopRightCornerY(const Node* node1, const Node* node2);

    bool COmpareByBottomRightCornerY(const Node* node1, const Node* node2);

    void ProcessRoomInRelationUpOrDown(Node* structure1, Node* structure2);

    int GetValidYForNeighourUpDown(Vector2Int bottomNodeLeft, Vector2Int bottomNodeRight, Vector2Int topNodeLeft, Vector2Int topNodeRight);
public:
    CorridorNode() {};

    CorridorNode(Node* node1, Node* node2, int corridorWidth);

};

