
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
	
	// 추가
	Node* Add(Node* parent, T data) {
		Node* node = new Node(data);
		
		if (parent->data > data) {
			if (parent->left == nullptr) {
				parent->left = node;
				node->parent = parent;
			}
			else {
				Add(parent->left, data);
			}
			
		}
		else {
			if (parent->right == nullptr) {
				parent->right = node;
				node->parent = parent;
			}
			else {
				Add(parent->right, data);
			}
		}

		return node;
	}

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

	Node* AddStart(T data) {
		return Add(root, data);
		
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
	BinaryTree<int>* binaryTree = new BinaryTree<int>(10);

	// 새로운 노드를 추가하고 그 노드의 포인터를 node에 저장
	BinaryTree<int> ::Node* node = nullptr;

	node = binaryTree->AddStart(30);
	node = binaryTree->AddStart(5);
	node = binaryTree->AddStart(7);

	binaryTree->PrintPreOrder(binaryTree->Root());

}