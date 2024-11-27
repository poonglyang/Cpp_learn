/*
Ʈ���� �׷���
	�������� �ڷḦ ��Ÿ���µ� ���� ���Ǵ� �ڷᱸ��
	�θ� ��尡 ���� �ڽ� ������ ���� �� ���ִ� 1�� �� �����̴�	
	�� ��忡�� ����Ͽ� �ٽ� �ڱ� �ڽ��� ���� ���ƿ��� ��ȯ ������ ������ �ʴ´�

[Ʈ�� ����]
	�θ�(Parent)	: ��Ʈ ��� �������� ���� ����� ���
	�ڽ�(child)	: ��Ʈ ��� �ݴ� �������� ���� ����� ���
	�Ѹ�(Root)	: �θ� ��尡 ���� �ֻ��� ���. Ʈ���� ���� 0�� �ϳ��� ����
	����(Branch)	: �θ� ���� �ڽ� ��尡 ��� �ִ� ���. Ʈ���� �߰��� ����
	��(Leaf)		: �ڽ� ��尡 ���� ���

[��ȸ]
	���� ��ȸ
	���� ��ȸ
	���� ��ȸ
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
//class Node {
//private:
//	Node* leftNode;
//	Node* rightNode;
//
//public:
//
//};

template <typename T>
class Tree {
public:
	struct Node {
		T data;
		Node* parent;

		std::vector<Node*> childs;

		Node(T data) : parent(nullptr), data(data) {

		}
	};

public:
	/// <summary>
	/// Ʈ���� �ʱ�ȭ �ϴ� ������
	/// </summary>
	/// <param name="data">��Ʈ ��忡 ���� ������</param>
	Tree(T data) {
		root = new Node(data);

	}

	~Tree() {
		delete root;
	}

	// ��Ʈ ��带 ��ȯ
	Node* GetRootNode() {
		return root;
	}

	// �θ� ��忡�� �ڽ� ��带 �߰��ϴ� �� �ʿ�
	Node* Add(Node* parent, T data) {
		// ��� ����
		Node* node = new Node(data);
		// ��� �θ� ����
		node->parent = parent;

		// �θ� ����� �ڽ� ��Ͽ� ���ο� ��� �߰�
		parent->childs.push_back(node);

		return node;
	}

	// ����ϴ� ��
	void Print(Node* node, int depth) {
		if (node->parent != nullptr) {
			cout << "�θ��� ������ : " << node->parent->data << "\t";
		}
		cout << "����� ������ : " << node->data << "\t���� : " << setw(3) << depth << endl;

		for (int i = 0; i < node->childs.size(); i++) {
			Print(node->childs[i], depth + 1);
		}
	}
private:
	// ��Ʈ ���
	Node* root;
};

int main() {
	// Ʈ�� ��ü �����
	Tree<int>* tree = new Tree<int>(20);

	// ���ο� ��带 �̰��ϰ� �� ����� �����͸� node�� ����
	Tree<int> ::Node* node = nullptr;

	node = tree->Add(tree->GetRootNode(), 30);
	tree->Add(node, 100);
	tree->Add(node, 200);
	node = tree->Add(tree->GetRootNode(), 40);
	node = tree->Add(node, 400);
	tree->Print(tree->GetRootNode(), 0);
}


