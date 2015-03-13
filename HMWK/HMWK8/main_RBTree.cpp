#include <iostream>
#include "RBTree.h"

using namespace std;
int main(int argc, char *argv[]) {
	RBTree tree;
	tree.insert(8);
	tree.insert(6);
	tree.insert(7);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	
	tree.printTree();
	cout << "\n\n\n" << endl;
	
	cout << tree.contains(5) << endl;
	cout << tree.size() << endl;
}