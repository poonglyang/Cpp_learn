#include "SLL.h"

SLL::SLL() : pHead(nullptr)
{
}

SLL::~SLL()
{
	while (pHead != nullptr) {
		node* temp = pHead;		// ���� ��带 ����Ű�� �����͸� �ӽ� ��忡 ����
		pHead = pHead->pNext;	// ���� ��带 ���� ���� ����
		delete temp;			// ���� ��� ����
	}
}

void SLL::Insert(int num)
{
	node* newNode = new node(num);
	if (pHead == nullptr) {
		// ������ ��������� ���ο� ��带 ù ���� ����
		pHead = newNode;
		return;
	}
	else {
		node* temp = pHead;
		while (temp->pNext != nullptr)	// ����Ʈ�� ��ȸ�� temp�� nullptr�� �ƴ� ������
		{
			temp = temp->pNext;
		}
		temp->pNext = newNode;
	}
}

void SLL::Delete(int num)
{
	// ���� ��带 ����Ű�� ������
	// ���� ��带 ����Ű�� ������

	// ù ��° ��尡 �����Ϸ��� �����
	// pHead�� ���� ������ �ٲٰ� ���� ��带 ��������

	// ���鼭 ������ ��带 ã�ƾ� �Ѵ�
	// ���� ��带 ���� ���� �̵�
	// ���� ��带 �� ���� ���� �̵�
	// ã�� ���ϸ� ����(nullptr)

	// ���� ��带 ���� ��忡 �����ϰ�
	// ����

	if (pHead->value == num) {
		// ù��° ��尡 ������ ���̸�
		node* temp = pHead;		// �ӽ� ����ҿ� pHead�� �ְ�
		pHead = pHead->pNext;	// pHead�� ���� pHead�� ���� ���� �ٲٰ�
		delete temp;			// ���� pHead ����
		temp = nullptr;
		return;					// �Լ� ����
	}

	node* tempBack = pHead;
	node* temp = pHead->pNext;			// pHead�� ������ �˻� �߱⿡ ������ �־���
	while (temp->pNext != nullptr) {
		if (temp->value == num) {
			// ���� temp�� ���� ������ ���̶��
			tempBack->pNext = temp->pNext;	// ���� ���� temp�� ���� ��带 ������
			delete temp;					// temp ����
			temp = nullptr;					
			return;							// �Լ� ����
		}
		// ���� �ƴϸ�
		tempBack = temp;					// ���� ��带 ���� ���� �ϰ�
		temp = temp->pNext;					// temp�� ���� ���� �̵�

	}
	std::cout << "����Ʈ �ȿ� " << num << "�� �����ϴ�" << std::endl;
}

void SLL::Print()
{
	node* temp = pHead;
	while (temp->pNext != nullptr)	// ����Ʈ�� ��ȸ�� temp�� nullptr�� �ƴ� ������
	{
		std::cout << temp->value << " ";
		temp = temp->pNext;
	}
	std::cout << temp->value << " ";
}
