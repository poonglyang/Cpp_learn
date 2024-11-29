#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "namespace.cpp"

using namespace myMath;
using namespace std;

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
public:
	vector<Node*> childrenNode;

	Node(Node* parentNode);

	bool operator==(const Node& other);

	void AddChild(Node* node);

	void RemoveChild(Node* node);



	Node* GetParent();

	void SetParent(Node* parent);



	bool GetIsVisited();

	void SetIsVisited(bool set);

	Vector2Int GetBottomLeftCorner();

	void SetBottomLeftCorner(Vector2Int vector2);

	void SetBottomLeftCorner(int x, int y);

	Vector2Int GetBottomRightCorner();

	void SetBottomRightCorner(Vector2Int vector2);

	void SetBottomRightCorner(int x, int y);

	Vector2Int GetTopRightCorner();

	void SetTopRightCorner(Vector2Int vector2);

	void SetTopRightCorner(int x, int y);

	Vector2Int GetTopLeftCorner();

	void SetTopLeftCorner(Vector2Int vector2);

	void SetTopLeftCorner(int x, int y);

	int GetTreeIndex();

	void SetTreeIndex(int index);
};

