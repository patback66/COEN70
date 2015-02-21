#include <iostream>

using namespace std;

struct BSTNode {
	float data;
	BSTNode* lc;
	BSTNode* rc;
};

struct node {
	float data;
	node* next;
};

void traverseBST(const BSTNode* tree, node*& last) {
	if (tree != NULL) {
		traverseBST(tree -> lc, last);
		node* nNode = new node;
		nNode -> data = tree -> data;
		nNode -> next = NULL;
		last -> next = nNode;
		last = nNode;
		traverseBST(tree -> rc, last);
	}
}

node* produceLinkedList(const BSTNode* tree) {
	node* begin = new node;
	node* index = begin;
	
	traverseBST(tree, index);
	
	node* actual = begin -> next;
	delete begin;
	
	return actual;
}

int main(int argc, char *argv[]) {
	BSTNode* a = new BSTNode;
	a -> data = 2.0;
	BSTNode* b = new BSTNode;
	b -> data = 1.0;
	b -> lc = NULL;
	b -> rc = NULL;
	BSTNode* c = new BSTNode;
	c -> data = 3.0;
	c -> lc = NULL;
	c -> rc = NULL;
	a -> lc = b;
	a -> rc = c;
	node* list = produceLinkedList(a);
	
	while (list != NULL) {
		cout << list -> data << endl;
		list = list -> next;
	}
	
	return 0;
}