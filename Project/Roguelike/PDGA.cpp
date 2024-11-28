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
	// 난수 생성기 설정
	std::random_device rd; // 난수 생성기의 시드 값
	std::mt19937 gen(rd()); // 메르센 트위스터 엔진
	std::uniform_real_distribution<> dis(0.0, 1.0); // 0.0에서 1.0 사이의 실수 난수 생성

	// t는 0부터 2π까지의 값
	double t = 2 * Mathf::PI * dis(gen);

	// u는 두 개의 0에서 1 사이의 값의 합
	double u = dis(gen) + dis(gen);

	// r 계산 (u가 1보다 크면 2-u, 아니면 u)
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
	vector<Vector2Int> tempRoomMiddlePoint;		// 임시 middlePoint

	for (int i = 0; i < 50; ++i) {	// 중앙점 생성
		tempRoomMiddlePoint.push_back(GetRandomPointInCircle(50));
	}

	vector<Room> tempRooms;	// 임시 방들

	for (int i = 0; i < tempRoomMiddlePoint.size(); ++i) {	// 방 생성
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
		cout << "[방 " << count 
			<< "]\n중앙점 : (" << room.GetMiddlePoint().x << ", " << room.GetMiddlePoint().y
			<< "), 가로 : " << room.GetWidth() << ", 세로 : " << room.GetHeight() 
			<< endl << endl;

		int count2 = 1;
		for (auto& room2 : dungeonRoom) {
			if (room == room2) {
				++count2;
				continue;
			}
			if (room.IsRoomOverlap(room2)) {
				cout << "방 " << count2 << ", ";
			}
			++count2;
			
		}
		cout << "와 겹칩니다" << endl;

		++count;
		cout << endl;
	}
	
}
