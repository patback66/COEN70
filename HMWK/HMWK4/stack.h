#include <iostream>

using namespace std;

class stack {
	private:
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
		
		void push(double);
		double pop();
		long size();
};