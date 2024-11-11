/*

switch - case 문
	여러 조건을 처리해야할 때 사용하는 조건문 중 하나.
	주로 상수 값을 기준으로 분기할 때 사용되며, 가독성이 좋음

구조
	하나의 변수를 검사하고 그 변수의 값에 따라 여러 case 블록 중 하나를 실행
	break 키워드를 통해 각 case의 실행을 종료
	break가 없으면 다음 case 블록이 연속해서 실행된다
	표현식에는 문자, 정수, 열거타입 등이 들어온다.

요약
	상수값을 기준으로 여러 선택지 중 하나를 선택하는 상황에서 사용하기 좋다.
	코드의 가독성을 높이고 효율성을 개선할 수는 있지만 표현식에 제한이 있다
	범위 기반 비교는 불가 (10 < x < 20 등)
	if 문은 범용적으로 다양한 조건을 다루기에 유용.

switch(표현식){
	case 표현식의 경우의 수 1:
		해당되는 코드
		break;
	case 표현식의 경우의 수 2:
		해당되는 코드
		break;
	default:
		어떤 case에도 해당되지 않은 경우 실행되는 코드
		break;
}

break란?
	반복문이나 switch 문을 제어할 때 사용
	break가 실행되면 해당 루프나 switch문을 종료하고 break 다음으로 이동하여 실행한다
	다중 switch나 중첩반복문에서는 break가 있는 해당 스코프만 빠져나간다

*/

#include <iostream>


enum MyActive {
	a,b,c,d
};

int main() {
	/*
	MyActive active = d;

	switch (active)
	{
	case a:
		break;
	case b:
		break;
	case c:
		break;
	case d:
		break;
	default:
		break;
	}
	*/

	/*
	int choice;
	std::cout << "게임을 선택하세요! " << std::endl;
	std::cout << "1. 롤\n2. 발로란트\n3. 오버워치\n4. 스타\n5. 디아4" << std::endl;

	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "롤 선택" << std::endl;
		break;
	case 2:
		std::cout << "발로란트 선택" << std::endl;
		break;
	case 3:
		std::cout << "오버워치 선택" << std::endl;
		break;
	case 4:
		std::cout << "스타 선택" << std::endl;
		break;
	case 5:
		std::cout << "디아4 선택" << std::endl;
		break;
	default :
		std::cout << "입력값이 잘못됨 선택" << std::endl;
		break;
	}
	*/

	int jobChoice;

	int skillChoice;

	std::cout << "직업을 선택해 주세요(1. 전사, 2. 마법사, 3. 도적) : ";
	std::cin >> jobChoice;

	switch (jobChoice)
	{
	case 1:
		std::cout << "전사를 선택했다. 어떤 스킬을 사용할까? (1. 대쉬. 2. 방패) : ";
		std::cin >> skillChoice;
		switch (skillChoice)
		{
		case 1:
			std::cout << "대쉬 공격" << std::endl;
			break;
		case 2:
			std::cout << "방패 공격" << std::endl;
			break;
		default:
			std::cout << "당신은 적을 앞두고 공격을 하지 못했다... 당신은 눈을 감았다" << std::endl;
			break;
		}
		break;
	case 2:
		std::cout << "마법사를 선택했다. 어떤 스킬을 사용할까? (1. 파이어볼. 2. 에너지볼) : ";
		std::cin >> skillChoice;
		switch (skillChoice)
		{
		case 1:
			std::cout << "파이어볼" << std::endl;
			break;
		case 2:
			std::cout << "에너지볼" << std::endl;
			break;
		default:
			std::cout << "당신은 적을 앞두고 공격을 하지 못했다... 당신은 눈을 감았다" << std::endl;
			break;
		}
		break;
	case 3:
		std::cout << "도적을 선택했다. 어떤 스킬을 사용할까? (1. 기습. 2. 비겁하게 찌르기) : ";
		std::cin >> skillChoice;
		switch (skillChoice)
		{
		case 1:
			std::cout << "기습" << std::endl;
			break;
		case 2:
			std::cout << "비겁하게 찌르기 공격" << std::endl;
			break;
		default:
			std::cout << "당신은 적을 앞두고 공격을 하지 못했다... 당신은 눈을 감았다" << std::endl;
			break;
		}
		break;

	default:
		std::cout << "당신은 전직에 실패했다" << std::endl;
		break;
	}

}