#pragma once
#include "Node.h"

class RoomNode : public Node
{

public:
	RoomNode(Node* parentNode, Vector2Int bottomLeftCorner,
		Vector2Int topRightCorner, int index);

	RoomNode(const Node& node) :Node(node) {};

	int GetWidth();

	int GetLength();
};

