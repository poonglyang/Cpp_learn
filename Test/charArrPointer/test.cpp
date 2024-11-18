#include<iostream>

using namespace std;
void ReverseStrEven(char str[]) {
	int len = strlen(str);
	char str1[11] = {};
	char temp;
	for (int i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}

	cout << endl;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (i % 2 != 0)
		{
			str1[count] = str[i];
			count++;
		}
	}

	cout << "str1[11]의 값 : " << str1[10] << endl;

	for (int i = 0; i < len; i++) {

		str[i] = str1[i];
	}

	cout << "배열 값 : " << str1 << ", 이 배열의 크기 " << sizeof(str1) << endl;
}

int main() {
	char str[] = "Hello, World";
	cout << "str의 값 : " << str << "str의 크기 : " << sizeof(str) << endl;
	ReverseStrEven(str);
	cout << "str의 값 : " << str << "str의 크기 : " << sizeof(str) << endl;
}