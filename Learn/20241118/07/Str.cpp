/*
C������ ��ǥ���� ���ڿ� ���� �Լ���
	strlen(const char* str) : ���ڿ��� ���̸� ��ȯ�Ѵ�
	strcpy(char* dest, const char* src) : ���ڿ� src�� dest�� ����
	strcat(char* dest, const char* src) : ���ڿ� src�� dest ���� �̾���δ�(���ڿ� + ���ڿ�)
	strcmp(const char* str1, const char* str2) : str1�� str2 ���ڿ��� ���������� ��, �����ϸ� 0, str1�� str2 ���� ������ ����, ũ�� ����� �����Ѵ�

*/

#include <iostream>
using namespace std;


void ReverseStr(char str[]) {
	int len = strlen(str);

	char temp;

	// �ݺ����� ���� ���ڿ��� �ݱ����� �ݺ�
	// �� �ݺ����� ���� ���ڸ� �ӽú��� temp�� ����
	// ���ڿ��� ���� ���ڸ� �������� �̵�
	// �ӽú����� ����� ���ڸ� �������� �̵�

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
	cout << strcmp("aab", "aaa") << endl;		// 1	97 97 98  /  97 97 97 ������� ���ϰ� �ٸ��� ������ �ƽ�Ű �ڵ� ���� ���� 1, -1���
	cout << strcmp("aab", "aac") << endl;		// -1
	cout << (strcmp1 == strcmp2) << endl;		// 1

	char strcpy1[10] = "Hello";
	char strcpy2[10];

	strcpy_s(strcpy2, strcpy1);	// strcpy1�� �տ� �־� ���� ���� �����ҷ��� �߾���


	//cout << strcpy << endl;

	char s1[10] = "world";
	char s2[11] = "Hello";
	strcat_s(s2, s1);			// ��ĥ ����� ũ�⸦ ����⿡ ������ �����
	cout << s2 << endl;

	char str3[] = "Hello, World";
	ReverseStr(str3);
	cout << str3 << endl;
}