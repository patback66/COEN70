#include <iostream>
#include "HW5_17.h"

using namespace std;

bag::bag() {
	head_ptr = NULL;
	many_nodes = 0;
}

bag::~bag() {
	node* p = head_ptr;
	while (p != NULL) {
		node* t = p -> link();
		delete p;
		p = t;
		if (p == head_ptr) {
			break;
		}
	}
}

bag::bag(const bag& source) {
	head_ptr = NULL;
	*this = source;
}

void bag::operator =(const bag& source) {
	if (this != &source) {
		many_nodes = source.many_nodes;
		if (source.many_nodes > 0) {
			node* head = new node(source.head_ptr -> data());
			node* o_T = source.head_ptr;
			node* c_T = head;
			while (o_T -> link() != source.head_ptr) {
				node* n = new node(o_T -> link() -> data());
				c_T -> set_link(n);
				c_T = n;
				o_T = o_T -> link();
			}
			c_T -> set_link(head);
			head_ptr = head;
		} else {
			head_ptr = NULL;
		}
	}
}

void bag::operator +=(const bag& addend) {
	if (addend.many_nodes > 0) {
		node* o_H = addend.head_ptr;
		insert(o_H -> data());
		while(o_H -> link() != addend.head_ptr) {
			bag::value_type v = o_H -> link() -> data();
			insert(v);
			o_H = o_H -> link();
		}
	}
}

bag operator +(const bag& b1, const bag& b2) {
	bag nBG;
	
	nBG += b1;
	nBG += b2;
	
	return nBG;
}

void bag::insert(const bag::value_type& entry) {
	node* n = new node(entry);
	
	if (head_ptr == NULL) {
		n -> set_link(n);
		head_ptr = n;
	} else {
		n -> set_link(head_ptr -> link());
		head_ptr -> set_link(n);
	}
	
	many_nodes ++;
}

bool bag::erase_one(const bag::value_type& target) {
	bool deleted = false;
	
	if (head_ptr != NULL) {
		node* p = head_ptr;
		if (p -> data() == target) {
			
			if (many_nodes == 1) {
				delete head_ptr;
				head_ptr = NULL;
				many_nodes --;
				
				deleted = true;
				return deleted;
			}
			
			node* t = p -> link();
			while (t -> link() != p) {
				t = t -> link();
			}
			
			t -> set_link(p -> link());
			delete p;
			head_ptr = t;
			many_nodes --;
			deleted = true;
			return deleted;
		}
		
		while (p -> link() != head_ptr) {
			if (p -> link() -> data() == target) {
				node* t = p -> link();
				p -> set_link(t -> link());
				delete t;
				many_nodes --;
				deleted = true;
				return deleted;
			}
			p = p -> link();
		}
	}
	
	return deleted;
}

bag::size_type bag::erase(const bag::value_type& target) {
	size_type count = 0;
	
	while (erase_one(target)) {
		count ++;
	}
	
	return count;
}

bag::size_type bag::count(const bag::value_type& target) const {
	size_type count = 0;
	
	node* p = head_ptr;
	
	if (p -> data() == target) {
		count ++;
	}
	
	while (p -> link() != head_ptr) {
		if (p -> link() -> data() == target) {
			count ++;
		}
		p = p -> link();
	}
	
	return count;
}

bag::value_type bag::grab( ) const {
	if (many_nodes == 0) {
		throw "Try to grab something from an empty bag!";
	}
	
	return head_ptr -> data();
}