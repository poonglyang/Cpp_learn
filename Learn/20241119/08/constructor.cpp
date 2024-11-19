/*
[생성자 (constructor)]
	객체가 생성될 때 자동으로 호출되는 특별한 멤버 함수
	객체의 초기화를 담당
	클래스와 이름이 같다
	반환값이 없다
	오버로딩이 가능하다 (여러개의 생성자를 정의할 수 있다.)
	기본 생성자, 매개변수가 있는 생성자, 복사 생성자

[기본 생성자]
	매개변수가 없는 생성자, 명시적으로 정의 하지 않으면 컴파일러가 자동으로 제공한다.

[매개변수가 있는 생성자]
	


*/

#include <iostream>

using namespace std;

class Cplayer {
public :
	string mName;
	int mAtk;
	int mDef;

public :
	Cplayer();
	Cplayer(const string& name, const int atk, const int def);

	void PrintInfo() const;
};

/// <summary>
/// 생성자
/// </summary>
Cplayer::Cplayer()
{
	mName = "홍길동";
	mAtk = 10;
	mDef = 200;
}

/// <summary>
/// 초기 값을 설정해주는 생성자
/// </summary>
/// <param name="name">이름</param>
/// <param name="atk">공격력</param>
/// <param name="def">방어력</param>
Cplayer::Cplayer(const string& name, const int atk, const int def)
{
	mName = name;
	mAtk = atk;
	mDef = def;
}

/// <summary>
/// 뒤에 const를 붙이면 이 맴버 함수는 맴버 변수를 수정하지 않겠다를 의미함
/// </summary>
void Cplayer::PrintInfo() const
{
	//mAtk = 10;	// 이거 에러남
	std::cout << "이름 : " << mName << ", 공격력 : " << mAtk << ", 방어력 : " << mDef << endl;
}


int main() {
	Cplayer cp1 = Cplayer();
	cp1.PrintInfo();

	Cplayer* cp2 = new Cplayer("김전사", 50, 200);
	cp2->PrintInfo();

	delete cp2;
	cp2 = nullptr;

	// cp2->PrintInfo();
}


