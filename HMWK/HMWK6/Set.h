#include <iostream>
#include <vector>

using namespace std;


class Set {
	private:
		class node {
			private:
				int *keys;
				int t;
				node** c;
				int n;
				bool leaf;
			public:
				node(int _t, bool _leaf);
				void traverse();
				node* search(int k);
				int findKey(int k);
				void insertNonFull(int k);
				void splitChild(int i, node* y);
				void remove(int k);
				void removeFromLeaf(int idx);
				void removeFromNonLeaf(int idx);
				int getPred(int idx);
				int getSucc(int idx);
				void fill(int idex);
				void borrowFromPrev(int idx);
				void borrowFromNext(int idx);
				void merge(int idx);
				friend class Set;
		};
		
		int _t;
		int _dataCount;
		node* root;
	public:
		Set(int t = 3) {root = NULL;_t = t;}
		~Set();
		
		bool insert(const int&);
		void remove(const int&);
		bool contains(const int&);
		bool empty() const { return (_dataCount == 0); }
		friend ostream& operator<< (ostream&,Set&);
};