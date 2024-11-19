/*
실습
	Person 이라는 클래스를 생성
	1. 속성 
		이름, 나이, 생년월일, 전화번호
	2. 기능
		위 정보를 출력하는 함수를 만들어라

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
	/// 생성자
	/// </summary>
	/// <param name="name">이름</param>
	/// <param name="age">나이</param>
	/// <param name="birthYear">탄생 년도</param>
	/// <param name="birthMonth">탄생 월</param>
	/// <param name="birthDay">탄생 일</param>
	/// <param name="phoneNumber">휴대폰 번호</param>
	Person(const string& name, const int age, const int birthYear, const int birthMonth, const int birthDay, const string& phoneNumber);

	/// <summary>
	/// 대상의 정보를 출력하는 함수
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
	cout << "이름 : " << name << ", 나이 : " << age
		<< "생일 : " << birthYear << "-" << birthMonth << "-" << birthDay
		<< ", 전화 번호 : " << phoneNumber << endl;
}

int main() {

	string name, phoneNumber;
	int age, year, month, day;

	cin >> name;
	cin >> age;
	cin >> year >> month >> day;
	cin >> phoneNumber;

	Person* p1 = new Person("김민수", 25, 2000, 4, 14, "010-1234-4444");
	p1->PrintInfo();

	Person* p2 = new Person(name, age, year, month, day, phoneNumber);
	p2->PrintInfo();

	delete p1;
	p1 = nullptr;

	delete p2;
	p2 = nullptr;

	
}


