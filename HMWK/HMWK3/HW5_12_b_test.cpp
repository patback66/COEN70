#include <iostream>
#include "HW5_12_b.h"

using namespace std;

int main(int argc, char *argv[]) {
	set x;

	x.insert(5);
	x.insert(4);
	x.insert(3);
	x.insert(2);

	set y(x);

	y.insert(1);

	set z = y;

	z.insert(0);

	cout << "x: " << x << endl; //should print out x: 5, 4, 3, 2,
	cout << "y: " << y << endl; //should print out y: 5, 4, 3, 2, 1,
	cout << "z: " << z << endl; //shoudl print out z: 5, 4, 3, 2, 1, 0,

	return 0;
}