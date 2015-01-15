#include <iostream>
#include "HW1_2.h"

using namespace std;

int main(int argc, char *argv[]) {
	statistician s;
	s.next_number(1.1);
	s.next_number(-2.4);
	s.next_number(0.8);
	cout << s.getLargestNumber() << endl; //expected 1.1
	cout << s.getLastNumber() << endl; //expected 0.8
	cout << s.getMean() << endl; //expected -0.166667
	cout << s.getSmallestNumber() << endl; //expected-2.4
	cout << s.getSum() << endl; //expected -0.5
}
