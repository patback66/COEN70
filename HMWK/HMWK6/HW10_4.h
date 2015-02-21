#include "iostream"

class BinaryTree {
	private:
		float* tree;
		bool* is_present;
		int current_node;
		int cap;
		int tSize;
		int p2lc(const int&) const;
		int c2p(const int&) const;
		void expand();
	public:
		BinaryTree();
		~BinaryTree();
		void create_first_node(const float&);
		void shift_to_root();
		void shift_up();
		void shift_left();
		void shift_right();
		void change(const float&);
		void add_left(const float&);
		void add_right(const float&);
		int size();
		float retrieve() const;
		bool has_parent() const;
		bool has_left_child() const;
		bool has_right_child() const;
};