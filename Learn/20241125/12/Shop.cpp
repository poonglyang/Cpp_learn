#include "Shop.h"

Shop::Shop()
{
    SetItems();
}

Shop::~Shop()
{
}

void Shop::SetItems()
{
    AddItem(Item(GameEnums::ItemType::ITEM_ARMOR, 
        "���װ���", "�簡������ ���� ��", 5, 100, 1));
    AddItem(Item(GameEnums::ItemType::ITEM_ARMOR, 
        "ö ����", "ö�� ���� ����", 5, 1000, 1));
    AddItem(Item(GameEnums::ItemType::ITEM_WEAPON, 
        "ö ��", "��ö�� ���� ��", 5, 200, 1));
    AddItem(Item(GameEnums::ItemType::ITEM_WEAPON,
        "�̽��� ��", "�̽����� ���� ��", 5, 3000, 1));

}

void Shop::DisplayItems(GameEnums::ItemType type) const
{
    std::cout << "���� ������ ��� (" <<
        (type == GameEnums::ItemType::ITEM_WEAPON ? "����" : "��") << ")" << std::endl;
    int i = 0;

    for (auto& item : items) {
        if (item.GetType() == type) {
            std::cout << i + 1 << ", " << item.GetName() << "- "
                << item.GetPrice() << "���" << std::endl;
            
        }
        ++i;
    }
}

Item* Shop::BuyItem(GameEnums::ItemType type, const int index, int& gold)
{
    Item& item = items[index];
    if (gold >= item.GetPrice()) {
        gold -= item.GetPrice();
        std::cout << item.GetName() << "��(��) �����Ͽ����ϴ�" << std::endl;
        items.erase(items.begin() + (index - 1));

        return &item;
    }
    else {
        return nullptr;
    }
    
}

void Shop::AddItem(const Item& item)
{
    items.push_back(item);
}
