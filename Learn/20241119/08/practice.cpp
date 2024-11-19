/*
�ǽ�
	Person �̶�� Ŭ������ ����
	1. �Ӽ� 
		�̸�, ����, �������, ��ȭ��ȣ
	2. ���
		�� ������ ����ϴ� �Լ��� ������

*/

#include <iostream>

using namespace std;

class Person {
private:
	string name;
	int age;
	int birthYear;
	int birthMonth;
	int birthDay;
	string phoneNumber;

public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="name">�̸�</param>
	/// <param name="age">����</param>
	/// <param name="birthYear">ź�� �⵵</param>
	/// <param name="birthMonth">ź�� ��</param>
	/// <param name="birthDay">ź�� ��</param>
	/// <param name="phoneNumber">�޴��� ��ȣ</param>
	Person(const string& name, const int age, const int birthYear, const int birthMonth, const int birthDay, const string& phoneNumber);

	/// <summary>
	/// ����� ������ ����ϴ� �Լ�
	/// </summary>
	void PrintInfo();
};

Person::Person(const string& name, const int age, const int birthYear, const int birthMonth, const int birthDay, const string& phoneNumber)
{
	this->name = name;
	this->age = age;
	this->birthYear = birthYear;
	this->birthMonth = birthMonth;
	this->birthDay = birthDay;
	this->phoneNumber = phoneNumber;
}

void Person::PrintInfo()
{
	cout << "�̸� : " << name << ", ���� : " << age
		<< "���� : " << birthYear << "-" << birthMonth << "-" << birthDay
		<< ", ��ȭ ��ȣ : " << phoneNumber << endl;
}

int main() {

	string name, phoneNumber;
	int age, year, month, day;

	cin >> name;
	cin >> age;
	cin >> year >> month >> day;
	cin >> phoneNumber;

	Person* p1 = new Person("��μ�", 25, 2000, 4, 14, "010-1234-4444");
	p1->PrintInfo();

	Person* p2 = new Person(name, age, year, month, day, phoneNumber);
	p2->PrintInfo();

	delete p1;
	p1 = nullptr;

	delete p2;
	p2 = nullptr;

	
}


