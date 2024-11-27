/*
[Map]
	���� �����̳�
	Red Black tree
	Key, Value�� ������ �����Ѵ� (pair)
	Key�� �����̳ʿ� �ߺ������� �� �� ������ �ߺ� ������ ����ϰ� ������ ��Ƽ���� ����ؾ��Ѵ�
	���� �� ������ �ڵ����� Ű�� ���ĵǾ�� �Ѵ�.

	���� ������ ������ �ִ�

[unordered_map]
	���ĵ��� �ʴ� ��
	���ΰ� �ؽ� ���̺��� ������ �ִ�
	�ؽÿ� ���� ���� ��ġ�� ������ �ȴ�

[�ؽ����̺�]
	Ű - �� ������ ����
	�ؽ� �Լ��� ����ؼ� Ű�� �ؽð����� ��ȯ�ϰ� �� ���� ������� �����͸� �����ϰų� �˻��ϴ� ���.
*/

#include <iostream>

#include <map>

class Armor {
private:
	std::string name;
	int defense;

public:
	Armor() : name(""), defense(0) {}
	Armor(const std::string& name, int defense) : name(name), defense(defense) {}

	std::string GetName() const {
		return name;
	}

	int GetDefense() const {
		return defense;
	}
};


int main() {
	std::map<std::string, int> data;

	std::map<std::string, int>::iterator iter;

	// pair
	//	��ĳ�� ���� ��� �ϳ��� ��ü�� ����ϴ� ���ø� Ŭ����
	//	�ΰ��� ���� �ٸ� Ÿ���� ���� �Բ� ������ �� ����
	//	���� �ΰ��� ����� ������ ������ first, second�� �ִ�

	// 1. value_type�� ����ؼ�
	//	�⺻���� Ű - �� �� Ÿ���� ��Ÿ����.
	//	�� ����� ��������� pair ��ü�� �����ؼ� insert�� �����Ѵ�
	//	�������� ��������
	data.insert(std::map<std::string, int>::value_type("1��°", 30));

	// 2. make_pair
	//	pair ��ü�� �����ϴ� �Լ� ���ø�
	//	���ø� ���ڸ� �ڵ����� �߷��ϹǷ� Ÿ���� ��Ȯ���� ���� �� ����
	//	������ Ÿ���� �ٷ� ���� ������� Ÿ�Լ����� �ʿ��� �� �ִ�	
	data.insert(std::make_pair("2��°", 5));		// std::make_pair("2��°", 5) -> std::pair<string, int> Ÿ���� ��ü�� �������ش�


	// 3. pair
	//	Ű-�� ���� ��������� �����Ͽ� ����
	//	��Ȯ�� Ÿ�Լ����� ���� �������� ���� �� ����
	data.insert(std::pair<std::string, int>("3��°",50));

	// 4. ��ü�� ���� ����
	std::pair<std::string, int> pt1("4��°", 90);
	std::pair<std::string, int> pt2("5��°", 20);
	data.insert(pt1);
	data.insert(pt2);
	data.erase("4��°");

	for (const auto& pair : data) {
		std::cout << "Ű�� : " << pair.first << ", ������ : " << pair.second << std::endl;
	}

	auto it = data.find("3��°");

	if (it != data.end()) {
		std::cout << "ã�� �� : " << it->second << std::endl;
	}

	// count : �־��� Ű�� ������ ��ȯ
	// clear : ���� ��� ��� ����
	// size : ���� ũ��
	// at : �־��� Ű�� �ش� ���� ��ȯ�Ѵ�. ������ ����
	// empty : ����ִ��� ������ Ȯ�� 
	std::cout << "Ű�� \"1��°\"�� ���� ���� " << data.count("1��°") << std::endl;
	std::cout << "Ű�� \"4��°\"�� ���� ���� " << data.count("4��°") << std::endl;

	std::cout << "Ű�� \"2��°\"�� ���� value " << data["2��°"] << std::endl;

	std::map<std::string, Armor> armorMap;

	armorMap.insert(std::make_pair("helmet", Armor("ö����", 5)));
	armorMap.insert(std::make_pair("shield", Armor("�ݹ���", 2)));
	armorMap.insert(std::make_pair("greaves", Armor("���� �Ź�", 5)));
	
	for (const auto& pair : armorMap) {
		std::cout << "Ű: " << pair.first << std::endl;
		std::cout << "�̸� : " << pair.second.GetName() << std::endl;
		std::cout << "���� : " << pair.second.GetDefense() << std::endl;
	}

	std::string search;
	std::cout << "�˻��� ���� Ű �Է� : ";
	std::cin >> search;

	auto it = armorMap.find(search);

	if (it->first != armorMap.end()->first) {	// pair�� ������ ���ؾ��ϴ��� ����
		std::cout << "Ȯ�ε�" << std::endl;
	}
}