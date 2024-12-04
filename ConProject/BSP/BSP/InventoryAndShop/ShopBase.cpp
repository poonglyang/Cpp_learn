#include "ShopBase.h"


/*
itemDatas::ItemType a;
*/

ShopBase::ShopBase(const std::string& name, int sellItemType, ItemManager& itemManager)
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
	std::cout << "�������� �����Ͻðڽ��ϱ�?(1. �����Ѵ�, 2. ���Ѵ�) : ";
	std::cin >> selectBuy;

	
	int selectIndex;
	int selectCount;
	switch (sellItemType)
	{
	case (int)itemDatas::Consumables:
		
		std::cout << "�� ��° �������� �����Ͻðڽ��ϱ�? (���� : 0 ~ "
			<< shopInventory->GetConsumableInventorySize() << ") : ";
		std::cin >> selectIndex;

		if (selectIndex < shopInventory->GetConsumableInventorySize()) {
			std::cout << "��� �����Ͻðڽ��ϱ�? (1 ~ " << 
			shopInventory->CountItem(
				shopInventory->GetConsumableInventoryItemIdByIndex(selectIndex)) << ") : ";
			std::cin >> selectCount;
			if (0 < selectCount && selectCount <= shopInventory->CountItem(
				shopInventory->GetConsumableInventoryItemIdByIndex(selectIndex))) {
				// 1 ~ ������ �ִ� ������ ���� ��ŭ ����ٸ�
				if (shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * selectCount
					<= buyerInventory->GetMoney()) {
					// ������ ������ ���ݺ��� ���� ���� ���ٸ�
					int remainingCount = buyerInventory->PushItem(
						shopInventory->GetConsumableInventoryItemIdByIndex(selectIndex), selectCount);

					shopInventory->PopItem(
						shopInventory->GetConsumableInventoryItemIdByIndex(selectIndex), selectCount - remainingCount);

					if (remainingCount == selectCount) {
						std::cout << "�κ��丮�� ������ �������� �������� �� �߽��ϴ�" << std::endl;
					}
					else if (0 < remainingCount) {
						std::cout << "�κ��丮�� ������ �Ϻ� �����۸� �����Ͽ����ϴ�" << std::endl;
						buyerInventory->SetMoney(remainingCount *
							shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * -1, true);
					}
					else {
						std::cout << "���� ���� �Ϸ�" << std::endl;
						buyerInventory->SetMoney(
							shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * selectCount * -1, true);
					}
				}
			}
			else {
				std::cout << "������ �ʴ� ���� �Է��ϼ̽��ϴ�" << std::endl;
			}
		}

		break;
	case (int)itemDatas::Equipable:

		break;
	case (int)itemDatas::Materials:
		std::cout << "�� ��° �������� �����Ͻðڽ��ϱ�? (���� : 0 ~ "
			<< shopInventory->GetMaterialInventorySize() << ") : ";
		std::cin >> selectIndex;

		if (selectIndex < shopInventory->GetMaterialInventorySize()) {
			std::cout << "��� �����Ͻðڽ��ϱ�? (1 ~ " <<
				shopInventory->CountItem(
					shopInventory->GetMaterialsInventoryItemIdByIndex(selectIndex)) << ") : ";
			std::cin >> selectCount;
			if (0 < selectCount && selectCount <= shopInventory->CountItem(
				shopInventory->GetMaterialsInventoryItemIdByIndex(selectIndex))) {
				// 1 ~ ������ �ִ� ������ ���� ��ŭ ����ٸ�
				if (shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * selectCount
					<= buyerInventory->GetMoney()) {
					// ������ ������ ���ݺ��� ���� ���� ���ٸ�
					int remainingCount = buyerInventory->PushItem(
						shopInventory->GetMaterialsInventoryItemIdByIndex(selectIndex), selectCount);

					shopInventory->PopItem(
						shopInventory->GetMaterialsInventoryItemIdByIndex(selectIndex), selectCount - remainingCount);

					if (remainingCount == selectCount) {
						std::cout << "�κ��丮�� ������ �������� �������� �� �߽��ϴ�" << std::endl;
					}
					else if (0 < remainingCount) {
						std::cout << "�κ��丮�� ������ �Ϻ� �����۸� �����Ͽ����ϴ�" << std::endl;
						buyerInventory->SetMoney(remainingCount *
							shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * -1, true);
					}
					else {
						std::cout << "���� ���� �Ϸ�" << std::endl;
						buyerInventory->SetMoney(
							shopInventory->GetConsumableInventoryItemPriceByIndex(selectIndex) * selectCount * -1, true);
					}
				}
			}
			else {
				std::cout << "������ �ʴ� ���� �Է��ϼ̽��ϴ�" << std::endl;
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
	std::cout << "��� �������� �Ǹ��Ͻðڽ��ϱ�? (1. ���, 2. �Һ�, 3. ���) : ";
	std::cin >> selectSellItemType;
	switch (selectSellItemType)
	{
	case 1:
		sellerInventroy->PrintEquipableInventory();
		std::cout << "�� ��° �������� �Ǹ��Ͻðڽ��ϱ�? : ";
		
		std::cin >> selectIndex;

		sellerInventroy->SetMoney(
			sellerInventroy->GetEquipableInventoryItemPriceByIndex(selectIndex) * 0.5, true);
		sellerInventroy->PopItem(selectIndex);
		break;
	case 2:
		sellerInventroy->PrintConsumableInventory();
		std::cout << "�� ��° �������� �Ǹ��Ͻðڽ��ϱ�? : ";
		std::cin >> selectIndex;

		
		std::cout << "�� ���� �Ǹ��Ͻðڽ��ϱ�? (1 ~ "
			<< sellerInventroy->CountItem(
				sellerInventroy->GetConsumableInventoryItemIdByIndex(selectIndex)) << ") : ";
		std::cin >> selectCount;

		sellerInventroy->SetMoney(
			sellerInventroy->GetConsumableInventoryItemPriceByIndex(selectIndex) * 0.5 * selectCount, true);

		sellerInventroy->PopItem(
			sellerInventroy->GetConsumableInventoryItemIdByIndex(selectIndex), selectCount);
		break;
	case 3:
		sellerInventroy->PrintConsumableInventory();
		std::cout << "�� ��° �������� �Ǹ��Ͻðڽ��ϱ�? : ";
		std::cin >> selectIndex;


		std::cout << "�� ���� �Ǹ��Ͻðڽ��ϱ�? (1 ~ "
			<< sellerInventroy->CountItem(
				sellerInventroy->GetMaterialsInventoryItemIdByIndex(selectIndex)) << ") : ";
		std::cin >> selectCount;

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
	std::cout << "[" << name << "������ ���]" << std::endl;
	
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
