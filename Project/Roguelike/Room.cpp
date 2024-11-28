#include "Room.h"

Room::Room(Vector2Int middlePoint, 
	int minWidth, int maxWidth, 
	int minHeight, int maxHeight)
{
	this->width = minWidth + rand() % (maxWidth - minWidth);
	this->height = minHeight + rand() % (maxHeight - minHeight);

	this->middlePoint = middlePoint;

	leftUpPoint = Vector2Int(
		middlePoint.x - width * 0.5,
		middlePoint.y + height * 0.5);

	rightDownPoint = Vector2Int(
		middlePoint.x + width * 0.5,
		middlePoint.y - height * 0.5);
}

bool Room::IsRoomOverlap(Room otherRoom)
{
	return !(rightDownPoint.x < otherRoom.leftUpPoint.x ||
		leftUpPoint.x > otherRoom.rightDownPoint.x ||
		rightDownPoint.y > otherRoom.leftUpPoint.y ||
		leftUpPoint.y < otherRoom.rightDownPoint.y);
}

bool Room::TooCloseTo(Room room)
{
	return middlePoint.x + width * 0.5 > room.GetMiddlePoint().x - room.GetWidth() * 0.5
		|| middlePoint.y + height * 0.5 > room.GetMiddlePoint().y - room.GetHeight() * 0.5 
		|| middlePoint.x - width * 0.5 < room.GetMiddlePoint().x + room.GetWidth() * 0.5 
		|| middlePoint.y - height * 0.5 < room.GetMiddlePoint().y + room.GetHeight() * 0.5;

}

void Room::SetNewPosition(Vector2Int newMiddlePos)
{
	this->middlePoint = middlePoint;

	leftUpPoint = Vector2Int(
		middlePoint.x - width * 0.5,
		middlePoint.y + height * 0.5);

	rightDownPoint = Vector2Int(
		middlePoint.x + width * 0.5,
		middlePoint.y - height * 0.5);
}

Vector2Int Room::GetMiddlePoint()
{
	return middlePoint;
}

int Room::GetWidth()
{
	return width;
}

int Room::GetHeight()
{
	return height;
}
