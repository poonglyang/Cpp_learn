#pragma once
#include <iostream>
struct node
{
	int value;
	node* pNext;

	//node* pBack; // 이거 넣으면 이중연결리스트 pBack가 마지막을 가리키게 하면 동적 원형 리스트

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

