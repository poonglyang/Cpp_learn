#include "CorridorNode.h"

void CorridorNode::GenerateCorridor()
{
    StructureHelper::RelativePosition relativePositionOfStructure2 = CheckPositionStructure2AgainstStructure1();     // 연결할 방의 방향을 구함

    switch (relativePositionOfStructure2)
    {
    case StructureHelper::RelativePosition::Up:       // 길을 위로 뚫어야 하면
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
        + Vector2(structure1->GetBottomLeftCorner().x, structure1->GetBottomLeftCorner().y)) / 2);      // structure1의 중앙 좌표
    Vector2 middlePointStructure2Temp = (
        Vector2(structure2->GetTopRightCorner().x, structure2->GetTopRightCorner().y)
        + Vector2(structure2->GetBottomLeftCorner().x, structure2->GetBottomLeftCorner().y)) / 2;      // structure2의 중앙 좌표

    double angle = CalcuateAngle(middlePointStructure1Temp, middlePointStructure2Temp);          // 두 좌표 사이의 각도 계산

    if ((angle < 45 && angle >= 0) || (angle > -45 && angle < 0))
    {
        // 두 방 사이의 각도가 -45 ~ 45면 오른쪽에 있다
        return StructureHelper::RelativePosition::Right;
    }
    else if (angle > 45 && angle < 135)
    {
        // 두 방 사이의 각도가 45 ~ 135면 위에 있다
        return StructureHelper::RelativePosition::Up;
    }
    else if (angle > -135 && angle < -45)
    {
        // 두 방 사이의 각도가 -45 ~ -135면 아래에 있다
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
    std::vector<Node*> leftStructureChildren = StructureHelper::TraverseGraphToExtractLowestLeafes(structure1);      // structure1의 잎 노드 리스트를 가져옴 leftStructureChildren에 넣음
    Node* rightStructure = nullptr;
    std::vector<Node*> rightStructureChildren = StructureHelper::TraverseGraphToExtractLowestLeafes(structure2);     // structure2의 잎 노드 리스트를 가져와 rightStructureChildren에 넣음

    //leftStructureChildren에 있는 것들을 TopRightAreaCorner.x를 기준으로 내림차순 정렬
    sort(leftStructureChildren.begin(), 
        leftStructureChildren.end(), 
        [](const Node* node1, const Node* node2) {
            return node1->GetTopRightCorner().x > node2->GetTopRightCorner().x;
        });

    
    /* 이거 였지만 한번에 leftStructureChildren를 정렬하는 것이 가능하기에
    var sortedLeftStructure = leftStructureChildren.OrderByDescending(
        child = > child.TopRightAreaCorner.x).ToList();    // leftStructureChildren에 있는 것들을 TopRightAreaCorner.x를 기준으로 내림차순 정렬하고 리스트에 넣음
    // leftStructureChildren에 있는 것들 중 TopRightAreaCorner.x가 제일 큰 것이 가장 앞에 온다
    */
    std::vector<Node*> sortedLeftStructure;

    if (leftStructureChildren.size() == 1)
    {
        // structure1기준 자식(잎)이 하나밖에 없으면
        leftStructure = leftStructureChildren[0];     // 왼쪽 방에 leftStructure를 넣음
    }
    else
    {
        // structure1의 자식이 여러개면
        int maxX = leftStructureChildren[0]->GetTopRightCorner().x;     // TopRightAreaCorner.x가 가장 큰 것의 x를 꺼내 maxX에 넣음

        for (auto node : leftStructureChildren) {   // leftStructureChildren에 있는 것들 중 
            if (abs(maxX - node->GetTopRightCorner().x) < 10) {
                // Mathf.Abs(maxX - children.TopRightAreaCorner.x) < 10 인 것만 필터링해 
                sortedLeftStructure.push_back(node); // sortedLeftStructure에 넣음
            }
        }

        int index = Mathf::Random::Range(0, sortedLeftStructure.size());     // sortedLeftStructure에 있는 것들중 하나 랜덤으로 골라
        leftStructure = sortedLeftStructure[index];                 // 왼쪽 방 구조에 넣음
    }

    // 왼쪽방에 길을 놓을 수 있는 오른쪽 방 리스트
    std::vector<Node*> possibleNeighboursInRightStructureVector;

    for (Node* node : rightStructureChildren) { // rightStructureChildren에 있는 것들 중
        if (GetValidYForNeighourLeftRight(
            leftStructure->GetTopRightCorner(),
            leftStructure->GetBottomRightCorner(),
            node->GetTopLeftCorner(),
            node->GetBottomLeftCorner()) 
            != -1) 
        {
            // 방 구조가 4개의 경우의 수에 맞는 것만 필터링해 possibleNeighboursInRightStructureList에 넣고
            possibleNeighboursInRightStructureVector.push_back(node);
        }
    }

    sort(possibleNeighboursInRightStructureVector.begin(),  // CompareByBottomRightCornerX 기준으로 정렬
        possibleNeighboursInRightStructureVector.end(),
        [](const Node* node1, const Node* node2) {
            return node1->GetBottomRightCorner().x > node2->GetBottomRightCorner().x;
        });


    if (possibleNeighboursInRightStructureVector.size() <= 0)
    {
        // 길을 놓을 수 있는게 없다면 
        rightStructure = structure2;    //structure2에 길을 놓음
    }
    else
    {
        // 길을 놓을 수 있는게 있으면 
        rightStructure = possibleNeighboursInRightStructureVector[0];     //possibleNeighboursInRightStructureVector에 0번을 꺼내서 놓음
    }

    int y = GetValidYForNeighourLeftRight(leftStructure->GetTopLeftCorner(), leftStructure->GetBottomRightCorner(), // 정해진 왼쪽 방과 오른쪽 방이 
        rightStructure->GetTopLeftCorner(), rightStructure->GetBottomLeftCorner());                                 // GetValidYForNeighourLeftRight경우의 수에 해당하는지 확인

    while (y == -1 && sortedLeftStructure.size() > 1)
    {
        // y가 -1(길을 놓을 수 없는 상태)이고 sortedLeftStructure가 남아 있다면
        std::vector<Node*> temp;
        for (auto node : sortedLeftStructure) {
            if (node->GetTopLeftCorner().y != leftStructure->GetTopLeftCorner().y) {
                temp.push_back(node);
            }
        }

        leftStructure = temp[0];    // 0번째 것을 꺼냄

        y = GetValidYForNeighourLeftRight(leftStructure->GetTopLeftCorner(), leftStructure->GetBottomRightCorner(), // 정해진 왼쪽 방과 오른쪽 방이 
            rightStructure->GetTopLeftCorner(), rightStructure->GetBottomLeftCorner());                             // GetValidYForNeighourLeftRight경우의 수에 해당하는지 확인

        sortedLeftStructure.clear();
        copy(temp.begin(), temp.end(), back_inserter(sortedLeftStructure));
    }

    bottomLeftCorner = Vector2Int(leftStructure->GetBottomRightCorner().x, y);                            // 이 길의 좌하단 코너 좌표
    topRightCorner = Vector2Int(rightStructure->GetTopLeftCorner().x, y + corridorWidth);                 // 이 길의 우상단 코너 좌표
    bottomRightCorner = Vector2Int(topRightCorner.x, bottomLeftCorner.y);
    topLeftCorner = Vector2Int(bottomLeftCorner.x, topRightCorner.y);

}



int CorridorNode::GetValidYForNeighourLeftRight(Vector2Int leftNodeUp, Vector2Int leftNodeDown, Vector2Int rightNodeUp, Vector2Int rightNodeDown)
{
    if (rightNodeUp.y >= leftNodeUp.y && leftNodeDown.y >= rightNodeDown.y)
    {
        // 오른쪽 노드의 y가 왼쪽 노드의 y보다 크고 왼쪽 노드의 y가 오른쪽 노드의 y보다 클 때
        return StructureHelper::CalculateMiddlePoint(
            leftNodeDown + Vector2Int(0, modifierDistanceFromWall),                 // 왼쪽 방 밑 좌표 + 벽과의 거리
            leftNodeUp - Vector2Int(0, modifierDistanceFromWall + corridorWidth)    // 왼쪽 방 위 좌표 - (벽과의 거리 + 길 넓이)
        ).y;                                                                        // 의 중간 값의 y를 넘긴다
    }
    if (rightNodeUp.y <= leftNodeUp.y && leftNodeDown.y <= rightNodeDown.y)
    {
        // 오른쪽 노드(방)의 윗변 y값이 왼쪽 방의 윗변 y값보다 작고 왼쪽 방의 밑변 y 값이 오른쪽 방의 밑변 y 값보다 작거나 같을 때
        return StructureHelper::CalculateMiddlePoint(
            rightNodeDown + Vector2Int(0, modifierDistanceFromWall),                // 오른쪽 밑 좌표 + 벽과의 거리
            rightNodeUp - Vector2Int(0, modifierDistanceFromWall + corridorWidth)   // 오른쪽 위 좌표 - (벽과의 거리 + 길의 넓이)
        ).y;                                                                        // 의 중간 값 y를 넘김
    }
    if (leftNodeUp.y >= rightNodeDown.y && leftNodeUp.y <= rightNodeUp.y)
    {
        // 왼쪽 윗변이 오른쪽 밑변보다 높고 왼쪽 윗변이 오른쪽 윗변보다 낮을 때
        return StructureHelper::CalculateMiddlePoint(
            rightNodeDown + Vector2Int(0, modifierDistanceFromWall),                // 오른쪽 밑변 + 벽과의 거리
            leftNodeUp - Vector2Int(0, modifierDistanceFromWall)                    // 왼쪽 윗변 - 벽과의 거리
        ).y;                                                                        // 의 중간 값 y를 넘김
    }
    if (leftNodeDown.y >= rightNodeDown.y && leftNodeDown.y <= rightNodeUp.y)
    {
        // 왼쪽 밑변이 오른쪽 밑변보다 높고 왼쪽 밑변이 오른쪽 윗변보다 낮을 때
        return StructureHelper::CalculateMiddlePoint(
            leftNodeDown + Vector2Int(0, modifierDistanceFromWall),                 // 왼쪽 밑변 + 벽과의 거리
            rightNodeUp - Vector2Int(0, modifierDistanceFromWall + corridorWidth)   // 오른쪽 윗변 - (벽과의 거리 + 복도 넓이)
        ).y;                                                                        // 의 중간 값 y를 넘김
    }

    return -1;          // 위 모든게 해당되지 않으면 -1을 넘긴다
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
    std::vector<Node*> leftStructureChildren = StructureHelper::TraverseGraphToExtractLowestLeafes(structure1);      // structure1의 잎 노드 리스트를 가져옴 leftStructureChildren에 넣음
    Node* topStructure = nullptr;
    std::vector<Node*> rightStructureChildren = StructureHelper::TraverseGraphToExtractLowestLeafes(structure2);

    //leftStructureChildren에 있는 것들을 TopRightAreaCorner.x를 기준으로 내림차순 정렬
    std::sort(leftStructureChildren.begin(),
        leftStructureChildren.end(), 
        [](const Node* node1, const Node* node2) {
            return node1->GetTopRightCorner().y > node2->GetTopRightCorner().y;
        });

    std::vector<Node*> sortedBottomStructure;

    if (leftStructureChildren.size() == 1)
    {
        // structure1기준 자식(잎)이 하나밖에 없으면
        bottomStructure = leftStructureChildren[0];     // 왼쪽 방에 leftStructure를 넣음
    }
    else
    {
        // structure1의 자식이 여러개면
        int maxY = leftStructureChildren[0]->GetTopRightCorner().y;     // TopRightAreaCorner.x가 가장 큰 것의 x를 꺼내 maxX에 넣음

        for (auto node : leftStructureChildren) {   // leftStructureChildren에 있는 것들 중 
            if (abs(maxY - node->GetTopRightCorner().y) < 10) {
                // Mathf.Abs(maxX - children.TopRightAreaCorner.x) < 10 인 것만 필터링해 
                sortedBottomStructure.push_back(node); // sortedLeftStructure에 넣음
            }
        }

        int index = Mathf::Random::Range(0, sortedBottomStructure.size());     // sortedLeftStructure에 있는 것들중 하나 랜덤으로 골라
        bottomStructure = sortedBottomStructure[index];                 // 왼쪽 방 구조에 넣음
    }

    // 왼쪽방에 길을 놓을 수 있는 오른쪽 방 리스트
    std::vector<Node*> possibleNeighboursInTopStructureList;

    for (Node* node : rightStructureChildren) { // rightStructureChildren에 있는 것들 중
        if (GetValidYForNeighourUpDown(
            bottomStructure->GetTopLeftCorner(),
            bottomStructure->GetTopRightCorner(),
            node->GetBottomLeftCorner(),
            node->GetBottomRightCorner())
            != -1)
        {
            // 방 구조가 4개의 경우의 수에 맞는 것만 필터링해 possibleNeighboursInRightStructureList에 넣고
            possibleNeighboursInTopStructureList.push_back(node);
        }
    }

    std::sort(possibleNeighboursInTopStructureList.begin(),  // CompareByBottomRightCornerX 기준으로 정렬
        possibleNeighboursInTopStructureList.end(),
        [](const Node* node1, const Node* node2) {
            return node1->GetBottomRightCorner().y < node2->GetBottomRightCorner().y;
        });

    if (possibleNeighboursInTopStructureList.size() <= 0)
    {
        // 길을 놓을 수 있는게 없다면 
        topStructure = structure2;    //structure2에 길을 놓음
    }
    else
    {
        // 길을 놓을 수 있는게 있으면 
        topStructure = possibleNeighboursInTopStructureList[0];     //possibleNeighboursInRightStructureVector에 0번을 꺼내서 놓음
    }

    int x = GetValidYForNeighourUpDown(bottomStructure->GetTopLeftCorner(), bottomStructure->GetTopRightCorner(), // 정해진 왼쪽 방과 오른쪽 방이 
        topStructure->GetBottomLeftCorner(), topStructure->GetBottomRightCorner());                                 // GetValidYForNeighourLeftRight경우의 수에 해당하는지 확인

    // 여기서 루프가 돈다는 것을 알았다
    while (x == -1 && sortedBottomStructure.size() > 1)
    {
        // y가 -1(길을 놓을 수 없는 상태)이고 sortedLeftStructure가 남아 있다면
        std::vector<Node*> temp;
        for (auto node : sortedBottomStructure) {
            if (node->GetTopLeftCorner().x != topStructure->GetTopLeftCorner().x) {
                temp.push_back(node);
            }
        }

        bottomStructure = temp[0];    // 0번째 것을 꺼냄

        x = GetValidYForNeighourUpDown(
            bottomStructure->GetTopLeftCorner(), bottomStructure->GetBottomRightCorner(), // 정해진 왼쪽 방과 오른쪽 방이 
            topStructure->GetBottomLeftCorner(), topStructure->GetBottomRightCorner());                             // GetValidYForNeighourLeftRight경우의 수에 해당하는지 확인

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
    if (topNodeLeft.x < bottomNodeLeft.x && bottomNodeRight.x < topNodeRight.x)       // 오른쪽 노드의 y가 왼쪽 노드의 y보다 크고 왼쪽 노드의 y가 오른쪽 노드의 y보다 클 때
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
