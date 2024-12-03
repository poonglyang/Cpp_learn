#include "BSP.h"

void BSP::SplitTheSpace(RoomNode* currentNode, std::vector<RoomNode*>& listToReturn, int roomLengthMin, int roomWidthMin, std::queue<RoomNode*>& graph)
{
    // 분할할 라인을 가져옴
    Line line = GetLineDividingSpace(currentNode->GetBottomLeftCorner(), 
        currentNode->GetTopRightCorner(), roomWidthMin, roomLengthMin);

    // 룸 노드 2개 생성
    if (line.GetOrientation() == Orientation::Horiszontal)
    {
        // 수평선이면
        RoomNode* node1 = new RoomNode(currentNode, currentNode->GetBottomLeftCorner(),                          // 노드 1의 좌하단 좌표 = 부모의 좌하단 좌표
            Vector2Int(currentNode->GetTopRightCorner().x, line.GetCoordinates().y),       // 노드 1의 우상단 좌표 = (부모의 우상단 x 좌표, 분할선의 y 좌표) 
            currentNode->GetTreeIndex() + 1);                                            // 트리 인덱스는 부모 노드 + 1

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

    // 선의 생성 가능 여부
    bool lengthStatus = (topRightAreaCorner.y - bottomLeftAreaCorner.y) >= 2 * roomLengthMin; // 노드의 세로 길이가 방 최소 크기의 2배보다 크거나 같을으면 true( 방 2개가 들어갈 수 있을 때)
    bool widthStatus = (topRightAreaCorner.x - bottomLeftAreaCorner.x) >= 2 * roomWidthMin; // 노드의 가로 길이가 방 2개 들어갈 수 있으면 true

    if (lengthStatus && widthStatus)                         // 둘다 만족하면
    {
        orientation = (Orientation)(rand() % 2);    // 랜덤으로 하나 결정
    }
    else if (widthStatus)
    {
        orientation = Orientation::Vertical;                 // 가로만 되면 세로줄 생성
    }
    else
    {
        orientation = Orientation::Horiszontal;              // 세로만 충족하면 가로 분할줄 생성
    }

    return Line(orientation, GetCoordinatesFororientation(orientation, bottomLeftAreaCorner, topRightAreaCorner, roomWidthMin, roomLengthMin));
}

Vector2Int BSP::GetCoordinatesFororientation(Orientation orientation, Vector2Int bottomLeftAreaCorner, Vector2Int topRightAreaCorner, int roomWidthMin, int roomLengthMin)
{
    Vector2Int coordinates = Vector2Int::zero();

    if (orientation == Orientation::Horiszontal)
    {
        // 세로 선이면
        // 분할점을 0, 아래서부터 방 가능한 크기, 위에서부터 방 가능한 크기 사이의 선으로 정한다
        coordinates = Vector2Int(0, Mathf::Random::Range(
            (bottomLeftAreaCorner.y + roomLengthMin),
            (topRightAreaCorner.y - roomLengthMin)));
        
    }
    else
    {
        // 가로 선이면
        // 분할점을 왼쪽부터 방 가능한 크기, 오른쪽에서부터 방 가능한 크기 사이의 선으로 정한다
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
    std::queue<RoomNode*> graph;            // 그래프 생성
    std::vector<RoomNode*> vectorToReturn;        // 리턴할 백터 생성

    graph.push(this->rootNode);                               // 그래프에 루트 노드 넣고
    vectorToReturn.push_back(this->rootNode);                            // 리스트에도 루트 노드 넣어줌

    int iterations = 0;                                         // 방 만든 횟수

    while (iterations < maxIterations && graph.size() > 0)
    {
        // 최대 방 생성 횟수보다 현재 방 생성 횟수가 적고, 큐에 있으면 반복 수행

        iterations++;                               // 방 생성 횟수 증가
        RoomNode* currentNode = graph.front();     // 큐에서 방노드를 꺼내 현재 노드로 설정
        graph.pop();
        if (currentNode->GetWidth() >= roomWidthMin * 2 || currentNode->GetLength() >= roomLengthMin * 2)
        {
            // 현재 노드의 가로가 방의 가로 최소 길이의 2배보다 크거나
            // 현재 노드의 세로가 방의 세로 최소 길이의 2배보다 크면
            SplitTheSpace(currentNode, vectorToReturn, roomLengthMin, roomWidthMin, graph);       // 방 분할 함수 실행
        }
    }

    return vectorToReturn;
}

void BSP::AddNewNodeToCollections(std::vector<RoomNode*>& listToReturn, std::queue<RoomNode*>& graph, RoomNode* node)
{
    listToReturn.push_back(node);
    graph.push(node);
}
