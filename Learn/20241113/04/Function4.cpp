/*
��� �Լ�, ������ �ּҸ� ������ �ִ�

[inline �Լ�]
	int a = Sum(1,2);��
	int a = a+b;�� ġȯ�Ѵ�.
	�ڵ尡 ��ų� ������ ��쿡�� ġȯ�ϴ� ���� �� ���� �� �ִ�.
	�����Ϸ��� ��ü������ ���м��� �Ͽ� inline ó���� �ϰų� ����.

[�Լ� ȣ�� �Ծ�]

[��ũ�� �Լ�]
	��ũ�� �Լ��� �Լ��� �ƴϴ�
	�����Ͽ� ��ü�Ǵ� �������� �Ѵ�

	#define �Լ���(�Ű�����) (����)
	
	������� ��ƴ� ���� ((x) * (x))�� (x * x)�� ���� ���
	SQUARE(5+1)�� �Ͽ��ٰ� ��������
	((x) * (x))�� ((5+1) * (5+1))�� ���ǰ�
	(x * x)�� (5+1*5+1)�� ���ȴ�

*/

#include <iostream>

#define SQUARE(x) ((x) * (x)) // ��ũ�� �Լ�

#define NUM1 5		// �Ѵ� ���� ��Ȱ�� ������ �� ����� �����϶�� ���� �ִ�
const int NUM2 = 5;

inline int Sum(int a, int b) {
	return a + b;
}

int main() {
	std::cout << SQUARE(5) << std::endl;	// ((5) * (5))
	std::cout << SQUARE(5+1) << std::endl;

	int a = 5;
	int res = SQUARE(5 + 1);		// 5 + 1 * 5 + 1
	std::cout << res << std::endl;	
	std::cout << NUM1 << std::endl;
}

int playerHp = 100;
int monsterHp = 100;

// Attack(1, monsterHp);