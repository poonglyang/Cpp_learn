/*
[template]
	����ڰ� ������ �ڷ����� �Լ�, Ŭ������ ������ �ð��� ����
	������ ������ ���� ���� ������ Ÿ�Կ� ���� �ߺ��� �ڵ带 �ۼ��� �ʿ䰡 ����
	������ Ÿ�ӿ� ������ Ÿ���� �����ϱ� ������ ���� Ÿ�� �������� ȿ������ �� �ִ�.

	�Լ� ���ø�
		�Լ��� �ʿ��� �ڷ����� �����ϰ� �Լ��� ȣ��� �ڷ����� �������־� ���


	Ŭ���� ���ø�
		�پ��� ������ Ÿ���� �����ϴ� Ŭ������ ������ �� �ְ� ���ش�.
		���ø� �Ű������� ���� Ŭ������ �ɹ� ������ �ɹ��Լ��� Ÿ���� �Ϲ�ȭ �� �� �ִ�.

Ư�� ������ Ÿ�Կ� ���� ������ ������ �ʿ��� ���
���ø� Ư��ȭ�� �������
�˾ƺ���

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
/// GetMax�� ���ø� �Ͽ� ���� �Լ�
/// ũ��񱳸� �� �� ū���� ��ȯ�Ѵ�
/// </summary>
/// <typeparam name="T">���׸� Ÿ��</typeparam>
/// <param name="x">���� �� 1</param>
/// <param name="y">���� �� 2</param>
/// <returns>ū ��</returns>
template<typename T>
T GetMax(const T x, const T y) {
	if (x > y) return x;
	else return y;
}

template<typename T>
void Output1(const T data) {
	std::cout << "������ : " << data << std::endl;
}

template<typename T>
void Output2(const T a, const T b) {
	std::cout << "������ : " << a << ", " << b << std::endl;
}

template<typename T1, typename T2>
void Output3(const T1 a, const T2 b) {
	std::cout << "������ : " << a << ", " << b << std::endl;
}

// ������ Ŭ���� ���ø�
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
	//Output2(1.5, 2);	// typename�� �ϳ��̱⿡ ������ ����
	Output3(1.5, 2);	// typename 2���� ���

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
