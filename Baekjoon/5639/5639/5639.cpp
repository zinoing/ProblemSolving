// 5639.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int val = 0;
	Node* parent = nullptr;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
};

class PostorderTree {
	Node* root;

public:
	PostorderTree(int node) {
		Node* newNode = new Node();
		newNode->val = node;
		root = newNode;
	}

	void push(int node) {
		Node* newNode = new Node();
		newNode->val = node;

		Node* parent = root;
		while (parent != nullptr) {
			// 좌측으로 이동
			if (parent->val > newNode->val) {
				if (parent->leftChild == nullptr) {
					parent->leftChild = newNode;
					newNode->parent = parent;
					break;
				}
				else {
					parent = parent->leftChild;
				}
			}
			// 우측으로 이동
			else {
				if (parent->rightChild == nullptr) {
					parent->rightChild = newNode;
					newNode->parent = parent;
					break;
				}
				else {
					parent = parent->rightChild;
				}
			}
		}

		return;
	}

	void print() {
		Node* currNode = root;
		
		while (1) {
			while (currNode->leftChild != nullptr) {
				currNode = currNode->leftChild;
			}

			if(currNode->rightChild != nullptr) {
				currNode = currNode->rightChild;
				continue;
			}

			if (currNode == root) {
				cout << currNode->val;
				break;
			}
			else {
				cout << currNode->val << "\n";

			}

			if (currNode->parent->rightChild == nullptr) {
				currNode = currNode->parent;
				currNode->leftChild = nullptr;
			}
			else if (currNode->parent->rightChild == currNode) {
				currNode = currNode->parent;
				currNode->leftChild = nullptr;
				currNode->rightChild = nullptr;
			}
			else {
				currNode = currNode->parent->rightChild;
				currNode->parent->leftChild = nullptr;
			}
		}

		return;
	}
};

int main() {
	int node = 0;

	cin >> node;
	PostorderTree tree(node);

	while (cin >> node) {
		tree.push(node);
	}

	tree.print();

	return 0;
}