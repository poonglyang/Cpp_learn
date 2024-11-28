#include "PDGA.h"


PDGA::PDGA(int tile_size, int minRoomWidth, int minRoomHeight, int maxRoomWidth, int maxRoomHeight)
	: tile_size(tile_size),
	minRoomWidth(minRoomWidth), minRoomHeight(minRoomHeight),
	maxRoomWidth(maxRoomWidth), maxRoomHeight(maxRoomHeight)
{
	GeneratorDungeon();
}

double PDGA::roundM(double n, double m)
{
	return floor((n + m - 1) / m) * m;
}


Vector2Int PDGA::GetRandomPointInCircle(int radius)
{
	/*double t = 2 * Mathf::PI * rand();
	double u = rand() % 2 + rand() % 2;
	double r = u > 1 ? 2 - u : r = u;
	return Vector2Int(
		roundM(
			(
				static_cast<double>(radius) * r * cos(t)), 
			tile_size)
		,
		roundM(
			(
				static_cast<double>(radius) * r * sin(t)), 
			tile_size)
	);*/
	// ���� ������ ����
	std::random_device rd; // ���� �������� �õ� ��
	std::mt19937 gen(rd()); // �޸��� Ʈ������ ����
	std::uniform_real_distribution<> dis(0.0, 1.0); // 0.0���� 1.0 ������ �Ǽ� ���� ����

	// t�� 0���� 2������� ��
	double t = 2 * Mathf::PI * dis(gen);

	// u�� �� ���� 0���� 1 ������ ���� ��
	double u = dis(gen) + dis(gen);

	// r ��� (u�� 1���� ũ�� 2-u, �ƴϸ� u)
	double r = (u > 1) ? (2 - u) : u;

	return Vector2Int(
		roundM(
			(
				static_cast<double>(radius) * r * cos(t)),
			tile_size)
		,
		roundM(
			(
				static_cast<double>(radius) * r * sin(t)),
			tile_size)
	); 
}

Vector2Int PDGA::GetRandomPointInCircle(int width, int height)
{
	double t = 2 * Mathf::PI * rand();
	double u = rand() + rand();
	double r = u > 1 ? 2 - u : r = u;
	return Vector2Int(
		roundM(
			static_cast<int> (
				static_cast<double>(width) * r * cos(t)),
			tile_size)
		,
		roundM(
			static_cast<int>(
				static_cast<double>(height) * r * sin(t)),
			tile_size)
	);
}

void PDGA::SeparateRooms(vector<Room>& rooms)
{
	for (Room& room : rooms) {
		Vector2Int oldPos = room.GetMiddlePoint();

		Vector2Int separation = computeSeparation(room, rooms);

		Vector2Int newPos = Vector2Int(
			oldPos.x += separation.x,
			oldPos.y += separation.y
		);

		room.SetNewPosition(newPos);
	}
}

Vector2Int PDGA::computeSeparation(Room& agent, vector<Room>& rooms)
{
	int neighbours = 0;
	Vector2Int v = Vector2Int(0,0);

	for (Room& room : rooms) {
		if (room != agent) {
			if (agent.TooCloseTo(room)) {
				v.x += (int)Difference(room, agent, 0);
				v.y += (int)Difference(room, agent, 1);
				++neighbours;
			}
		}
	}

	if (neighbours == 0) {
		return v;
	}

	v.x /= neighbours;
	v.y /= neighbours;

	v.x *= -1;
	v.y *= -1;

	return v;
}

double PDGA::Difference(Room room, Room agent, int type)
{
	double x1;
	double x2;
	switch (type)
	{
	case 0:
		 x1 =
			(room.GetMiddlePoint().x + room.GetWidth() * 0.5)
			- (agent.GetMiddlePoint().x - agent.GetWidth() * 0.5);
		 x2 =
			(agent.GetMiddlePoint().x - agent.GetWidth() * 0.5)
			- (room.GetMiddlePoint().x + room.GetWidth() * 0.5);
		return x1 > 0 ? x1 : x2;
		break;
	case 1:
		 x1 =
			(room.GetMiddlePoint().y + room.GetHeight() * 0.5)
			- (agent.GetMiddlePoint().y - agent.GetHeight() * 0.5);
		 x2 =
			(agent.GetMiddlePoint().y - agent.GetHeight() * 0.5)
			- (room.GetMiddlePoint().y + room.GetHeight() * 0.5);
		return x1 > 0 ? x1 : x2;
		break;
	default:
		break;
	}
	return 0.0;
}

void PDGA::GeneratorDungeon()
{
	vector<Vector2Int> tempRoomMiddlePoint;		// �ӽ� middlePoint

	for (int i = 0; i < 50; ++i) {	// �߾��� ����
		tempRoomMiddlePoint.push_back(GetRandomPointInCircle(50));
	}

	vector<Room> tempRooms;	// �ӽ� ���

	for (int i = 0; i < tempRoomMiddlePoint.size(); ++i) {	// �� ����
		tempRooms.push_back(
			Room(
				tempRoomMiddlePoint[i],
				minRoomWidth, maxRoomWidth,
				minRoomHeight, maxRoomHeight
			)
		);
	}

	SeparateRooms(tempRooms);

	//copy(tempRooms.begin(), tempRooms.end(), dungeonRoom.begin());
	dungeonRoom = tempRooms;

}

void PDGA::PrintDungeon()
{
	int count = 1;
	for (auto& room : dungeonRoom) {
		cout << "[�� " << count 
			<< "]\n�߾��� : (" << room.GetMiddlePoint().x << ", " << room.GetMiddlePoint().y
			<< "), ���� : " << room.GetWidth() << ", ���� : " << room.GetHeight() 
			<< endl << endl;

		int count2 = 1;
		for (auto& room2 : dungeonRoom) {
			if (room == room2) {
				++count2;
				continue;
			}
			if (room.IsRoomOverlap(room2)) {
				cout << "�� " << count2 << ", ";
			}
			++count2;
			
		}
		cout << "�� ��Ĩ�ϴ�" << endl;

		++count;
		cout << endl;
	}
	
}
