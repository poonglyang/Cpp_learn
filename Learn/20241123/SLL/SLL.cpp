#include "SLL.h"

SLL::SLL() : pHead(nullptr)
{
}

SLL::~SLL()
{
	while (pHead != nullptr) {
		node* temp = pHead;		// 현재 노드를 가리키는 포인터를 임시 노드에 저장
		pHead = pHead->pNext;	// 다음 노드를 현재 노드로 설정
		delete temp;			// 이전 노드 삭제
	}
}

void SLL::Insert(int num)
{
	node* newNode = new node(num);
	if (pHead == nullptr) {
		// 시작이 비어있으면 새로운 노드를 첫 노드로 설정
		pHead = newNode;
		return;
	}
	else {
		node* temp = pHead;
		while (temp->pNext != nullptr)	// 리스트를 순회할 temp가 nullptr이 아닐 때까지
		{
			temp = temp->pNext;
		}
		temp->pNext = newNode;
	}
}

void SLL::Delete(int num)
{
	// 현재 노드를 가리키는 포인터
	// 다음 노드를 가리키는 포인터

	// 첫 번째 노드가 삭제하려는 노드라면
	// pHead를 다음 것으로 바꾸고 현재 노드를 지워버림

	// 돌면서 삭제할 노드를 찾아야 한다
	// 현재 노드를 다음 노드로 이동
	// 다음 노드를 그 다음 노드로 이동
	// 찾지 못하면 종료(nullptr)

	// 이전 노드를 다음 노드에 연결하고
	// 삭제

	if (pHead->value == num) {
		// 첫번째 노드가 삭제할 것이면
		node* temp = pHead;		// 임시 저장소에 pHead를 넣고
		pHead = pHead->pNext;	// pHead를 기존 pHead의 다음 노드로 바꾸고
		delete temp;			// 기존 pHead 삭제
		temp = nullptr;
		return;					// 함수 종료
	}

	node* tempBack = pHead;
	node* temp = pHead->pNext;			// pHead는 전에서 검사 했기에 다음거 넣어줌
	while (temp->pNext != nullptr) {
		if (temp->value == num) {
			// 만약 temp의 값이 삭제할 것이라면
			tempBack->pNext = temp->pNext;	// 이전 노드와 temp의 다음 노드를 연결함
			delete temp;					// temp 삭제
			temp = nullptr;					
			return;							// 함수 종료
		}
		// 값이 아니면
		tempBack = temp;					// 이전 노드를 지금 노드로 하고
		temp = temp->pNext;					// temp를 다음 노드로 이동

	}
	std::cout << "리스트 안에 " << num << "이 없습니다" << std::endl;
}

void SLL::Print()
{
	node* temp = pHead;
	while (temp->pNext != nullptr)	// 리스트를 순회할 temp가 nullptr이 아닐 때까지
	{
		std::cout << temp->value << " ";
		temp = temp->pNext;
	}
	std::cout << temp->value << " ";
}
