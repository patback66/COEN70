#include <iostream>
#include "AVL.h"

using namespace std;
int main(int argc, char *argv[]) {
	AVLTree tree;
	for (int i = 0;i < 10;i ++) {
		tree.insert(i);
	}
	
	tree.printTree();	
	
	cout << "\n\n\n" << endl;
	cout << tree.contains(5) << endl;
	tree.remove(5);
	tree.remove(8);
	
	cout << tree.contains(5) << endl;
	cout << tree.size() << endl;
	
	cout << "\n\n\n" << endl;
	tree.printTree();
	cout << "\n\n\n" << endl;
}