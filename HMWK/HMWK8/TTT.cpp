#include "TTT.h"
#include <iomanip>

TTT::TTT() {
	root = NULL;
	items = 0;
}

TTT::~TTT() {
	if (root)
	{
		dealloc(root);
		root = NULL;
	}
}

void TTT::dealloc(Node* n) {
	if (n)
	{
		dealloc(n -> left);
		dealloc(n -> right);
		delete n;
	}
}

void TTT::flipColor(Node* p) {
	if (p)
	{
		p -> color = 'R';
		if (p -> left)
		{
			p -> left -> color = 'B';
		}
		if (p -> right)
		{
			p -> right -> color = 'B';
		}
	}
}

void TTT::rotateLeft(Node*& p) {
	Node* x = p -> right;
	p -> right = x -> left;
	x -> left = p;
	x -> color = p -> color;
	p -> color = 'R';
	
	p -> parent = x -> parent;
	x -> parent = p;
	
	p = x;
}

void TTT::rotateRight(Node*& p) {	
	Node* y = p -> parent;
	int data = y -> data;
	y -> data = p -> data;
	
	y -> left = p -> left;
	if (p -> left) {
		p -> left -> parent = y;
	}
	
	y -> right = p;
	p -> data = y -> data;
	
	p = y;
}

void TTT::insert(const int& value) {
	root = insert(root, value);
	root -> color = 'B';
	items ++;
}

TTT::Node* TTT::insert(Node* n, const int& value) {
	if (!n)
	{
		Node* n1 = new Node(value);
		return n1;
	}

	if (value < n -> data)
	{
		n -> left = insert(n -> left, value);
		n -> left -> parent = n;
	} else {
		n -> right = insert(n -> right, value);
		n -> right -> parent = n;
	}
	
	if (n -> color == 'R' && n -> right && n -> right -> color == 'R')
	{
		rotateLeft(n);
	}

	if (n -> color == 'R' && n -> left && n -> left -> color == 'R')
	{
		rotateRight(n);
	}

	if (n -> left && n -> right && n -> left -> color == 'R' && n -> right -> color == 'R')
	{
		flipColor(n);
	}

	return n;
}

bool TTT::contains(const int& value) {
	if (root == NULL)
	{
		return false;
	}

	if (root -> data == value)
	{
		return true;
	} else {
		if (root -> data > value)
		{
			return contains(root -> left, value);
		} else {
			return contains(root -> right, value);
		}
	}
}

bool TTT::contains(Node* n, const int& value) {
	if (n == NULL)
	{
		return false;
	}

	if (n -> data == value)
	{
		return true;
	} else {
		if (n -> data > value)
		{
			return contains(n -> left, value);
		} else {
			return contains(n -> right, value);
		}
	}
}

void TTT::print(Node* r, int depth) {
	if (r != NULL)
	{
		print(r -> right, depth + 1);
		cout << setw(4*depth) << "" << r -> data << "(" << r -> color << ")" << endl;
		print(r -> left, depth + 1);
	}
}

void TTT::printTree() {
	print(root, 0);
}

int TTT::height() {
	return height(root,false);
}

int TTT::black_height() {
	return height(root,true);
}

int TTT::height(Node* n, bool blackOnly) {
	if (!n)
	{
		return 0;
	}
	if (blackOnly && n -> color != 'B')
	{
		return max(height(n->left, blackOnly),height(n->right, blackOnly));
	}
	return 1 + max(height(n->left, blackOnly),height(n->right, blackOnly));
}

bool TTT::empty() {
	return (items == 0);
}

int TTT::size() {
	return items;
}

bool TTT::isLeaf(Node* n) {
	return ((n -> left == NULL) && (n -> right == NULL));
}