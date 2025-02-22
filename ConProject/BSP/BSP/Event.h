#include <iostream>
#include <windows.h>
#include <conio.h>
#include "StructureHelper.h"
#include "Player.h"
#include "namespace.cpp"


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
	virtual void EventStart(Player* player) = 0;

	virtual void EventUpdate(Player* player) = 0;

	virtual void EventEnd() = 0;

	virtual void RenderEvent() = 0;
};

