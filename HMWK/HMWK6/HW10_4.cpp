#include "HW10_4.h"

using namespace std;

BinaryTree::BinaryTree() {
	tree = new float[10]();
	is_present = new bool[10]();
	current_node = -1;
	tSize = 0;
	cap = 10;
}

BinaryTree::~BinaryTree() {
	if (tree != NULL) {
		delete []tree;
		tree = NULL;
	}
	if (is_present != NULL) {
		delete []is_present;
		is_present = NULL;
	}
}

void BinaryTree::create_first_node(const float& value) {
	if (tSize == 0) {
		tree[0] = value;
		current_node = 0;
		tSize ++;
	}
}

void BinaryTree::shift_to_root() {
	if (tSize > 0) {
		current_node = 0;
	}
}

void BinaryTree::shift_up() {
	if (has_parent()) {
		current_node = c2p(current_node);
	}
}

void BinaryTree::shift_left() {
	if (has_left_child()) {
		current_node = p2lc(current_node);
	}
}

void BinaryTree::shift_right() {
	if (has_right_child()) {
		current_node = p2lc(current_node) + 1;
	}
}

void BinaryTree::change(const float& value) {
	if (current_node != -1) {
		tree[current_node] = value;
	}
}

void BinaryTree::add_left(const float& value) {
	if (tSize > 0 && !has_left_child()) {
		if (tSize >= cap) {
			expand();
		}
		int cIndex = p2lc(current_node);
		tree[cIndex] = value;
		is_present[cIndex] = true;
		tSize++;
	}
}

void BinaryTree::add_right(const float& value) {
	if (tSize > 0 && !has_right_child()) {
		if (tSize >= cap) {
			expand();
		}
		int cIndex = p2lc(current_node) + 1;
		tree[cIndex] = value;
		is_present[cIndex] = true;
		tSize++;
	}
}

bool BinaryTree::has_parent() const {
	if (c2p(current_node) >= 0) {
		return true;
	} else {
		return false;
	}
}

bool BinaryTree::has_left_child() const {
	if (p2lc(current_node) >= 0) {
		int cIndex = p2lc(current_node);
		if (cIndex <= cap) {
			return is_present[cIndex];
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool BinaryTree::has_right_child() const {
	if (p2lc(current_node) >= 0) {
		int cIndex = p2lc(current_node) + 1;
		if (cIndex <= cap) {
			return is_present[cIndex];
		} else {
			return false;
		}
	} else {
		return false;
	}
}

int BinaryTree::p2lc(const int& pindex) const {
	return (2*pindex + 1);
}

int BinaryTree::c2p(const int& cindex) const {
	return (cindex - 1)/2;
}

void BinaryTree::expand() {
	float* temp = new float[cap * 2]();
	copy(tree, tree + cap, temp);
	delete []tree;
	tree = temp;
	
	bool* temp1 = new bool[cap * 2]();
	copy(is_present, is_present + cap, temp1);
	cap = cap * 2;
	delete []is_present;
	is_present = temp1;
}

float BinaryTree::retrieve() const {
	if (current_node != -1) {
		return tree[current_node];
	}
	return 0;
}

int BinaryTree::size() {
	return tSize;
}