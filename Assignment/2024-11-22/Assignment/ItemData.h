#pragma once
#include <iostream>

using namespace std;

namespace itemDatas {
    enum ItemId
    {
        Item1,
        Item2,
        Item3,
    };

    enum ItemType {
        /// <summary>
        /// 소모품
        /// </summary>
        Consumables,

        /// <summary>
        /// 장비
        /// </summary>
        Equipable,

        /// <summary>
        /// 재료
        /// </summary>
        Materials
    };

    enum class EquipSlot {
        Weapon_Both,     // 양손 장비
        Weapon_Both_OneHand,   // 두 손 다 장비 가능한 장비
        Weapon_Right,    // 오른손 장비
        Weapon_Left,     // 왼손 장비
        Armor_Top,       // 상의 방어구
        Armor_Bottom,    // 하의 방어구
        Helmet,          // 헬멧
        Gloves,          // 장갑
        Boots,           // 신발
        Ring,            // 반지
        Necklace,        // 목걸이
        Belt,            // 벨트
        Bracelet,        // 팔찌
    };
};

class ItemData
{


};

