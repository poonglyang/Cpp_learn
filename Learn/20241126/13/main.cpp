/*
[static]
	전역변수라 할 지라도 외부에서 사용할 수 없고 선언한 내부에서만 사용할 수 있음
	함수 내에서 선언된 static 변수는 함수가 끝나도 남아 있다(생명주기를 함수와 같이하지 않는다)

[extern]
	외부에 있는 전역변수를 사용할 수 있음


*/

#include <iostream>

extern int GlovalValue;

extern int staticGValue;

/*
	클래스에서의 static 변수와 함수
		클래스 static로 선언된 변수는 해당 클래스의 모든 인스턴스에서 공유된다
		인스턴스간의 공통으로 사용되는 변수
		클래스에 인스턴스가 없어도 접근이 가능하다

		1. 클래스 정적 맴버 변수
			모든 클래스 인스턴스가 공유하는 변수
			클래스의 모든 인스턴스가 해당 변수에 접근 가능
			하나의 인스턴스에서 변수를 수정하는 다른 인스턴스에서도 반영 된다
			클래스 밖에서 초기화를 해준다

		2. 클래스 정적 맴버 함수
			클래스의 인스턴스 없이 호출할 수 있는 함수
			정적 맴버함수는 클래스의 정적 맴버변수에만 접근 가능
			인스턴스 맴버 변수나 함수에는 접근 불가

*/
extern class CountClass
{
private:
	int num;
	static int count;

	// C++ 17이상부터는 inline을 앞에 붙이면 초기화 가능하다
	inline static int count2 = 200;


public:
	CountClass() {
		count++;
	}


	static int GetCount() {
		return count;
	}

	void Print() {
		std::cout << "프린트 함수" << std::endl;
	}

	static int Sum(int a, int b) {
		count = 1;	// 정적 맴버 변수이기에 사용 가능
		// num = 2;	// static가 없는 맴버변수이기에 불가

		GetCount();	// 정적 맴버 함수이기에 가능
		//Print();	// 일반 맴버 함수이기에 불가능

	}
};

int CountClass::count = 0;	// 클래스 밖에서 초기화를 해준다

/*
	함수에서의 static변수
*/
void Count() {
	static int count = 0;				// 단 한번만 초기화 된다
	count++;
	std::cout << count << std::endl;
}



int main() {

	std::cout << GlovalValue << std::endl;

	std::cout << GlovalValue << std::endl;

	//std::cout << staticGValue << std::endl;
	GlovalValue = 10;
	//std::cout << staticGValue << std::endl;
	
	Count();
	Count();

	CountClass c1;
	CountClass c2;
	CountClass c3;

	
	std::cout << CountClass::GetCount() << std::endl; // 인스턴스 없이 범위 지정 명령어로 소환 가능하다
}