#include <iostream>
#include "stack.h"

using namespace std;

class newStack: public stack {
	public:
		friend bool compare(newStack&, newStack&);
};

bool compare(newStack& s1, newStack& s2) {
	if (s1._size != s2._size) {
		return false;
	}
	
	if (s1._size == 0 && s1._size == 0) {
		return true;
	}
	
	if (s1._size == 0 && s2._size > 0) {
		return false;
	}
	
	if (s1._size > 0 && s2._size == 0) {
		return false;
	}
	
	newStack::node* s1n = s1._head -> _next;
	newStack::node* s2n = s2._head -> _next;
	
	while (s1n != NULL) {
		if (s1n -> _data != s2n -> _data) {
			return false;
		}
		s1n = s1n -> _next;
		s2n = s2n -> _next;
	}
	
	return true;
}

int main(int argc, char *argv[]) {
	newStack a,b,c;
	a.push(1);
	a.push(2);
	a.push(3);
	
	b.push(1);
	b.push(2);
	b.push(3);
	
	c.push(2);
	c.push(3);
	
	cout << compare(a, b) << endl;
	cout << compare(a, c) << endl;
	return 0;
}