#include "AVL.h"

AVLTree::AVLTree() {
	//No new variable need to initialize
}

AVLTree::~AVLTree() {
	//No new local allocations
	//Do nothing
}

void AVLTree::rotateLeft(Node* n) {
	if(n == NULL) {
		return;
	}

	Node* left = n -> left;
	if (left)
	{
		Node* lRight = left -> right;
		if (lRight)
		{
			int temp = left -> data;
			left -> data = lRight -> data;
			lRight -> data = temp;
			left -> left = lRight;
			left -> right = lRight -> right;
		}
	}
}

void AVLTree::rotateRight(Node* n) {
	if (n == NULL)
	{
		return;
	}
	Node* left = n -> left;
	if (left)
	{
		Node* leftL = left -> left;
		Node* leftR = left -> right;
		n -> left = leftR;
		left -> right = n;
		left -> parent = n -> parent;
		if (n -> parent)
		{
			if (n -> parent -> left == n)
			{
				n -> parent -> left = left;
			} else {
				n -> parent -> right = left;
			}
			n -> parent = left;
		} else {
			root = left;
			n -> parent = left;
		}
		fixWeight(left);
	}
}

void AVLTree::rotateLeft2(Node* n) {
	if(n == NULL) {
		return;
	}

	Node* right = n -> right;
	if (right)
	{
		Node* rightL = right -> left;
		Node* rightR = right -> right;
		n -> right = rightL;
		right -> left = n;
		right -> parent = n -> parent;
		if (n -> parent)
		{
			if (n -> parent -> left == n)
			{
				n -> parent -> left = right;
			} else {
				n -> parent -> right = right;
			}
			n -> parent = right;
		} else {
			root = right;
			n -> parent = right;
		}
		fixWeight(right);
	}
}

void AVLTree::rotateRight2(Node* n) {
	if (n == NULL)
	{
		return;
	}
	Node* right = n -> right;
	if (right)
	{
		Node* rLeft = right -> left;
		if (rLeft)
		{
			int temp = right -> data;
			right -> data = rLeft -> data;
			rLeft -> data = temp;
			right -> left = rLeft -> left;
			right -> right = rLeft;
		}
	}
}

int AVLTree::fixWeight(Node* n) {
	if (n == NULL)
	{
		return 0;
	}
	n -> weight = max(fixWeight(n -> left),fixWeight(n -> right)) + 1;
	return n -> weight;
}

void AVLTree::fixTree(Node* n) {
	if (n == NULL)
	{
		return;
	}

	if (isLeaf(n))
	{
		fixTree(n -> parent);
	} else {
		int leftW = 0;
		int rightW = 0;
		if (n -> left)
		{
			leftW = n -> left -> weight;
		}
		if (n -> right)
		{
			rightW = n -> right -> weight;
		}
		if (leftW - rightW >= 2)
		{
			if (n -> left && n-> right && n -> left -> right) {
				Node* parent = n;
				Node* left = n -> left;
				Node* lRight = left -> right;
				left -> right = parent;
				parent -> left = lRight;
				if (parent -> parent) {
					if (parent -> parent -> left == parent) {
						parent -> parent -> left = left;
					} else {
						parent -> parent -> right = left;
					}
					left -> parent = parent -> parent;
					parent -> parent = left;
				} else {
					root = left;
					left -> parent = NULL;
					parent -> parent = left;
				}
				fixWeight(n -> parent);
			} else {
				rotateLeft(n);
				rotateRight(n);
			}
		}
		if (rightW - leftW >= 2)
		{
			if (n -> left && n-> right && n -> right -> left) {
				Node* parent = n;
				Node* right = n -> right;
				Node* rLeft = right -> left;
				right -> left = parent;
				parent -> right = rLeft;
				if (parent -> parent) {
					if (parent -> parent -> left == parent) {
						parent -> parent -> left = right;
					} else {
						parent -> parent -> right = right;
					}
					right -> parent = parent -> parent;
					parent -> parent = right;
				} else {
					root = right;
					right -> parent = NULL;
					parent -> parent = right;
				}
				fixWeight(n -> parent);
			} else {
				rotateRight2(n);
				rotateLeft2(n);
			}
		}
		fixTree(n -> parent);
	}
}

void AVLTree::insert(const int& value) {
	Node* t = BST::_insert(value);
	fixTree(t);
}

void AVLTree::remove(const int& value) {
	Node* t = BST::_remove(value);
	fixTree(t);
}