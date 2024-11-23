#pragma once
#include <iostream>

using namespace std;

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

        /// <summary>
        /// ����� 10���̻� 20�� �̸��� �ݵ�� �Һ� �������̴�
        /// </summary>
        Consumables1 = 100001,
        Consumables2,
        Consumables3,

        /// <summary>
        /// ������ 20�� �̻��� �ݵ�� �����̴�
        /// </summary>
        Materials1 = 200001,
        Materials2,
        Materials3
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
};

class ItemData
{


};

