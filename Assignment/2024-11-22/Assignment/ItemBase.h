#pragma once
#include<iostream>
#include "ItemData.h"
#include <vector>

using namespace itemDatas;
using namespace std;

class ItemBase
{
private:
#pragma region ������ ���̽� ���� ����
	/// <summary>
	/// �������� id
	/// </summary>
	int id;

	/// <summary>
	/// �������� �̸�
	/// </summary>
	string name;

	/// <summary>
	/// ������ ����
	/// </summary>
	int count;

	/// <summary>
	/// ������ �ִ� ����
	/// </summary>
	int maxCount;

	/// <summary>
	/// ������ Ÿ��
	/// </summary>
	int itemType;

	/// <summary>
	/// ������ ����
	/// </summary>
	string explain;

#pragma endregion


public:
	
	/// <summary>
	/// ������ ������
	/// </summary>
	/// <param name="id">�� �������� id</param>
	/// <param name="name">�� �������� �̸�</param>
	/// <param name="count">�� �������� ����, �⺻�� 1</param>
	/// <param name="maxCount">�� �������� �ִ� ũ��</param>
	ItemBase(int id, const string& name, int count, int maxCount, int itemType);

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
	string GetItemName();

	/// <summary>
	/// �������� ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>�������� ����</returns>
	int GetItemCount();

	/// <summary>
	/// ������ ������ �����ϴ� �Լ�
	/// ������ ���� + ���� ������ < ������ �ִ� �����̸�
	/// ������ ���� + ���� ������ - ������ �ִ� ���� ��ȯ
	/// </summary>
	/// <returns>������ �ʰ���</returns>
	virtual int SetItemCount(int delta);

	/// <summary>
	/// �������� �ִ� ��ø ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ �ִ� ��ø ����</returns>
	int GetItemMaxCount();

	/// <summary>
	/// �������� Ÿ���� ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ Ÿ��</returns>
	int GetItemType();

	/// <summary>
	/// �������� ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ ���� string</returns>
	string GetItemExplain();

	virtual void PrintItemInfo();
};

