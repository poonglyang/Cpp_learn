/*
실습
	1. 좌표를 나타내는 구조체를 정의하라
	2. 두 점 사이의 거리를 계산하는 함수를 만들어라
	3. 두개의 좌표를 생성하고 함수 호출을 하여 두 점 사이의 거리를 계산

*/

#include <iostream>
#include <math.h>
#include "Mathf.h";


struct Point {
	float x;
	float y;
};

float CalcutateDistance(const Point& p1, const Point& p2)	// 용량 때문에 &붙이고 변경 불가하게 const 붙여라
{
	return std::sqrt((std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2)));
}

int main() {
	Point p1;
	Point p2;

	std::cout << "첫 번째 점을 공백을 두고 입력하세요. : ";
	std::cin >> p1.x >> p1.y;

	std::cout << "두 번째 점을 공백을 두고 입력하세요. : ";
	std::cin >> p2.x >> p2.y;


	std::cout << "두 점 사이의 거리 : " << CalcutateDistance(p1, p2) << std::endl;
}