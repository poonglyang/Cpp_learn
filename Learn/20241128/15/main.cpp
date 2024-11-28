/*
[stack]
	LIFO의 원칙을 따르는 자료구조
	후입선출
	.push	: 스택에 새로운 요소를 추가하는 연산. 항상 상단에 추가
	.pop	: 최상단 요소를 제거하고 반환
	.top	: 스택의 최상단 요소를 반환
	.Empty	: 비어있는지 확인하는 함수

[queue]
	FIFO의 원칙을 따르는 자료구조
	선입 선출

[list]

*/

#include <iostream>
#include <queue>
#include <stack>

int main() {
	std::stack<int> defaultStack;
	defaultStack.push(10);

	std::stack<int, std::vector<int>> stackVector;	// 스택은 deque로 구현되어 있지만 vector로 바꾼 모양이다

	std::queue<int> queue1;

	std::priority_queue<int> queue3;
}
