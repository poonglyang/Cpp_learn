#include "ItemManager.h"

ItemManager::ItemManager()
{
#pragma region 장비 아이템 추가 부분
#pragma region 초보자용 검
	Item_Equipable equipable_Item = Item_Equipable(
		1, "초보자용 검", 10, (int)itemDatas::ItemType::Equipable,
		"검에 막 입문한 초보자가 쓰기 좋은 검",
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,
		20, 0, 7, 3, 5, 0, 0, 5, 0, 0, 10);
	
	equipable_Items.push_back(equipable_Item);

#pragma endregion 초보자용 검

#pragma region 초보자용 단검
	equipable_Item = Item_Equipable(
		2,		// 아이템 id
		"초보자용 단검",		// 아이템 설명
		10,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"단검에 막 입문한 초보자가 쓰기 좋은 양손검",		// 아이템 설명
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,	// 아이템 장착 부위
		10,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		3,		// 장착시 추가 atk
		20,		// 장착시 추가 크확
		15,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		10,		// 장착시 추가 명중률
		5,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		20		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 초보자용 단검

#pragma region 초보자용 창
	equipable_Item = Item_Equipable(
		3,		// 아이템 id
		"초보자용 창",		// 아이템 설명
		10,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"창에 막 입문한 초보자가 쓰기 좋은 창",		// 아이템 설명
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,	// 아이템 장착 부위
		20,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		4,		// 장착시 추가 atk
		10,		// 장착시 추가 크확
		10,		// 장착시 추가 크뎀증
		10,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		7,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		12		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 초보자용 창

#pragma region 초보자용 둔기
	equipable_Item = Item_Equipable(
		4,		// 아이템 id
		"초보자용 둔기",		// 아이템 설명
		10,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"둔기에 막 입문한 초보자가 쓰기 좋은 둔기",		// 아이템 설명
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,	// 아이템 장착 부위
		25,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		8,		// 장착시 추가 atk
		3,		// 장착시 추가 크확
		3,		// 장착시 추가 크뎀증
		3,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		3,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		5		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 초보자용 둔기

#pragma region 초보자용 활
	equipable_Item = Item_Equipable(
		5,		// 아이템 id
		"초보자용 활",		// 아이템 설명
		10,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"활에 막 입문한 초보자가 쓰기 좋은 활",		// 아이템 설명
		(int)itemDatas::EquipSlot::Weapon_Right,	// 아이템 장착 부위
		18,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		8,		// 장착시 추가 atk
		10,		// 장착시 추가 크확
		10,		// 장착시 추가 크뎀증
		10,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		15,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		4		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 초보자용 활

#pragma region 초보자용 방패
	equipable_Item = Item_Equipable(
		6,		// 아이템 id
		"초보자용 방패",		// 아이템 설명
		10,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"초보자가 쓰기 좋은 방패",		// 아이템 설명
		(int)itemDatas::EquipSlot::Weapon_Left,	// 아이템 장착 부위
		50,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		0,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		20,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		-5,		// 장착시 추가 회피율
		10,		// 장착시 추가 방패 막기 확률
		0		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 초보자용 방패

#pragma region 초보자용 지팡이
	equipable_Item = Item_Equipable(
		7,		// 아이템 id
		"초보자용 지팡이",		// 아이템 설명
		10,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"마법에 막 입문한 초보자가 쓰기 좋은 지팡이",		// 아이템 설명
		(int)itemDatas::EquipSlot::Weapon_Right,	// 아이템 장착 부위
		0,		// 장착시 추가 hp
		50,		// 장착시 추가 mp
		30,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		-10,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		-10,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		-10		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 초보자의 지팡이

#pragma region 철 단검
	equipable_Item = Item_Equipable(
		8,		// 아이템 id
		"철 단검",		// 아이템 설명
		50,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"질좋은 철로 만든 단검",		// 아이템 설명
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,			// 아이템 장착 부위
		50,		// 장착시 추가 hp
		10,		// 장착시 추가 mp
		30,		// 장착시 추가 atk
		30,		// 장착시 추가 크확
		15,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		20,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 초보자용 양손검

#pragma region 철 한손검
	equipable_Item = Item_Equipable(
		9,		// 아이템 id
		"철 한손검",		// 아이템 설명
		50,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"질 좋은 철로 만든 단검",		// 아이템 설명
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,			// 아이템 장착 부위
		80,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		50,		// 장착시 추가 atk
		20,		// 장착시 추가 크확
		10,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		15,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 철 한손검

#pragma region 철 창
	equipable_Item = Item_Equipable(
		10,		// 아이템 id
		"철 창",		// 아이템 설명
		50,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"질 좋은 철로 만든 창",		// 아이템 설명
		(int)itemDatas::EquipSlot::Weapon_Both_OneHand,			// 아이템 장착 부위
		70,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		40,		// 장착시 추가 atk
		35,		// 장착시 추가 크확
		22,		// 장착시 추가 크뎀증
		10,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		70,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 철 창

#pragma region 나무 갑옷
	equipable_Item = Item_Equipable(
		11,		// 아이템 id
		"나무 갑옷",		// 아이템 설명
		10,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"나무로 만든 갑옷",		// 아이템 설명
		(int)itemDatas::EquipSlot::Armor_Top,			// 아이템 장착 부위
		100,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		0,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		10,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 나무 갑옷

#pragma region 철 갑옷
	equipable_Item = Item_Equipable(
		12,		// 아이템 id
		"철 갑옷",		// 아이템 설명
		50,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"질 좋은 철로 만든 갑옷",		// 아이템 설명
		(int)itemDatas::EquipSlot::Armor_Top,			// 아이템 장착 부위
		200,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		0,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		50,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 철 갑옷

#pragma region 나무 각반
	equipable_Item = Item_Equipable(
		13,		// 아이템 id
		"나무 각반",		// 아이템 설명
		10,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"나무로 만든 각반",		// 아이템 설명
		(int)itemDatas::EquipSlot::Armor_Bottom,			// 아이템 장착 부위
		80,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		0,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		8,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 나무 각반

#pragma region 철 각반
	equipable_Item = Item_Equipable(
		14,		// 아이템 id
		"나무 각반",		// 아이템 설명
		50,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"질 좋은 철로 만든 각반",		// 아이템 설명
		(int)itemDatas::EquipSlot::Armor_Bottom,			// 아이템 장착 부위
		160,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		0,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		20,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 철 각반


#pragma region 나무 헬멧
	equipable_Item = Item_Equipable(
		15,		// 아이템 id
		"나무 헬멧",		// 아이템 설명
		10,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"나무로 만든 헬멧",		// 아이템 설명
		(int)itemDatas::EquipSlot::Helmet,			// 아이템 장착 부위
		30,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		0,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		10,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 나무 헬멧

#pragma region 철 헬멧
	equipable_Item = Item_Equipable(
		16,		// 아이템 id
		"철 헬멧",		// 아이템 설명
		50,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"질 좋은 철로 만든 헬멧",		// 아이템 설명
		(int)itemDatas::EquipSlot::Helmet,			// 아이템 장착 부위
		65,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		0,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		33,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 철 헬멧

#pragma region 채력의 반지
	equipable_Item = Item_Equipable(
		17,		// 아이템 id
		"채력의 반지",		// 아이템 설명
		200,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"채력을 대폭 올려주는 반지",		// 아이템 설명
		(int)itemDatas::EquipSlot::Ring,			// 아이템 장착 부위
		500,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		0,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 채력의 반지

#pragma region 마나의 반지
	equipable_Item = Item_Equipable(
		18,		// 아이템 id
		"마나의 반지",		// 아이템 설명
		200,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"마나을 대폭 올려주는 반지",		// 아이템 설명
		(int)itemDatas::EquipSlot::Ring,			// 아이템 장착 부위
		0,		// 장착시 추가 hp
		500,		// 장착시 추가 mp
		0,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 마나의 반지

#pragma region 공격력의 반지
	equipable_Item = Item_Equipable(
		19,		// 아이템 id
		"공격력의 반지",		// 아이템 설명
		300,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"공격력을 대폭 올려주는 반지",		// 아이템 설명
		(int)itemDatas::EquipSlot::Ring,			// 아이템 장착 부위
		0,		// 장착시 추가 hp
		0,		// 장착시 추가 mp
		200,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		0,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		0,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 공격력의 반지

#pragma region 오색찬란 반지
	equipable_Item = Item_Equipable(
		20,		// 아이템 id
		"오색찬란 반지",		// 아이템 설명
		150,		// 가격
		(int)itemDatas::ItemType::Equipable,			// 아이템 타입
		"여려 능력치를 골고루 올려주는 아이템",		// 아이템 설명
		(int)itemDatas::EquipSlot::Ring,			// 아이템 장착 부위
		100,		// 장착시 추가 hp
		100,		// 장착시 추가 mp
		50,		// 장착시 추가 atk
		0,		// 장착시 추가 크확
		20,		// 장착시 추가 크뎀증
		0,		// 장착시 추가 방무
		70,		// 장착시 추가 방어력
		0,		// 장착시 추가 명중률
		0,		// 장착시 추가 회피율
		0,		// 장착시 추가 방패 막기 확률
		1		// 장착시 추가 행동력
	);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 오색찬란 반지

#pragma region 정체 모를 목걸이
	equipable_Item = Item_Equipable(
		2, "정체 모를 아이템", 99999999, (int)itemDatas::ItemType::Equipable,
		"신화시대 때 만들어졌을  추측되는 목걸이\n\t부조리하다고 생각될 정도로 많은 능력치를 올린다",
		(int)itemDatas::EquipSlot::Necklace,
		10000, 10000, 999, 999, 999, 999, 999, 999, 999, 999, 999);

	equipable_Items.push_back(equipable_Item);
#pragma endregion 솔직히 그냥 개발자용 목걸이

#pragma endregion 장비 아이템 추가 부분

#pragma region 소비 아이템 추가 부분
#pragma region 소형 hp 포션
	Item_Consumables consumable = Item_Consumables (
		100001, "소형 hp 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables, 
		"hp 50을 즉시 채워줍니다", 50, 0,0,0,0,0,0,0,0,0,0,0,0);

	consumables_Items.push_back(consumable);
#pragma endregion 소형 hp 포션

#pragma region 소형 mp 포션
	consumable = Item_Consumables(
		100002, "소형 mp 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"mp 50을 즉시 채워줍니다",0,0,50,0,0,0, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 소형 mp 포션

#pragma region 최대 채력 증가 포션
	consumable = Item_Consumables(
		100003, "최대 채력 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"최대hp 30 올립니다", 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 최대 채력 증가 포션

#pragma region 최대 마나 증가 포션
	consumable = Item_Consumables(
		100004, "최대 마나 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"최대mp 30 올립니다", 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 최대 마나 증가 포션

#pragma region 공격력 증가 포션
	consumable = Item_Consumables(
		100005, "공격력 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"공격력을 10 올립니다", 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 공격력 증가 포션

#pragma region 방어력 증가 포션
	consumable = Item_Consumables(
		100006, "방어력 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"방어력을 10 올립니다", 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 방어력 증가 포션

#pragma region 방어력 무시 증가 포션
	consumable = Item_Consumables(
		100007, "방어력 무시 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"방어력을 5% 더 무시합니다", 0, 0, 0, 0, 0, 0, 0, 0, 0.05f, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 방어력 무시 증가 포션

#pragma region 명중률 증가 포션
	consumable = Item_Consumables(
		100008, "명중률 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"명중률이 7% 더 상승합니다", 0,0,0,0,0,0,0,0,0,0.07f,0,0,0);

	consumables_Items.push_back(consumable);
#pragma endregion 명중률 증가 포션

#pragma region 크리티컬 확률 증가 포션
	consumable = Item_Consumables(
		100009, "크리티컬 확률 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"크리티컬 확률이 7% 더 상승합니다", 0, 0, 0, 0, 0, 0, 0.07f, 0, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 크리티컬 확률 증가 포션

#pragma region 크리티컬 데미지 증가 포션
	consumable = Item_Consumables(
		100010, "크리티컬 데미지 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"크리티컬 데미지가 10% 더 상승합니다", 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 크리티컬 데미지 증가 포션

#pragma region 회피 확률 증가 포션
	consumable = Item_Consumables(
		100011, "회피 확률 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"회피 확률이 5% 더 상승합니다", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.05f, 0, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 회피 확률 증가 포션

#pragma region 방어 확률 증가 포션
	consumable = Item_Consumables(
		100012, "방어 확률 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"방어 확률이 5% 더 상승합니다", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.05f, 0);

	consumables_Items.push_back(consumable);
#pragma endregion 방어 확률 증가 포션

#pragma region 행동력 증가 포션
	consumable = Item_Consumables(
		100013, "행동력 증가 포션", 1, 10, 30, (int)itemDatas::ItemType::Consumables,
		"행동력이 1% 증가합니다", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);

	consumables_Items.push_back(consumable);
#pragma endregion 행동력 확률 증가 포션

#pragma endregion

#pragma region 재료 아이템 추가 부분
#pragma region 깃털
	Item_Material misc = Item_Material(
		200001, "깃털", 1, 30, 1, (int)itemDatas::ItemType::Materials, 
		"새가 있다는 증명");

	material_Items.push_back(misc);
#pragma endregion 깃털

#pragma region 돌맹이
	misc = Item_Material(
		200002, "돌맹이", 1, 30, 2, (int)itemDatas::ItemType::Materials, 
		"어디에나 굴러다니는 돌맹이");

	material_Items.push_back(misc);
#pragma endregion 돌맹이

#pragma region 나무
	misc = Item_Material(
		200003, "나무", 1, 30, 5, (int)itemDatas::ItemType::Materials, 
		"우주적 관점으로 가장 희귀한 재료");

	material_Items.push_back(misc);
#pragma endregion 나무

#pragma region 잡철
	misc = Item_Material(
		200004, "잡철", 1, 30, 3, (int)itemDatas::ItemType::Materials,
		"불순물이 많이 섞인 철");

	material_Items.push_back(misc);
#pragma endregion 잡철

#pragma region 철괴
	misc = Item_Material(
		200005, "철괴", 1, 30, 15, (int)itemDatas::ItemType::Materials,
		"철로 된 괴");

	material_Items.push_back(misc);
#pragma endregion 철괴

#pragma region 허브
	misc = Item_Material(
		200006, "허브", 1, 30, 8, (int)itemDatas::ItemType::Materials,
		"연금술에 쓰이는 약초");

	material_Items.push_back(misc);
#pragma endregion 허브

#pragma region 가죽
	misc = Item_Material(
		200007, "가죽", 1, 30, 7, (int)itemDatas::ItemType::Materials,
		"정체 모를 것의 가죽");

	material_Items.push_back(misc);
#pragma endregion 가죽

#pragma region 마석
	misc = Item_Material(
		200008, "마석", 1, 30, 30, (int)itemDatas::ItemType::Materials,
		"마나가 많이 모인 돌");

	material_Items.push_back(misc);
#pragma endregion 마석

#pragma region 유령 실크
	misc = Item_Material(
		200009, "유령 실크", 1, 30, 22, (int)itemDatas::ItemType::Materials,
		"안이 흐릿하게 보이는 실크");

	material_Items.push_back(misc);
#pragma endregion 유령 실크

#pragma endregion

	// 절대 반환되면 안되는 아이템
	fuck = new ItemBase(-999, "Error", 0, 0, 0, -999, "Error아이템 에초에 존재 자체가 불가능함");
}

int ItemManager::GetItemMaxCountById(int id)
{
	int itemType = id / 100000;
	int index = id - itemType * 100000 - 1;
	if (id < 100000) {
		return 1;
	}
	else if (id < 200000) {
		return consumables_Items[index].GetItemMaxCount();
	}
	else if (id < 300000) {
		return material_Items[index].GetItemMaxCount();
	}
	else {
		//제발 이거 출력되면 ㅈ됨
		return 0;
	}
}

Item_Equipable* ItemManager::GetEquipableItemByIndex(int index)
{
	Item_Equipable* deepCopyItem = new Item_Equipable(equipable_Items[index]);
	return deepCopyItem;
}

Item_Equipable* ItemManager::GetEquipableItem(int id)
{
	int itemType = id / 100000;
	int index = id - itemType * 100000 - 1;

	Item_Equipable* deepCopyItem = new Item_Equipable(equipable_Items[index]);

	return deepCopyItem;
}

Item_Consumables* ItemManager::GetConsumableItemByIndex(int index, int count)
{
	Item_Consumables* deepCopyItem = new Item_Consumables(consumables_Items[index]);
	deepCopyItem->SetItemCount(count, false);
	return deepCopyItem;
}


Item_Consumables* ItemManager::GetConsumableItem(int id, int count)
{
	int itemType = id / 100000;
	int index = id - itemType * 100000 - 1;
	Item_Consumables* deepCopyItem = new Item_Consumables(consumables_Items[index]);
	deepCopyItem->SetItemCount(count, false);
	return deepCopyItem;
}

Item_Material* ItemManager::GetMaterialItem(int id, int count)
{
	int itemType = id / 100000;
	int index = id - itemType * 100000 - 1;
	Item_Material* deepCopyItem = new Item_Material(material_Items[index]);
	deepCopyItem->SetItemCount(count, false);
	return deepCopyItem;
}

int ItemManager::GetRandomItemId()
{
	std::vector<int> tempV;

	for (Item_Consumables item : consumables_Items) {
		tempV.push_back(item.GetItemId());
	}

	for (Item_Material item : material_Items) {
		tempV.push_back(item.GetItemId());
	}

	

	return tempV[myMath::Mathf::Random::Range(0, tempV.size())];
}

int ItemManager::GetEquipVectorSize()
{
	return equipable_Items.size();;
}

int ItemManager::GetConsumableVectorSize()
{
	return consumables_Items.size();
}





