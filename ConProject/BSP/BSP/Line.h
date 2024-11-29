#pragma once
#include "StructureHelper.h"

class Line
{
private:
    /// <summary>
    /// 선의 방향
    /// </summary>
    StructureHelper::Orientation orientation;

    /// <summary>
    /// 선의 좌표
    /// </summary>
    Vector2Int coordinates;

public:
    StructureHelper::Orientation GetOrientation();

    void SetOrientation(StructureHelper::Orientation ori);

    Vector2Int GetCoordinates();

    void SetCoordinates(Vector2Int coordinates);

    Line() {};

    /// <summary>
    /// 선 생성 생성자
    /// </summary>
    /// <param name="orientation">선의 방향(가로, 세로)</param>
    /// <param name="coordinates">선의 시작 좌표</param>
    Line(StructureHelper::Orientation orientation, Vector2Int coordinates);
	
};

