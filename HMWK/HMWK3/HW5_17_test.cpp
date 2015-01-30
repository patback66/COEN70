#include <iostream>
#include "HW5_17.h"

using namespace std;
int main(int argc, char *argv[]) {
	bag bg;
	
	bg.insert(3.14);
	bg.insert(6.28);
	bg.insert(3.15);
	bg.insert(3.14);
	
	bag nBG(bg);
	nBG.insert(3.14);
	
	nBG += bg;
	
	cout << bg.count(3.14) << ";"<< bg.size() << endl;
	bg.erase(3.14);
	cout << bg.count(3.14) << endl;
	cout << nBG.count(3.14) << endl;
	cout << bg.grab() << endl;
}