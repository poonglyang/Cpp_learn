#include "ItemManager.h"

ItemManager::ItemManager()
{

	fuck = new ItemBase(-999, "Error", 0, 0, 0, -999, "Error������ ���ʿ� ���� ��ü�� �Ұ�����");
}

template<typename T>
#if __cplusplus >= 202002L
requires std::is_base_of<ItemBase, T>::value
#endif
T ItemManager::GetItem(int id, int count)
{
	int itemType = id / 100000;
	int index = id - type * 100000 - 1;

	if (id < 100000) {
		T deepCopyItem = T(equipable_Items[index]);
		deepCopyItem.SetItemCount(count, false);
		return deepCopyItem;
	}
	else if (id < 200000) {
		T deepCopyItem = T(consumables_Items[index]);
		deepCopyItem.SetItemCount(count, false);
		return deepCopyItem;
	}
	else if (id < 300000) {
		T deepCopyItem = T(material_Items[index]);
		deepCopyItem.SetItemCount(count, false);
		return deepCopyItem;
	}
	else {
		//���� �̰� ��µǸ� ����
		return fuck;
	}
}


