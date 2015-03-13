#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include "RBNode.h"

using namespace std;

class RBTree {
private:
	RBNode<int>* root;
	RBNode<int>* NIL;
	
	int items;

	RBNode<int>* getSibling(RBNode<int>*);
	RBNode<int>* getAunt(RBNode<int>*);
	RBNode<int>* getGrandparent(RBNode<int>*);
	void rotateLeft(RBNode<int>*);
	void rotateRight(RBNode<int>*);

	void fixTree(RBNode<int>*);
	void dealloc(RBNode<int>*);

	void insert(RBNode<int>*,int);

	void printNode(ostream&, RBNode<int>*, int);
	bool contains(RBNode<int>*, const int&);
	int height(RBNode<int>*,bool);
public:
	RBTree();
	~RBTree();

	void insert(int);
	bool contains(const int&);
	bool empty();
	int size();
	int height();
	int black_height();
	void printTree();
};

#endif