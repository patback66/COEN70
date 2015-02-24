#include <iostream>

using namespace std;

class ExpressionTree {
	private:
		class node {
			public:
				node(double v) {type=0;value=v;op=0;left=NULL;right=NULL;};
				node(int o, int t) {type=t;op=o;left=NULL;right=NULL;};
				int type;
				double value;
				int op;
				node* left;
				node* right;
		};
		node* root;
		void build(const std::string&);
		double evaluate(node*);
		string extractSubString(const string& str, int&);
		void dealloc(node*);
	public:
		ExpressionTree(const std::string&);
		~ExpressionTree();
		double evaluate();
		void print_preoder(node*);
		void print_postorder(node*);
		void print_inorder(node*);