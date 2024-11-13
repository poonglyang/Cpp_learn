#include <iostream>


/// <summary>
/// 0���� ������ ���ڱ����� ���� ��ȯ�ϴ� �Լ�
/// </summary>
/// <param name="n">������ ����</param>
/// <returns>0���� n������ ���� ���� ���� ��</returns>
int Sum(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += i;
	}
	return result;
}

/// <summary>
/// �Է¹��� �� ���� �� ū ���ڸ� �����ϴ� �Լ�
/// </summary>
/// <param name="a">����1</param>
/// <param name="b">����2</param>
/// <returns>�� �� �� ū��</returns>
int FindMaxNumber(int a, int b) {
	return a > b ? a : b;
}

/// <summary>
/// �Է¹��� ���ڰ� �Ҽ����� �ƴ��� �Ǻ��ϴ� �Լ�
/// </summary>
/// <param name="n">�Ҽ����� Ȯ���� ����</param>
/// <returns>0�̸� �Ҽ� �ƴ�, 1�̸� �Ҽ�</returns>
bool IsPrime(int n) {
	bool result = true;

	if (n == 1) {
		result = false;
	}
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				result = false;
				break;
			}
		}
	}

	return result;
}

int main() {
	std::cout << "0���� " << 10 << "������ �� : " << Sum(10) << std::endl;
	std::cout << "10�� 5�� �� ū �� : " << FindMaxNumber(10, 5) << std::endl;

	int primeArr[] = { 2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417, 2423 };

	for (int i = 0; i < sizeof(primeArr) / sizeof(int); i++) {
		std::cout << primeArr[i] << "��(��) �Ҽ��ΰ�? : " << IsPrime(primeArr[i]) << std::endl;
	}
}