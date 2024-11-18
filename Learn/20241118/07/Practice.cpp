/*
�ǽ�
	1. ��ǥ�� ��Ÿ���� ����ü�� �����϶�
	2. �� �� ������ �Ÿ��� ����ϴ� �Լ��� ������
	3. �ΰ��� ��ǥ�� �����ϰ� �Լ� ȣ���� �Ͽ� �� �� ������ �Ÿ��� ���

*/

#include <iostream>
#include <math.h>
#include "Mathf.h";


struct Point {
	float x;
	float y;
};

float CalcutateDistance(const Point& p1, const Point& p2)	// �뷮 ������ &���̰� ���� �Ұ��ϰ� const �ٿ���
{
	return std::sqrt((std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2)));
}

int main() {
	Point p1;
	Point p2;

	std::cout << "ù ��° ���� ������ �ΰ� �Է��ϼ���. : ";
	std::cin >> p1.x >> p1.y;

	std::cout << "�� ��° ���� ������ �ΰ� �Է��ϼ���. : ";
	std::cin >> p2.x >> p2.y;


	std::cout << "�� �� ������ �Ÿ� : " << CalcutateDistance(p1, p2) << std::endl;
}