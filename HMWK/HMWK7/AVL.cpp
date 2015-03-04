#include "AVL.h"

AVLTree::AVLTree() {
	//No new variable need to initialize
}

AVLTree::~AVLTree() {
	//No new local allocations
	//Do nothing
}

AVLTree::Node* AVLTree::rotateLeft(Node* n) {
	if(n == NULL) {
		return NULL;
	}

	Node* right = n -> right;
	if (right)
	{
		Node* rLeft = right -> left;
		right -> left = n;
		n -> right = rLeft;
		right -> parent = n -> parent;
		n -> parent = right;
		if (rLeft) {
			rLeft -> parent = n;
		}
		
		n -> height = max(height(n->left),height(n->right)) + 1;
		right -> height = max(height(right->left),height(right->right)) + 1;
		
		return right;
	}
	return NULL;
}

AVLTree::Node* AVLTree::rotateRight(Node* n) {
	if (n == NULL)
	{
		return NULL;
	}
	Node* left = n -> left;
	if (left)
	{
		Node* lRight = left -> right;
		left -> right = n;
		n -> left = lRight;
		left -> parent = n -> parent;
		n -> parent = left;
		if (lRight) {
			lRight -> parent = n;
		}
		
		n -> height = max(height(n->left),height(n->right)) + 1;
		left -> height = max(height(left->left),height(left->right)) + 1;
		
		return left;
	}
	return NULL;
}

int AVLTree::height(Node* n) {
	if (n == NULL)
	{
		return 0;
	}
	return n -> height;
}

int AVLTree::balance(Node* n) {
	if (n == NULL) {
		return 0;
	}
	
	return height(n -> left) - height(n -> right);
}

AVLTree::Node* AVLTree::insert(Node* n, const int& value) {
	if (n == NULL) {
		Node* n1 = new Node(value);
		return n1;
	}
	
	if (value < n -> data) {
		n -> left = insert(n -> left, value);
	} else {
		n -> right = insert(n -> right, value);
	}
	
	n -> height = max(height(n->left),height(n->right)) + 1;
	
	int bal = balance(n);
	if (bal > 1 && value < n -> left -> data) {
		return rotateRight(n);
	}
	
	if (bal < -1 && value >= n -> right -> data) {
		return rotateLeft(n);
	}
	
	if (bal > 1 && value >= n -> left -> data) {
		n -> left = rotateLeft(n -> left);
		return rotateRight(n);
	}
	
	if (bal < -1 && value < n -> right -> data) {
		n -> right = rotateRight(n -> right);
		return rotateLeft(n);
	}
	
	return n;
}

void AVLTree::insert(const int& value) {
	root = insert(root,value);
	items ++;
}

AVLTree::Node* AVLTree::remove(Node* n, const int& value) {
	if(n == NULL){
		return NULL;
	}
	
	if(value < n -> data) {
		n -> left = remove(n -> left, value);
	} else if (value > n -> data) {
		n -> right = remove(n -> right, value);
	} else {
		if (n -> left == NULL || n -> right == NULL) {
			Node* t = (n -> left)?n->left:n->right;
			if(t == NULL) {
				t = n;
				n = NULL;
			} else {
				n -> data = t -> data;
				n -> left = t -> left;
				if( t -> left ) {
					t -> left -> parent = n;
				}
				n -> right = t -> right;
				if( t -> right ) {
					t -> right -> parent = n;
				}
				n -> height = t -> height;
			}
			delete t;
		} else {
			Node* p = predecessor(n -> left);
			n -> data = p -> data;
			n -> left = remove(n -> left, p -> data);
		}
	}
	
	if (n == NULL) {
		return NULL;
	}
	
	int bal = balance(n);
	
	if (bal > 1 && balance(n -> left) >= 0) {
		return rotateRight(n);
	}
	
	if (bal > 1 && balance(n -> left) < 0) {
		n -> left = rotateLeft(n -> left);
		return rotateRight(n);
	}
	
	if (bal < -1 && balance(n -> right) <= 0) {
		return rotateLeft(n);
	}
	
	if (bal < -1 && balance(n -> right) > 0) {
		n -> right = rotateRight(n -> right);
		return rotateLeft(n);
	}
	
	return n;
}

void AVLTree::remove(const int& value) {
	root = remove(root, value);
	items --;
}