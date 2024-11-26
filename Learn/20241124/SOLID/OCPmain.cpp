/*
O(Open-Close Principle, OCP, ���� �м� ��Ģ)
	Ŭ����, �Լ�, ��� ���� Ȯ�忡�� ���� �ְ� ���濡�� ���� �־�� �Ѵ�.
	���� �ڵ带 �������� �����鼭 �ý����� ����� Ȯ���� �� �־�� �Ѵ�.
	���ο� ����� �߰��ϰų� ���� ������ ���� �� ������ �ڵ忡 ������ ���� �ʰ� ������ų �� �ִ�.

*/

#include <iostream>
#include <vector>
enum class ShapeType {
	Circle,
	Rectangle,

};

#pragma region ������

/*


class Shape {
private:
	ShapeType type;
	double radius;				// ��
	double width, height;		// �簢��

public:
	Shape(ShapeType t, double r = 0.0, double w = 0.0, double h = 0.0)
		: type(t), radius(r), width(w), height(h) {

	}

	double CalculateArea(const std::vector<Shape>& shapes) {
		double totalArea = 0;
		for (const auto& shape : shapes) {
			if (shape.type == ShapeType::Circle) {
				totalArea += 3.14 * shape.radius * shape.radius;
			}
			else if(shape.type == ShapeType::Rectangle) {
				totalArea += shape.width * shape.height;
			}
			else {

			}
		}

		return totalArea;
	}

	double CalculateArea() {

		return type == ShapeType::Circle ? radius * radius : width * height;
	}
};
*/
#pragma endregion


class Shape {
public:
	virtual double Area() const = 0;

	virtual ~Shape() = default;
};

class Cricle : public Shape {
private:
	double radius;

public:
	Cricle(double r) : radius(r) {

	}

	double Area() const override {
		return 3.14 * radius * radius;
	}
};

class Rectangle : public Shape {
private:
	double width;
	double height;

public:
	Rectangle(double width, double height) : width(width), height(height) {

	}

	double Area() const override {
		return width * height;
	}
};

double CalcuateArea(const std::vector<Shape*>shapes) {
	double totalArea = 0;
	for (const Shape* shape : shapes) {
		totalArea += shape->Area();
	}
}