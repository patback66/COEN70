#ifndef AVLTREE_H
#define AVLTREE_H

#include "BST.h"

class AVLTree: public BST {
protected:
	AVLTree::Node* rotateLeft(Node*);
	AVLTree::Node* rotateRight(Node*);

	int height(Node*);
	int balance(Node*);
	AVLTree::Node* insert(Node*, const int&);
	AVLTree::Node* remove(Node*, const int&);
public:
	AVLTree();
	~AVLTree();

	void insert(const int&);
	void remove(const int&);
};

#endif