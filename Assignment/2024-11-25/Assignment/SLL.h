#pragma once
#include <iostream>
struct node
{
	int value;
	node* pNext;

	//node* pBack; // �̰� ������ ���߿��Ḯ��Ʈ pBack�� �������� ����Ű�� �ϸ� ���� ���� ����Ʈ

	node(int n) : value(n), pNext(nullptr){}
};

class SLL
{
private:
	node* pHead;
public:
	SLL();
	~SLL();

	void Insert(int num);

	void Delete(int num);

	void Print();

};

