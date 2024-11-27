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
        "°¡Á×°©¿Ê", "¾ç°¡Á×À¸·Î ¸¸µç °Í", 5, 100, 1));
    AddItem(Item(GameEnums::ItemType::ITEM_ARMOR, 
        "Ã¶ °©¿Ê", "Ã¶·Î ¸¸µç °©¿Ê", 5, 1000, 1));
    AddItem(Item(GameEnums::ItemType::ITEM_WEAPON, 
        "Ã¶ °Ë", "ÀâÃ¶·Î ¸¸µç °Ë", 5, 200, 1));
    AddItem(Item(GameEnums::ItemType::ITEM_WEAPON,
        "¹Ì½º¸± °Ë", "¹Ì½º¸±·Î ¸¸µç °Ë", 5, 3000, 1));

}

void Shop::DisplayItems(GameEnums::ItemType type) const
{
    std::cout << "»óÁ¡ ¾ÆÀÌÅÛ ¸ñ·Ï (" <<
        (type == GameEnums::ItemType::ITEM_WEAPON ? "¹«±â" : "¹æ¾î±¸") << ")" << std::endl;
    int i = 0;

    for (auto& item : items) {
        if (item.GetType() == type) {
            std::cout << i + 1 << ", " << item.GetName() << "- "
                << item.GetPrice() << "°ñµå" << std::endl;
            
        }
        ++i;
    }
}

Item* Shop::BuyItem(GameEnums::ItemType type, const int index, int& gold)
{
    Item& item = items[index];
    if (gold >= item.GetPrice()) {
        gold -= item.GetPrice();
        std::cout << item.GetName() << "À»(¸¦) ±¸ÀÔÇÏ¿´½À´Ï´Ù" << std::endl;
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
