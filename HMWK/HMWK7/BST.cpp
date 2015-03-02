#include "BST.h"
#include <iomanip>

BST::BST() {
	root = NULL;
	items = 0;
}

BST::~BST() {
	if (root)
	{
		dealloc(root);
		root = NULL;
	}
}

void BST::dealloc(Node* n) {
	if (n)
	{
		dealloc(n -> left);
		dealloc(n -> right);
		delete n;
	}
}

void BST::insert(const int& value) {
	_insert(value);
}

BST::Node* BST::_insert(const int& value) {
	if (root == NULL)
	{
		root = new Node(value);
		root -> weight = 1;
		items ++;
		return root;
	} else {
		return insert(root, value);
	}
}

BST::Node* BST::insert(Node* n, const int& value) {
	if (n -> data >= value)
	{
		if (n -> left == NULL)
		{
			Node* t = new Node(value);
			t -> parent = n;
			n -> left = t;
			n -> weight ++;
			items ++;
			return t;
		} else {
			n -> weight ++;
			return insert(n -> left, value);
		}
	} else {
		if (n -> right == NULL)
		{
			Node* t = new Node(value);
			t -> parent = n;
			n -> right = t;
			n -> weight ++;
			items ++;
			return t;
		} else {
			n -> weight ++;
			return insert(n -> right, value);
		}
	}
}

bool BST::contains(const int& value) {
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

bool BST::contains(Node* n, const int& value) {
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

void BST::print(Node* r, int depth) {
	if (r != NULL)
	{
		print(r -> right, depth + 1);
		cout << setw(4*depth) << "" << r -> data << "(" << r -> weight << ")" << endl;
		print(r -> left, depth + 1);
	}
}

void BST::printTree() {
	print(root, 0);
}

bool BST::empty() {
	return (items == 0);
}

int BST::size() {
	return items;
}

bool BST::isLeaf(Node* n) {
	return ((n -> left == NULL) && (n -> right == NULL));
}

BST::Node* BST::predecessor(Node* n) {
	if (n == NULL)
	{
		return NULL;
	}
	Node* t = n;
	while(t -> right != NULL) {
		t = t -> right;
	}
	return t;
}

void BST::remove(const int& value) {
	_remove(value);
}

BST::Node* BST::_remove(const int& value) {
	if (root != NULL)
	{
		return remove(root, value);
	}
	return NULL;
}

BST::Node* BST::remove(Node*& n, const int& v) {
	if (n == NULL)
	{
		return NULL;
	}
	if (isLeaf(n) && n -> data == v)
	{
		Node* p = n -> parent;
		while(p != NULL) {
			p -> weight --;
			p = p -> parent;
		}

		if (n -> parent)
		{
			if (n -> parent -> left == n)
			{
				n -> parent -> left = NULL;
			} else {
				n -> parent -> right = NULL;
			}
		}

		if (n == root)
		{
			root = NULL;
		}

		items --;
		Node* parent = n -> parent;

		delete n;
		n = NULL;

		return parent;
	}

	Node* t = n;
	while(t != NULL && t -> data != v) {
		if (t -> data < v)
		{
			t = t -> right;
		} else {
			t = t -> left;
		}
	}
	
	if (t == NULL)
	{
		return NULL;
	}

	Node* f = predecessor(t -> left);
	if (f == NULL)
	{
		if (isLeaf(t))
		{
			return remove(t, t -> data);
		} else {
			t -> data = t -> right -> data;
			t -> weight --;
			items --;
			Node* trc = t -> right;
			t -> left = trc -> left;
			if (trc -> left)
			{
				trc -> left -> parent = t;
			}
			t -> right = trc -> right;
			if (trc -> right)
			{
				trc -> right -> parent = t;
			}
			delete trc;
			return t -> parent;
		}
	} else {
		t -> data = f -> data;
		return remove(f, f -> data);
	}
}