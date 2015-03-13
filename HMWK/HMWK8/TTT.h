#ifndef TTTREE_H
#define TTTREE_H

#include <iostream>

using namespace std;

class TTT {
protected:
	class Node{
	public:
		Node(int d = 0){ data = d;left = NULL;right = NULL;parent = NULL;color = 'R';}
		int data;
		Node* left;
		Node* right;
		Node* parent;
		char color;
	};

	Node* root;
	int items;

	void print(Node*, int);
	bool isLeaf(Node*);
	void dealloc(Node*);
	Node* insert(Node*, const int&);
	bool contains(Node*, const int&);
	int height(Node*,bool);

	void flipColor(Node*);
	void rotateLeft(Node*&);
	void rotateRight(Node*&);
public:
	TTT();
	~TTT();

	void insert(const int&);
	bool contains(const int&);
	bool empty();
	int size();
	int height();
	int black_height();
	void printTree();
};

#endif