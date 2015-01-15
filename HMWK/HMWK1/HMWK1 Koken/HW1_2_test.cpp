#include <iostream>
#include "HW1_2.cpp"

using namespace std;

int main(int argc, char *argv[]) {
	statistician s;
	s.next_number(1.1);
	s.next_number(-2.4);
	s.next_number(0.8);
	cout << s.getLargestNumber() << endl;
	cout << s.getLastNumber() << endl;
	cout << s.getMean() << endl;
	cout << s.getSmallestNumber() << endl;
	cout << s.getSum() << endl;
}
