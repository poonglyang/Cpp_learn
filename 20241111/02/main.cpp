/*
������(operator)
	1. ��� ������(+, -, *, /, %)
		���ϱ�, ����, ���ϱ�, ������, ������ ��ȯ
		���ϱⰡ ���� �� ������

	2. ���� ������ (++, --)
		++�� --�� �̿��ϴ� ������, �ǿ������� ���� 1���� �Ǵ� 1���� ��Ų��
		A�� ������ ������ �� A++ �� ++A�� �ٸ���
			++A�� ���(�ǿ������� �տ� ���� ���) : �� ���� �� ����(���� ������ ���� �����Ѵ�)
			A++�� ���(�ǿ����� �ڿ� ���� ���) : �� ���� �� ����(���� �����ϰ� �� ���� �����Ѵ�)
			--A�� ��� : �� ���� �� ���� (���� ���ҽ�Ű�� �� ���� ����)
			A--�� ��� : �� ���� �� ���� (���� �����ϰ� �� ���� ����)

		���� ����� ���� ����
			���� �������� ��ġ�� ������ �տ� ��ġ�ϸ� ���� ���, �ڿ� ��ġ�ϸ� ���� ���

	3. ���� ������(>, <, >=, <=, ==, !=)
			A > B : A�� B ���� ũ��
			A < B : A�� B ���� �۴�
			A >= B : A�� B ���� ũ�ų� ����
			A =< B : A�� B ���� �۰ų� ����
			A == B : A�� B�� ����
			A != B : A�� B�� �ٸ���

	4. �� ������ (||, &&)

	5. ��Ʈ ������ 

	6. ���� ���� ������ (+=, -=, *=, /=, %=)
		+= : A += B, A�� B�� ���ؼ� �ִ´�
		-= : A -= B, A�� B�� ���� �ִ´�
		*= : A *= B, A�� B�� ���ϰ� �ִ´�
		/= : A /= B, 

*/

#include <iostream>

/// <summary>
/// �⺻ ���� �Լ�
/// </summary>
/// <param name="">���� ���� void�� ��� ���ڵ� ���޹��� �ʴ´ٴ� ���̴�</param>
/// <returns>0��ȯ</returns>
int main(void) 
{
	int testNum1 = 10;
	int testNum2 = 3;

	std::cout << "������ �����ڸ� �����Ѵ�" << std::endl << std::endl;
	
	std::cout << "------���������------" << std::endl;
	std::cout << "testNum1 + testNum2 == " << testNum1 + testNum2 << std::endl;
	std::cout << "testNum1 - testNum2 == " << testNum1 - testNum2 << std::endl;
	std::cout << "testNum1 * testNum2 == " << testNum1 * testNum2 << std::endl;
	std::cout << "testNum1 / testNum2 == " << testNum1 / testNum2 << std::endl;
	std::cout << "testNum1 % testNum2 == " << testNum1 % testNum2 << std::endl << std::endl;

	std::cout << "------����������------" << std::endl;
	int testNum3 = 10;

	std::cout << "���� testNum3�� ����Ǿ� �ִ� �� : " << testNum3 << std::endl;

	testNum3++;
	std::cout << "testNum3++ �� testNum3�� ����Ǿ� �ִ� �� : " << testNum3 << std::endl;

	++testNum3;
	std::cout << "++testNum3 �� testNum3�� ����Ǿ� �ִ� �� : " << testNum3 << std::endl;

	testNum3--;
	std::cout << "testNum-- �� testNum3�� ����Ǿ� �ִ� �� : " << testNum3 << std::endl;

	--testNum3;
	std::cout << "--testNum �� testNum3�� ����Ǿ� �ִ� �� : " << testNum3 << std::endl;

	int num1 = 10;
	int num2 = 20;

	int c, d;

	c = ++num1;	// ���� ���, �� ���� �� ����
	std::cout << "c = ++num1 �� c�� �� : " << c << std::endl;	// num1�� 1�� ���� ���ϰ� c�� �����Ѵ�

	d = num2++;	// ���� ���, �� ���� �� ����
	std::cout << "d = num2++ �� d�� �� : " << d << std::endl << std::endl;	// d�� num2�� ���� �����ϰ� num2�� 1�� �����Ѵ�

	std::cout << "------���� ������------" << std::endl;

	int num3 = 1;
	int num4 = 2;
	
	int result1, result2, result3, result4, result5, result6;
	
	result1 = 1 > 2;
	std::cout << "result1�� ����� �� : " << result1 << std::endl;

	result2 = 1 < 2;
	std::cout << "result2�� ����� �� : " << result2 << std::endl;

	result3 = 1 >= 2;
	std::cout << "result3�� ����� �� : " << result3 << std::endl;

	result4 = 1 <= 2;
	std::cout << "result4�� ����� �� : " << result4 << std::endl;

	result5 = 1 == 2;
	std::cout << "result5�� ����� �� : " << result5 << std::endl;

	result6 = 1 != 2;
	std::cout << "result6�� ����� �� : " << result6 << std::endl << std::endl;

	std::cout << "------�� ������------" << std::endl;



	return 0;
}

/*
/// <summary>
/// ��� ���� ��ȯ���� �ʴ´��ε� ǥ���� �ƴϴ�
/// </summary>
void main() {

}
*/

