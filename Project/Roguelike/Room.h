#pragma once
#include "namespace.cpp"

using namespace myMath;

class Room
{
protected:

	/// <summary>
	/// 가로 길이
	/// </summary>
	int width;

	/// <summary>
	/// 세로 길이
	/// </summary>
	int height;

	/// <summary>
	/// 중앙 좌표 (계산 상의 편의를 위해 남겨둠)
	/// </summary>
	Vector2Int middlePoint;

	/// <summary>
	/// 왼위 좌표
	/// </summary>
	Vector2Int leftUpPoint;

	/// <summary>
	/// 왼오 좌표
	/// </summary>
	Vector2Int rightDownPoint;

	

public:
	Room(Vector2Int middlePoint,
		int minWidth, int maxWidth,
		int minHeight, int maxHeight);

	bool operator ==(const Room& other) {
		return (middlePoint == other.middlePoint)
			&& (width == other.width)
			&& (height == other.height);
	}

	bool operator != (const Room& other) {
		return (middlePoint != other.middlePoint)
			|| (width != other.width)
			|| (height != other.height);
	}


	/// <summary>
	/// 매개변수로 받은 다른 방이랑 겹치는지 확인하는 함수
	/// </summary>
	/// <param name="otherRoom">다른 방</param>
	/// <returns>true면 겹친다, false면 겹치지 않는다</returns>
	bool IsRoomOverlap(Room otherRoom);

	bool TooCloseTo(Room room);
	

	/// <summary>
	/// 방의 좌표를 바꾸는 함수
	/// </summary>
	/// <param name="newMiddlePos">바꿀 방의 중앙 좌표</param>
	void SetNewPosition(Vector2Int newMiddlePos);

	Vector2Int GetMiddlePoint();

	int GetWidth();

	int GetHeight();


};

