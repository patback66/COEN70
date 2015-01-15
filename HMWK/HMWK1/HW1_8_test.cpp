#include <iostream>
#include <math.h>
#include "HW1_8.h"

using namespace std;

int main(int argc, char *argv[]) {
	quadratic q(2,-10,3);
	
	cout << q.numberOfRealRoots() << endl; //expected 2
	cout << q.smallerSolution() << endl; //expected 0.320551
	cout << q.largerSolution() << endl; //expected 4.67945
	
	return 0;
}