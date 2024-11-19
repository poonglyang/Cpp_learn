/*
[������ (constructor)]
	��ü�� ������ �� �ڵ����� ȣ��Ǵ� Ư���� ��� �Լ�
	��ü�� �ʱ�ȭ�� ���
	Ŭ������ �̸��� ����
	��ȯ���� ����
	�����ε��� �����ϴ� (�������� �����ڸ� ������ �� �ִ�.)
	�⺻ ������, �Ű������� �ִ� ������, ���� ������

[�⺻ ������]
	�Ű������� ���� ������, ��������� ���� ���� ������ �����Ϸ��� �ڵ����� �����Ѵ�.

[�Ű������� �ִ� ������]
	


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
/// ������
/// </summary>
Cplayer::Cplayer()
{
	mName = "ȫ�浿";
	mAtk = 10;
	mDef = 200;
}

/// <summary>
/// �ʱ� ���� �������ִ� ������
/// </summary>
/// <param name="name">�̸�</param>
/// <param name="atk">���ݷ�</param>
/// <param name="def">����</param>
Cplayer::Cplayer(const string& name, const int atk, const int def)
{
	mName = name;
	mAtk = atk;
	mDef = def;
}

/// <summary>
/// �ڿ� const�� ���̸� �� �ɹ� �Լ��� �ɹ� ������ �������� �ʰڴٸ� �ǹ���
/// </summary>
void Cplayer::PrintInfo() const
{
	//mAtk = 10;	// �̰� ������
	std::cout << "�̸� : " << mName << ", ���ݷ� : " << mAtk << ", ���� : " << mDef << endl;
}


int main() {
	Cplayer cp1 = Cplayer();
	cp1.PrintInfo();

	Cplayer* cp2 = new Cplayer("������", 50, 200);
	cp2->PrintInfo();

	delete cp2;
	cp2 = nullptr;

	// cp2->PrintInfo();
}


