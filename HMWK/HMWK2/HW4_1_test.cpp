#include <iostream>
#include "HW4_1.h"

using namespace std;

int main(int argc, char *argv[]) {
	hw::string str("Hello");
	hw::string wstr(" World!");
	
	str += wstr;
	
	cout << str << endl;
	
	return 0;
}