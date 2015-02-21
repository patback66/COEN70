#include "iostream"

class CBT {
	private:
		float* tree;
		int last;
		int cap;
		int p2lc(const int&);
		int c2p(const int&);
		void expand();
	public:
		CBT();
		~CBT();
		void insert(const float&);
		void removeLast();
		int size();
};