#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Vecort2 {
	float x;
	float y;
};

struct Node {
	/// <summary>
	/// �θ� ��� �ּ�
	/// </summary>
	Node* parentNode;

	/// <summary>
	/// �ڽ� ��� ����
	/// </summary>
	list<Node> childNode;

	/// <summary>
	/// �湮 ����
	/// </summary>
	bool isVisited;

	/// <summary>
	/// Ʈ���� ����
	/// </summary>
	int treeLevel;

	Vecort2 topRightCorner;

	Vecort2 bottomLeftCorner;

	/// <summary>
	/// ����� ���� ���̸� �������� �Լ�
	/// </summary>
	/// <returns>����� ���� ����</returns>
	float GetWidth();

	/// <summary>
	/// ����� ���� ���̸� �������� �Լ�
	/// </summary>
	/// <returns>����� ���� ����</returns>
	float GetLength();

	/// <summary>
	/// �ڽ� ����Ʈ�� �߰��ϴ� �Լ�
	/// </summary>
	/// <param name="node">�߰��� �ڽ�</param>
	void AddChild(Node node);

	/// <summary>
	/// �ڽ� ����Ʈ���� �ش� �Ǵ� ���� ���� �Լ�
	/// </summary>
	/// <param name="node">�� �ڽ�</param>
	void RemoveChild(Node node);
};


float Node::GetWidth()
{
	return topRightCorner.x - bottomLeftCorner.x;
}

float Node::GetLength()
{
	return topRightCorner.y - bottomLeftCorner.y;
}


void Node::AddChild(Node node)
{
	childNode.push_back(node);
}

void Node::RemoveChild(Node node)
{
	childNode.remove(node);
}


