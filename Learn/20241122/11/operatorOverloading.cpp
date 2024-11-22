/*
[������ �����ε�(������ ������)]
	����� ���� �ڷ����̳� Ŭ������ �����ڸ� �������Ͽ� ���� �ǹ̷� ����Ѵ�.
	��ü���� ��� ����, ��, ���Ե��� �����ϰ� ���ش�.
	��, �Ϻ� �����ڴ� �����ε��� �� �� ����.

	��� ���
		// ��ȯ�� operator �������ҿ����� ��ȣ(�Ű����� ���){�Լ� ����}
		�⺻ �������� ������ �Լ��� �������Ͽ� ����� ������


*/

#include <iostream>

struct Point
{
	float x;
	float y;

	Point(float x, float y) {
		this->x = x;
		this->y = y;
	}

	/// <summary>
	/// ������ ������
	/// </summary>
	Point operator+(const Point& other) {
		return Point(this->x + other.x, this->y + other.y);
	}

	void Print() const {
		std::cout << "(" << x << ", " << y << ")";
	}
};

Point operator-(const Point& left, const Point& right) {
	return Point(left.x - right.x, left.y - right.y);
}

int main() {
	Point p1 = Point(5, 5);
	Point p2 = Point(10, 10);

	Point add = p1 + p2;
	Point sub = p1 - p2;

	std::cout << "p1 + p2 : (" << add.x << ", " << add.y << ")" << std::endl;
	std::cout << "p1 - p2 : (" << sub.x << ", " << sub.y << ")" << std::endl;
}