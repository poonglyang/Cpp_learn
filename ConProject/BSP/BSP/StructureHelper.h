#pragma once
#include "Node.h"
#include <queue>

using namespace std;

namespace StructureHelper {

	static enum class Orientation {
		Horiszontal,
		Vertical
	};

	static enum class RelativePosition
	{
		Up,
		Down,
		Right,
		Left
	};

	/// <summary>
	/// 트리의 잎을 추출하는 함수
	/// </summary>
	/// <param name="parentNode"></param>
	/// <returns></returns>
	static vector<Node*> TraverseGraphToExtractLowestLeafes
	(Node* parentNode)
	{
		queue<Node*> nodesToCheck;
		vector<Node*> listToReturn;

		if (parentNode->childrenNode.size() == 0) {
			listToReturn.push_back(parentNode);
			return listToReturn;
		}

		for (auto* child : parentNode->childrenNode) {
			nodesToCheck.push(child);
		}

		while (!nodesToCheck.empty()) {
			Node* currentNode = nodesToCheck.front();
			nodesToCheck.pop();
			if (currentNode->childrenNode.empty()) {
				listToReturn.push_back(currentNode);
			}
			else {
				for (int i = 0; i < currentNode->childrenNode.size(); i++) {
					Node* temp = currentNode->childrenNode[i];
					nodesToCheck.push(temp);
				}

				//for (auto* child : currentNode->childrenNode) {
				//	nodesToCheck.push(child);
				//}
			}
		}

		return listToReturn;
	}

	/// <summary>
	/// 좌하단 코너 좌표를 만드는 함수
	/// </summary>
	/// <param name="boundrayLeftPoint">노드의 좌하단 좌표</param>
	/// <param name="boundrayRightPoint">노드의 우상단 좌표</param>
	/// <param name="pointModifire">생성 범위( 0에 가까우면 minX와 minY에 1에 가까우면 maxX와 maxY에 가깝게 생성)</param>
	/// <param name="offset">복도 넓이</param>
	/// <returns>좌하단 코너</returns>
	static Vector2Int GenerateBottomLeftCornerBetween(
		Vector2Int boundrayLeftPoint,
		Vector2Int boundrayRightPoint,
		double pointModifire, int offset) 
	{
		int minX = boundrayLeftPoint.x + offset;
		int maxX = boundrayRightPoint.x - offset;

		int minY = boundrayLeftPoint.y + offset;
		int maxY = boundrayRightPoint.y - offset;

		return Vector2Int(
			Mathf::Random::Range(minX, (int)(minX + (maxX - minX) * pointModifire)),
			Mathf::Random::Range(minY, (int)(minY + (maxY - minY) * pointModifire))
		);
	}


	static Vector2Int GenerateTopRightCornerBetween(
		Vector2Int boundrayLeftPoint, 
		Vector2Int boundrayRightPoint, 
		float pointModifire, int offset) 
	{
		int minX = boundrayLeftPoint.x + offset;
		int maxX = boundrayRightPoint.x - offset;

		int minY = boundrayLeftPoint.y + offset;
		int maxY = boundrayRightPoint.y - offset;

		return Vector2Int(
			Mathf::Random::Range((int)(minX + (maxX - minX) * pointModifire), maxX),
			Mathf::Random::Range((int)(minY + (maxY - minY) * pointModifire), maxY)
		);
	}


	static Vector2Int CalculateMiddlePoint(
		Vector2Int v1, Vector2Int v2) {
		Vector2 sum = Vector2(v1.x, v1.y) + Vector2(v2.x, v2.y);             // 두 백터 더하고~
		Vector2 tempVector = sum * 0.5;   // 두 백터 나누고~
		return Vector2Int((int)tempVector.x, (int)tempVector.y);    // 그 값 반환 하기~
	}
}

