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

	4. 논리 연산자 (||, &&, !)
		&&	: AND 연산, 피 연산자가 모두 참일 경우 참이다 
			(true && ture) == ture
			(true && false) == false
			(false && ture) == false
			(false && false) == false

		||	: OR 연산, 피 연산자 중 하나가 참이면 참이다
			(true || ture) == true
			(true || false) == true
			(false || ture) == true
			(false || false) == false

		!	: NOT 연산, 피연산자가 참이면 거짓, 거짓이면 참이다
			!(true) == false
			!(false) == true

	5. 비트 연산자 (&, |, ^, ~, <<, >>)
		비트 연산자는 데이터를 비트 단위로 처리하는 연산자
			하드웨어랑 밀접하게 관련된 각종 처리를 한다
			메모리 공간을 줄여서 성능을 높여준다
			컴퓨터는 0과 1로 처리한다
		
		비트는 2진수 값 하나 (0 또는 1)를 저장할 수 있는 최소 메모리 공간을 의미
		1bit로 표현할 수 있는 데이터 수 : 1,0
		2bit : 00,01,10,11 4가지, 3bit : 8개 *2씩 늘어난다
		1byte : 2^^8 (C++에서 제곱은 뭐냐?)만큼 저장용량을 가진다

		2진수, 10진수, 16진수, 8진수
			2진수 : 0, 1 사용
			10진수 : 0 ~ 9 사용
			16진수 : 0 ~ 9, A, B, C, D, E, F 사용
				A : 10 ~ F : 15
				색 코드가 255까지 있는 이유 16**2
			8진수 : 0 ~ 7 까지의 숫자 사용

		& : 비트단위 AND 연산
			a & b : a와 b의 비트가 모두 1일때 1을 반환
		| : 비트단위 OR 연산
			a | b : a와 b 둘 중 하나의 비트가 1이면 1반환
		^ : 비트단위 XOR 연산
			a ^ b : a와 b 두 비트가 서로 같지 않을 경우 1을 반환
		~ : 비트단위 NOT 연산
			!a : a를 반전시킨다 (0101001 -> 1010110)
		<< : 왼쪽으로 쉬프트 시킨다 - 2배씩 증가한다
			a<<3 : 왼쪽으로 비트를 3칸 이동시킨다 (0000 0111 << 3 == 0011 1000)
		>> : 오른쪽으로 쉬프트 시킨다 - 2배씩 감소한다
			a>>3 : 오른쪽으로 비트를 3칸 이동시킨다 (0111 >> 3 == 0000)
		
		128 64 32 16 8 4 2 0
		

	6. 복합 대입 연산자 (+=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=)
		+= : A += B, A에 B를 더해서 A에 대입한다
		-= : A -= B, A에 B를 빼서 A에 대입한다
		*= : A *= B, A에 B를 곱하고 A에 대입한다
		/= : A /= B, A에 B를 나누고 A에 대입한다
		&= : A &= B, A에 B를 AND 비트 연산을 하고 A에 대입한다
		|= : A |= B, A에 B를 OR 비트 연산을 A에 대입한다
		^= : A ^= B, A에 B를 XOR 비트 연산을 하고 A에 대입한다
		<<= : A <<= B, A에 B만큼 왼쪽으로 쉬프트 하고 A에 대입한다
		>>= : A >>= B, A에 B만큼 오른쪽으로 쉬프트 하고 A에 대입한다

	7. 삼항연산자
		연산자가 2개(?, :)와 피연산자 3개로 이루어지는 삼항연산자
			bool a = testNum1 > 0 ? 0 : 1;
			testNum1이 0보다 크면 0, 아니면 1을 a에 대입한다
		

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
	int num5 = 3;
	int num6 = 5;
	bool result7;
	bool result8;
	bool result9;

	result7 = (num5 > 0 && num6 < 10);
	std::cout << "result7의 값 : " << result7 << std::endl;

	result8 = (num5 <= 2 || num6 > 5);
	std::cout << "result8의 값 : " << result8 << std::endl;

	result9 = !num6;
	std::cout << "result9의 값 : " << result9 << std::endl << std::endl;

	std::cout << "------비트 연산자------" << std::endl;
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

	// 강의에서 편의상 1byte로 나타내었지 int는 4byte 숫자다 00000000 00000000 00000000 00001010이다
	// 0으로 계속 채워진다. 에초에 없더라도 0으로 채워질것
	// 128 64 32 16 8 4 2 1  

	std::cout << "------복합 대입 연산자------" << std::endl;

	int x = 5;
	int y = 4;
	x += y;
	std::cout << x << std::endl << std::endl;

	std::cout << "------삼항 연산자------" << std::endl;

	int num7 = 2;
	int num8 = 3;
	int numberResult;

	numberResult = num7 > num8 ? num7 : num8;

	/* 위의 삼항연산자는 아래의 if else문과 같다
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
/// 어떠한 값도 반환하지 않는다인데 표준이 아니다
/// </summary>
void main() {

}
*/

