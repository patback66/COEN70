#include <iostream>
#include "HW4_1.h"

using namespace std;

int main(int argc, char *argv[]) {
	hw::string str("Hello World");
	hw::string wstr("World");
	
	int index = str.search(wstr);
	
	cout << index << endl;
	
	//str += wstr;
	
	str += " Woof!";
	str += 'M';
	cout << str << endl;
	str.insert(0, "Meow");
	cout << str << endl;
	str.deletion(3, 10);
	cout << str << endl;
	
	return 0;
}