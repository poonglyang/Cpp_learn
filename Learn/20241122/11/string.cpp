/*
String
	C++에서 제공하는 문자열을 다루기 위한 클래스
	C 스타일의 문자배열보다 쉽고 안전하고 유용하다
	내부적으로 동적 배열을 사용하고 크기는 자동으로 조절한다
	문자열 비교, 연결, 부분 문자열 추출, 검색, 수정 등 다양한 연산을 지원한다
	메모리를 동적으로 관리 하기 때문에 대규모 문자열 작업에서 메모리 오버헤드가 될 수 있다.
	크기 변경이 자주 발생하는 경우, 재할당 비용으로 인해 성능저하가 있을 수 있다.
	문자열이 짧으면 동적 메모리 할당을 피하고 스택에 저장하여 알아서 최적화 한다 (SSO(small string optimization)


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

}