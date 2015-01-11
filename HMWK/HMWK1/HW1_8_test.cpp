#include <iostream>
#include <math.h>
#include "HW1_8.h"

using namespace std;

int main(int argc, char *argv[]) {
	quadratic q(2,-10,3);
	
	cout << q.numberOfRealRoots() << endl;
	cout << q.smallerSolution() << endl;
	cout << q.largerSolution() << endl;
	
	return 0;
}