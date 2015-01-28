/*
 *
 *    COEN70 HW2
 *    Tian Zhang
 *    Matthew Koken
 *
 */

#include <iostream>
#include "HW3_2.h"

using namespace std;

int main(int argc, char *argv[]) {
	bag b;
	b.add(3.14);
	b.add(4.28);
	
	cout << b << endl;
	
	bag c;
	c.add(3.14);
	
	bag d = b - c;
	
	cout << d;
	
	return 0;
}