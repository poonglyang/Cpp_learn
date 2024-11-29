#pragma once
#include "StructureHelper.h"

class Line
{
private:
    /// <summary>
    /// ���� ����
    /// </summary>
    StructureHelper::Orientation orientation;

    /// <summary>
    /// ���� ��ǥ
    /// </summary>
    Vector2Int coordinates;

public:
    StructureHelper::Orientation GetOrientation();

    void SetOrientation(StructureHelper::Orientation ori);

    Vector2Int GetCoordinates();

    void SetCoordinates(Vector2Int coordinates);

    Line() {};

    /// <summary>
    /// �� ���� ������
    /// </summary>
    /// <param name="orientation">���� ����(����, ����)</param>
    /// <param name="coordinates">���� ���� ��ǥ</param>
    Line(StructureHelper::Orientation orientation, Vector2Int coordinates);
	
};

