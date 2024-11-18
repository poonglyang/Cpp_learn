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
	/// 부모 노드 주소
	/// </summary>
	Node* parentNode;

	/// <summary>
	/// 자식 노드 백터
	/// </summary>
	list<Node> childNode;

	/// <summary>
	/// 방문 여부
	/// </summary>
	bool isVisited;

	/// <summary>
	/// 트리의 레벨
	/// </summary>
	int treeLevel;

	Vecort2 topRightCorner;

	Vecort2 bottomLeftCorner;

	/// <summary>
	/// 노드의 가로 길이를 가져오는 함수
	/// </summary>
	/// <returns>노드의 가로 길이</returns>
	float GetWidth();

	/// <summary>
	/// 노드의 세로 길이를 가져오는 함수
	/// </summary>
	/// <returns>노드의 세로 길이</returns>
	float GetLength();

	/// <summary>
	/// 자식 리스트에 추가하는 함수
	/// </summary>
	/// <param name="node">추가할 자식</param>
	void AddChild(Node node);

	/// <summary>
	/// 자식 리스트에서 해당 되는 것을 빼는 함수
	/// </summary>
	/// <param name="node">뺄 자식</param>
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


