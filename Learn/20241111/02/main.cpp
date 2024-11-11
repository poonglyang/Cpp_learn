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

	4. �� ������ (||, &&, !)
		&&	: AND ����, �� �����ڰ� ��� ���� ��� ���̴� 
			(true && ture) == ture
			(true && false) == false
			(false && ture) == false
			(false && false) == false

		||	: OR ����, �� ������ �� �ϳ��� ���̸� ���̴�
			(true || ture) == true
			(true || false) == true
			(false || ture) == true
			(false || false) == false

		!	: NOT ����, �ǿ����ڰ� ���̸� ����, �����̸� ���̴�
			!(true) == false
			!(false) == true

	5. ��Ʈ ������ (&, |, ^, ~, <<, >>)
		��Ʈ �����ڴ� �����͸� ��Ʈ ������ ó���ϴ� ������
			�ϵ����� �����ϰ� ���õ� ���� ó���� �Ѵ�
			�޸� ������ �ٿ��� ������ �����ش�
			��ǻ�ʹ� 0�� 1�� ó���Ѵ�
		
		��Ʈ�� 2���� �� �ϳ� (0 �Ǵ� 1)�� ������ �� �ִ� �ּ� �޸� ������ �ǹ�
		1bit�� ǥ���� �� �ִ� ������ �� : 1,0
		2bit : 00,01,10,11 4����, 3bit : 8�� *2�� �þ��
		1byte : 2^^8 (C++���� ������ ����?)��ŭ ����뷮�� ������

		2����, 10����, 16����, 8����
			2���� : 0, 1 ���
			10���� : 0 ~ 9 ���
			16���� : 0 ~ 9, A, B, C, D, E, F ���
				A : 10 ~ F : 15
				�� �ڵ尡 255���� �ִ� ���� 16**2
			8���� : 0 ~ 7 ������ ���� ���

		& : ��Ʈ���� AND ����
			a & b : a�� b�� ��Ʈ�� ��� 1�϶� 1�� ��ȯ
		| : ��Ʈ���� OR ����
			a | b : a�� b �� �� �ϳ��� ��Ʈ�� 1�̸� 1��ȯ
		^ : ��Ʈ���� XOR ����
			a ^ b : a�� b �� ��Ʈ�� ���� ���� ���� ��� 1�� ��ȯ
		~ : ��Ʈ���� NOT ����
			!a : a�� ������Ų�� (0101001 -> 1010110)
		<< : �������� ����Ʈ ��Ų�� - 2�辿 �����Ѵ�
			a<<3 : �������� ��Ʈ�� 3ĭ �̵���Ų�� (0000 0111 << 3 == 0011 1000)
		>> : ���������� ����Ʈ ��Ų�� - 2�辿 �����Ѵ�
			a>>3 : ���������� ��Ʈ�� 3ĭ �̵���Ų�� (0111 >> 3 == 0000)
		
		128 64 32 16 8 4 2 0
		

	6. ���� ���� ������ (+=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=)
		+= : A += B, A�� B�� ���ؼ� A�� �����Ѵ�
		-= : A -= B, A�� B�� ���� A�� �����Ѵ�
		*= : A *= B, A�� B�� ���ϰ� A�� �����Ѵ�
		/= : A /= B, A�� B�� ������ A�� �����Ѵ�
		&= : A &= B, A�� B�� AND ��Ʈ ������ �ϰ� A�� �����Ѵ�
		|= : A |= B, A�� B�� OR ��Ʈ ������ A�� �����Ѵ�
		^= : A ^= B, A�� B�� XOR ��Ʈ ������ �ϰ� A�� �����Ѵ�
		<<= : A <<= B, A�� B��ŭ �������� ����Ʈ �ϰ� A�� �����Ѵ�
		>>= : A >>= B, A�� B��ŭ ���������� ����Ʈ �ϰ� A�� �����Ѵ�

	7. ���׿�����
		�����ڰ� 2��(?, :)�� �ǿ����� 3���� �̷������ ���׿�����
			bool a = testNum1 > 0 ? 0 : 1;
			testNum1�� 0���� ũ�� 0, �ƴϸ� 1�� a�� �����Ѵ�
		

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
	int num5 = 3;
	int num6 = 5;
	bool result7;
	bool result8;
	bool result9;

	result7 = (num5 > 0 && num6 < 10);
	std::cout << "result7�� �� : " << result7 << std::endl;

	result8 = (num5 <= 2 || num6 > 5);
	std::cout << "result8�� �� : " << result8 << std::endl;

	result9 = !num6;
	std::cout << "result9�� �� : " << result9 << std::endl << std::endl;

	std::cout << "------��Ʈ ������------" << std::endl;
	int bitNum1 = 20;
	int bitNum2 = 16;
	
	int bitRes1 = bitNum1 & bitNum2;
	std::cout << "bitRes == " << bitRes1 << std::endl;
	
	int bitRes2 = bitNum1 | bitNum2;
	std::cout << "bitRes == " << bitRes2 << std::endl;

	int shiftNum = 10;
	int shiftRes1 = shiftNum << 2;	
	std::cout << "shiftRes1 == " << shiftRes1 << std::endl;
	
	int shiftRes2 = shiftRes1 >> 1;
	std::cout << "shiftRes2 == " << shiftRes2 << std::endl << std::endl;

	// ���ǿ��� ���ǻ� 1byte�� ��Ÿ������ int�� 4byte ���ڴ� 00000000 00000000 00000000 00001010�̴�
	// 0���� ��� ä������. ���ʿ� ������ 0���� ä������
	// 128 64 32 16 8 4 2 1  

	std::cout << "------���� ���� ������------" << std::endl;

	int x = 5;
	int y = 4;
	x += y;
	std::cout << x << std::endl << std::endl;

	std::cout << "------���� ������------" << std::endl;

	int num7 = 2;
	int num8 = 3;
	int numberResult;

	numberResult = num7 > num8 ? num7 : num8;

	/* ���� ���׿����ڴ� �Ʒ��� if else���� ����
	if (num7 > num8) {
		numberResult = num7;
	}
	else {
		numberResult = num8;
	}
	*/

	std::cout << "numberResult : " << numberResult << std::endl;

	return 0;
}

/*
/// <summary>
/// ��� ���� ��ȯ���� �ʴ´��ε� ǥ���� �ƴϴ�
/// </summary>
void main() {

}
*/

