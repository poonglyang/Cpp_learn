/*
- 상속을 public, protected, private로 하였을 때의 차이
- 상속을 하는데 부모클래스의 멤버들은 protected, public, private로 하나씩 만들고
- 상속을 받는 자식 클래스는 protected로 상속, public 로 상속, private로 상속을 만들고 접근이 어떻게 되는지 살펴보시오
*/

#include <iostream>
#include <cassert>



using namespace std;

class base {
private:
	int privateNum;
	void privateFunc() {
		cout << "private 안에 있는 함수 실행" << endl;
	}

protected:
	int protectedNum;
	void protectedFunc() {
		cout << "private 안에 있는 함수 실행" << endl;
	}

public:
	int publicNum;

	void PrintPrivateNum() {
		cout << privateNum << endl;
	}

	/// <summary>
	/// 생성자
	/// </summary>
	/// <param name="n1">privateNum를 초기화할 값</param>
	/// <param name="n2">protectedNum를 초기화할 값</param>
	/// <param name="n3">publicNum를 초기화할 값</param>
	base(int n1, int n2, int n3) : privateNum(n1), protectedNum(n2), publicNum(n3) {}

	~base() {}

	void publicFunc() {
		cout << "private 안에 있는 함수 실행" << endl;
	}

	
};

class InheritancePrivate : private base {
public:
	InheritancePrivate(int n1, int n2, int n3) : base(n1, n2, n3) {}

	void PrintPrivate() {
		PrintPrivateNum();
	}
};

class InheritanceProtected : protected base {
public:
	InheritanceProtected(int n1, int n2, int n3) : base(n1, n2, n3) {}
};

class InheritancePublic : public base {
public:
	InheritancePublic(int n1, int n2, int n3) : base(n1, n2, n3) {}

	
};


int main() {
	InheritancePrivate* iPrivate = new InheritancePrivate(10,20,30);
	InheritanceProtected* iProtected = new InheritanceProtected(40, 50, 60);
	InheritancePublic* iPublic = new InheritancePublic(70, 80, 90);

	//base* IPrivate = iPrivate;
	//base* IProtected = iProtected;
	//base* IPublic = iPublic;

	iPrivate->PrintPrivate();

	cout << "[private로 상속하였을 경우]" << endl;
	//iPrivate->privateNum;		// 접근 불가
	//iPrivate->protectedNum;	// 접근 불가
	//iPrivate->publicNum;		// 접근 불가

	cout << "[protected로 상속하였을 경우]" << endl;
	//iProtected->privateNum;		// 접근 불가
	//iProtected->protectedNum;		// 접근 불가
	//iProtected->publicNum;		// 접근 불가

	cout << "[public로 상속하였을 경우]" << endl;
	// iPublic->privateNum;			// 접근 불가
	// iPublic->protectedNum;		// 접근 불가
	iPublic->publicNum;				// 접근 가능
	
	/********************************************
	[결론]
		protected private로 상속할 경우 부모 클래스에서 public로 선언되어 있다 하더라도
		부모의 맴버는 선언한 접근 제한자로 변경된다

		protected 상속의 경우
			부모 클래스의 public 멤버는 자식 클래스에서 protected로 변경된다
			자식 내부에서만 접근할 수 있다

		private 상속의 경우
			부모클래스의 public, protected 맴버는 자식 클래스에서 private로 변경된다
			자식 내부에서도 접근할 수 없다.

	*********************************************/

	delete iPrivate;
	iPrivate = nullptr;

	delete iProtected;
	iProtected = nullptr;

	delete iPublic;
	iPublic = nullptr;
}