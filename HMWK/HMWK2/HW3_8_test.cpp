#include <iostream>
#include "HW3_8.h"

using namespace std;
int main(int argc, char *argv[]) {
	keyed_bag kb;
	kb.insert(3.14, 0);
	kb.insert(3.15, 3);
	
	cout << kb << endl;
	
	kb.remove(3);
	cout << kb << endl;

	keyed_bag b = kb;
	b.insert(5.55, 2);
	cout << kb << endl;
	cout << b << endl;
}