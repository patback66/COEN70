#include <iostream>
#include "HW8_7.h"

using namespace std;

deque::node::node(double value, node* next, node* prev) {
	_d = value;
	_n = next;
	_p = prev;
}

deque::deque() {
	_size = 0;
	_front = new node(0);
	_rear = _front;
}

deque::~deque() {
	node* p = _front;
	while (p != NULL) {
		node* t = p -> _n;
		delete p;
		p = t;
	}
	_front = NULL;
	_rear = NULL;
}

deque::deque(const deque& other) {
	_front = NULL;
	_rear = NULL;
	*this = other;
}

deque& deque::operator= (const deque& rhs) {
	if (this != & rhs) {
		_size = rhs._size;
		if (_front != NULL) {
			node* p = _front;
			while (p != NULL) {
				node* t = p -> _n;
				delete p;
				p = t;
			}
			_front = NULL;
			_rear = NULL;
		}
		
		_front = new node(0);
		node* rP = rhs._front -> _n;
		node* nP = _front;
		while (rP != NULL) {
			node* n1 = new node(rP -> _d, NULL, nP);
			nP -> _n = n1;
			nP = n1;
			rP = rP -> _n;
		}
		_rear = nP;
	}
	return *this;
}

bool deque::empty() {
	return (_size == 0);
}

long deque::size() {
	return _size;
}

void deque::push_back(double value) {
	node* nNode = new node(value, NULL, _rear);
	_rear -> _n = nNode;
	_rear = nNode;
	_size ++;
}

void deque::push_front(double value) {
	node* nNode = new node(value, _front -> _n, _front);
	if (_front -> _n != NULL) {
		_front -> _n -> _p = nNode;
	} else {
		_rear = nNode;
	}
	_front -> _n = nNode;
	_size ++;
}

double deque::pop_back() {
	if (_size == 0) {
		throw "Popping from emtpy deque.";
	}
	
	node* p = _rear;
	double v = p -> _d;
	_rear = p -> _p;
	_rear -> _n = NULL;
	delete p;
	_size --;
	
	return v;
}

double deque::pop_front() {
	if (_size == 0) {
		throw "Popping from emtpy deque.";
	}
	
	node* p = _front -> _n;
	double v = p -> _d;
	_front -> _n = p -> _n;
	if (_front -> _n == NULL) {
		_rear = _front;
	}
	delete p;
	_size --;
	
	return v;
}

ostream& operator<< (ostream& out, const deque& rhs) {
	out << "{";
	deque::node* p = rhs._front -> _n;
	while (p != NULL) {
		out << p -> _d;
		if (p -> _n != NULL) {
			out << ", ";
		}
		p = p -> _n;
	}
	out << "}";
	return out;
}