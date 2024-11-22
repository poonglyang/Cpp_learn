/*
[연산자 오버로딩(연산자 재정의)]
	사용자 정의 자료형이나 클래스의 연산자를 재정의하여 여러 의미로 사용한다.
	객체간의 산술 연산, 비교, 대입등을 가능하게 해준다.
	단, 일부 연산자는 오버로딩을 할 수 없다.

	사용 방법
		// 반환형 operator 재정의할연산자 기호(매개변수 목록){함수 내용}
		기본 연산자의 연산을 함수로 재정의하여 기능을 구현함


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
	/// 연산자 재정의
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