#include "RoomNode.h"

RoomNode::RoomNode(Node* parentNode, myMath::Vector2Int bottomLeftCorner, myMath::Vector2Int topRightCorner, int index)
	: Node(parentNode)
{
	this->bottomLeftCorner = bottomLeftCorner;
	this->topRightCorner = topRightCorner;
	this->bottomRightCorner = myMath::Vector2Int(topRightCorner.x, bottomLeftCorner.y);
	this->topLeftCorner = myMath::Vector2Int(bottomLeftCorner.x, topRightCorner.y);
	this->treeIndex = index;
}

int RoomNode::GetWidth()
{
	return topRightCorner.x - bottomLeftCorner.x;
}

int RoomNode::GetLength()
{
	return topRightCorner.y - bottomLeftCorner.y;
}
