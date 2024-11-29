#include "RoomNode.h"

RoomNode::RoomNode(Node* parentNode, Vector2Int bottomLeftCorner, Vector2Int topRightCorner, int index)
	: Node(parentNode)
{
	this->bottomLeftCorner = bottomLeftCorner;
	this->topRightCorner = topRightCorner;
	this->bottomRightCorner = Vector2Int(topRightCorner.x, bottomLeftCorner.y);
	this->topLeftCorner = Vector2Int(bottomLeftCorner.x, topRightCorner.y);
	this->treeIndex = treeIndex;
}

int RoomNode::GetWidth()
{
	return topRightCorner.x - bottomLeftCorner.x;
}

int RoomNode::GetLength()
{
	return topRightCorner.y - bottomLeftCorner.y;
}
