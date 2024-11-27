/*
���� Ʈ��	
	�� ��尡 �ִ� 2���� �ڽ� ��带 ���� �� �ִ� Ʈ�� ����
	���� ���� Ʈ�� : ��� ��� ������ ���� �� �ְ� ������ �������� ���ʺ��� ���ʴ�� ä���� Ʈ��

	�� ���� Ʈ�� : �� ��尡 0 �Ǵ� 2���� �ڽ� ��带 ������ Ʈ��
		��� ��尡 2���� �ڽ� ��带 ������ �ְų� �ƿ� ���� ���

	���� ���� Ʈ��
		��� ��尡 ���� �������θ� �ڽ� ��带 ������ Ʈ��


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

	// �߰�
	// ����
	Node* AddLeft(Node* parent, T data) {
		Node* node = new Node(data);
		node->parent = parent;
		if (parent->left != nullptr) {
			// �θ��� ���ʿ� ��尡 �ִٸ�
			// �θ��� ���� ����� �ڽ� ��带 node�� �־�� �Ѵ�
			node->left = parent->left->left;	
			node->right = parent->left->right;
			delete parent->left;
		}
		parent->left = node;

		return node;
	}
	// ������
	Node* AddRight(Node* parent, T data) {
		Node* node = new Node(data);
		node->parent = parent;
		if (parent->right != nullptr) {
			// �θ��� ���ʿ� ��尡 �ִٸ�
			// �θ��� ���� ����� �ڽ� ��带 node�� �־�� �Ѵ�
			node->left = parent->right->left;
			node->right = parent->right->right;
			delete parent->left;
		}
		parent->right = node;
		return node;
	}

	// ���
	
	// ����
	void PrintPreOrder(Node* node) {

		if (node == nullptr)
			return;

		cout << node->data << " ";

		PrintPreOrder(node->left);
		PrintPreOrder(node->right);
	}

	// ����
	void PrintInOrder(Node* node) {
		if (node == nullptr)
			return;
		PrintInOrder(node->left);
		cout << node->data << " ";
		PrintInOrder(node->right);
	}
	// ����
	void PrintPostOrder(Node* node) {
		if (node == nullptr)
			return;

		if (node == nullptr)
			return;
		PrintInOrder(node->left);
		PrintInOrder(node->right);
		cout << node->data << " ";
	}
	
	// ����
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

	// ���ο� ��带 �߰��ϰ� �� ����� �����͸� node�� ����
	BinaryTree<int> ::Node* node = nullptr;

	BinaryTree<int>::Node* rootLeft = binaryTree->AddLeft(binaryTree->Root(), 2);
	BinaryTree<int>::Node* rootRight = binaryTree->AddRight(binaryTree->Root(), 3);

	// ��Ʈ ���ʿ� �߰�
	node = binaryTree->AddLeft(rootLeft, 4);

	binaryTree->AddLeft(node, 8);
	binaryTree->AddRight(node, 9);

	binaryTree->AddLeft(rootLeft, 44);

	binaryTree->PrintPreOrder(binaryTree->Root());

}