#include <iostream>
using namespace std;

class deque {
	private:
		class node{
			public:
				node(double, node* = NULL, node* = NULL);
				double _d;
				node* _n;
				node* _p;
		};
		node* _front;
		node* _rear;
		long _size;
	public:
		deque();
		deque(const deque&);
		~deque();
		deque& operator= (const deque&);
		
		bool empty();
		long size();
		
		void push_back(double);
		void push_front(double);
		double pop_back();
		double pop_front();
		
		friend ostream& operator<< (ostream&, const deque&);
};