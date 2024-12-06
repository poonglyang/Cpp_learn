#pragma once
#include "Node.h"

class RoomNode : public Node
{

public:
	RoomNode(Node* parentNode, myMath::Vector2Int bottomLeftCorner,
		myMath::Vector2Int topRightCorner, int index);

	RoomNode(const Node& node) :Node(node) {};

	int GetWidth();

	int GetLength();
};

