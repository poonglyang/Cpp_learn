#include <iostream>

using namespace std;


void ReverseEven(char str[]);

int FindChar(char str[], char c);

int main() {
	char str1[] = "Hello, World";
	ReverseEven(str1);

	cout << endl << endl;

	char str2[] = "Hello, World";
	cout << FindChar(str2, 'W') << "\t" << FindChar(str2, 'z');


}

/// <summary>
/// 뒤집고 짝수만 출력하는 함수
/// </summary>
/// <param name="str">뒤집을 문자열</param>
void ReverseEven(char str[]) {
	int len = strlen(str);

	char temp;

	for (int i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}

	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			cout << str[i];
		}
	}

}


/// <summary>
/// 문장에서 특정 문자를 찾고 그 문자의 인덱스를 반환하는 함수
/// </summary>
/// <param name="str">문장</param>
/// <param name="c">찾을 문자</param>
/// <returns>찾을 문자가 있으면 그 문자가 있는 인덱스를 반환하고, 없으면 -1를 반환</returns>
int FindChar(char str[], char c) {
	for (int i = 0; i < strlen(str); i++) {
		//cout << strcmp(&str[i], &c) << endl;
		if (str[i] == c) {
			return i;
		}
	}
	return -1;
}