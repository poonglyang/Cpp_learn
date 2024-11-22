/*
String
	C++에서 제공하는 문자열을 다루기 위한 클래스
	C 스타일의 문자배열보다 쉽고 안전하고 유용하다
	내부적으로 동적 배열을 사용하고 크기는 자동으로 조절한다
	문자열 비교, 연결, 부분 문자열 추출, 검색, 수정 등 다양한 연산을 지원한다
	메모리를 동적으로 관리 하기 때문에 대규모 문자열 작업에서 메모리 오버헤드가 될 수 있다.
	크기 변경이 자주 발생하는 경우, 재할당 비용으로 인해 성능저하가 있을 수 있다.
	문자열이 짧으면 동적 메모리 할당을 피하고 스택에 저장하여 알아서 최적화 한다 (SSO(small string optimization))


*/
#include <iostream>

int main() {
	std::string str1 = "hello";
	std::string str2 = "World";

	std::string str3;

	// 문자열 길이 계산
	std::cout << "str1의 길이 : " << str1.length() << std::endl;
	std::cout << "str2의 길이 : " << str2.size() << std::endl;
	
	// 문자열 연결
	str3 = str1 + ", " + str2 + "!";
	std::cout << "연결 : " << str3 << std::endl;

	// 부분 문자열 추출
	std::string sub = str3.substr(0, 5);
	std::cout << "부분 문자열 : " << sub << std::endl;

	// 문자열 바꾸기
	// 문자열의 특정 부분을 다른 문자열로 바꿈
	str3.replace(0, 2, "Hi");		// 0번째 위치에서 2개의 문자를 Hi로 바꿈
	std::cout << "문자열 바꾸기 : " << str3 << std::endl;

	//
	const char* cstr = str3.c_str();
	std::cout << "c언어 스타일로 : " << cstr << std::endl;

	// append : 문자열 끝에 다른 문자열을 추가
	// insert : 지정한 위치에 문자열을 삽입(위치, 삽입할 문자열)
	// erase  : 지정된 위치에서 특정 길이만큼 문자열 삭제(위치, 길이)

	// 문자열 뒤집기
	std::string input;
	std::cin >> input;
	std::reverse(input.begin(), input.end());
	std::cout << input << std::endl;

	// 문자열 내 특정 문자 갯수
	std::string input2;
	std::cout << "문자열을 입력해라 : " << std::endl;
	std::cin >> input2;

	char target;
	int count = 0;
	std::cout << "찾을 문자를 입력해라 : " << std::endl;
	std::cin >> target;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == target) {
			count++;
		}
	}





}