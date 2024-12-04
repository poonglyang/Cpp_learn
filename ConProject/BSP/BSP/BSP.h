#pragma once
#include "RoomGenerator.h"
#include "Line.h"
class BSP
{
private:
    RoomNode* rootNode;

    /// <summary>
    /// ����� ������ �����ϴ� �Լ�
    /// </summary>
    /// <param name="currentNode">������ ���</param>
    /// <param name="listToReturn">����Ʈ</param>
    /// <param name="roomLengthMin">���� ���� �ּ� ����</param>
    /// <param name="roomWidthMin">���� ���� �ּ� ���� </param>
    /// <param name="graph">�׷���</param>
    void SplitTheSpace(RoomNode* currentNode, std::vector<RoomNode*>& listToReturn, int roomLengthMin, int roomWidthMin, std::queue<RoomNode*>& graph);

    /// <summary>
    /// ������ ���� �������� �Լ�
    /// </summary>
    /// <param name="bottomLeftAreaCorner">������ ���� ���ϴ� ��ǥ</param>
    /// <param name="topRightAreaCorner">������ ���� �»�� ��ǥ</param>
    /// <param name="roomWidthMin">���� �ּ� ���� ����</param>
    /// <param name="roomLengthMin">���� �ּ� ���� ����</param>
    /// <returns></returns>
    Line GetLineDividingSpace(Vector2Int bottomLeftAreaCorner, Vector2Int topRightAreaCorner, int roomWidthMin, int roomLengthMin);

    /// <summary>
    /// ���� ���� �������� ��ȯ�� �Լ�
    /// </summary>
    /// <param name="orientation">���� ���� ����</param>
    /// <param name="bottomLeftAreaCorner">������ ���� ���ϴ� ��ǥ</param>
    /// <param name="topRightAreaCorner">������ ���� ���� ��ǥ</param>
    /// <param name="roomWidthMin">�� ���� �ּ� ũ��</param>
    /// <param name="roomLengthMin">�� ���� �ּ� ũ��</param>
    /// <returns></returns>
    Vector2Int GetCoordinatesFororientation(Orientation orientation, Vector2Int bottomLeftAreaCorner, Vector2Int topRightAreaCorner, int roomWidthMin, int roomLengthMin);

public:
    /// <summary>
    /// BSP ������ 
    /// </summary>
    /// <param name="dungeonWidth">���� ���� ����</param>
    /// <param name="dungeonLength">���� ���� ����</param>
    BSP(int dungeonWidth, int dungeonLength);
    
    ~BSP();


    RoomNode* GetRootNode();

    /// <summary>
    /// ��带 ����� ������ ���� ���� ������ ��ȯ�ϴ� �޼���
    /// </summary>
    /// <param name="maxIterations">�ִ� ���Ҽ�</param>
    /// <param name="roomWidthMin">�� �ּ� ���� ����</param>
    /// <param name="roomLengthMin">�� �ּ� ���� ����</param>
    /// <returns>���� ���� ����</returns>
    std::vector<RoomNode*> PrepareNodesCollection(int maxIterations, int roomWidthMin, int roomLengthMin);

    void AddNewNodeToCollections(std::vector<RoomNode*>& listToReturn, std::queue<RoomNode*>& graph, RoomNode* node);



};
