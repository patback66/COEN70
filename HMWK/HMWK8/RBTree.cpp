#include "RBNode.h"
#include "RBTree.h"
#include <iomanip>

RBTree::RBTree() {
	root = NULL;
	items = 0;
	//Setup "NIL" node
	NIL = new RBNode<int>();
	NIL -> set_color(RBNode<int>::BLACK);
}

RBTree::~RBTree() {
	//Free memory of nodes
	if (root != NULL)
	{
		dealloc(root);
		root = NULL;
	}
	//Free "NIL" node
	if (NIL != NULL)
	{
		delete NIL;
		NIL = NULL;
	}
}

void RBTree::dealloc(RBNode<int>* n) {
	if (n != NULL && n != NIL)
	{
		dealloc(n -> left());
		dealloc(n -> right());
		delete n;
	}
}

void RBTree::printNode(ostream& out, RBNode<int>* r, int depth) {
	if (r != NULL && r != NIL)
	{
		printNode(out, r -> right(), depth + 1);
		cout << setw(4*depth) << "" << r -> data() << "(" << r -> color() << ")" << endl;
		printNode(out, r -> left(), depth + 1);
	}
}

void RBTree::printTree() {
	printNode(cout, root, 0);
	cout << endl;
}

RBNode<int>* RBTree::getSibling(RBNode<int>* n) {
	//Return the sibling node of current node
	if (n -> parent())
	{
		if (n == (n -> parent() -> left()))
		{
			return (n -> parent() -> right());
		} else {
			return (n -> parent() -> left());
		}
	}
	return NULL;
}

RBNode<int>* RBTree::getAunt(RBNode<int>* n) {
	//Return Aunt (Sibling of n's parent node)
	return getSibling(n -> parent());
}

RBNode<int>* RBTree::getGrandparent(RBNode<int>* n) {
	//Return Grandparent of current node
	if (n -> parent())
	{
		return (n -> parent() -> parent());
	}
	return NULL;
}

void RBTree::rotateLeft(RBNode<int>* n) {
	//Check if it's top node
	if (n -> parent() == NULL)
	{
		root = n;
		return;
	}

	RBNode<int>* grandParent = getGrandparent(n);
	RBNode<int>* parent = n -> parent();
	RBNode<int>* y = n -> left();

	//Set parent's right node to be your left node (Rotate left)
	parent -> set_right(y);

	//Update y's parent
	if (y != NIL)
	{
		y -> set_parent(parent);
	}

	//Switch parent
	n -> set_left(parent);
	parent -> set_parent(n);

	//Update root if necessary
	if (root == parent)
	{
		root = n;
	}
	//Fix grandParent relationship
	n -> set_parent(grandParent);
	if (grandParent != NULL)
	{
		if (grandParent -> left() == parent)
		{
			grandParent -> set_left(n);
		} else {
			grandParent -> set_right(n);
		}
	}
}

void RBTree::rotateRight(RBNode<int>* n) {
	RBNode<int>* grandParent = getGrandparent(n);
	RBNode<int>* parent = n -> parent();
	RBNode<int>* y = n -> right();

	//Set parent's left to be your right node (Rotate Right)
	parent -> set_left(y);

	//Adjust parent
	if (y != NIL)
	{
		y -> set_parent(parent);
	}

	//Swap n's position with parent
	n -> set_right(parent);
	parent -> set_parent(n);

	//Adjust root if needed
	if (root == parent)
	{
		root = n;
	}

	//Adjust grandparent relationship
	n -> set_parent(grandParent);
	if (grandParent != NULL)
	{
		if (grandParent -> left() == parent)
		{
			grandParent -> set_left(n);
		} else {
			grandParent -> set_right(n);
		}
	}
}

void RBTree::insert(int value) {
	//Insert as root
	if (root == NULL)
	{
		root = new RBNode<int>(value);
		//Mark as "Black" to match the Red Black Tree Requirement
		root -> set_color(RBNode<int>::BLACK);
		root -> set_left(NIL);
		root -> set_right(NIL);
	} else {
	//Insert as sub node
		insert(root,value);
	}
	items++;
}

void RBTree::insert(RBNode<int>* n, int value) {
	//Find the place to insert using binary search
	if (n -> data() >= value)
	{
		if (n -> left() != NIL)
		{
			//Go to next node
			insert(n -> left(), value);
		} else {
			//Insert at current location
			//Default RED
			RBNode<int>* t = new RBNode<int>(value);
			t -> set_data(value);
			t -> set_parent(n);
			t -> set_left(NIL);
			t -> set_right(NIL);
			n -> set_left(t);
			//Fix the tree color and places
			fixTree(t);
		}
	} else {
		if (n -> right() != NIL)
		{
			insert(n -> right(), value);
		} else {
			//Insert at current location
			//Default RED
			RBNode<int>* t = new RBNode<int>(value);
			t -> set_data(value);
			t -> set_parent(n);
			t -> set_left(NIL);
			t -> set_right(NIL);
			n -> set_right(t);
			fixTree(t);
		}
	}
}

void RBTree::fixTree(RBNode<int>* n) {
	//n is root 
	//Update color and root pointer
	if (n -> parent() == NULL)
	{
		root = n;
		n -> set_color(RBNode<int>::BLACK);
		return;
	}

	//Parent is RED
	if (n -> parent() -> color() == RBNode<int>::RED)
	{
		RBNode<int>* aunt = getAunt(n);
		if (aunt != NULL)
		{
			//Aunt is also RED
			if (aunt -> color() == RBNode<int>::RED)
			{
				//Adjust parent's color to BLACK
				n -> parent() -> set_color(RBNode<int>::BLACK);
				//Adjust aunt's color to BLACK
				aunt -> set_color(RBNode<int>::BLACK);

				//Adjust grandparent's color to RED
				RBNode<int>* grandParent = getGrandparent(n);
				if (grandParent)
				{
					grandParent -> set_color(RBNode<int>::RED);
					//Fix tree upward
					fixTree(grandParent);
				}
			} else {
				//Aunt is BLACK
				if (n -> parent() -> right() == n && getGrandparent(n) -> left() == n -> parent())
				{
					//n is the right node and n's parent is grandparent's left node
					//Perform rotation
					rotateLeft(n);
					rotateRight(n);
					//Adjust n's color to BLACK
					n -> set_color(RBNode<int>::BLACK);
					//Flip sub nodes' color to RED
					n -> left() -> set_color(RBNode<int>::RED);
					n -> right() -> set_color(RBNode<int>::RED);
				} else if (n -> parent() -> left() == n && getGrandparent(n) -> right() == n -> parent()) {
					//n is the right node and n's parent is grandparent's right node
					//Rotate right first and then rotate the branch to left
					rotateRight(n);
					rotateLeft(n);

					//Adjust colors
					n -> set_color(RBNode<int>::BLACK);
					n -> left() -> set_color(RBNode<int>::RED);
					n -> right() -> set_color(RBNode<int>::RED);
				} else if (n -> parent() -> left() == n && getGrandparent(n) -> left() == n -> parent()) {
					//n is parent's left node and parent is grandparent's left node
					//adjust parent's color to BLACK and grandparent's Color to RED
					n -> parent() -> set_color(RBNode<int>::BLACK);
					getGrandparent(n) -> set_color(RBNode<int>::RED);
					//Perform the rotation on n's parent
					rotateRight(n -> parent());
				} else if (n -> parent() -> right() == n && getGrandparent(n) -> right() == n -> parent()) {
					//n is parent's right node and parent is grandparent's right node
					//adjust parent's color to BLACK and grandparent's Color to RED
					n -> parent() -> set_color(RBNode<int>::BLACK);
					getGrandparent(n) -> set_color(RBNode<int>::RED);

					//Since parent is on the right, we perform left rotation
					rotateLeft(n -> parent());
				}
			}
		}
	}
}

bool RBTree::contains(const int& value) {
	if (root == NULL)
	{
		return false;
	}

	if (root -> data() == value)
	{
		return true;
	} else {
		if (root -> data() > value)
		{
			return contains(root -> left(), value);
		} else {
			return contains(root -> right(), value);
		}
	}
}

bool RBTree::contains(RBNode<int>* n, const int& value) {
	if (n == NULL)
	{
		return false;
	}

	if (n -> data() == value)
	{
		return true;
	} else {
		if (n -> data() > value)
		{
			return contains(n -> left(), value);
		} else {
			return contains(n -> right(), value);
		}
	}
}

bool RBTree::empty() {
	return (items == 0);
}

int RBTree::size() {
	return items;
}

int RBTree::height() {
	return height(root,false);
}

int RBTree::black_height() {
	return height(root,true);
}

int RBTree::height(RBNode<int>* n, bool blackOnly) {
	if (!n)
	{
		return 0;
	}
	if (blackOnly && n -> color() != RBNode<int>::BLACK)
	{
		return max(height(n->left(), blackOnly),height(n->right(), blackOnly));
	}
	return 1 + max(height(n->left(), blackOnly),height(n->right(), blackOnly));
}