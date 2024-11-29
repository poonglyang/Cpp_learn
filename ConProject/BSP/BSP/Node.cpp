#include "Node.h"

Node::Node()
{
    parent = nullptr;
}

Node::Node(Node* parentNode) //: parent(&parentNode)
{
    if (parentNode != nullptr) {
        parentNode->AddChild(this);
    }
    parent = parentNode;
}

bool Node::operator==(const Node& other)
{
    return (bottomLeftCorner == other.bottomLeftCorner)
        && (topRightCorner == other.topRightCorner)
        && (treeIndex == other.treeIndex);
    
}

void Node::AddChild(Node* node)
{
    childrenNode.push_back(node);
}

void Node::RemoveChild(Node* node)
{
    for (int i = 0; i < childrenNode.size(); i++) {
        if (childrenNode[i] == node) {
            childrenNode.erase(childrenNode.begin() + i);
        }
    }
}

Node* Node::GetParent()
{
    return parent;
}

void Node::SetParent(Node* parent)
{
    this->parent = parent;
}

bool Node::GetIsVisited() const
{
    return isVisited;
}

void Node::SetIsVisited(bool set)
{
    isVisited = set;
}

Vector2Int Node::GetBottomLeftCorner() const
{
    return bottomLeftCorner;
}

void Node::SetBottomLeftCorner(Vector2Int vector2)
{
    bottomLeftCorner = vector2;
}

void Node::SetBottomLeftCorner(int x, int y) 
{
    bottomLeftCorner.x = x;
    bottomLeftCorner.y = y;
}

Vector2Int Node::GetBottomRightCorner() const
{
    return bottomRightCorner;
}

void Node::SetBottomRightCorner(Vector2Int vector2)
{
    bottomRightCorner = vector2;
}

void Node::SetBottomRightCorner(int x, int y)
{
    bottomRightCorner.x = x;
    bottomRightCorner.y = y;
}

Vector2Int Node::GetTopRightCorner() const
{
    return topRightCorner;
}

void Node::SetTopRightCorner(Vector2Int vector2)
{
    topRightCorner = vector2;
}

void Node::SetTopRightCorner(int x, int y)
{
    topRightCorner.x = x;
    topRightCorner.y = y;
}

Vector2Int Node::GetTopLeftCorner() const
{
    return topLeftCorner;
}

void Node::SetTopLeftCorner(Vector2Int vector2)
{
    topLeftCorner = vector2;
}

void Node::SetTopLeftCorner(int x, int y)
{
    topLeftCorner.x = x;
    topLeftCorner.y = y;
}

int Node::GetTreeIndex() const
{
    return treeIndex;
}

void Node::SetTreeIndex(int index)
{
    treeIndex = index;
}


