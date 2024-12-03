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
	
	Vector2Int bottomLeftCorner;

	Vector2Int bottomRightCorner;

	Vector2Int topRightCorner;

	Vector2Int topLeftCorner;
	
	int treeIndex;

	Vector2Int GetMiddlePoint();
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

	Vector2Int GetBottomLeftCorner() const;

	void SetBottomLeftCorner(Vector2Int vector2);

	void SetBottomLeftCorner(int x, int y);

	Vector2Int GetBottomRightCorner() const;

	void SetBottomRightCorner(Vector2Int vector2);

	void SetBottomRightCorner(int x, int y);

	Vector2Int GetTopRightCorner() const;

	void SetTopRightCorner(Vector2Int vector2);

	void SetTopRightCorner(int x, int y);

	Vector2Int GetTopLeftCorner() const;

	void SetTopLeftCorner(Vector2Int vector2);

	void SetTopLeftCorner(int x, int y);

	int GetTreeIndex() const;

	void SetTreeIndex(int index);

	Vector2Int GetNodeMiddlePoint();
};

