#include "Line.h"

StructureHelper::Orientation Line::GetOrientation()
{
    return orientation;
}

void Line::SetOrientation(StructureHelper::Orientation ori)
{
    orientation = ori;
}

myMath::Vector2Int Line::GetCoordinates()
{
    return coordinates;
}

void Line::SetCoordinates(myMath::Vector2Int coordinates)
{
    this->coordinates = coordinates;
}

Line::Line(StructureHelper::Orientation orientation, myMath::Vector2Int coordinates)
{
    this->orientation = orientation;
    this->coordinates = coordinates;
}


