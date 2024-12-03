#include "BSP.h"

void BSP::SplitTheSpace(RoomNode* currentNode, std::vector<RoomNode*>& listToReturn, int roomLengthMin, int roomWidthMin, std::queue<RoomNode*>& graph)
{
    // ������ ������ ������
    Line line = GetLineDividingSpace(currentNode->GetBottomLeftCorner(), 
        currentNode->GetTopRightCorner(), roomWidthMin, roomLengthMin);

    // �� ��� 2�� ����
    if (line.GetOrientation() == Orientation::Horiszontal)
    {
        // �����̸�
        RoomNode* node1 = new RoomNode(currentNode, currentNode->GetBottomLeftCorner(),                          // ��� 1�� ���ϴ� ��ǥ = �θ��� ���ϴ� ��ǥ
            Vector2Int(currentNode->GetTopRightCorner().x, line.GetCoordinates().y),       // ��� 1�� ���� ��ǥ = (�θ��� ���� x ��ǥ, ���Ҽ��� y ��ǥ) 
            currentNode->GetTreeIndex() + 1);                                            // Ʈ�� �ε����� �θ� ��� + 1

        RoomNode* node2 = new RoomNode(currentNode, Vector2Int(currentNode->GetBottomLeftCorner().x,
            line.GetCoordinates().y), currentNode->GetTopRightCorner(),
            currentNode->GetTreeIndex() + 1);

        AddNewNodeToCollections(listToReturn, graph, node1);
        AddNewNodeToCollections(listToReturn, graph, node2);
    }
    else
    {
        RoomNode* node1 = new RoomNode(currentNode, currentNode->GetBottomLeftCorner(),
            Vector2Int(line.GetCoordinates().x, currentNode->GetTopRightCorner().y),
            currentNode->GetTreeIndex() + 1);

        RoomNode* node2 = new RoomNode(currentNode, Vector2Int(
            line.GetCoordinates().x, currentNode->GetBottomLeftCorner().y),
            currentNode->GetTopRightCorner(), currentNode->GetTreeIndex() + 1);

        AddNewNodeToCollections(listToReturn, graph, node1);
        AddNewNodeToCollections(listToReturn, graph, node2);
    }

    
}

Line BSP::GetLineDividingSpace(Vector2Int bottomLeftAreaCorner, Vector2Int topRightAreaCorner, int roomWidthMin, int roomLengthMin)
{
    Orientation orientation;

    // ���� ���� ���� ����
    bool lengthStatus = (topRightAreaCorner.y - bottomLeftAreaCorner.y) >= 2 * roomLengthMin; // ����� ���� ���̰� �� �ּ� ũ���� 2�躸�� ũ�ų� �������� true( �� 2���� �� �� ���� ��)
    bool widthStatus = (topRightAreaCorner.x - bottomLeftAreaCorner.x) >= 2 * roomWidthMin; // ����� ���� ���̰� �� 2�� �� �� ������ true

    if (lengthStatus && widthStatus)                         // �Ѵ� �����ϸ�
    {
        orientation = (Orientation)(rand() % 2);    // �������� �ϳ� ����
    }
    else if (widthStatus)
    {
        orientation = Orientation::Vertical;                 // ���θ� �Ǹ� ������ ����
    }
    else
    {
        orientation = Orientation::Horiszontal;              // ���θ� �����ϸ� ���� ������ ����
    }

    return Line(orientation, GetCoordinatesFororientation(orientation, bottomLeftAreaCorner, topRightAreaCorner, roomWidthMin, roomLengthMin));
}

Vector2Int BSP::GetCoordinatesFororientation(Orientation orientation, Vector2Int bottomLeftAreaCorner, Vector2Int topRightAreaCorner, int roomWidthMin, int roomLengthMin)
{
    Vector2Int coordinates = Vector2Int::zero();

    if (orientation == Orientation::Horiszontal)
    {
        // ���� ���̸�
        // �������� 0, �Ʒ������� �� ������ ũ��, ���������� �� ������ ũ�� ������ ������ ���Ѵ�
        coordinates = Vector2Int(0, Mathf::Random::Range(
            (bottomLeftAreaCorner.y + roomLengthMin),
            (topRightAreaCorner.y - roomLengthMin)));
        
    }
    else
    {
        // ���� ���̸�
        // �������� ���ʺ��� �� ������ ũ��, �����ʿ������� �� ������ ũ�� ������ ������ ���Ѵ�
        coordinates = Vector2Int(Mathf::Random::Range(
            (bottomLeftAreaCorner.x + roomWidthMin),
            (topRightAreaCorner.x - roomWidthMin)), 0);

    }

    return coordinates;
}

BSP::BSP(int dungeonWidth, int dungeonLength)
{
	this->rootNode = new RoomNode(nullptr, Vector2Int(0, 0), Vector2Int(dungeonWidth, dungeonLength), 0);
}

BSP::~BSP()
{
    delete rootNode;
}

RoomNode* BSP::GetRootNode()
{
	return rootNode;
}

std::vector<RoomNode*> BSP::PrepareNodesCollection(int maxIterations, int roomWidthMin, int roomLengthMin)
{
    std::queue<RoomNode*> graph;            // �׷��� ����
    std::vector<RoomNode*> vectorToReturn;        // ������ ���� ����

    graph.push(this->rootNode);                               // �׷����� ��Ʈ ��� �ְ�
    vectorToReturn.push_back(this->rootNode);                            // ����Ʈ���� ��Ʈ ��� �־���

    int iterations = 0;                                         // �� ���� Ƚ��

    while (iterations < maxIterations && graph.size() > 0)
    {
        // �ִ� �� ���� Ƚ������ ���� �� ���� Ƚ���� ����, ť�� ������ �ݺ� ����

        iterations++;                               // �� ���� Ƚ�� ����
        RoomNode* currentNode = graph.front();     // ť���� ���带 ���� ���� ���� ����
        graph.pop();
        if (currentNode->GetWidth() >= roomWidthMin * 2 || currentNode->GetLength() >= roomLengthMin * 2)
        {
            // ���� ����� ���ΰ� ���� ���� �ּ� ������ 2�躸�� ũ�ų�
            // ���� ����� ���ΰ� ���� ���� �ּ� ������ 2�躸�� ũ��
            SplitTheSpace(currentNode, vectorToReturn, roomLengthMin, roomWidthMin, graph);       // �� ���� �Լ� ����
        }
    }

    return vectorToReturn;
}

void BSP::AddNewNodeToCollections(std::vector<RoomNode*>& listToReturn, std::queue<RoomNode*>& graph, RoomNode* node)
{
    listToReturn.push_back(node);
    graph.push(node);
}
