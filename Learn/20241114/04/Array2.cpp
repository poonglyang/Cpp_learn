#include <iostream> 
#include <algorithm>

int main() {
	srand(time(0));

	int intArr1[10];

	// 초기화
	for (int i = 0; i < 10; i++) {
		intArr1[i] = i;
	}

	// 셔플전
	std::cout << "셔플 전" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << i << ", " << std::endl;
	}

	std::cout << std::endl;

	// 셔플용 변수들
	int dest, sour, temp;

	for (int i = 0; i < 1000; i++) {
		dest = rand() % 10;
		sour = rand() % 10;

		std::cout << std::endl << dest << ", " << sour << std::endl;

		temp = intArr1[dest];
		intArr1[dest] = intArr1[sour];
		intArr1[sour] = temp;
	}

	// 셔플후
	std::cout << "셔플 후" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout <<  i << " " << intArr1[i];
	}

	// 로또 번호 만들기
	std::cout << std::endl;

	int lottoNumberArr[45];
	int lottoArr[6];

	for (int i = 0; i < 45; i++) {
		lottoNumberArr[i] = i + 1;
	}

	for (int i = 0; i < 777; i++) {
		dest = rand() % 45;
		sour = rand() % 45;

		temp = lottoNumberArr[dest];
		lottoNumberArr[dest] = lottoNumberArr[sour];
		lottoNumberArr[sour] = temp;
	}

	std::cout << "이번주 로또 번호는 ";

	for (int i = 0; i < 6; i++) {
		lottoArr[i] = lottoNumberArr[i];
	}
	std::sort(lottoArr, lottoArr + 6);

	for (int i = 0; i < 6; i++) {
		std::cout << lottoArr[i] << ", ";
	}

	std::cout << "입니다!" << std::endl;

	// 실습
	// 10명의 학생 성적을 입력. 배열에 저장하고 총점과 평균을 구해라
	std::cout << "\n학생의 점수를 10개 입력하세요 : ";

	int scores[10];
	int sum = 0;
	for (int i = 0; i < sizeof(scores) / sizeof(int); i++) {
		std::cin >> scores[i];
		sum += scores[i];
	}

	std::cout << "총점 : " << sum << ", 평균 : " << sum / (sizeof(scores) / sizeof(int)) << std::endl;

	
}