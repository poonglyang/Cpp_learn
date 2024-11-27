/*
트리와 그래프
	계층적인 자료를 나타내는데 자주 사용되는 자료구조
	부모 노드가 여러 자식 노드들을 가질 수 있있는 1대 다 구조이다	
	한 노드에서 출발하여 다시 자기 자신의 노드로 돌아오는 순환 구조를 가지지 않는다

[트리 구성]
	부모(Parent)	: 루트 노드 방향으로 직접 연결된 노드
	자식(child)	: 루트 노드 반대 방향으로 직접 연결된 노드
	뿌리(Root)	: 부모 노드가 없는 최상위 노드. 트리의 깊이 0에 하나만 존재
	가지(Branch)	: 부모 노드와 자식 노드가 모두 있는 노드. 트리의 중간에 존재
	잎(Leaf)		: 자식 노드가 없는 노드

[순회]
	전위 순회
	중위 순회
	후위 순회
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
	/// 트리를 초기화 하는 생성자
	/// </summary>
	/// <param name="data">루트 노드에 넣을 데이터</param>
	Tree(T data) {
		root = new Node(data);

	}

	~Tree() {
		delete root;
	}

	// 루트 노드를 반환
	Node* GetRootNode() {
		return root;
	}

	// 부모 노드에서 자식 노드를 추가하는 것 필요
	Node* Add(Node* parent, T data) {
		// 노드 생성
		Node* node = new Node(data);
		// 노드 부모 설정
		node->parent = parent;

		// 부모 노드의 자식 목록에 새로운 노드 추가
		parent->childs.push_back(node);

		return node;
	}

	// 출력하는 것
	void Print(Node* node, int depth) {
		if (node->parent != nullptr) {
			cout << "부모의 데이터 : " << node->parent->data << "\t";
		}
		cout << "노드의 데이터 : " << node->data << "\t깊이 : " << setw(3) << depth << endl;

		for (int i = 0; i < node->childs.size(); i++) {
			Print(node->childs[i], depth + 1);
		}
	}
private:
	// 루트 노드
	Node* root;
};

int main() {
	// 트리 객체 만들고
	Tree<int>* tree = new Tree<int>(20);

	// 새로운 노드를 ㅜ가하고 그 노드의 포인터를 node에 저장
	Tree<int> ::Node* node = nullptr;

	node = tree->Add(tree->GetRootNode(), 30);
	tree->Add(node, 100);
	tree->Add(node, 200);
	node = tree->Add(tree->GetRootNode(), 40);
	node = tree->Add(node, 400);
	tree->Print(tree->GetRootNode(), 0);
}


