#pragma once
#include "namespace.cpp"

using namespace myMath;

class Room
{
protected:

	/// <summary>
	/// ���� ����
	/// </summary>
	int width;

	/// <summary>
	/// ���� ����
	/// </summary>
	int height;

	/// <summary>
	/// �߾� ��ǥ (��� ���� ���Ǹ� ���� ���ܵ�)
	/// </summary>
	Vector2Int middlePoint;

	/// <summary>
	/// ���� ��ǥ
	/// </summary>
	Vector2Int leftUpPoint;

	/// <summary>
	/// �޿� ��ǥ
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
	/// �Ű������� ���� �ٸ� ���̶� ��ġ���� Ȯ���ϴ� �Լ�
	/// </summary>
	/// <param name="otherRoom">�ٸ� ��</param>
	/// <returns>true�� ��ģ��, false�� ��ġ�� �ʴ´�</returns>
	bool IsRoomOverlap(Room otherRoom);

	bool TooCloseTo(Room room);
	

	/// <summary>
	/// ���� ��ǥ�� �ٲٴ� �Լ�
	/// </summary>
	/// <param name="newMiddlePos">�ٲ� ���� �߾� ��ǥ</param>
	void SetNewPosition(Vector2Int newMiddlePos);

	Vector2Int GetMiddlePoint();

	int GetWidth();

	int GetHeight();


};

