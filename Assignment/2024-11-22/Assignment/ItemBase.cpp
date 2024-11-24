#include "ItemBase.h"
using namespace itemDatas;
using namespace std;

ItemBase::ItemBase(int id, const string& name, int count, int maxCount, int price, int itemType, const string& explain)
	: id(id), name(name), count(count), maxCount(maxCount), price(price), itemType(itemType), explain(explain)
{

}

ItemBase::ItemBase(const ItemBase& other)
{
	this->id = other.id;
	this->name = other.name;
	this->count = other.count;
	this->maxCount = other.maxCount;
	this->price = other.price;
	this->itemType = other.itemType;
	this->explain = other.explain;
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



int ItemBase::SetItemCount(int delta, bool isAdd)
{
	if (isAdd) {
		// ���� ī��Ʈ + delta�� -�̰ų� 0�� ��쵵 ������ �Ѵ�
		if (this->count + delta > this->maxCount) {
			// ���� ������ ���� + ������ �������� ������ ��ø �ִ� �������� ũ�ٸ�
			this->count = this->maxCount;					// ���� ������ ������ �ִ� ������ �ٲٰ�
			return this->count + delta - this->maxCount;	// ���� ������ ���� ��ȯ
		}
		else {
			this->count += delta;
		}
		return 0;	// �ʰ��Ȱ� ���ų� �߰��Ȱ� ���ٰ�
	}
	else {
		this->count = delta;
		return 0;
	}
}

int ItemBase::GetItemMaxCount()
{
	return maxCount;
}

int ItemBase::GetPrice()
{
	return price;
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


