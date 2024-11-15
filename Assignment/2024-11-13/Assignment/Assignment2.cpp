#include <iostream>


/// <summary>
/// 0부터 지정된 숫자까지의 합을 반환하는 함수
/// </summary>
/// <param name="n">지정된 숫자</param>
/// <returns>0부터 n까지의 수를 전부 더한 값</returns>
int Sum(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += i;
	}
	return result;
}

/// <summary>
/// 입력받은 두 숫자 중 큰 숫자를 리턴하는 함수
/// </summary>
/// <param name="a">숫자1</param>
/// <param name="b">숫자2</param>
/// <returns>두 수 중 큰수</returns>
int FindMaxNumber(int a, int b) {
	return a > b ? a : b;
}

/// <summary>
/// 입력받은 숫자가 소수인지 아닌지 판별하는 함수
/// </summary>
/// <param name="n">소수인지 확인할 숫자</param>
/// <returns>0이면 소수 아님, 1이면 소수</returns>
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
	std::cout << "0부터 " << 10 << "까지의 합 : " << Sum(10) << std::endl;
	std::cout << "10과 5중 더 큰 수 : " << FindMaxNumber(10, 5) << std::endl;

	int primeArr[] = { 2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417, 2423 };

	for (int i = 0; i < sizeof(primeArr) / sizeof(int); i++) {
		std::cout << primeArr[i] << "은(는) 소수인가? : " << IsPrime(primeArr[i]) << std::endl;
	}
}