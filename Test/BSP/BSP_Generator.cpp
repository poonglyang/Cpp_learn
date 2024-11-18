#include <iostream>
#include <vector>

using namespace std;

struct Vecort2 {
	float x;
	float y;
};

struct Node {
	Node* parentNode;
	vector<Node> childNode;

	Vecort2 topRightCorner;
	Vecort2 bottomLeftCorner;

	float width();
	float length();
};

float Node::width()
{
	return topRightCorner.x - bottomLeftCorner.x;
}

float Node::length()
{
	return topRightCorner.y - bottomLeftCorner.y;
}
