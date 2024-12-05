#pragma once
#include <iostream>

namespace itemDatas {
    /// <summary>
    /// 아이템의 id를 적은 것
    /// 1 ~ 10만 미만은 장비, 100,001 이상 20만 미만은 소비, 
    /// 200,001 이상은 반드시 잡탬으로 설정한다
    /// 아이템의 id값은 위의 값의 범위를 넘어설 수 없다
    /// </summary>
    enum ItemId
    {
        /// <summary>
        /// 아이테 10만 미만은 반드시 장비 아이템이다
        /// </summary>
        Equipable1 = 1,
        Equipable2,
        Equipable3,
        Equipable4,
        Equipable5,
        Equipable6,
        Equipable7,

        /// <summary>
        /// 어아탬 10만이상 20만 미만은 반드시 소비 아이템이다
        /// </summary>
        Consumables1 = 100001,
        Consumables2,
        Consumables3,
        Consumables4,
        Consumables5,
        Consumables6,
        Consumables7,

        /// <summary>
        /// 아이템 20만 이상은 반드시 잡탬이다
        /// </summary>
        Materials1 = 200001,
        Materials2,
        Materials3,
        Materials4,
        Materials5,
        Materials6,
        Materials7,
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

    enum class InventoryNum {
        Equip, Consumable, Material
    };
};

class ItemData
{


};

