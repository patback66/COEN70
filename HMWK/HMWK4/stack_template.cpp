#include <iostream>
#include "stack_template.h"

using namespace std;

//Constructor for the stack
template <class T>
stack<T>::stack() {
	_size = 0;
	//Create a dummy node
	_head = new node(0, NULL);
}

//Destructor
//Free the memory used by nodes
template <class T>
stack<T>::~stack() {
	node* p = _head;
	while (p != NULL) {
		node* t = p;
		p = p -> _next;
		delete t;
	}
}

//Push the value to the second item in the linked list
template <class T>
void stack<T>::push(T value) {
	node* n = new node(value, _head -> _next);
	_head -> _next = n;
	_size ++;
}


//Get the value of last pushed object in the stack
template <class T>
T stack<T>::pop() {
	node *p = _head -> _next;
	
	if (p == NULL) {
		throw "Empty Header";
	}
	
	//Adjust the list
	_head -> _next = p -> _next;
	
	T value = p -> _data;
	
	//Since the p is no longer needed, free it.
	delete p;
	
	//Update Size.
	_size --;
	
	return value;
}

template <class T>
long stack<T>::size() {
	return _size;
}