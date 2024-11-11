/*
분기
	if
		조건문이라고도 하며 프로그램의 실행 흐름을 제어하는데 사용
		주어진 조건이 참인지 거짓인지에 따라 코드블록을 실행하게 된다
		if문의 작성에 제한은 없지만 좀 적게 써라
		
		if (조건1){
			조건1 참
		}
		else if(조건2) {
			위에 if문이든 else if문이든 반드시 있어야함
			위에 있는 if문(조건1,)은 거짓 내 조건(조건2) 참
		}
		else {
			위의 if문의 조건이 거짓일 경우
		}

		// 패턴만들겠다고 if 5중첩 궁극기 쓰지 말고
		// 얌전히 상태 머신을 이용합시다
		// 행동트리 만들던가..

*/

#include <iostream>

int main() {
	/*
	std::cout << "------if문------" << std::endl;

	if (true)
	{
		// if(조건)의 조건이 참일 경우
		std::cout << "여긴 if문 블록 안!" << std::endl;
	}
	else if(true)
	{
		// 위에 있는것(지금의 경우 if(조건))의 조건이 거짓이고 else if(조건)의 조건이 참이면
		std::cout << "여긴 else if문 블록 안!" << std::endl;
	}
	else 
	{
		// 바로 위에 있는 것 거짓이면
		std::cout << "여긴 else문 블록 안!" << std::endl;
	}

	int number;
	std::cout << std::endl << "----------정수를 입력해볼까?-----------" << std::endl;

	std::cout << "정수를 입력해라 : ";
	std::cin >> number;		// 입력하기

	// 내가 입력받은 정수가 0보다 크다면
	if (number > 0) 
	{
		std::cout << "number는 양수다" << std::endl;
	}
	else if(number < 0)
	{
		std::cout << "number는 음수다" << std::endl;
	}
	else {
		std::cout << "number는 0이다" << std::endl;
	}
	*/
	/*
	int score;

	std::cout << "점수를 입력해 보아라 : ";
	std::cin >> score;

	if (score >= 90) {
		std::cout << "A학점" << std::endl;
	}
	else if (score >= 80) {
		std::cout << "B학점" << std::endl;
	}
	else if (score >= 70) {
		std::cout << "C학점" << std::endl;
	}
	else if (score >= 60) {
		std::cout << "D학점" << std::endl;
	}
	else {
		std::cout << "F학점" << std::endl;
	}
	*/

	// 실습
	//	1. 입력을 받는다(월(月) 정수로 입력 받음)
	//	2. 3~5는 봄 출력
	//	3. 6~8은 여름 출력
	//	4. 9~11은 가을 출력
	//	5. 그 외 겨울
	
	int month;
	
	std::cout << "달을 입력해주세요 : ";
	std::cin >> month;
	
	if ((1 <= month && month <= 2) || (month == 12)) {
			std::cout << "겨울" << std::endl;
	}
	else if (3 <= month && month <= 5) {
		std::cout << "봄" << std::endl;
	}
	else if (6 <= month && month <= 8) {
		std::cout << "여름" << std::endl;
	}
	else if (9 <= month && month <= 11) {
		std::cout << "가을" << std::endl;
	}
	else {
		std::cout << "12달에 맞는 달을 입력하세요" << std::endl;
	}


	
	/*
	// 테스트 케이스
	for (month = -1; month < 14; month++) {
		std::cout << month << "달로 입력된 상태입니다. " << std::endl;
		if ((0 < month && month < 3) || (month == 12)) {
			std::cout << "겨울" << std::endl;
		}
		else if (2 < month && month < 6) {
			std::cout << "봄" << std::endl;
		}
		else if (5 < month && month < 9) {
			std::cout << "여름" << std::endl;
		}
		else if (8 < month && month < 12) {
			std::cout << "가을" << std::endl;
		}
		else {
			std::cout << "12달에 맞는 달을 입력하세요" << std::endl;
		}
		std::cout << std::endl;
	}
	*/
	
	// 내가 입력한 점수가 유효하고 유효한 점수 내에서 합격이라는 기준이 60점 이상이다
	// 60점 이상에서 학점을 구분한다면
	int input;

	std::cout << "점수 입력 : "; std::cin >> input;

	// 유효한 점수인가?
	if (0 <= input && input <= 100) {
		if (input >= 60) {
			std::cout << "합격입니다" << std::endl;
			if (input >= 90) {
				std::cout << "A학점" << std::endl;
			}
			else if (input >= 80) {
				std::cout << "B학점" << std::endl;
			}
			else if (input >= 70) {
				std::cout << "C학점" << std::endl;
			}
			else {
				std::cout << "D학점" << std::endl;
			}
		}
		else {
			std::cout << "불합격입니다" << std::endl;
		}
	}
	else {
		std::cout << "유효한 점수값이 아닙니다" << std::endl;
	}

	int inputNum;
	std::cin >> inputNum;
	if ((inputNum % 2) == 0) {
		// 짝수일경우 진입
	}
	else {

	}

	//char a[] = { '■' };
	
}