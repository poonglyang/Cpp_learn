/*
UserDataTypes
	����ü
		�������� ������ ���� �ϳ��� ������ ������ �����ϴ� ����� ���� ������ ����
		����ü�� ������ ������ �ɹ��� ������ �ɹ����� ���� �ٸ� ������ Ÿ���� �� �ִ�.
		C++������ �Լ��� ���� �����ϴ�
*/


#include <iostream>

// Ű����, ����ü �̸�
struct Struct1{
	// ���⿡ �ʿ��� ������� ����
	
};

// �л��� ���õ� ������ ����ٸ�
struct Student {
	int age;
	int phoneNumber;
	std::string name;
	int length;
};

struct Point {
	int x;
	int y;
	void Print();	// c++������ �Լ��� ����� �����ϴ�
};

struct Person {
	std::string name;
	std::string phoneNumber;
	int age;
};

struct Test {
	short s;	// 2
	int i;		// 4
	char c;		// 1
};

int main() {
	Student student1;
	student1.age = 10;
	student1.name = "����";
	student1.phoneNumber = 1098761234;

	std::cout << "�̸� : " << student1.name << std::endl;
	std::cout << "���� : " << student1.age << std::endl;
	std::cout << "��ȭ��ȣ : +82)" << student1.phoneNumber << std::endl;


	Point p;
	p.x = 10;
	p.y = 20;
	std::cout << "����ü p.x�� �� : " << p.x << "\n����ü p.y�� �� : " << p.y << std::endl;
	p.Print();

	Point p1 = { 50, 102 }; // ������ ���ÿ� �ʱ�ȭ
	std::cout << "����ü p1.x�� �� : " << p1.x << "\n����ü p1.y�� �� : " << p1.y << std::endl;

	Person person[3];
	person[0].name = "�̸�1";
	person[0].phoneNumber = "010-1234-5678";
	person[0].age = 15;

	person[1].name = "�̸�2";
	person[1].phoneNumber = "010-9876-5432";
	person[1].age = 30;

	person[2].name = "�̸�3";
	person[2].phoneNumber = "010-7894-1235";
	person[2].age = 20;

	Person person1[3] = {
		{"�̸�1", "01044", 40},
		{"�̸�2", "0100000000000", 50},
		{"�̸�3", "01022340135", 60}
	};

	for (int i = 0; i < 3; i++) {
		std::cout << person1[i].name << ", " << person1[i].age << ", " << person1[i].phoneNumber << std:: endl;
	}

	Test t;
	std::cout << sizeof(t) << std::endl;	
	// �޸𸮸� 4byte ������ �����ϱ⿡ ������ ��ġ�� ���� ũ�Ⱑ �޶�����
	// short, char, int �� ���� short 2, char 1�ؼ� 3byte�� ������ int�� �� �� ���⿡ 1�� pading���� ä���
	// �׸��Ͽ� 8byte�� �ȴ�
	// short, int, char �� �ϸ� short 2�ε� int�� 4�̹Ƿ� 4byte�� �ʰ��ϹǷ� short�� 2byte�� pading, int 4byteä��� char 1byte�� 4����Ʈ �����̴� 3byte�� pading�Ͽ�
	// 12byte�� �ȴ�


}

/// <summary>
/// Point�� ��� �Լ��̴�
/// </summary>
void Point::Print()
{
	std::cout << "Point ����ü�� ��� �Լ��̴�" << std::endl;
}
