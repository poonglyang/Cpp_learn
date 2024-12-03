#include "CorridorNode.h"

void CorridorNode::GenerateCorridor()
{
    StructureHelper::RelativePosition relativePositionOfStructure2 = CheckPositionStructure2AgainstStructure1();     // ������ ���� ������ ����

    switch (relativePositionOfStructure2)
    {
    case StructureHelper::RelativePosition::Up:       // ���� ���� �վ�� �ϸ�
        ProcessRoomInRelationUpOrDown(structure1, structure2);
        break;
    case StructureHelper::RelativePosition::Down:
        ProcessRoomInRelationUpOrDown(structure2, structure1);
        break;
    case StructureHelper::RelativePosition::Right:
        ProcessRoomInRelationRightOrLeft(structure1, structure2);
        break;
    case StructureHelper::RelativePosition::Left:
        ProcessRoomInRelationRightOrLeft(structure2, structure1);
        break;
    default:
        break;
    }
}

StructureHelper::RelativePosition CorridorNode::CheckPositionStructure2AgainstStructure1()
{
    Vector2 middlePointStructure1Temp = (
        (Vector2(structure1->GetTopRightCorner().x, structure1->GetTopRightCorner().y)
        + Vector2(structure1->GetBottomLeftCorner().x, structure1->GetBottomLeftCorner().y)) / 2);      // structure1�� �߾� ��ǥ
    Vector2 middlePointStructure2Temp = (
        Vector2(structure2->GetTopRightCorner().x, structure2->GetTopRightCorner().y)
        + Vector2(structure2->GetBottomLeftCorner().x, structure2->GetBottomLeftCorner().y)) / 2;      // structure2�� �߾� ��ǥ

    double angle = CalcuateAngle(middlePointStructure1Temp, middlePointStructure2Temp);          // �� ��ǥ ������ ���� ���

    if ((angle < 45 && angle >= 0) || (angle > -45 && angle < 0))
    {
        // �� �� ������ ������ -45 ~ 45�� �����ʿ� �ִ�
        return StructureHelper::RelativePosition::Right;
    }
    else if (angle > 45 && angle < 135)
    {
        // �� �� ������ ������ 45 ~ 135�� ���� �ִ�
        return StructureHelper::RelativePosition::Up;
    }
    else if (angle > -135 && angle < -45)
    {
        // �� �� ������ ������ -45 ~ -135�� �Ʒ��� �ִ�
        return StructureHelper::RelativePosition::Down;
    }
    else
    {
        return StructureHelper::RelativePosition::Left;
    }
}

double CorridorNode::CalcuateAngle(Vector2 middlePointStructure1Temp, Vector2 middlePointStructure2Temp)
{
    double deltaY = middlePointStructure2Temp.y - middlePointStructure1Temp.y;
    double deltaX = middlePointStructure2Temp.x - middlePointStructure1Temp.x;

    return atan2(deltaY, deltaX) * Mathf::Rad2Deg;
}

bool CorridorNode::CompareByTopRightCornerX(const Node* node1, const Node* node2)
{
    return node1->GetTopRightCorner().x > node2->GetTopRightCorner().x;
}

bool CorridorNode::CompareByBottomRightCornerX(const Node* node1, const Node* node2)
{
    return node1->GetBottomRightCorner().x > node2->GetBottomRightCorner().x;
}

void CorridorNode::ProcessRoomInRelationRightOrLeft(Node* structure1, Node* structure2)
{
    Node* leftStructure = nullptr;
    std::vector<Node*> leftStructureChildren = StructureHelper::TraverseGraphToExtractLowestLeafes(structure1);      // structure1�� �� ��� ����Ʈ�� ������ leftStructureChildren�� ����
    Node* rightStructure = nullptr;
    std::vector<Node*> rightStructureChildren = StructureHelper::TraverseGraphToExtractLowestLeafes(structure2);     // structure2�� �� ��� ����Ʈ�� ������ rightStructureChildren�� ����

    //leftStructureChildren�� �ִ� �͵��� TopRightAreaCorner.x�� �������� �������� ����
    sort(leftStructureChildren.begin(), 
        leftStructureChildren.end(), 
        [](const Node* node1, const Node* node2) {
            return node1->GetTopRightCorner().x > node2->GetTopRightCorner().x;
        });

    
    /* �̰� ������ �ѹ��� leftStructureChildren�� �����ϴ� ���� �����ϱ⿡
    var sortedLeftStructure = leftStructureChildren.OrderByDescending(
        child = > child.TopRightAreaCorner.x).ToList();    // leftStructureChildren�� �ִ� �͵��� TopRightAreaCorner.x�� �������� �������� �����ϰ� ����Ʈ�� ����
    // leftStructureChildren�� �ִ� �͵� �� TopRightAreaCorner.x�� ���� ū ���� ���� �տ� �´�
    */
    std::vector<Node*> sortedLeftStructure;

    if (leftStructureChildren.size() == 1)
    {
        // structure1���� �ڽ�(��)�� �ϳ��ۿ� ������
        leftStructure = leftStructureChildren[0];     // ���� �濡 leftStructure�� ����
    }
    else
    {
        // structure1�� �ڽ��� ��������
        int maxX = leftStructureChildren[0]->GetTopRightCorner().x;     // TopRightAreaCorner.x�� ���� ū ���� x�� ���� maxX�� ����

        for (auto node : leftStructureChildren) {   // leftStructureChildren�� �ִ� �͵� �� 
            if (abs(maxX - node->GetTopRightCorner().x) < 10) {
                // Mathf.Abs(maxX - children.TopRightAreaCorner.x) < 10 �� �͸� ���͸��� 
                sortedLeftStructure.push_back(node); // sortedLeftStructure�� ����
            }
        }

        int index = Mathf::Random::Range(0, sortedLeftStructure.size());     // sortedLeftStructure�� �ִ� �͵��� �ϳ� �������� ���
        leftStructure = sortedLeftStructure[index];                 // ���� �� ������ ����
    }

    // ���ʹ濡 ���� ���� �� �ִ� ������ �� ����Ʈ
    std::vector<Node*> possibleNeighboursInRightStructureVector;

    for (Node* node : rightStructureChildren) { // rightStructureChildren�� �ִ� �͵� ��
        if (GetValidYForNeighourLeftRight(
            leftStructure->GetTopRightCorner(),
            leftStructure->GetBottomRightCorner(),
            node->GetTopLeftCorner(),
            node->GetBottomLeftCorner()) 
            != -1) 
        {
            // �� ������ 4���� ����� ���� �´� �͸� ���͸��� possibleNeighboursInRightStructureList�� �ְ�
            possibleNeighboursInRightStructureVector.push_back(node);
        }
    }

    sort(possibleNeighboursInRightStructureVector.begin(),  // CompareByBottomRightCornerX �������� ����
        possibleNeighboursInRightStructureVector.end(),
        [](const Node* node1, const Node* node2) {
            return node1->GetBottomRightCorner().x > node2->GetBottomRightCorner().x;
        });


    if (possibleNeighboursInRightStructureVector.size() <= 0)
    {
        // ���� ���� �� �ִ°� ���ٸ� 
        rightStructure = structure2;    //structure2�� ���� ����
    }
    else
    {
        // ���� ���� �� �ִ°� ������ 
        rightStructure = possibleNeighboursInRightStructureVector[0];     //possibleNeighboursInRightStructureVector�� 0���� ������ ����
    }

    int y = GetValidYForNeighourLeftRight(leftStructure->GetTopLeftCorner(), leftStructure->GetBottomRightCorner(), // ������ ���� ��� ������ ���� 
        rightStructure->GetTopLeftCorner(), rightStructure->GetBottomLeftCorner());                                 // GetValidYForNeighourLeftRight����� ���� �ش��ϴ��� Ȯ��

    while (y == -1 && sortedLeftStructure.size() > 1)
    {
        // y�� -1(���� ���� �� ���� ����)�̰� sortedLeftStructure�� ���� �ִٸ�
        std::vector<Node*> temp;
        for (auto node : sortedLeftStructure) {
            if (node->GetTopLeftCorner().y != leftStructure->GetTopLeftCorner().y) {
                temp.push_back(node);
            }
        }

        leftStructure = temp[0];    // 0��° ���� ����

        y = GetValidYForNeighourLeftRight(leftStructure->GetTopLeftCorner(), leftStructure->GetBottomRightCorner(), // ������ ���� ��� ������ ���� 
            rightStructure->GetTopLeftCorner(), rightStructure->GetBottomLeftCorner());                             // GetValidYForNeighourLeftRight����� ���� �ش��ϴ��� Ȯ��

        sortedLeftStructure.clear();
        copy(temp.begin(), temp.end(), back_inserter(sortedLeftStructure));
    }

    bottomLeftCorner = Vector2Int(leftStructure->GetBottomRightCorner().x, y);                            // �� ���� ���ϴ� �ڳ� ��ǥ
    topRightCorner = Vector2Int(rightStructure->GetTopLeftCorner().x, y + corridorWidth);                 // �� ���� ���� �ڳ� ��ǥ
    bottomRightCorner = Vector2Int(topRightCorner.x, bottomLeftCorner.y);
    topLeftCorner = Vector2Int(bottomLeftCorner.x, topRightCorner.y);

}



int CorridorNode::GetValidYForNeighourLeftRight(Vector2Int leftNodeUp, Vector2Int leftNodeDown, Vector2Int rightNodeUp, Vector2Int rightNodeDown)
{
    if (rightNodeUp.y >= leftNodeUp.y && leftNodeDown.y >= rightNodeDown.y)
    {
        // ������ ����� y�� ���� ����� y���� ũ�� ���� ����� y�� ������ ����� y���� Ŭ ��
        return StructureHelper::CalculateMiddlePoint(
            leftNodeDown + Vector2Int(0, modifierDistanceFromWall),                 // ���� �� �� ��ǥ + ������ �Ÿ�
            leftNodeUp - Vector2Int(0, modifierDistanceFromWall + corridorWidth)    // ���� �� �� ��ǥ - (������ �Ÿ� + �� ����)
        ).y;                                                                        // �� �߰� ���� y�� �ѱ��
    }
    if (rightNodeUp.y <= leftNodeUp.y && leftNodeDown.y <= rightNodeDown.y)
    {
        // ������ ���(��)�� ���� y���� ���� ���� ���� y������ �۰� ���� ���� �غ� y ���� ������ ���� �غ� y ������ �۰ų� ���� ��
        return StructureHelper::CalculateMiddlePoint(
            rightNodeDown + Vector2Int(0, modifierDistanceFromWall),                // ������ �� ��ǥ + ������ �Ÿ�
            rightNodeUp - Vector2Int(0, modifierDistanceFromWall + corridorWidth)   // ������ �� ��ǥ - (������ �Ÿ� + ���� ����)
        ).y;                                                                        // �� �߰� �� y�� �ѱ�
    }
    if (leftNodeUp.y >= rightNodeDown.y && leftNodeUp.y <= rightNodeUp.y)
    {
        // ���� ������ ������ �غ����� ���� ���� ������ ������ �������� ���� ��
        return StructureHelper::CalculateMiddlePoint(
            rightNodeDown + Vector2Int(0, modifierDistanceFromWall),                // ������ �غ� + ������ �Ÿ�
            leftNodeUp - Vector2Int(0, modifierDistanceFromWall)                    // ���� ���� - ������ �Ÿ�
        ).y;                                                                        // �� �߰� �� y�� �ѱ�
    }
    if (leftNodeDown.y >= rightNodeDown.y && leftNodeDown.y <= rightNodeUp.y)
    {
        // ���� �غ��� ������ �غ����� ���� ���� �غ��� ������ �������� ���� ��
        return StructureHelper::CalculateMiddlePoint(
            leftNodeDown + Vector2Int(0, modifierDistanceFromWall),                 // ���� �غ� + ������ �Ÿ�
            rightNodeUp - Vector2Int(0, modifierDistanceFromWall + corridorWidth)   // ������ ���� - (������ �Ÿ� + ���� ����)
        ).y;                                                                        // �� �߰� �� y�� �ѱ�
    }

    return -1;          // �� ���� �ش���� ������ -1�� �ѱ��
}

bool CorridorNode::CompareByTopRightCornerY(const Node* node1, const Node* node2)
{
    return node1->GetTopRightCorner().y > node2->GetTopRightCorner().y;
}

bool CorridorNode::COmpareByBottomRightCornerY(const Node* node1, const Node* node2)
{
    return node1->GetBottomRightCorner().y > node2->GetBottomRightCorner().y;
}

void CorridorNode::ProcessRoomInRelationUpOrDown(Node* structure1, Node* structure2)
{
    Node* bottomStructure = nullptr;
    std::vector<Node*> leftStructureChildren = StructureHelper::TraverseGraphToExtractLowestLeafes(structure1);      // structure1�� �� ��� ����Ʈ�� ������ leftStructureChildren�� ����
    Node* topStructure = nullptr;
    std::vector<Node*> rightStructureChildren = StructureHelper::TraverseGraphToExtractLowestLeafes(structure2);

    //leftStructureChildren�� �ִ� �͵��� TopRightAreaCorner.x�� �������� �������� ����
    std::sort(leftStructureChildren.begin(),
        leftStructureChildren.end(), 
        [](const Node* node1, const Node* node2) {
            return node1->GetTopRightCorner().y > node2->GetTopRightCorner().y;
        });

    std::vector<Node*> sortedBottomStructure;

    if (leftStructureChildren.size() == 1)
    {
        // structure1���� �ڽ�(��)�� �ϳ��ۿ� ������
        bottomStructure = leftStructureChildren[0];     // ���� �濡 leftStructure�� ����
    }
    else
    {
        // structure1�� �ڽ��� ��������
        int maxY = leftStructureChildren[0]->GetTopRightCorner().y;     // TopRightAreaCorner.x�� ���� ū ���� x�� ���� maxX�� ����

        for (auto node : leftStructureChildren) {   // leftStructureChildren�� �ִ� �͵� �� 
            if (abs(maxY - node->GetTopRightCorner().y) < 10) {
                // Mathf.Abs(maxX - children.TopRightAreaCorner.x) < 10 �� �͸� ���͸��� 
                sortedBottomStructure.push_back(node); // sortedLeftStructure�� ����
            }
        }

        int index = Mathf::Random::Range(0, sortedBottomStructure.size());     // sortedLeftStructure�� �ִ� �͵��� �ϳ� �������� ���
        bottomStructure = sortedBottomStructure[index];                 // ���� �� ������ ����
    }

    // ���ʹ濡 ���� ���� �� �ִ� ������ �� ����Ʈ
    std::vector<Node*> possibleNeighboursInTopStructureList;

    for (Node* node : rightStructureChildren) { // rightStructureChildren�� �ִ� �͵� ��
        if (GetValidYForNeighourUpDown(
            bottomStructure->GetTopLeftCorner(),
            bottomStructure->GetTopRightCorner(),
            node->GetBottomLeftCorner(),
            node->GetBottomRightCorner())
            != -1)
        {
            // �� ������ 4���� ����� ���� �´� �͸� ���͸��� possibleNeighboursInRightStructureList�� �ְ�
            possibleNeighboursInTopStructureList.push_back(node);
        }
    }

    std::sort(possibleNeighboursInTopStructureList.begin(),  // CompareByBottomRightCornerX �������� ����
        possibleNeighboursInTopStructureList.end(),
        [](const Node* node1, const Node* node2) {
            return node1->GetBottomRightCorner().y < node2->GetBottomRightCorner().y;
        });

    if (possibleNeighboursInTopStructureList.size() <= 0)
    {
        // ���� ���� �� �ִ°� ���ٸ� 
        topStructure = structure2;    //structure2�� ���� ����
    }
    else
    {
        // ���� ���� �� �ִ°� ������ 
        topStructure = possibleNeighboursInTopStructureList[0];     //possibleNeighboursInRightStructureVector�� 0���� ������ ����
    }

    int x = GetValidYForNeighourUpDown(bottomStructure->GetTopLeftCorner(), bottomStructure->GetTopRightCorner(), // ������ ���� ��� ������ ���� 
        topStructure->GetBottomLeftCorner(), topStructure->GetBottomRightCorner());                                 // GetValidYForNeighourLeftRight����� ���� �ش��ϴ��� Ȯ��

    // ���⼭ ������ ���ٴ� ���� �˾Ҵ�
    while (x == -1 && sortedBottomStructure.size() > 1)
    {
        // y�� -1(���� ���� �� ���� ����)�̰� sortedLeftStructure�� ���� �ִٸ�
        std::vector<Node*> temp;
        for (auto node : sortedBottomStructure) {
            if (node->GetTopLeftCorner().x != topStructure->GetTopLeftCorner().x) {
                temp.push_back(node);
            }
        }

        bottomStructure = temp[0];    // 0��° ���� ����

        x = GetValidYForNeighourUpDown(
            bottomStructure->GetTopLeftCorner(), bottomStructure->GetBottomRightCorner(), // ������ ���� ��� ������ ���� 
            topStructure->GetBottomLeftCorner(), topStructure->GetBottomRightCorner());                             // GetValidYForNeighourLeftRight����� ���� �ش��ϴ��� Ȯ��

        sortedBottomStructure.clear();
        copy(temp.begin(), temp.end(), back_inserter(sortedBottomStructure));
    }
    bottomLeftCorner = Vector2Int(x, bottomStructure->GetTopLeftCorner().y);
    topRightCorner = Vector2Int(x + corridorWidth, topStructure->GetBottomRightCorner().y);
    bottomRightCorner = Vector2Int(topRightCorner.x, bottomLeftCorner.y);
    topLeftCorner = Vector2Int(bottomLeftCorner.x, topRightCorner.y);
}

int CorridorNode::GetValidYForNeighourUpDown(Vector2Int bottomNodeLeft, Vector2Int bottomNodeRight, Vector2Int topNodeLeft, Vector2Int topNodeRight)
{
    if (topNodeLeft.x < bottomNodeLeft.x && bottomNodeRight.x < topNodeRight.x)       // ������ ����� y�� ���� ����� y���� ũ�� ���� ����� y�� ������ ����� y���� Ŭ ��
    {
        return StructureHelper::CalculateMiddlePoint(
            bottomNodeLeft + Vector2Int(modifierDistanceFromWall, 0),
            bottomNodeRight - Vector2Int(corridorWidth + modifierDistanceFromWall, 0)
        ).x;
    }
    if (topNodeLeft.x >= bottomNodeLeft.x && bottomNodeRight.x >= topNodeRight.x)
    {
        return StructureHelper::CalculateMiddlePoint(
            topNodeLeft +  Vector2Int(modifierDistanceFromWall, 0),
            topNodeRight -  Vector2Int(corridorWidth + modifierDistanceFromWall, 0)
        ).x;
    }
    if (bottomNodeLeft.x >= topNodeLeft.x && bottomNodeLeft.x <= topNodeRight.x)
    {
        return StructureHelper::CalculateMiddlePoint(
            bottomNodeLeft +  Vector2Int(modifierDistanceFromWall, 0),
            topNodeRight -  Vector2Int(corridorWidth + modifierDistanceFromWall, 0)
        ).x;
    }
    if (bottomNodeRight.x <= topNodeRight.x && bottomNodeRight.x >= topNodeLeft.x)
    {
        return StructureHelper::CalculateMiddlePoint(
            topNodeLeft +  Vector2Int(modifierDistanceFromWall, 0),
            bottomNodeRight -  Vector2Int(corridorWidth + modifierDistanceFromWall, 0)
        ).x;
    }

    return -1;
}

CorridorNode::CorridorNode(Node* node1, Node* node2, int corridorWidth)
	: Node()
{
    this->structure1 = node1;
    this->structure2 = node2;
    this->corridorWidth = corridorWidth;
    GenerateCorridor();
}

CorridorNode::~CorridorNode()
{
    delete structure1;
    delete structure2;
}
