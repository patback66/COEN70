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
		node* constructTree(const std::string&);
		double evaluateAtNode(node*);
		string extractSubString(const string& str, int&);
	public:
		ExpressionTree(const std::string&);
		
		double evaluate();
};