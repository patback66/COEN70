#include "HW10_3.h"

using namespace std;

CBT::CBT() {
	tree = new float[10];
	last = -1;
	cap = 10;
}

CBT::~CBT() {
	if (tree != NULL) {
		delete []tree;
		tree = NULL;
	}
}

int CBT::p2lc(const int& pindex) {
	return (2*pindex + 1);
}

int CBT::c2p(const int& cindex) {
	return (cindex - 1)/2;
}

void CBT::expand() {
	float* temp = new float[cap * 2];
	copy(tree, tree + cap, temp);
	cap = cap * 2;
	delete []tree;
	tree = temp;
}

void CBT::insert(const float& value) {
	if (last >= cap) {
		expand();
	}
	tree[++last] = value;
}

void CBT::removeLast() {
	if (last >= 0) {
		last --;
	}
}

int CBT::size() {
	return last + 1;
}