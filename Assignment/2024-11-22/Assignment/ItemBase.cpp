#include "ItemBase.h"
using namespace itemDatas;
using namespace std;

ItemBase::ItemBase(int id, const string& name, int count, int maxCount, int itemType)
	: id(id), name(name), count(count), maxCount(maxCount), itemType(itemType)
{
	explain = "�׽�Ʈ";
}

ItemBase::~ItemBase()
{
}

int ItemBase::GetItemId()
{
	return id;
}

string ItemBase::GetItemName()
{
	return name;
}

int ItemBase::GetItemCount()
{
	return count;
}

int ItemBase::SetItemCount(int delta)
{
	if (this->count + delta < this->maxCount) {
		// ���� ������ ���� + ������ �������� ������ ��ø �ִ� �������� ũ�ٸ�
		this->count = this->maxCount;					// ���� ������ ������ �ִ� ������ �ٲٰ�
		return this->count + delta - this->maxCount;	// ���� ������ ���� ��ȯ
	}
	return 0;	// �ʰ��Ȱ� ���ٰ� ��ȯ
}

int ItemBase::GetItemMaxCount()
{
	return maxCount;
}

int ItemBase::GetItemType()
{
	return itemType;
}

string ItemBase::GetItemExplain()
{
	return explain;
}

void ItemBase::PrintItemInfo()
{

}


