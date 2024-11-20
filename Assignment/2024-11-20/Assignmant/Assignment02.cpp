/*
- ����� public, protected, private�� �Ͽ��� ���� ����
- ����� �ϴµ� �θ�Ŭ������ ������� protected, public, private�� �ϳ��� �����
- ����� �޴� �ڽ� Ŭ������ protected�� ���, public �� ���, private�� ����� ����� ������ ��� �Ǵ��� ���캸�ÿ�
*/

#include <iostream>
#include <cassert>



using namespace std;

class base {
private:
	int privateNum;
	void privateFunc() {
		cout << "private �ȿ� �ִ� �Լ� ����" << endl;
	}

protected:
	int protectedNum;
	void protectedFunc() {
		cout << "private �ȿ� �ִ� �Լ� ����" << endl;
	}

public:
	int publicNum;

	/// <summary>
	/// ������
	/// </summary>
	/// <param name="n1"></param>
	/// <param name="n2"></param>
	/// <param name="n3"></param>
	base(int n1, int n2, int n3) : privateNum(n1), protectedNum(n2), publicNum(n3) {}

	~base() {}

	void publicFunc() {
		cout << "private �ȿ� �ִ� �Լ� ����" << endl;
	}
};

class InheritancePrivate : private base {
public:
	InheritancePrivate(int n1, int n2, int n3) : base(n1, n2, n3) {}
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

	cout << "[private�� ����Ͽ��� ���]" << endl;
	iPrivate->privateNum;	// ���� �Ұ�
	iPrivate->protectedNum;	// ���� �Ұ�
	iPrivate->publicNum;	// ���� �Ұ�
	
	delete iPrivate;
	iPrivate = nullptr;

	delete iProtected;
	iProtected = nullptr;

	delete iPublic;
	iPublic = nullptr;
}