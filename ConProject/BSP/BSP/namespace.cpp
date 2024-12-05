#include <iostream>
#include <cmath>
#include <random>

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
			x += other.x;
			y += other.y;
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

		Vector2Int operator* (const int other) {
			return Vector2Int(x *= other, y *= other);
		}

		Vector2Int operator/ (const int other) {
			return Vector2Int(x /= other, y /= other);
		}

		Vector2Int operator+ (const Vector2Int other) {
			return Vector2Int(x + other.x, y + other.y);
		}

		Vector2Int operator- (const Vector2Int other) {
			return Vector2Int(x - other.x, y - other.y);
		}

		

		/*operator Vector2() const {
			return Vector2(x, y);
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

		Vector2 operator/ (const double other) {
			return Vector2(x /= other, y /= other);
		}

		Vector2 operator+ (const Vector2 other) {
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator- (const Vector2 other) {
			return Vector2(x - other.x, y - other.y);
		}


		/*operator Vector2Int() const {
			return Vector2Int(x, y);
		}*/
	};

	class Mathf {
	public:
		inline static double PI = 3.14159265359;
		inline static double Rad2Deg = 180.0 / PI;
		class Random {
		public:
			static int Range(int num1, int num2) {
				if (num1 == num2 || num1 + 1 == num2) {
					return num1;
				}

				return num1 + rand() % (num2 -1 - num1);
			}

			static float Value() {
				static std::random_device rd;                        // 난수 생성기
				static std::default_random_engine engine(rd());      // 엔진 초기화
				static std::uniform_real_distribution<float> dist(0.0f, 1.0f); // 0.0 ~ 1.0 사이

				return dist(engine);
			}
		};

		static double Atan2(double x, double y) {
			return atan2(x, y);
		}

	};
}
