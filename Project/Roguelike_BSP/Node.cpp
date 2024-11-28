#include "Node.h"

Node::Node(Node* parent)
{
	this->parent = parent;
	if (parent != nullptr)                  // 부모가 있으면
	{
		parent->AddChild(*this);          // 부모 노드의 자식 노드에 이 노드를 추가함
	}
	isVisited = false;
	
}

vector<Node> Node::GetChildrenNodeVecotr()
{
	return vector<Node>();
}

void Node::AddChild(Node& node)
{
	childrenNodeVector.push_back(node);
}

void Node::RemoveChild(Node& node)
{
	for (int i = 0; i < childrenNodeVector.size(); i ++) {
		if (node == childrenNodeVector[i]) {
			childrenNodeVector.erase(childrenNodeVector.begin() + i);
			break;
		}
	}
}
