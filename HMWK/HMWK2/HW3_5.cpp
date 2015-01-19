#include <iostream>
#include "set.h"

using namespace std;

set::node::node(double value, node* prev) {
	_data = value;
	_prev = prev;
	_next = NULL;
}

set::set() {
	_size = 0;
	_head = new node();
	_tail = _head;
}

set::~set() {
	deallocNodes(_tail);
}

void set::copyNodes(node* dst, node* src) {
	if (src -> _next != NULL)
	{
		node* next = new node((src -> _next) -> _data, dst);
		copyNodes(next, src -> _next);
		dst -> _next = next;
	}
}

void set::deallocNodes(node *nd) {
	node* t = nd;
	while(t != NULL) {
		node* p = t;
		t = t -> _prev;
		delete p;
	}
}

set::set(const set& other) {
	_head = NULL;
	_tail = NULL;
	*this = other;
}

set& set::operator=(const set& rhs) {

	if (this != &rhs)
	{
		if (_tail != NULL)
			deallocNodes(_tail);

		_head = new node();
		copyNodes(_head, rhs._head);
		_size = rhs._size;
		node* c = _head;
		while(c -> _next != NULL) {
			c = c -> _next;
		}
		_tail = c;
	}

	return *this;
}

ostream& operator<<(ostream& out, const set& rhs) {
	set::node *p = rhs._head -> _next;

	while (p != NULL) {
		out << p -> _data <<", ";
		p = p -> _next;
	}

	return out;
}

bool set::contains(const double& value) const{
	bool find = false;

	node *p = _head -> _next;

	while (p != NULL) {
		if (p -> _data == value)
		{
			find = true;
			break;
		}
		p = p -> _next;
	}

	return find;
}

void set::insert(const double& value) {
	if (!contains(value))
	{
		node* next = new node(value, _tail);
		_tail -> _next = next;
		_tail = next;
		_size ++;
	}
}

void set::remove(const double& value) {
	node *p = _head -> _next;

	while (p != NULL) {
		if (p -> _data == value)
		{
			p -> _prev -> _next = p -> _next;
						
			if (_tail == p) {
				_tail = p -> _prev;
			} else {
				p -> _next -> _prev = p -> _prev;
			}
			
			delete p;
			_size --;
		}
		p = p -> _next;
	}
}

long set::size() const {
	return _size;
}