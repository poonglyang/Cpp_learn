#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "namespace.cpp"

using namespace myMath;

class Node
{
protected:
	Node* parent;

	bool isVisited;
	
	myMath::Vector2Int bottomLeftCorner;

	myMath::Vector2Int bottomRightCorner;

	myMath::Vector2Int topRightCorner;

	myMath::Vector2Int topLeftCorner;
	
	int treeIndex;

	myMath::Vector2Int GetMiddlePoint();
public:
	std::vector<Node*> childrenNode;

	Node();

	Node(Node* parentNode);

	bool operator==(const Node& other);

	void AddChild(Node* node);

	void RemoveChild(Node* node);



	Node* GetParent();

	void SetParent(Node* parent);



	bool GetIsVisited() const;

	void SetIsVisited(bool set);

	myMath::Vector2Int GetBottomLeftCorner() const;

	void SetBottomLeftCorner(myMath::Vector2Int vector2);

	void SetBottomLeftCorner(int x, int y);

	myMath::Vector2Int GetBottomRightCorner() const;

	void SetBottomRightCorner(myMath::Vector2Int vector2);

	void SetBottomRightCorner(int x, int y);

	myMath::Vector2Int GetTopRightCorner() const;

	void SetTopRightCorner(myMath::Vector2Int vector2);

	void SetTopRightCorner(int x, int y);

	myMath::Vector2Int GetTopLeftCorner() const;

	void SetTopLeftCorner(myMath::Vector2Int vector2);

	void SetTopLeftCorner(int x, int y);

	int GetTreeIndex() const;

	void SetTreeIndex(int index);

	myMath::Vector2Int GetNodeMiddlePoint();
};

