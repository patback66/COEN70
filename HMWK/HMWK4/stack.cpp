#include <iostream>
#include "stack.h"

using namespace std;

//Constructor for the node
stack::node::node(double value, node* next) {
	_data = value;
	_next = next;
}

//Constructor for the stack
stack::stack() {
	_size = 0;
	//Create a dummy node
	_head = new node(0, NULL);
}

//Destructor
//Free the memory used by nodes
stack::~stack() {
	node* p = _head;
	while (p != NULL) {
		node* t = p;
		p = p -> _next;
		delete t;
	}
}

//Push the value to the second item in the linked list
void stack::push(double value) {
	node* n = new node(value, _head -> _next);
	_head -> _next = n;
	_size ++;
}


//Get the value of last pushed object in the stack
double stack::pop() {
	node *p = _head -> _next;
	
	if (p == NULL) {
		throw "Empty Header";
	}
	
	//Adjust the list
	_head -> _next = p -> _next;
	
	double value = p -> _data;
	
	//Since the p is no longer needed, free it.
	delete p;
	
	//Update Size.
	_size --;
	
	return value;
}

long stack::size() {
	return _size;
}

ostream& operator << (ostream& out, const stack& s) {
	if (s._size > 0) {
		stack::node* p = s._head -> _next;
		while (p != NULL) {
			out << p -> _data << ", ";
			p = p -> _next;
		}
	}
	return out;
}