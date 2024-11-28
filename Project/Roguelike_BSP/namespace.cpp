#include <iostream>
#include <string>

using namespace std;

namespace myMath {

	struct Vector2 {
		double x;
		double y;

		Vector2() {};

		Vector2(double x, double y) : x(x), y(y) {}

		bool operator==(const Vector2& other) {
			return (x == other.x) && (y == other.y);
		}

		bool operator!= (const Vector2& other) {
			return (x != other.x) || (y != other.y);
		}

		void operator+= (const Vector2& other) {
			x += other.x;
			y += other.y;
		}

		string toString() const {
			return "x : " + to_string(x) + ", y : " + to_string(y);
		}
	};

	struct Vector2Int {
		int x;
		int y;

		Vector2Int() {};

		Vector2Int(int x, int y) : x(x), y(y) {}

		bool operator==(const Vector2Int& other) {
			return (x == other.x) && (y == other.y);
		}

		bool operator!= (const Vector2Int& other) {
			return (x != other.x) || (y != other.y);
		}

		string toString() const {
			return "x : " + to_string(x) + ", y : " + to_string(y);
		}
	};

	extern class Mathf {
	public:
		inline static double PI = 3.14159265358979323846;
	};

}