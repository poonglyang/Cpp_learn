#include "ShopBase.h"


/*
itemDatas::ItemType a;
*/

ShopBase::ShopBase(const string& name, int sellItemType, ItemManager& itemManager)
	: name(name), sellItemType(sellItemType)
{
	switch (sellItemType)
	{
	case (int)itemDatas::Consumables:
		shopInventory = new Inventory(0, 100, 0, itemManager);
		shopInventory->PushItem(100001, 20);
		shopInventory->PushItem(100002, 20);
		break;
	case (int)itemDatas::Equipable:
		shopInventory = new Inventory(100, 0, 0, itemManager);
		break;
	case (int)itemDatas::Materials:
		shopInventory = new Inventory(0, 0, 100, itemManager);
		shopInventory->PushItem(200001, 20);
		shopInventory->PushItem(200002, 20);
		shopInventory->PushItem(200003, 20);

		break;
	default:
		shopInventory = new Inventory(100, 100, 100, itemManager);
		break;
	}
}

void ShopBase::Buy(Inventory*& buyerInventory)
{
	int selectBuy;
	cout << "아이템을 구입하시겠습니까?(1. 구매한다, 2. 안한다) : ";
	cin >> selectBuy;

	
	int selectIndex;
	int selectCount;
	switch (sellItemType)
	{
	case (int)itemDatas::Consumables:
		
		cout << "몇 번째 아이템을 구입하시겠습니까? (범위 : 0 ~ "
			<< shopInventory->GetConsumableInventorySize() << ") : ";
		cin >> selectIndex;

		if (selectIndex < shopInventory->GetConsumableInventorySize()) {
			cout << "몇개를 구입하시겠습니까? (1 ~ " << 
			shopInventory->CountItem(
				shopInventory->GetConsumableInventoryItemIdByIndex(selectIndex)) << ") : ";
			cin >> selectCount;
			if (0 < selectCount && selectCount <= shopInventory->CountItem(
				shopInventory->GetConsumableInventoryItemIdByIndex(selectIndex))) {
				// 1 ~ 상점에 있는 아이템 갯수 만큼 골랐다면
				if (shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * selectCount
					<= buyerInventory->GetMoney()) {
					// 구입할 아이템 가격보다 가진 돈이 많다면
					int remainingCount = buyerInventory->PushItem(
						shopInventory->GetConsumableInventoryItemIdByIndex(selectIndex), selectCount);

					shopInventory->PopItem(
						shopInventory->GetConsumableInventoryItemIdByIndex(selectIndex), selectCount - remainingCount);

					if (remainingCount == selectCount) {
						cout << "인벤토리가 부족해 아이템을 구매하지 못 했습니다" << endl;
					}
					else if (0 < remainingCount) {
						cout << "인벤토리가 부족해 일부 아이템만 구입하였습니다" << endl;
						buyerInventory->SetMoney(remainingCount *
							shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * -1, true);
					}
					else {
						cout << "전량 구매 완료" << endl;
						buyerInventory->SetMoney(
							shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * selectCount * -1, true);
					}
				}
			}
			else {
				cout << "허용되지 않는 값을 입력하셨습니다" << endl;
			}
		}

		break;
	case (int)itemDatas::Equipable:

		break;
	case (int)itemDatas::Materials:
		cout << "몇 번째 아이템을 구입하시겠습니까? (범위 : 0 ~ "
			<< shopInventory->GetMaterialInventorySize() << ") : ";
		cin >> selectIndex;

		if (selectIndex < shopInventory->GetMaterialInventorySize()) {
			cout << "몇개를 구입하시겠습니까? (1 ~ " <<
				shopInventory->CountItem(
					shopInventory->GetMaterialsInventoryItemIdByIndex(selectIndex)) << ") : ";
			cin >> selectCount;
			if (0 < selectCount && selectCount <= shopInventory->CountItem(
				shopInventory->GetMaterialsInventoryItemIdByIndex(selectIndex))) {
				// 1 ~ 상점에 있는 아이템 갯수 만큼 골랐다면
				if (shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * selectCount
					<= buyerInventory->GetMoney()) {
					// 구입할 아이템 가격보다 가진 돈이 많다면
					int remainingCount = buyerInventory->PushItem(
						shopInventory->GetMaterialsInventoryItemIdByIndex(selectIndex), selectCount);

					shopInventory->PopItem(
						shopInventory->GetMaterialsInventoryItemIdByIndex(selectIndex), selectCount - remainingCount);

					if (remainingCount == selectCount) {
						cout << "인벤토리가 부족해 아이템을 구매하지 못 했습니다" << endl;
					}
					else if (0 < remainingCount) {
						cout << "인벤토리가 부족해 일부 아이템만 구입하였습니다" << endl;
						buyerInventory->SetMoney(remainingCount *
							shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * -1, true);
					}
					else {
						cout << "전량 구매 완료" << endl;
						buyerInventory->SetMoney(
							shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * selectCount * -1, true);
					}
				}
			}
			else {
				cout << "허용되지 않는 값을 입력하셨습니다" << endl;
			}
		}
		break;
	default:
		break;
	}
}

void ShopBase::Sell(Inventory*& sellerInventroy)
{
	int selectSellItemType;
	int selectIndex;
	int selectCount;
	ItemBase* sellItem = nullptr;
	cout << "어느 아이템을 판매하시겠습니까? (1. 장비, 2. 소비, 3. 재료) : ";
	cin >> selectSellItemType;
	switch (selectSellItemType)
	{
	case 1:
		sellerInventroy->PrintEquipableInventory();
		cout << "몇 번째 아이템을 판매하시겠습니까? : ";
		
		cin >> selectIndex;

		sellerInventroy->SetMoney(
			sellerInventroy->GetEquipableInventoryItemPriceByIndex(selectIndex) * 0.5, true);
		sellerInventroy->PopItem(selectIndex);
		break;
	case 2:
		sellerInventroy->PrintConsumableInventory();
		cout << "몇 번째 아이템을 판매하시겠습니까? : ";
		cin >> selectIndex;

		
		cout << "몇 개를 판매하시겠습니까? (1 ~ "
			<< sellerInventroy->CountItem(
				sellerInventroy->GetConsumableInventoryItemIdByIndex(selectIndex)) << ") : ";
		cin >> selectCount;

		sellerInventroy->SetMoney(
			sellerInventroy->GetConsumableInventoryItemPriceByIndex(selectIndex) * 0.5 * selectCount, true);

		sellerInventroy->PopItem(
			sellerInventroy->GetConsumableInventoryItemIdByIndex(selectIndex), selectCount);
		break;
	case 3:
		sellerInventroy->PrintConsumableInventory();
		cout << "몇 번째 아이템을 판매하시겠습니까? : ";
		cin >> selectIndex;


		cout << "몇 개를 판매하시겠습니까? (1 ~ "
			<< sellerInventroy->CountItem(
				sellerInventroy->GetMaterialsInventoryItemIdByIndex(selectIndex)) << ") : ";
		cin >> selectCount;

		sellerInventroy->SetMoney(
			sellerInventroy->GetMaterialsInventoryItemPriceByIndex(selectIndex) * 0.5 * selectCount, true);

		sellerInventroy->PopItem(
			sellerInventroy->GetMaterialsInventoryItemIdByIndex(selectIndex), selectCount);
		break;
	default:
		break;
	}
}

void ShopBase::PrintSellItem(Inventory*& sellerInventroy)
{
	cout << "[" << name << "아이템 목록]" << endl;
	
	switch (sellItemType)
	{
	case (int)itemDatas::Consumables:
		
		shopInventory->PrintConsumableInventory();
		break;
	case (int)itemDatas::Equipable:
		shopInventory->PrintEquipableInventory();
		break;
	case (int)itemDatas::Materials:
		shopInventory->PrintMaterialInventory();
		break;
	default:
		break;
	}
}
