#include "ItemBase.h"
using namespace itemDatas;
using namespace std;

ItemBase::ItemBase(int id, const string& name, int count, int maxCount, int itemType)
	: id(id), name(name), count(count), maxCount(maxCount), itemType(itemType)
{
	explain = "테스트";
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
		// 현재 아이템 갯수 + 아이템 증감값이 아이템 중첩 최대 갯수보다 크다면
		this->count = this->maxCount;					// 현재 아이템 갯수를 최대 갯수로 바꾸고
		return this->count + delta - this->maxCount;	// 남은 아이템 갯수 반환
	}
	return 0;	// 초과된게 없다고 반환
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


