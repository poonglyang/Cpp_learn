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
		// 만약 카운트 + delta가 -이거나 0인 경우도 만들어야 한다
		if (this->count + delta > this->maxCount) {
			// 현재 아이템 갯수 + 아이템 증감값이 아이템 중첩 최대 갯수보다 크다면
			this->count = this->maxCount;					// 현재 아이템 갯수를 최대 갯수로 바꾸고
			return this->count + delta - this->maxCount;	// 남은 아이템 갯수 반환
		}
		else {
			this->count += delta;
		}
		return 0;	// 초과된게 없거나 추가된게 없다고
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


