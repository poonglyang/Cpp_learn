/*
String
	C++���� �����ϴ� ���ڿ��� �ٷ�� ���� Ŭ����
	C ��Ÿ���� ���ڹ迭���� ���� �����ϰ� �����ϴ�
	���������� ���� �迭�� ����ϰ� ũ��� �ڵ����� �����Ѵ�
	���ڿ� ��, ����, �κ� ���ڿ� ����, �˻�, ���� �� �پ��� ������ �����Ѵ�
	�޸𸮸� �������� ���� �ϱ� ������ ��Ը� ���ڿ� �۾����� �޸� ������尡 �� �� �ִ�.
	ũ�� ������ ���� �߻��ϴ� ���, ���Ҵ� ������� ���� �������ϰ� ���� �� �ִ�.
	���ڿ��� ª���� ���� �޸� �Ҵ��� ���ϰ� ���ÿ� �����Ͽ� �˾Ƽ� ����ȭ �Ѵ� (SSO(small string optimization))


*/
#include <iostream>

int main() {
	std::string str1 = "hello";
	std::string str2 = "World";

	std::string str3;

	// ���ڿ� ���� ���
	std::cout << "str1�� ���� : " << str1.length() << std::endl;
	std::cout << "str2�� ���� : " << str2.size() << std::endl;
	
	// ���ڿ� ����
	str3 = str1 + ", " + str2 + "!";
	std::cout << "���� : " << str3 << std::endl;

	// �κ� ���ڿ� ����
	std::string sub = str3.substr(0, 5);
	std::cout << "�κ� ���ڿ� : " << sub << std::endl;

	// ���ڿ� �ٲٱ�
	// ���ڿ��� Ư�� �κ��� �ٸ� ���ڿ��� �ٲ�
	str3.replace(0, 2, "Hi");		// 0��° ��ġ���� 2���� ���ڸ� Hi�� �ٲ�
	std::cout << "���ڿ� �ٲٱ� : " << str3 << std::endl;

	//
	const char* cstr = str3.c_str();
	std::cout << "c��� ��Ÿ�Ϸ� : " << cstr << std::endl;

	// append : ���ڿ� ���� �ٸ� ���ڿ��� �߰�
	// insert : ������ ��ġ�� ���ڿ��� ����(��ġ, ������ ���ڿ�)
	// erase  : ������ ��ġ���� Ư�� ���̸�ŭ ���ڿ� ����(��ġ, ����)

	// ���ڿ� ������
	std::string input;
	std::cin >> input;
	std::reverse(input.begin(), input.end());
	std::cout << input << std::endl;

	// ���ڿ� �� Ư�� ���� ����
	std::string input2;
	std::cout << "���ڿ��� �Է��ض� : " << std::endl;
	std::cin >> input2;

	char target;
	int count = 0;
	std::cout << "ã�� ���ڸ� �Է��ض� : " << std::endl;
	std::cin >> target;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == target) {
			count++;
		}
	}





}