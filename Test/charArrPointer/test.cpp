#include<iostream>

using namespace std;
void ReverseStrEven(char str[]) {
	int len = strlen(str);
	char str1[100] = {};
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

	cout << "str1[30]ÀÇ °ª : " << str1[30] << endl;

	for (int i = 0; i < len; i++) {

		str[i] = str1[i];
	}

	cout << str1 << endl;
}

int main() {
	char str[] = "Hello, World";
	cout << str << endl;
	ReverseStrEven(str);
	cout << str << endl;
}