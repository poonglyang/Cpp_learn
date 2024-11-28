#pragma once
#include "Node.h"
#include <vector>
#include <queue>

using namespace myMath;
using namespace std;

namespace StructureHelper {
	/// <summary>
	/// 트리의 잎을 추출하는 함수
	/// </summary>
	/// <param name="parentNode"></param>
	/// <returns></returns>
	static vector<Node> TraverseGraphToExtractLowestLeafes(Node parentNode);

	/// <summary>
	/// 좌하단 코너 좌표를 만드는 함수
	/// </summary>
	/// <param name="boundrayLeftPoint">노드의 좌하단 좌표</param>
	/// <param name="boundrayRightPoint">노드의 우상단 좌표</param>
	/// <param name="pointModifire">생성 범위( 0에 가까우면 minX와 minY에 1에 가까우면 maxX와 maxY에 가깝게 생성)</param>
	/// <param name="offset">복도 넓이</param>
	/// <returns>좌하단 코너</returns>
	static Vector2Int GenerateBottomLeftCornerBetween(Vector2Int boundrayLeftPoint, Vector2Int boundrayRightPoint, float pointModifire, int offset);


	static Vector2Int GenerateTopRightCornerBetween(Vector2Int boundrayLeftPoint, Vector2Int boundrayRightPoint, float pointModifire, int offset);


	static Vector2Int CalculateMiddlePoint(Vector2Int v1, Vector2Int v2);
}

