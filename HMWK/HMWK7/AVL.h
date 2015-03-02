#ifndef AVLTREE_H
#define AVLTREE_H

#include "BST.h"

class AVLTree: public BST {
protected:
	void fixTree(Node*);
	void rotateLeft(Node*);
	void rotateRight(Node*);

	void rotateLeft2(Node*);
	void rotateRight2(Node*);

	int fixWeight(Node*);
public:
	AVLTree();
	~AVLTree();

	void insert(const int&);
	void remove(const int&);
};

#endif