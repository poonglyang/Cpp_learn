//-주석 ----------------------
// 컴파일러가 무시함
// 소스코드에 영향을 주지 않게 하기 위할 때
// 소스코드를 설명하기 위한 용도

// 주석 1
/* 
	주석 2
	범위 주석을 나타낸다
	내용
	내용
	주석 2
*/

/// <summary>
/// 주석 3
/// 함수 또는 변수가 무었인지 나타내는 주석
/// </summary>
/// <param name="a">그냥 넣은거</param>
/// <returns>a를 반환한다</returns>
int testDef(int a) {
	return a;
}

#include <iostream>		// include : 지시문에 포함된 헤더파일의 내용을 현재 파일에 포함한다
						// iostream(input output stream) : C++의 표준 라이브러리
						// <> : 시스템 헤더에서 사용(C++을 설치한 폴더에서 헤더파일을 찾음)
						// "" : 유저의 헤더에서 사용(프로젝트 폴더에서 헤더파일을 찾음)

// using namespace std;	// 전역 공간에 있는 것, std라는 이름 공간에 있는 것을 사용하겠다.

/// <summary>
/// main 함수란? 
/// 프로그램의 시작점을 알려주는 함수
/// 반드시 있어야 실행이 된다. 근데 생성자가 있는 일반 파일은?
/// 반드시 1개의 main함수를 포함해야 한다.
/// </summary>
/// <returns>항상 0을 반환</returns>
int main() {		// { 시작

	// 작성될 장소

	// cout	: (consolOut) C++에서 표준 출력 스트림을 나타내는 객체, 콘솔에 데이터를 출력할 때 사용
	//		: iostream 헤더파일에 포함되어 있는 함수
	// <<	: cout에 값을 전달한다는 의미로 사용
	// endl	: (endLine) 줄바꿈을 나타낸다
	std::cout << "이걸 출력하자";
	std::cout << "이걸 출력하자22" << std::endl;
	
	std::cout << 1 << std::endl;
	std::cout << 3.14 << std::endl;

	// 내가 무언가를 때렸을 경우
	float enemyHp = 100.1;

	std::cout << "적의 채력이 "<< enemyHp - 10.1 << "가 되었다" << std::endl;

	



	return 0;
}					// } 끝



