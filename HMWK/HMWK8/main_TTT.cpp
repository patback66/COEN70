#include <iostream>
#include "TTT.h"

using namespace std;
int main(int argc, char *argv[]) {
	TTT tree;
	tree.insert(4);
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.insert(6);
	tree.insert(5);
	tree.insert(8);
	tree.insert(7);
	
	tree.printTree();
	cout << "\n\n\n" << endl;
	
	cout << tree.contains(5) << endl;
	cout << tree.size() << endl;
}