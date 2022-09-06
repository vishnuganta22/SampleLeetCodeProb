#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include"Node.h"

class BinarySearchTree {
private:
	Node* treeRoot;

	Node* getNewNode(int x);
	Node* insert(Node* root, int x);
	bool search(Node* root, int x);
	Node* get(Node* root, int x);
	void setRoot(Node* root);
	Node* minNode(Node* root);
	int min(Node* root);
	Node* maxNode(Node* root);
	int max(Node* root);
	int height(Node* root);

public:
	BinarySearchTree();
	Node* getRoot();
	void insert(int x);
	bool search(int x);
	int min();
	Node* minNode();
	int max();
	Node* maxNode();
	int height();
	Node* get(int x);
	void deleteAtElement(int x);
	int getSuccessor(int data);
};

#endif // !BINARYSEARCHTREE_H
