#pragma once
#include <iostream>

namespace itemDatas {
    /// <summary>
    /// �������� id�� ���� ��
    /// 1 ~ 10�� �̸��� ���, 100,001 �̻� 20�� �̸��� �Һ�, 
    /// 200,001 �̻��� �ݵ�� �������� �����Ѵ�
    /// �������� id���� ���� ���� ������ �Ѿ �� ����
    /// </summary>
    enum ItemId
    {
        /// <summary>
        /// ������ 10�� �̸��� �ݵ�� ��� �������̴�
        /// </summary>
        Equipable1 = 1,
        Equipable2,
        Equipable3,
        Equipable4,
        Equipable5,
        Equipable6,
        Equipable7,

        /// <summary>
        /// ����� 10���̻� 20�� �̸��� �ݵ�� �Һ� �������̴�
        /// </summary>
        Consumables1 = 100001,
        Consumables2,
        Consumables3,
        Consumables4,
        Consumables5,
        Consumables6,
        Consumables7,

        /// <summary>
        /// ������ 20�� �̻��� �ݵ�� �����̴�
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
        Weapon_Both,     // ��� ���
        Weapon_Both_OneHand,   // �� �� �� ��� ������ ���
        Weapon_Right,    // ������ ���
        Weapon_Left,     // �޼� ���
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

    enum class InventoryNum {
        Equip, Consumable, Material
    };
};

class ItemData
{


};

