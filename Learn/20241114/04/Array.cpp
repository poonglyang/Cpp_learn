/*
[배열]
	동일한 타입의 여러 값을 연속적으로 저장할 수 있는 데이터 구조
	메모리에서 연속적인 공간을 가지고 각 요소는 인덱스를 통해 접근할 수 있다.
	배열을 선언 할 때 지정된 크기를 변경할 수 없다.
	배열의 모든 요소는 동일한 데이터 타입을 가져야 한다.
	연속된 공간에 저장되기 때문에 요소에 대한 인덱스 접근이 매우 빠르다.

[선언]
	자료형 배열[배열 길이];


*/


#include <iostream>
#include <list>
#include <vector>
int main() {
	// 1. 크기를 명시하고 초기화
	int intArr[4] = { 1,2,3,4 };

	// 2. 배열의 크기를 생략하고 초기화
	int intArr2[] = { 1,2,3 };	// 크기를 알아서 3으로 잡음

	// 3. 크기를 명시작으로 지정하고 일부 요소만 초기화
	int intArr3[5] = { 1,2,3 };	// 나머지는 0으로 초기화

	// 4. 모든 요소를 초기화 하지 않으면 기본값으로 초기화 됨 (0)
	int intArr4[5] = {};	// 으로 초기화
	
	std::cout << intArr[0] << std::endl;

	for (int i = 0; i < sizeof(intArr) / sizeof(int); i++) {
		std::cout << intArr[i];
	}
	std::cout << std::endl;

	int numbers[5] = { 10,20,30,40,50 };

	for (int i = 0; i < 5; i++) {
		std::cout << "각 인덱스에 접근하여 출력 : " << i << " : " << numbers[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << "배열 intArr[0]의 주소 : " << intArr << std::endl;		// 배열의 시작 주소가 나옴 (배열의 시작 주소는 배열의 0번째 주소와 같다)
	std::cout << "배열 intArr[0]의 주소 : " << &intArr[0] << std::endl;	// 배열[0]의 주소가 나옴
	std::cout << "배열 intArr[1]의 주소 : " << &intArr[1] << std::endl;	// 배열[1]의 주소가 나옴
	std::cout << "배열 intArr[1]의 주소 : " << &intArr[2] << std::endl;	// 배열[2]의 주소가 나옴
	std::cout << "배열 intArr[1]의 주소 : " << &intArr[3] << std::endl;	// 배열[3]의 주소가 나옴
	// 주소 값을 보면 연속적으로 4byte씩 증가하는 것을 확인할 수 있다 -> 연속적인 공간에 저장된다

	std::cout << std::endl;

	// 배열에 저장된 숫자를 찾아봅시다
	int intArr5[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int select;
	bool isFind = false;
	std::cin >> select;

	// 입력과 처리는 구분해라
	for (int i = 0; i < 10; i++) {
		if (intArr5[i] == select) {
			isFind = true;
			std::cout << "인덱스 : " << i << "에 있습니다. ";
			break;
		}
	}

	if (isFind) {
		std::cout << "찾음" << std::endl;
	}
	else {
		std::cout << "없음" << std::endl;
	}

	// 배열에 저장된 모든 요소의 합을 구하시오

	int intArr6[] = { 1,2,3,4,5 };

	int sum = 0;
	for (int i = 0; i < sizeof(intArr6) / sizeof(int); i++) {
		sum += intArr6[i];
	}
	std::cout << "\n\n합계 : " << sum << std::endl;


}