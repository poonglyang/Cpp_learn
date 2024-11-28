#include "Node.h"

Node::Node(Node* parent)
{
	this->parent = parent;
	if (parent != nullptr)                  // �θ� ������
	{
		parent->AddChild(*this);          // �θ� ����� �ڽ� ��忡 �� ��带 �߰���
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
