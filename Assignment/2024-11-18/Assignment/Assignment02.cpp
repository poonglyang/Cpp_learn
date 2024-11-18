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
/// ������ ¦���� ����ϴ� �Լ�
/// </summary>
/// <param name="str">������ ���ڿ�</param>
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
/// ���忡�� Ư�� ���ڸ� ã�� �� ������ �ε����� ��ȯ�ϴ� �Լ�
/// </summary>
/// <param name="str">����</param>
/// <param name="c">ã�� ����</param>
/// <returns>ã�� ���ڰ� ������ �� ���ڰ� �ִ� �ε����� ��ȯ�ϰ�, ������ -1�� ��ȯ</returns>
int FindChar(char str[], char c) {
	for (int i = 0; i < strlen(str); i++) {
		//cout << strcmp(&str[i], &c) << endl;
		if (str[i] == c) {
			return i;
		}
	}
	return -1;
}