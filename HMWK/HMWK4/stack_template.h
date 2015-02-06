#include <iostream>

using namespace std;

template <class T>
class stack {
	protected:
		class node {
			public:
				T _data;
				node* _next;
				node(const T& d = T(), node* n = NULL) : _data(d), _next(n) {};
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