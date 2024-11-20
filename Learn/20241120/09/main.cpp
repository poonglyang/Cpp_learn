/*
복사 생성자
	동일한 클래스에 객체를 복사하여 객체를 생성할 때 사용하는 생성자

	1. 얕은 복사
		객채를 복사할 때 객체의 모든 맴버를 단순히 복사
		멤버 변수 중에 포인터인 경우가 있으면 포인터의 주소 값만 복사
		같은 메모리 영역을 가리키게 된다
		만약 한 객체에서 복사한 상태에서 복사한 메모리를 수정하면 복사된 매모리에 영향을 준다
		두 객체가 같은 메모리 주소를 가리키기 때문에 한 객체가 소멸되면서 메모리를 해제하면 다른 객체는 더 이상 유효하지 않은 메모리를 가리키게 되어 문제가 발생한다

	2. 깊은 복사
		원본 객체와 동일한 값을 가지는 새로운 메모리를 할당하여 복사하는 것
		원본과 다른 메모리를 사용하므로 원본에 영향을 주지 않는다.

*/

#include <iostream>

using namespace std;

#pragma region ShallowCopy
//class Array {
//private:
//	int* data;
//	int size;
//public:
//	Array();
//
//	Array(int size) : size(size), data(new int[size]) {}
//
//	// 기본 복사 생성자 (얕은 복사) : 없어도 자동으로 넣어준다
//	Array(const Array& other) : size(other.size), data(other.data) {
//		cout << "복사 생성자 호출" << endl;
//
//	}
//
//
//	//Array(const Array& other) = delete;		// 기본 복사 생성자를 이런식으로 아에 막아버릴 수도 있다
//
//	~Array();
//
//	void SetValue(int index, int value) {
//		data[index] = value;
//	}
//
//	int GetValue(int index) {
//		return data[index];
//	}
//
//	int* GetDataAddr() {
//		return data;
//	}
//};
//
//Array::~Array()
//{
//	delete[] data;
//}
//
//
//int main() {
//	Array arr1(10);
//
//	arr1.SetValue(0, 42);
//
//	//Array arr2 = arr1;
//	Array arr2(arr1);	// 얕은 복사를 하였기에 마지막에 arr1의 소멸자가 실행되면 arr2에서 문제가 생겨 에러가 생긴다
//
//	cout << "arr1의 주소 : " << &arr1 << ", data[0] 주소 : " << arr1.GetDataAddr()
//		<< "\narr2의 주소 : " << &arr2 << ", data[0] 주소 : " << arr2.GetDataAddr() << endl;
//
//	cout << "arr1의 data[0] 값 : " << arr1.GetValue(0) << endl
//		<< "arr2의 data[0] 값 : " << arr2.GetValue(0) << endl;
//
//	arr1.SetValue(0, 3);
//	cout << "arr1의 data[0]을 3으로 바꿈" << endl;
//
//	cout << "arr1의 data[0] 값 : " << arr1.GetValue(0) << endl
//		<< "arr2의 data[0] 값 : " << arr2.GetValue(0);
//
//	//Array* arr3 = new Array(5);
//
//	//delete arr3;
//	//arr3 = nullptr;
//}
#pragma endregion

#pragma region DeepCopy
//class MyClass
//{
//private:
//	int* data;
//	int size;
//
//public:
//	MyClass(int size);
//
//	// 깊은 복사
//	MyClass(const MyClass& other);
//
//
//	~MyClass() {
//		if (data != nullptr) {
//			delete[] data;
//		}
//		data = nullptr;
//	}
//
//	int* GetDataArr() const {
//		return data;
//	}
//};
//
//MyClass::MyClass(int size)
//{
//	this->size = size;
//	data = new int[size];
//}
//
//// 깊은 복사
//MyClass::MyClass(const MyClass& other)
//{
//	cout << "복사 생성자 호출" << endl;
//	this->size = other.size;
//	this->data = new int[other.size];
//	for (int i = 0; i < size; i++) {		// ohter.data에 있는 것을 새로 메모리를 할당한 data에 넣어준다
//		this->data[i] = other.data[i];
//	}
//}
//
//int main() {
//	MyClass arr1(10);
//
//	cout << arr1.GetDataArr() << endl;
//
//	MyClass arr2(arr1);
//
//	cout << arr2.GetDataArr() << endl;
//}
#pragma endregion

#pragma region etc
class MyClass
{
private:
	int data;

public:
	MyClass(int value) : data(value) {
		cout << "생성자 호출" << endl;
	}

	MyClass(const MyClass& other) : data(other.data) {
		cout << "복사 생성자" << endl;
	}

	void Show() const {
		cout << "데이터 : " << data << endl;
	}

	void SetData(int n) {
		data = n;
	}
	
	~MyClass() {

	}

};

void Func1(MyClass m) {				// MyClass에 &를 붙이면 얕은 복사 안붙이면 깊은 복사로 된다
	cout << "복사된 객체" << endl;
	m.Show();
	m.SetData(30);
	m.Show();
}

void Func2(MyClass& m) {				// MyClass에 &를 붙이면 얕은 복사 안붙이면 깊은 복사로 된다
	cout << "복사된 객체" << endl;
	m.Show();
	m.SetData(30);
	m.Show();
}

int main() {
	MyClass mc1(10);

	Func1(mc1);

	mc1.Show();

	Func2(mc1);

	mc1.Show();
}
#pragma endregion


