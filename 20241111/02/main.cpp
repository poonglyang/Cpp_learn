/*
연산자(operator)
	1. 산술 연산자(+, -, *, /, %)
		더하기, 빼기, 곱하기, 나누기, 나머지 반환
		곱하기가 조금 더 빠르다

	2. 증감 연산자 (++, --)
		++와 --를 이용하는 연산자, 피연산자의 값을 1증가 또는 1감소 시킨다
		A를 변수라 가정할 때 A++ 와 ++A는 다르다
			++A일 경우(피연산자의 앞에 있을 경우) : 선 증가 후 연산(먼저 증가한 다음 연산한다)
			A++일 경우(피연산자 뒤에 있을 경우) : 선 연산 후 증가(먼저 연산하고 그 다음 증가한다)
			--A일 경우 : 선 감소 후 연산 (먼저 감소시키고 그 다음 연산)
			A--일 경우 : 선 연산 후 감소 (먼저 연산하고 그 다음 감소)

		전위 연산과 후위 연산
			증감 연산자의 위치가 변수의 앞에 위치하면 전위 방식, 뒤에 위치하면 후위 방식

	3. 관계 연산자(>, <, >=, <=, ==, !=)
			A > B : A는 B 보다 크다
			A < B : A는 B 보다 작다
			A >= B : A는 B 보다 크거나 같다
			A =< B : A는 B 보다 작거나 같다
			A == B : A와 B는 같다
			A != B : A와 B는 다르다

	4. 논리 연산자 (||, &&)

	5. 비트 연산자 

	6. 복합 대입 연산자 (+=, -=, *=, /=, %=)
		+= : A += B, A에 B를 더해서 넣는다
		-= : A -= B, A에 B를 빼서 넣는다
		*= : A *= B, A에 B를 곱하고 넣는다
		/= : A /= B, 

*/

#include <iostream>

/// <summary>
/// 기본 시작 함수
/// </summary>
/// <param name="">인자 값의 void는 어떠한 인자도 전달받지 않는다는 뜻이다</param>
/// <returns>0반환</returns>
int main(void) 
{
	int testNum1 = 10;
	int testNum2 = 3;

	std::cout << "오늘은 연산자를 공부한다" << std::endl << std::endl;
	
	std::cout << "------산술연산자------" << std::endl;
	std::cout << "testNum1 + testNum2 == " << testNum1 + testNum2 << std::endl;
	std::cout << "testNum1 - testNum2 == " << testNum1 - testNum2 << std::endl;
	std::cout << "testNum1 * testNum2 == " << testNum1 * testNum2 << std::endl;
	std::cout << "testNum1 / testNum2 == " << testNum1 / testNum2 << std::endl;
	std::cout << "testNum1 % testNum2 == " << testNum1 % testNum2 << std::endl << std::endl;

	std::cout << "------증감연산자------" << std::endl;
	int testNum3 = 10;

	std::cout << "변수 testNum3에 저장되어 있는 값 : " << testNum3 << std::endl;

	testNum3++;
	std::cout << "testNum3++ 후 testNum3에 저장되어 있는 값 : " << testNum3 << std::endl;

	++testNum3;
	std::cout << "++testNum3 후 testNum3에 저장되어 있는 값 : " << testNum3 << std::endl;

	testNum3--;
	std::cout << "testNum-- 후 testNum3에 저장되어 있는 값 : " << testNum3 << std::endl;

	--testNum3;
	std::cout << "--testNum 후 testNum3에 저장되어 있는 값 : " << testNum3 << std::endl;

	int num1 = 10;
	int num2 = 20;

	int c, d;

	c = ++num1;	// 전위 방식, 선 증가 후 연산
	std::cout << "c = ++num1 후 c의 값 : " << c << std::endl;	// num1에 1을 먼저 더하고 c에 대입한다

	d = num2++;	// 후위 방식, 선 연산 후 증가
	std::cout << "d = num2++ 후 d의 값 : " << d << std::endl << std::endl;	// d에 num2를 먼저 대입하고 num2에 1를 증가한다

	std::cout << "------관계 연산자------" << std::endl;

	int num3 = 1;
	int num4 = 2;
	
	int result1, result2, result3, result4, result5, result6;
	
	result1 = 1 > 2;
	std::cout << "result1에 저장된 값 : " << result1 << std::endl;

	result2 = 1 < 2;
	std::cout << "result2에 저장된 값 : " << result2 << std::endl;

	result3 = 1 >= 2;
	std::cout << "result3에 저장된 값 : " << result3 << std::endl;

	result4 = 1 <= 2;
	std::cout << "result4에 저장된 값 : " << result4 << std::endl;

	result5 = 1 == 2;
	std::cout << "result5에 저장된 값 : " << result5 << std::endl;

	result6 = 1 != 2;
	std::cout << "result6에 저장된 값 : " << result6 << std::endl << std::endl;

	std::cout << "------논리 연산자------" << std::endl;



	return 0;
}

/*
/// <summary>
/// 어떠한 값도 반환하지 않는다인데 표준이 아니다
/// </summary>
void main() {

}
*/

