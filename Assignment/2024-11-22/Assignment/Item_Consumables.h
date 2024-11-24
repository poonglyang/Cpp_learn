#pragma once
#include "ItemBase.h"
#include<iostream>

using namespace std;
using namespace itemDatas;

class Item_Consumables : public ItemBase
{
protected:
	int toCopy;

public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="id">������ id</param>
	/// <param name="name">������ �̸�</param>
	/// <param name="count">������ ����</param>
	/// <param name="maxCount">������ �ִ� ũ��</param>
	/// <param name="price">������ ����</param>
	/// <param name="itemType">������ Ÿ��</param>
	/// <param name="explain">������ ����</param>
	Item_Consumables(int id, const string& name, int count, int maxCount, int price, int itemType, const string& explain);

	Item_Consumables(const Item_Consumables& other);


	/// <summary>
	/// ����� �� ����� ȿ���ε� �̰Ŵ� ���߿� ���� �˾Ƽ� �����ϰ���
	/// ���ʿ� ���� ���뿡�� �̷��� ���ݾ�
	/// </summary>
	void OnUse();

	void PrintItemInfo() override;
};

