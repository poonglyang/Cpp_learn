/*

switch - case ��
	���� ������ ó���ؾ��� �� ����ϴ� ���ǹ� �� �ϳ�.
	�ַ� ��� ���� �������� �б��� �� ���Ǹ�, �������� ����

����
	�ϳ��� ������ �˻��ϰ� �� ������ ���� ���� ���� case ��� �� �ϳ��� ����
	break Ű���带 ���� �� case�� ������ ����
	break�� ������ ���� case ����� �����ؼ� ����ȴ�
	ǥ���Ŀ��� ����, ����, ����Ÿ�� ���� ���´�.

���
	������� �������� ���� ������ �� �ϳ��� �����ϴ� ��Ȳ���� ����ϱ� ����.
	�ڵ��� �������� ���̰� ȿ������ ������ ���� ������ ǥ���Ŀ� ������ �ִ�
	���� ��� �񱳴� �Ұ� (10 < x < 20 ��)
	if ���� ���������� �پ��� ������ �ٷ�⿡ ����.

switch(ǥ����){
	case ǥ������ ����� �� 1:
		�ش�Ǵ� �ڵ�
		break;
	case ǥ������ ����� �� 2:
		�ش�Ǵ� �ڵ�
		break;
	default:
		� case���� �ش���� ���� ��� ����Ǵ� �ڵ�
		break;
}

break��?
	�ݺ����̳� switch ���� ������ �� ���
	break�� ����Ǹ� �ش� ������ switch���� �����ϰ� break �������� �̵��Ͽ� �����Ѵ�
	���� switch�� ��ø�ݺ��������� break�� �ִ� �ش� �������� ����������

*/

#include <iostream>


enum MyActive {
	a,b,c,d
};

int main() {
	/*
	MyActive active = d;

	switch (active)
	{
	case a:
		break;
	case b:
		break;
	case c:
		break;
	case d:
		break;
	default:
		break;
	}
	*/

	/*
	int choice;
	std::cout << "������ �����ϼ���! " << std::endl;
	std::cout << "1. ��\n2. �߷ζ�Ʈ\n3. ������ġ\n4. ��Ÿ\n5. ���4" << std::endl;

	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "�� ����" << std::endl;
		break;
	case 2:
		std::cout << "�߷ζ�Ʈ ����" << std::endl;
		break;
	case 3:
		std::cout << "������ġ ����" << std::endl;
		break;
	case 4:
		std::cout << "��Ÿ ����" << std::endl;
		break;
	case 5:
		std::cout << "���4 ����" << std::endl;
		break;
	default :
		std::cout << "�Է°��� �߸��� ����" << std::endl;
		break;
	}
	*/

	int jobChoice;

	int skillChoice;

	std::cout << "������ ������ �ּ���(1. ����, 2. ������, 3. ����) : ";
	std::cin >> jobChoice;

	switch (jobChoice)
	{
	case 1:
		std::cout << "���縦 �����ߴ�. � ��ų�� ����ұ�? (1. �뽬. 2. ����) : ";
		std::cin >> skillChoice;
		switch (skillChoice)
		{
		case 1:
			std::cout << "�뽬 ����" << std::endl;
			break;
		case 2:
			std::cout << "���� ����" << std::endl;
			break;
		default:
			std::cout << "����� ���� �յΰ� ������ ���� ���ߴ�... ����� ���� ���Ҵ�" << std::endl;
			break;
		}
		break;
	case 2:
		std::cout << "�����縦 �����ߴ�. � ��ų�� ����ұ�? (1. ���̾. 2. ��������) : ";
		std::cin >> skillChoice;
		switch (skillChoice)
		{
		case 1:
			std::cout << "���̾" << std::endl;
			break;
		case 2:
			std::cout << "��������" << std::endl;
			break;
		default:
			std::cout << "����� ���� �յΰ� ������ ���� ���ߴ�... ����� ���� ���Ҵ�" << std::endl;
			break;
		}
		break;
	case 3:
		std::cout << "������ �����ߴ�. � ��ų�� ����ұ�? (1. ���. 2. ����ϰ� ���) : ";
		std::cin >> skillChoice;
		switch (skillChoice)
		{
		case 1:
			std::cout << "���" << std::endl;
			break;
		case 2:
			std::cout << "����ϰ� ��� ����" << std::endl;
			break;
		default:
			std::cout << "����� ���� �յΰ� ������ ���� ���ߴ�... ����� ���� ���Ҵ�" << std::endl;
			break;
		}
		break;

	default:
		std::cout << "����� ������ �����ߴ�" << std::endl;
		break;
	}

}