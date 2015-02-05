#include <iostream>

using namespace std;

class stack {
	protected:
		class node {
			public:
				node(double, node* = NULL);
				double _data;
				node* _next;
		};
		node* _head;
		long _size;
	public:
		stack();
		~stack();
		
		virtual void push(double);
		virtual double pop();
		virtual long size();
		
		friend ostream& operator << (ostream& out, const stack& s);
};