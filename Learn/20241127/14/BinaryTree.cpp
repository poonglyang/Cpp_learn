/*
이진 트리	
	각 노드가 최대 2개의 자식 노드를 가질 수 있는 트리 구조
	완전 이진 트리 : 모든 노드 레벨이 가득 차 있고 마지막 레벨만이 왼쪽부터 차례대로 채워진 트리

	전 이진 트리 : 각 노드가 0 또는 2개의 자식 노드를 가지는 트리
		모든 노드가 2개의 자식 노드를 가지고 있거나 아예 없는 경우

	편향 이진 트리
		모든 노드가 한쪽 방향으로만 자식 노드를 가지는 트리


*/
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class BinaryTree {


public:
	//struct Node;

	struct Node {
		T data;
		Node* parent;
		Node* left;
		Node* right;

		Node(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}
	};

private:

	Node* root;

public:
	Node* Root() {
		return root;
	}

	BinaryTree(T data) {
		root = new Node(data);
	}

	~BinaryTree() {
		DeleteTree();
	}

	// 추가
	// 왼쪽
	Node* AddLeft(Node* parent, T data) {
		Node* node = new Node(data);
		node->parent = parent;
		if (parent->left != nullptr) {
			// 부모의 왼쪽에 노드가 있다면
			// 부모의 왼쪽 노드의 자식 노드를 node에 넣어야 한다
			node->left = parent->left->left;	
			node->right = parent->left->right;
			delete parent->left;
		}
		parent->left = node;

		return node;
	}
	// 오른쪽
	Node* AddRight(Node* parent, T data) {
		Node* node = new Node(data);
		node->parent = parent;
		if (parent->right != nullptr) {
			// 부모의 왼쪽에 노드가 있다면
			// 부모의 왼쪽 노드의 자식 노드를 node에 넣어야 한다
			node->left = parent->right->left;
			node->right = parent->right->right;
			delete parent->left;
		}
		parent->right = node;
		return node;
	}

	// 출력
	
	// 전위
	void PrintPreOrder(Node* node) {

		if (node == nullptr)
			return;

		cout << node->data << " ";

		PrintPreOrder(node->left);
		PrintPreOrder(node->right);
	}

	// 중위
	void PrintInOrder(Node* node) {
		if (node == nullptr)
			return;
		PrintInOrder(node->left);
		cout << node->data << " ";
		PrintInOrder(node->right);
	}
	// 후위
	void PrintPostOrder(Node* node) {
		if (node == nullptr)
			return;

		if (node == nullptr)
			return;
		PrintInOrder(node->left);
		PrintInOrder(node->right);
		cout << node->data << " ";
	}
	
	// 삭제
	void DeleteTree(Node* node) {
		if (node == nullptr) {
			return;
		}

		DeleteTree(node->left);
		DeleteTree(node->right);
	
	}
};

int main() {
	BinaryTree<int>* binaryTree = new BinaryTree<int>(1);

	// 새로운 노드를 추가하고 그 노드의 포인터를 node에 저장
	BinaryTree<int> ::Node* node = nullptr;

	BinaryTree<int>::Node* rootLeft = binaryTree->AddLeft(binaryTree->Root(), 2);
	BinaryTree<int>::Node* rootRight = binaryTree->AddRight(binaryTree->Root(), 3);

	// 루트 왼쪽에 추가
	node = binaryTree->AddLeft(rootLeft, 4);

	binaryTree->AddLeft(node, 8);
	binaryTree->AddRight(node, 9);

	binaryTree->AddLeft(rootLeft, 44);

	binaryTree->PrintPreOrder(binaryTree->Root());

}