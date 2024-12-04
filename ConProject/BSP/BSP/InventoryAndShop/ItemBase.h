#pragma once

#include "ItemData.h"
#include <vector>

using namespace itemDatas;

class ItemBase
{
protected:
#pragma region ������ ���̽� ���� ����
	/// <summary>
	/// �������� id
	/// </summary>
	int id;

	/// <summary>
	/// �������� �̸�
	/// </summary>
	std::string name;

	/// <summary>
	/// ������ ����
	/// </summary>
	int count;

	/// <summary>
	/// ������ �ִ� ����
	/// </summary>
	int maxCount;

	/// <summary>
	/// ������ ����
	/// </summary>
	int price;

	/// <summary>
	/// ������ Ÿ��
	/// </summary>
	int itemType;

	/// <summary>
	/// ������ ����
	/// </summary>
	std::string explain;

#pragma endregion


public:
	
	/// <summary>
	/// ������ ������
	/// </summary>
	/// <param name="id">�� �������� id</param>
	/// <param name="name">�� �������� �̸�</param>
	/// <param name="count">�� �������� ����, �⺻�� 1</param>
	/// <param name="maxCount">�� �������� �ִ� ũ��</param>
	ItemBase(int id, const std::string& name, int count, int maxCount, int price, int itemType, const std::string& explain);

	ItemBase(const ItemBase& other);

	virtual ~ItemBase();

	/// <summary>
	/// �������� id�� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>�������� id ��</returns>
	int GetItemId();

	/// <summary>
	/// �������� �̸��� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ �̸�</returns>
	std::string GetItemName();

	/// <summary>
	/// �������� ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>�������� ����</returns>
	int GetItemCount();

	/// <summary>
	/// ������ ������ �����ϴ� �Լ�
	/// ������ ���� + ���� ������ < ������ �ִ� �����̸�
	/// ������ ���� + ���� ������ - ������ �ִ� ���� ��ȯ
	/// �̰� �����ε� �ؼ� ���ϴ°Ŷ� �ٲ���ϳ� ����� ���� ��
	/// </summary>
	/// <returns>������ �ʰ���</returns>
	virtual int SetItemCount(int delta, bool isAdd);

	/// <summary>
	/// �������� �ִ� ��ø ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ �ִ� ��ø ����</returns>
	int GetItemMaxCount();

	/// <summary>
	/// �������� ������ ��ȯ�ϴ� �Լ�
	/// ���� 0 �̿��� ���� ��ȯ �� ���
	/// ���� �������ε� ��ȯ�� �� ��ŭ count�� �ִ� �������� �������Ѵ�
	/// </summary>
	/// <returns>����</returns>
	int GetPrice();

	/// <summary>
	/// �������� Ÿ���� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ Ÿ��</returns>
	int GetItemType();

	/// <summary>
	/// �������� ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ ���� std::string</returns>
	std::string GetItemExplain();

	/// <summary>
	/// ������ ������ ����ϴ� �Լ�
	/// </summary>
	virtual void PrintItemInfo();
};

