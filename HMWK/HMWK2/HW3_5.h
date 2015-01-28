/*
 *
 *    COEN70 HW2
 *    Tian Zhang
 *    Matthew Koken
 *
 */

#include <iostream>
using namespace std;

class set {
	private:
		class node {
			public:
				node(double = 0, node* = NULL);
				double _data;
				node* _prev;
				node* _next;
		};

		long _size;
		node* _head;
		node* _tail;
		
		void copyNodes(node*, node*);
		void deallocNodes(node *);
	public:
		set();
		~set();
		set(const set&);
		set& operator=(const set&);
		friend ostream& operator<<(ostream&, const set&);

		void insert(const double&);
		void remove(const double&);
		long size() const;
		bool contains(const double&) const;
};