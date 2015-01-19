#include <iostream>
#include "HW3_3.h"

using namespace std;
int main(int argc, char *argv[]) {
	sequence seq;
	seq.insert(1.1);
	seq.insert(2.2);
	
	seq.add_front(3.3);
	seq.remove_front();
	seq.add_end(4.4);
	
	sequence seq1;
	seq1.insert(2.3);
	seq1.insert(4.2);
	
	seq += seq1;
	
	cout << seq << endl;
}