/*
C에서의 대표적인 문자열 관련 함수들
	strlen(const char* str) : 문자열의 길이를 반환한다
	strcpy(char* dest, const char* src) : 문자열 src를 dest로 복사
	strcat(char* dest, const char* src) : 문자열 src를 dest 끝에 이어붙인다(문자열 + 문자열)
	strcmp(const char* str1, const char* str2) : str1과 str2 문자열을 사전순으로 비교, 동일하면 0, str1이 str2 보다 작으면 음수, 크면 양수를 리턴한다

*/

#include <iostream>
using namespace std;


void ReverseStr(char str[]) {
	int len = strlen(str);

	char temp;

	// 반복문을 통해 문자열의 반까지만 반복
	// 각 반복에서 앞쪽 문자를 임시변수 temp에 저장
	// 문자열의 뒤쪽 문자를 앞쪽으로 이동
	// 임시변수에 저장된 문자를 뒤쪽으로 이동

	for (int i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main() {
	string a = "wlrmaango";
	string b;

	const char* str = "Hello";
	char str1[10] = "abcd";
	
	cout << strlen(str) << endl;
	cout << strlen(str1) << endl;

	const char* strcmp1 = "aaa";
	const char* strcmp2 = "aaa";

	cout << strcmp(strcmp1, strcmp2) << endl;	// 0
	cout << strcmp("aab", "aaa") << endl;		// 1	97 97 98  /  97 97 97 순서대로 비교하고 다른게 나오면 아스키 코드 값을 비교해 1, -1출력
	cout << strcmp("aab", "aac") << endl;		// -1
	cout << (strcmp1 == strcmp2) << endl;		// 1

	char strcpy1[10] = "Hello";
	char strcpy2[10];

	strcpy_s(strcpy2, strcpy1);	// strcpy1을 앞에 넣어 없는 것을 복사할려고 했었다


	//cout << strcpy << endl;

	char s1[10] = "world";
	char s2[11] = "Hello";
	strcat_s(s2, s1);			// 합칠 경우의 크기를 벗어났기에 에러가 생겼다
	cout << s2 << endl;

	char str3[] = "Hello, World";
	ReverseStr(str3);
	cout << str3 << endl;
}