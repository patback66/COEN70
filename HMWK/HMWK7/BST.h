#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

using namespace std;

class BST {
protected:
	class Node{
	public:
		Node(int d = 0){ data = d;left = NULL;right = NULL;parent = NULL;height = 1;}
		int data;
		Node* left;
		Node* right;
		Node* parent;
		int height;
	};

	Node* root;
	int items;

	void print(Node*, int);
	Node* predecessor(Node* n);
	bool isLeaf(Node*);
	void dealloc(Node*);
	Node* insert(Node*, const int&);
	Node* _insert(const int&);
	bool contains(Node*, const int&);
	Node* remove(Node*&, const int&);
	Node* _remove(const int&);
public:
	BST();
	~BST();

	void insert(const int&);
	void remove(const int&);
	bool contains(const int&);
	bool empty();
	int size();
	void printTree();
};

#endif