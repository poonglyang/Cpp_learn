#include <iostream>
#include <windows.h>
#include <conio.h>
#include "StructureHelper.h"

using namespace std;

#pragma once
/// <summary>
/// 이벤트 추상 클래스
/// </summary>
class Event
{
protected:
	void SetRGBColor(int r, int g, int b);

	void SetConsoleColor(int color);
public:
	virtual void EventStart() = 0;

	virtual void EventUpdate() = 0;

	virtual void EventEnd() = 0;

	virtual void RenderEvent() = 0;
};

