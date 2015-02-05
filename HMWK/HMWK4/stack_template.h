#include <iostream>

using namespace std;

template <class T>
class stack {
	protected:
		class node {
			public:
				T _data;
				node* _next;
			node(const T& _data = L(), node* _next = NULL) : _data(x), _next(y) {};
		};
		node* _head;
		long _size;
	public:
		stack();
		~stack();
		
		virtual void push(T);
		virtual T pop();
		virtual long size();
};