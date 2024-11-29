#pragma once
#include "Node.h"
#include <vector>
#include <queue>

using namespace myMath;
using namespace std;

namespace StructureHelper {
	/// <summary>
	/// Ʈ���� ���� �����ϴ� �Լ�
	/// </summary>
	/// <param name="parentNode"></param>
	/// <returns></returns>
	static vector<Node> TraverseGraphToExtractLowestLeafes(Node parentNode);

	/// <summary>
	/// ���ϴ� �ڳ� ��ǥ�� ����� �Լ�
	/// </summary>
	/// <param name="boundrayLeftPoint">����� ���ϴ� ��ǥ</param>
	/// <param name="boundrayRightPoint">����� ���� ��ǥ</param>
	/// <param name="pointModifire">���� ����( 0�� ������ minX�� minY�� 1�� ������ maxX�� maxY�� ������ ����)</param>
	/// <param name="offset">���� ����</param>
	/// <returns>���ϴ� �ڳ�</returns>
	static Vector2Int GenerateBottomLeftCornerBetween(Vector2Int boundrayLeftPoint, Vector2Int boundrayRightPoint, float pointModifire, int offset);


	static Vector2Int GenerateTopRightCornerBetween(Vector2Int boundrayLeftPoint, Vector2Int boundrayRightPoint, float pointModifire, int offset);


	static Vector2Int CalculateMiddlePoint(Vector2Int v1, Vector2Int v2);
}

