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
	/// Ʈ���� ���� �����ϴ� �Լ�
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
	/// ���ϴ� �ڳ� ��ǥ�� ����� �Լ�
	/// </summary>
	/// <param name="boundrayLeftPoint">����� ���ϴ� ��ǥ</param>
	/// <param name="boundrayRightPoint">����� ���� ��ǥ</param>
	/// <param name="pointModifire">���� ����( 0�� ������ minX�� minY�� 1�� ������ maxX�� maxY�� ������ ����)</param>
	/// <param name="offset">���� ����</param>
	/// <returns>���ϴ� �ڳ�</returns>
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
		Vector2 sum = Vector2(v1.x, v1.y) + Vector2(v2.x, v2.y);             // �� ���� ���ϰ�~
		Vector2 tempVector = sum * 0.5;   // �� ���� ������~
		return Vector2Int((int)tempVector.x, (int)tempVector.y);    // �� �� ��ȯ �ϱ�~
	}
}

