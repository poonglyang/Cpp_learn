/*
���� ������
	������ Ŭ������ ��ü�� �����Ͽ� ��ü�� ������ �� ����ϴ� ������

	1. ���� ����
		��ä�� ������ �� ��ü�� ��� �ɹ��� �ܼ��� ����
		��� ���� �߿� �������� ��찡 ������ �������� �ּ� ���� ����
		���� �޸� ������ ����Ű�� �ȴ�
		���� �� ��ü���� ������ ���¿��� ������ �޸𸮸� �����ϸ� ����� �Ÿ𸮿� ������ �ش�
		�� ��ü�� ���� �޸� �ּҸ� ����Ű�� ������ �� ��ü�� �Ҹ�Ǹ鼭 �޸𸮸� �����ϸ� �ٸ� ��ü�� �� �̻� ��ȿ���� ���� �޸𸮸� ����Ű�� �Ǿ� ������ �߻��Ѵ�

	2. ���� ����
		���� ��ü�� ������ ���� ������ ���ο� �޸𸮸� �Ҵ��Ͽ� �����ϴ� ��
		������ �ٸ� �޸𸮸� ����ϹǷ� ������ ������ ���� �ʴ´�.

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
//	// �⺻ ���� ������ (���� ����) : ��� �ڵ����� �־��ش�
//	Array(const Array& other) : size(other.size), data(other.data) {
//		cout << "���� ������ ȣ��" << endl;
//
//	}
//
//
//	//Array(const Array& other) = delete;		// �⺻ ���� �����ڸ� �̷������� �ƿ� ���ƹ��� ���� �ִ�
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
//	Array arr2(arr1);	// ���� ���縦 �Ͽ��⿡ �������� arr1�� �Ҹ��ڰ� ����Ǹ� arr2���� ������ ���� ������ �����
//
//	cout << "arr1�� �ּ� : " << &arr1 << ", data[0] �ּ� : " << arr1.GetDataAddr()
//		<< "\narr2�� �ּ� : " << &arr2 << ", data[0] �ּ� : " << arr2.GetDataAddr() << endl;
//
//	cout << "arr1�� data[0] �� : " << arr1.GetValue(0) << endl
//		<< "arr2�� data[0] �� : " << arr2.GetValue(0) << endl;
//
//	arr1.SetValue(0, 3);
//	cout << "arr1�� data[0]�� 3���� �ٲ�" << endl;
//
//	cout << "arr1�� data[0] �� : " << arr1.GetValue(0) << endl
//		<< "arr2�� data[0] �� : " << arr2.GetValue(0);
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
//	// ���� ����
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
//// ���� ����
//MyClass::MyClass(const MyClass& other)
//{
//	cout << "���� ������ ȣ��" << endl;
//	this->size = other.size;
//	this->data = new int[other.size];
//	for (int i = 0; i < size; i++) {		// ohter.data�� �ִ� ���� ���� �޸𸮸� �Ҵ��� data�� �־��ش�
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
		cout << "������ ȣ��" << endl;
	}

	MyClass(const MyClass& other) : data(other.data) {
		cout << "���� ������" << endl;
	}

	void Show() const {
		cout << "������ : " << data << endl;
	}

	void SetData(int n) {
		data = n;
	}
	
	~MyClass() {

	}

};

void Func1(MyClass m) {				// MyClass�� &�� ���̸� ���� ���� �Ⱥ��̸� ���� ����� �ȴ�
	cout << "����� ��ü" << endl;
	m.Show();
	m.SetData(30);
	m.Show();
}

void Func2(MyClass& m) {				// MyClass�� &�� ���̸� ���� ���� �Ⱥ��̸� ���� ����� �ȴ�
	cout << "����� ��ü" << endl;
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


