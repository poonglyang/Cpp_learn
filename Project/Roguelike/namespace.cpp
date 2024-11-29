#include <iostream>

namespace myMath {

	class Vector2Int
	{
	public:
		int x;
		int y;

		Vector2Int() {};

		Vector2Int(int x, int y) : x(x), y(y) {};

		~Vector2Int() {};

		static Vector2Int zero() {
			return Vector2Int(0, 0);
		}

		void operator+= (const Vector2Int other) {
			x += other.x;
			y += other.y;
		}

		void operator-= (const Vector2Int other) {
			x -= other.x;
			y -= other.y;
		}

		void operator*= (const Vector2Int other) {
			x *= other.x;
			y *= other.y;
		}

		void operator*= (const int other) {
			x *= other;
			y *= other;
		}

		void operator/= (const Vector2Int other) {
			x /= other.x;
			y /= other.y;
		}

		bool operator== (const Vector2Int other) {
			return (x == other.x) && (y == other.y);
		}

		bool operator!= (const Vector2Int other) {
			return (x != other.x) || (y != other.y);
		}

		Vector2Int operator+ (const Vector2Int other) {
			return Vector2Int(x + other.x, y + other.y);
		}

		Vector2Int operator- (const Vector2Int other) {
			return Vector2Int(x - other.x, y - other.y);
		}

		Vector2Int operator/(int divisor) const
		{
			return{ x / divisor, y / divisor };
		}

		float ToDirection()
		{
			const float length{ sqrtf(static_cast<float>(x * x + y * y)) };
			const float xRanged{ static_cast<float>(x) / length };
			const float yRanged{ static_cast<float>(y) / length };

			x = static_cast<int>(abs(xRanged) > 0.5f);
			if (xRanged < 0)
			{
				x *= -1;
			}

			y = static_cast<int>(abs(yRanged) > 0.5f);
			if (yRanged < 0)
			{
				y *= -1;
			}

			return length;
		}

		/*operator Vector2() const {
			return Vector2(static_cast<int>(x), static_cast<int>(y));
		}*/
	};

	class Vector2 {
	public:
		double x;
		double y;

		Vector2() {};

		Vector2(double x, double y) : x(x), y(y) {};

		~Vector2() {};

		Vector2 zero() {
			return Vector2(0, 0);
		}

		void operator+= (const Vector2 other) {
			x += other.x;
			y += other.y;
		}

		void operator-= (const Vector2 other) {
			x -= other.x;
			y -= other.y;
		}

		void operator*= (const Vector2 other) {
			x += other.x;
			y += other.y;
		}

		void operator/= (const Vector2 other) {
			x /= other.x;
			y /= other.y;
		}

		bool operator== (const Vector2 other) {
			return (x == other.x) && (y == other.y);
		}

		bool operator!= (const Vector2 other) {
			return (x != other.x) || (y != other.y);
		}

		Vector2 operator* (const double other) {
			return Vector2(x *= other, y *= other);
		}

		Vector2 operator+ (const Vector2 other) {
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator- (const Vector2 other) {
			return Vector2(x - other.x, y - other.y);
		}


		/*operator Vector2Int() const {
			return Vector2Int(static_cast<double>(x), static_cast<double>(y));
		}*/
	};

	class Mathf {
	public:
		inline static double PI = 3.14159265359;

		class Random {
		public:
			static int Range(int num1, int num2) {
				return num1 + rand() % (num2 - 1 - num1);
			}
		};
	};
}