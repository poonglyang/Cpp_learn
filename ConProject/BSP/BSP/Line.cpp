#include "Line.h"

StructureHelper::Orientation Line::GetOrientation()
{
    return orientation;
}

void Line::SetOrientation(StructureHelper::Orientation ori)
{
    orientation = ori;
}

Vector2Int Line::GetCoordinates()
{
    return coordinates;
}

void Line::SetCoordinates(Vector2Int coordinates)
{
    this->coordinates = coordinates;
}

Line::Line(StructureHelper::Orientation orientation, Vector2Int coordinates)
{
    this->orientation = orientation;
    this->coordinates = coordinates;
}


