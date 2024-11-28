/*
[stack]
	LIFO�� ��Ģ�� ������ �ڷᱸ��
	���Լ���
	.push	: ���ÿ� ���ο� ��Ҹ� �߰��ϴ� ����. �׻� ��ܿ� �߰�
	.pop	: �ֻ�� ��Ҹ� �����ϰ� ��ȯ
	.top	: ������ �ֻ�� ��Ҹ� ��ȯ
	.Empty	: ����ִ��� Ȯ���ϴ� �Լ�

[queue]
	FIFO�� ��Ģ�� ������ �ڷᱸ��
	���� ����

[list]

*/

#include <iostream>
#include <queue>
#include <stack>

int main() {
	std::stack<int> defaultStack;
	defaultStack.push(10);

	std::stack<int, std::vector<int>> stackVector;	// ������ deque�� �����Ǿ� ������ vector�� �ٲ� ����̴�

	std::queue<int> queue1;

	std::priority_queue<int> queue3;
}
