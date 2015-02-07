#include <iostream>
#include "HW8_7.h"

using namespace std;
int main(int argc, char *argv[]) {
	deque n;
	
	n.push_back(1.1);
	n.push_back(2.2);
	
	cout << n.pop_front() << endl;
	
	cout << n << endl;
}