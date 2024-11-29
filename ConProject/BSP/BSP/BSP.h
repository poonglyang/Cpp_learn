#pragma once
#include "RoomGenerator.h"
#include "Line.h"
class BSP
{
private:
    RoomNode* rootNode;

    /// <summary>
    /// 노드의 공간을 분할하는 함수
    /// </summary>
    /// <param name="currentNode">분할할 노드</param>
    /// <param name="listToReturn">리스트</param>
    /// <param name="roomLengthMin">방의 세로 최소 길이</param>
    /// <param name="roomWidthMin">방의 가로 최소 길이 </param>
    /// <param name="graph">그래프</param>
    void SplitTheSpace(RoomNode* currentNode, vector<RoomNode*>& listToReturn, int roomLengthMin, int roomWidthMin, queue<RoomNode*>& graph);

    /// <summary>
    /// 분할할 선을 가져오는 함수
    /// </summary>
    /// <param name="bottomLeftAreaCorner">분할할 방의 좌하단 좌표</param>
    /// <param name="topRightAreaCorner">분할할 방의 좌상단 좌표</param>
    /// <param name="roomWidthMin">방의 최소 가로 길이</param>
    /// <param name="roomLengthMin">방의 최소 세로 길이</param>
    /// <returns></returns>
    Line GetLineDividingSpace(Vector2Int bottomLeftAreaCorner, Vector2Int topRightAreaCorner, int roomWidthMin, int roomLengthMin);

    /// <summary>
    /// 분할 선의 시작점을 반환는 함수
    /// </summary>
    /// <param name="orientation">가로 세로 여부</param>
    /// <param name="bottomLeftAreaCorner">분할할 방의 좌하단 좌표</param>
    /// <param name="topRightAreaCorner">분할할 방의 우상단 좌표</param>
    /// <param name="roomWidthMin">방 가로 최소 크기</param>
    /// <param name="roomLengthMin">방 세로 최소 크기</param>
    /// <returns></returns>
    Vector2Int GetCoordinatesFororientation(Orientation orientation, Vector2Int bottomLeftAreaCorner, Vector2Int topRightAreaCorner, int roomWidthMin, int roomLengthMin);
public:
    /// <summary>
    /// BSP 생성자 
    /// </summary>
    /// <param name="dungeonWidth">던전 가로 길이</param>
    /// <param name="dungeonLength">던전 세로 길이</param>
    BSP(int dungeonWidth, int dungeonLength);

    RoomNode* GetRootNode();

    /// <summary>
    /// 노드를 만들고 분할해 방을 만들 노드들을 반환하는 메서드
    /// </summary>
    /// <param name="maxIterations">최대 분할수</param>
    /// <param name="roomWidthMin">방 최소 가로 길이</param>
    /// <param name="roomLengthMin">방 최소 세로 길이</param>
    /// <returns>방을 만든 노드들</returns>
    vector<RoomNode*> PrepareNodesCollection(int maxIterations, int roomWidthMin, int roomLengthMin);

    void AddNewNodeToCollections(vector<RoomNode*>& listToReturn, queue<RoomNode*>& graph, RoomNode* node);
};

