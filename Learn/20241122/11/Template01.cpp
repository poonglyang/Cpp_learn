/*
[template]
	사용자가 지정한 자료형의 함수, 클래스를 컴파일 시간에 생성
	동일한 로직에 대해 여러 데이터 타입에 대해 중복된 코드를 작성할 필요가 없다
	컴파일 타임에 데이터 타입을 결정하기 때문에 동적 타입 결정보다 효율적일 수 있다.

	함수 탬플릿
		함수에 필요한 자료형을 선언하고 함수의 호출시 자료형을 지정해주어 사용


	클래스 탬플릿
		다양한 데이터 타입을 지원하는 클래스를 정의할 수 있게 해준다.
		탬플릿 매개변수를 통해 클래스의 맴버 변수와 맴버함수의 타입을 일반화 할 수 있다.

특정 데이터 타입에 대해 별도의 구현이 필요한 경우
탬플릿 특수화를 사용하자
알아보자

*/

#include <iostream>

int GetMax(const int x, const int y) {
	if (x > y) return x;
	else return y;
}

float GetMax(const float x, const float y) {
	if (x > y) return x;
	else return y;
}

/// <summary>
/// GetMax를 탬플릿 하여 만든 함수
/// 크기비교를 해 더 큰것을 반환한다
/// </summary>
/// <typeparam name="T">제네릭 타입</typeparam>
/// <param name="x">비교할 값 1</param>
/// <param name="y">비교할 값 2</param>
/// <returns>큰 값</returns>
template<typename T>
T GetMax(const T x, const T y) {
	if (x > y) return x;
	else return y;
}

template<typename T>
void Output1(const T data) {
	std::cout << "데이터 : " << data << std::endl;
}

template<typename T>
void Output2(const T a, const T b) {
	std::cout << "데이터 : " << a << ", " << b << std::endl;
}

template<typename T1, typename T2>
void Output3(const T1 a, const T2 b) {
	std::cout << "데이터 : " << a << ", " << b << std::endl;
}

// 간단한 클래스 템플릿
template<typename T>
class Box {
private:
	T data;
public:
	void SetData(T data) {
		this->data = data;
	}

	T GetData() const {
		return data;
	}
};

template<typename T1, typename T2>
class Box2 {
private:
	T1 data_one;
	T2 data_two;
public:
	void SetData(T1 data1, T2 data2) {
		this->data_one = data1;
		this->data_two = data2;
	}

	T1 GetData_One();
	T2 GetData_Two();

	void SetDataOne(T1 val) {
		data_one = val;
	}

	void SetDataTwo(T2 val) {
		data_two = val;
	}
};

template<typename T1, typename T2>
T1 Box2<T1, T2>::GetData_One()
{
	return data_one;
}
template<typename T1, typename T2>
T2 Box2<T1, T2>::GetData_Two()
{
	return data_two;
}


int main() {
	std::cout << GetMax(3.14, 1.7724) << std::endl;

	Output1(1);
	Output1(2.5);

	Output2(1, 3);
	//Output2(1.5, 2);	// typename이 하나이기에 에러가 난다
	Output3(1.5, 2);	// typename 2개인 경우

	std::cout << " ----- " << std::endl;

	Box<int> box;
	box.SetData(10);
	std::cout << box.GetData() << std::endl;

	Box<double> box2;
	box2.SetData(10.5);
	std::cout << box2.GetData() << std::endl;

	Box2<int, double> box3;
	box3.SetDataOne(10);
	box3.SetDataTwo(10.65);

	std::cout << box3.GetData_One() << ", " << box3.GetData_Two() << std::endl;
}
