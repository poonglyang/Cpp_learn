/*
UserDataTypes
	구조체
		여러개의 변수를 묶어 하나의 데이터 단위로 정의하는 사용자 정의 데이터 형식
		구조체는 각각의 변수를 맴버로 가지고 맴버들은 서로 다른 데이터 타입일 수 있다.
		C++에서는 함수도 포함 가능하다
*/


#include <iostream>

// 키워드, 구조체 이름
struct Struct1{
	// 여기에 필요한 멤버들이 들어간다
	
};

// 학생과 관련된 정보를 만든다면
struct Student {
	int age;
	int phoneNumber;
	std::string name;
	int length;
};

struct Point {
	int x;
	int y;
	void Print();	// c++에서는 함수도 멤버로 가능하다
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
	student1.name = "네임";
	student1.phoneNumber = 1098761234;

	std::cout << "이름 : " << student1.name << std::endl;
	std::cout << "나이 : " << student1.age << std::endl;
	std::cout << "전화번호 : +82)" << student1.phoneNumber << std::endl;


	Point p;
	p.x = 10;
	p.y = 20;
	std::cout << "구조체 p.x의 값 : " << p.x << "\n구조체 p.y의 값 : " << p.y << std::endl;
	p.Print();

	Point p1 = { 50, 102 }; // 생성과 동시에 초기화
	std::cout << "구조체 p1.x의 값 : " << p1.x << "\n구조체 p1.y의 값 : " << p1.y << std::endl;

	Person person[3];
	person[0].name = "이름1";
	person[0].phoneNumber = "010-1234-5678";
	person[0].age = 15;

	person[1].name = "이름2";
	person[1].phoneNumber = "010-9876-5432";
	person[1].age = 30;

	person[2].name = "이름3";
	person[2].phoneNumber = "010-7894-1235";
	person[2].age = 20;

	Person person1[3] = {
		{"이름1", "01044", 40},
		{"이름2", "0100000000000", 50},
		{"이름3", "01022340135", 60}
	};

	for (int i = 0; i < 3; i++) {
		std::cout << person1[i].name << ", " << person1[i].age << ", " << person1[i].phoneNumber << std:: endl;
	}

	Test t;
	std::cout << sizeof(t) << std::endl;	
	// 메모리를 4byte 단위로 저장하기에 변수의 위치에 따라 크기가 달라진다
	// short, char, int 일 때는 short 2, char 1해서 3byte가 나오고 int는 들어갈 수 없기에 1을 pading으로 채운다
	// 그리하여 8byte가 된다
	// short, int, char 로 하면 short 2인데 int는 4이므로 4byte를 초과하므로 short에 2byte를 pading, int 4byte채우고 char 1byte에 4바이트 단위이니 3byte를 pading하여
	// 12byte가 된다


}

/// <summary>
/// Point의 멤버 함수이다
/// </summary>
void Point::Print()
{
	std::cout << "Point 구조체의 멤버 함수이다" << std::endl;
}
