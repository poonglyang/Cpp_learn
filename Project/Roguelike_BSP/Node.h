#pragma once
#include <iostream>
#include <vector>
#include "namespace.cpp"

using namespace myMath;
using namespace std;

class Node
{
protected:
	int nodeId;

	vector<Node> childrenNodeVector;

	Node* parent = nullptr;

	Vector2Int bottomLeftPoint;
	Vector2Int bottomTopPoint;

	Vector2Int topRightPoint;
	Vector2Int topLeftPoint;

	bool isVisited;

	int treeLevel;


public:
	bool operator==(const Node& other) const {
		return this->nodeId == other.nodeId;  // ID가 같으면 같은 노드로 판단
	}

	Node(Node* parent);

	vector<Node> GetChildrenNodeVecotr();

	void AddChild(Node& node);

	void RemoveChild(Node& node);
};

