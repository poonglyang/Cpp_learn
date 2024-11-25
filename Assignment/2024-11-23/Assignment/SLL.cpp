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

//void SLL::Delete(int num)
//{
//	// ���� ��带 ����Ű�� ������
//	// ���� ��带 ����Ű�� ������
//
//	// ù ��° ��尡 �����Ϸ��� �����
//	// pHead�� ���� ������ �ٲٰ� ���� ��带 ��������
//
//	// ���鼭 ������ ��带 ã�ƾ� �Ѵ�
//	// ���� ��带 ���� ���� �̵�
//	// ���� ��带 �� ���� ���� �̵�
//	// ã�� ���ϸ� ����(nullptr)
//
//	// ���� ��带 ���� ��忡 �����ϰ�
//	// ����
//
//	if (pHead->value == num) {
//		// ù��° ��尡 ������ ���̸�
//		node* temp = pHead;		// �ӽ� ����ҿ� pHead�� �ְ�
//		pHead = pHead->pNext;	// pHead�� ���� pHead�� ���� ���� �ٲٰ�
//		delete temp;			// ���� pHead ����
//		temp = nullptr;
//		return;					// �Լ� ����
//	}
//
//	node* tempBack = pHead;
//	node* temp = pHead->pNext;			// pHead�� ������ �˻� �߱⿡ ������ �־���
//	while (temp->pNext != nullptr) {
//		if (temp->value == num) {
//			// ���� temp�� ���� ������ ���̶��
//			tempBack->pNext = temp->pNext;	// ���� ���� temp�� ���� ��带 ������
//			delete temp;					// temp ����
//			temp = nullptr;					
//			return;							// �Լ� ����
//		}
//		// ���� �ƴϸ�
//		tempBack = temp;					// ���� ��带 ���� ���� �ϰ�
//		temp = temp->pNext;					// temp�� ���� ���� �̵�
//
//	}
//
//	delete tempBack, temp;
//	tempBack = nullptr;
//	temp = nullptr;
//	std::cout << "����Ʈ �ȿ� " << num << "�� �����ϴ�" << std::endl;
//}

void SLL::Delete(int num)    //����
{
    //���� ��带 ����Ű�� ������
    node* temp = pHead;
    //���� ��带 ����Ű�� ������
    node* sour = temp->pNext;
    //���࿡ ù��° ��尡 �����Ϸ��� �����
    if (num == pHead->value)
        //��带 ���� ��带 �̵���Ű�� �����带 ����
    {
        pHead = sour;
        delete temp;
    }
    else
    {
        // ���鼭 ������ ��带 ã�ƾߵ�.
        // ���� ��尡 nullptr�̸� �ݺ� ����
        while (sour != nullptr)
        {
            // ���� ����� ���� num�̸�
            if (sour->value == num) {
                //���� ��带 ���� ��忡 �����ϰ�
                temp->pNext = sour->pNext;
                //���� ��� ����
                delete sour;
                sour = nullptr;
                // �Լ� ����
                return; // �Ǵ� break;
            }
            else {
                //���� ��带 ���� ���� �̵�
                temp = sour;
                //���� ��带 �� ���� ���� �̵�
                sour = sour->pNext;
            }
        }
        //ã�����ϸ� ����
    }
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
