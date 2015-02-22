#include <iostream>
#include "Set.h"

using namespace std;

Set::node::node(int _t, bool _leaf) {
	t = _t;
	leaf = _leaf;
	
	keys = new int[2*t - 1];
	c = new node* [2*t];
	
	n = 0;
}

int Set::node::findKey(int k) {
	int idx = 0;
	while (idx < n && keys[idx] < k) {
		idx++;
	}
	return idx;
}

void Set::node::remove(int k) {
	int idx = findKey(k);
	
	if (idx < n && keys[idx] == k) {
		if (leaf) {
			removeFromLeaf(idx);
		} else {
			removeFromNonLeaf(idx);
		}
	} else {
		if (leaf) {
			cout << "Can't find the key" << endl;
			return;
		}
		
		bool flag = ((idx == n) ? true : false);
		if (c[idx] -> n < t) {
			fill(idx);
		}
		if (flag && idx > n) {
			c[idx - 1] -> remove(k);
		} else {
			c[idx] -> remove(k);
		}
	}
	return;
}

void Set::node::removeFromLeaf(int idx) {
	for (int i = idx + 1;i < n; i++) {
		keys[i - 1] = keys[i];
	}
	n --;
	return;
}

void Set::node::removeFromNonLeaf(int idx) {
	int k = keys[idx];
	
	if (c[idx] -> n >= t) {
		int pred = getPred(idx);
		keys[idx] = pred;
		c[idx] -> remove(pred);
	} else if (c[idx + 1] -> n >= t) {
		int succ = getSucc(idx);
		keys[idx] = succ;
		c[idx + 1] -> remove(succ);
	} else {
		merge(idx);
		c[idx] -> remove(k);
	}
	return;
}

int Set::node::getPred(int idx) {
	node* cur = c[idx];
	while (!cur -> leaf) {
		cur = cur -> c[cur -> n];
	}
	
	return cur -> keys[cur -> n - 1];
}

int Set::node::getSucc(int idx) {
	node* cur = c[idx + 1];
	while (!cur -> leaf) {
		cur = cur -> c[0];
	}
	return cur -> keys[0];
}

void Set::node::fill(int idx) {
	if (idx != 0 && c[idx - 1] -> n >= t) {
		borrowFromPrev(idx);
	} else if (idx != n && c[idx+1] -> n >= t) {
		borrowFromNext(idx);
	} else {
		if (idx != n) {
			merge(idx);
		} else {
			merge(idx - 1);
		}
	}
}

void Set::node::borrowFromPrev(int idx) {
	node* child = c[idx];
	node* sib = c[idx - 1];
	for (int i = child -> n - 1;i >= 0;i--) {
		child -> keys[i + 1] = child -> keys[i];
	}
	if (!child -> leaf) {
		for (int i = child -> n;i>=0;i--) {
			child -> c[i+1] = child ->c[i];
		}
	}
	child -> keys[0] = keys[idx - 1];
	if (!leaf) {
		child -> c[0] = sib -> c[sib -> n];
	}
	keys[idx - 1] = sib -> keys[sib -> n - 1];
	child -> n += 1;
	sib -> n -= 1;
}

void Set::node::borrowFromNext(int idx) {
	node* child = c[idx];
	node* sib = c[idx + 1];
	
	child -> keys[child -> n] = keys[idx];
	
	if (!(child -> leaf)) {
		child -> c[(child -> n) + 1] = sib -> c[0];
	}
	keys[idx] = sib -> keys[0];
	for (int i = 1;i<sib -> n;i++) {
		sib -> keys[i - 1] = sib -> keys[i];
	}
	if (!sib->leaf) {
		for (int i = 1;i <= sib -> n;i++) {
			sib -> c[i - 1] = sib -> c[i];
		}
	}
	
	child -> n += 1;
	sib -> n -= 1;
}

void Set::node::merge(int idx) {
	node* child = c[idx];
	node* sib = c[idx+1];
	child -> keys[t-1] = keys[idx];
	for (int i = 0;i < sib -> n;i++) {
		child -> keys[i+t] = sib -> keys[i];
	}
	if (!child -> leaf) {
		for (int i = 0;i <= sib -> n;i++) {
			child -> c[i+t] = sib -> c[i];
		}
	}
	for (int i = idx + 1;i < n;i++) {
		keys[i - 1] = keys[i];
	}
	for (int i = idx + 2;i <= n;i++) {
		c[i-1] = c[i];
	}
	child -> n += sib -> n + 1;
	n--;
	delete sib;
}

void Set::node::insertNonFull(int k) {
	int i = n - 1;
	if (leaf) {
		while (i >= 0 && keys[i] > k) {
			keys[i+1] = keys[i];
			i --;
		}
		keys[i+1] = k;
		n = n + 1;
	} else {
		while (i >= 0 && keys[i] > k) {
			i--;
		}
		if (c[i+1] -> n == 2*t - 1) {
			splitChild(i+1, c[i+1]);
			if (keys[i+1] < k) {
				i++;
			}
		}
		c[i+1]->insertNonFull(k);
	}
}

void Set::node::splitChild(int i, node* y) {
	node* z = new node(y-> t, y->leaf);
	z->n = t - 1;

	for (int j = 0; j < t-1; j++) {
		z->keys[j] = y->keys[j+t];
	}
	if (!(y->leaf))
	{
		for (int j = 0; j < t; j++){
			z->c[j] = y->c[j+t];
		}
	}
	y -> n = t - 1;
	for (int j = n;j>=i+1;j--) {
		c[j+1] = c[j];
	}
	c[i+1] = z;
	for (int j = n -1;j >= i;j--) {
		keys[j+1] = keys[j];
	}
	keys[i] = y -> keys[t-1];
	n += 1;
}

void Set::node::traverse() {
	int i;
	for (i = 0;i < n;i++) {
		if (leaf == false) {
			c[i] -> traverse();
		}
		cout << " " << keys[i];
	}
	
	if (!leaf) {
		c[i] -> traverse();
	}
}

Set::node* Set::node::search(int k) {
	int i = 0;
	while (i < n && k > keys[i]) {
		i++;
	}
	if (keys[i] == k) {
		return this;
	}
	if (leaf == true) {
		return NULL;
	}
	return c[i] -> search(k);
}

bool Set::insert(const int& k) {
	if(root == NULL) {
		root = new node(_t, true);
		root -> keys[0] = k;
		root -> n = 1;
		return true;
	} else {
		if (root -> search(k) != NULL) {
			return false;
		}
		if (root -> n == 2*_t - 1) {
			node* s = new node(_t, false);
			s -> c[0] = root;
			s -> splitChild(0,root);
			int i = 0;
			if (s -> keys[0] < k) {
				i ++;
			}
			s -> c[i] -> insertNonFull(k);
			
			root = s;
		} else {
			root -> insertNonFull(k);
		}
		_dataCount ++;
		return true;
	}
}

void Set::remove(const int& k) {
	if (!root) {
		cout << "Error!" << endl;
		return;
	}
	if(root -> search(k) != NULL) {
		_dataCount --;
	}
	root -> remove(k);
	if (root -> n == 0) {
		node* tmp = root;
		if(root->leaf) {
			root = NULL;
		} else {
			root = root -> c[0];
		}
		delete tmp;
	}
	return;
}

bool Set::contains(const int& k) {
	if (!root) {
		return false;
	}
	if (root -> search(k) != NULL) {
		return true;
	} else {
		return false;
	}
}

Set::~Set() {
	if(root != NULL) {
		delete root;
		root = NULL;
	}
}

ostream& operator<< (ostream& out, Set& s) {
	if (s.root != NULL) {
		s.root -> traverse();
	}
	return out;
}

int main(int argc, char *argv[]) {
	Set s;
	
	s.insert(3);
	s.insert(2);
		
	for (int i = 0;i < 10;i++) {
		s.insert(i);
	}
	
	cout << s << endl;
	s.remove(2);
	cout << s << endl;
	s.remove(4);
	cout << s << endl;
		
	return 0;
}