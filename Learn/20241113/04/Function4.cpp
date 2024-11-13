/*
모든 함수, 변수는 주소를 가지고 있다

[inline 함수]
	int a = Sum(1,2);을
	int a = a+b;로 치환한다.
	코드가 길거나 복잡한 경우에는 치환하는 것이 더 느릴 수 있다.
	컴파일러가 자체적으로 비용분석을 하여 inline 처리를 하거나 땐다.

[함수 호출 규약]

[메크로 함수]
	메크로 함수는 함수가 아니다
	컴파일에 대체되는 형식으로 한다

	#define 함수명(매개변수) (내용)
	
	디버깅이 어렵다 당장 ((x) * (x))와 (x * x)이 있을 경우
	SQUARE(5+1)를 하였다고 가정하자
	((x) * (x))는 ((5+1) * (5+1))로 계산되고
	(x * x)는 (5+1*5+1)로 계산된다

*/

#include <iostream>

#define SQUARE(x) ((x) * (x)) // 메크로 함수

#define NUM1 5		// 둘다 같은 역활을 하지만 이 방식은 지양하라는 말이 있다
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