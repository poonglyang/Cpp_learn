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
        /// �Ҹ�ǰ
        /// </summary>
        Consumables,

        /// <summary>
        /// ���
        /// </summary>
        Equipable,

        /// <summary>
        /// ���
        /// </summary>
        Materials
    };

    enum class EquipSlot {
        Weapon_Both,     // ��� ����
        Weapon_Right,    // ������ ����
        Weapon_Left,     // �޼� ����
        Armor_Top,       // ���� ��
        Armor_Bottom,    // ���� ��
        Helmet,          // ���
        Gloves,          // �尩
        Boots,           // �Ź�
        Ring,            // ����
        Necklace,        // �����
        Belt,            // ��Ʈ
        Bracelet,        // ����
    };
};

class ItemData
{


};

