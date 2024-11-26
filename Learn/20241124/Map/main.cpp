/*
[Map]
	연관 컨테이너
	Red Black tree
	Key, Value의 쌍으로 저장한다 (pair)
	Key는 컨테이너에 중복저장이 될 수 없으며 중복 저장을 사용하고 싶으면 멀티맵을 사용해야한다
	삽입 될 때마다 자동으로 키가 정렬되어야 한다.

	비선형 구조를 가지고 있다

[unordered_map]
	정렬되지 않는 맵
	내부가 해쉬 테이블을 가지고 있다
	해시에 따라 내부 위치를 가지게 된다

[해시테이블]
	키 - 값 쌍으로 저장
	해시 함수를 사용해서 키를 해시값으로 변환하고 이 값을 기반으로 데이터를 저장하거나 검색하는 방식.
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
	//	두캐의 값을 묶어서 하나의 객체로 사용하는 템플릿 클래스
	//	두개의 서로 다른 타입의 값을 함께 저장할 수 있음
	//	페어는 두개의 멤버를 가지고 있으며 first, second가 있다

	// 1. value_type을 사용해서
	//	기본적인 키 - 값 쌍 타입을 나타낸다.
	//	이 방법은 명시적으로 pair 객체를 생성해서 insert에 전달한다
	//	가독성이 떨어진다
	data.insert(std::map<std::string, int>::value_type("1번째", 30));

	// 2. make_pair
	//	pair 객체를 생성하는 함수 템플릿
	//	템플릿 인자를 자동으로 추론하므로 타입이 명확하지 않을 수 있음
	//	복잡한 타입을 다룰 때는 명시적인 타입선언이 필요할 수 있다	
	data.insert(std::make_pair("2번째", 5));		// std::make_pair("2번째", 5) -> std::pair<string, int> 타입의 객체를 생성해준다


	// 3. pair
	//	키-값 쌍을 명시적으로 생성하여 삽입
	//	명확한 타입선언을 통해 가독성을 높일 수 있음
	data.insert(std::pair<std::string, int>("3번째",50));

	// 4. 객체를 직접 생성
	std::pair<std::string, int> pt1("4번째", 90);
	std::pair<std::string, int> pt2("5번째", 20);
	data.insert(pt1);
	data.insert(pt2);
	data.erase("4번째");

	for (const auto& pair : data) {
		std::cout << "키값 : " << pair.first << ", 데이터 : " << pair.second << std::endl;
	}

	auto it = data.find("3번째");

	if (it != data.end()) {
		std::cout << "찾은 값 : " << it->second << std::endl;
	}

	// count : 주어진 키의 갯수를 반환
	// clear : 맵의 모든 요소 삭제
	// size : 맵의 크기
	// at : 주어진 키의 해당 값을 반환한다. 없으면 예외
	// empty : 비어있는지 없는지 확인 
	std::cout << "키가 \"1번째\"인 것의 갯수 " << data.count("1번째") << std::endl;
	std::cout << "키가 \"4번째\"인 것의 갯수 " << data.count("4번째") << std::endl;

	std::cout << "키가 \"2번째\"인 것의 value " << data["2번째"] << std::endl;

	std::map<std::string, Armor> armorMap;

	armorMap.insert(std::make_pair("helmet", Armor("철모자", 5)));
	armorMap.insert(std::make_pair("shield", Armor("금방패", 2)));
	armorMap.insert(std::make_pair("greaves", Armor("가죽 신발", 5)));
	
	for (const auto& pair : armorMap) {
		std::cout << "키: " << pair.first << std::endl;
		std::cout << "이름 : " << pair.second.GetName() << std::endl;
		std::cout << "방어력 : " << pair.second.GetDefense() << std::endl;
	}

	std::string search;
	std::cout << "검색할 방어구의 키 입력 : ";
	std::cin >> search;

	auto it = armorMap.find(search);

	if (it->first != armorMap.end()->first) {	// pair의 무엇을 비교해야하는지 몰라서
		std::cout << "확인됨" << std::endl;
	}
}