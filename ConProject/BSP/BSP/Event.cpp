#include "Event.h"

void Event::SetRGBColor(int r, int g, int b)
{
	printf("\033[38;2;%d;%d;%dm", r, g, b);
}

void Event::SetConsoleColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	SetConsoleTextAttribute(hConsole, color);         // 색상 변경
}
