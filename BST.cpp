#include "BST.h"
#include <string>
#include <iostream>
using namespace std;

BinarySearchTree* Create() {
	BinarySearchTree* tree = new BinarySearchTree;
	tree->count = NULL;
	tree->root = nullptr;
	return tree;
}

Node* NewNode(int value) {
	Node* no = new Node;
	no->data = value;
	no->left = nullptr;
	no->right = nullptr;
	return no;
}

Node* insert(BinarySearchTree* tree, Node* root, int value) {
	if (root == nullptr) {
		root = NewNode(value);
		tree->count++;
		return root;
	}
	else if (root->data > value) {
		if (root->left == nullptr) {
			root->left = NewNode(value);
			tree->count++;
			return root;
		}
		insert(tree, root->left, value);
		return root;
	}
	else if (root->data < value) {
		if (root->right == nullptr) {
			root->right = NewNode(value);
			tree->count++;
			return root;
		}
		insert(tree, root->right, value);
		return root;
	}
}

bool Search(Node* root, int data) {
	if (root == nullptr) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

int Height(Node* root) {
	if (root == NULL) {
		return -1;
	}

	int leftHeight = Height(root->left);
	int rightHeight = Height(root->right);
	return max(leftHeight, rightHeight) + 1;
}

void InOrder(Node* root) {
	if (root) {
		InOrder(root->left);
		cout << root->data << "\n";
		InOrder(root->right);
	}
}

Node* Delete(Node* root, int data) {
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
			return root;
		}
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else {
			Node* temp = root;
			Node* temp1 = root->left;

			while (temp1->right != nullptr) {
				temp1 = temp1->right;
			}
			root = temp1;
			root->left = NULL;
			root->right = temp->right;
			delete temp;
			

		}

	}
	return root;
}
