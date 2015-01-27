#include <iostream>
#include "HW4_2_a.h"

using namespace std;
int main(int argc, char *argv[]) {
	sequence seq;
	seq.insert(1.1);
	seq.insert(2.2);

	for (int i = 0; i < 100; ++i)
	{
		seq.insert(i);
	}

	cout << seq << endl;
	
	seq.add_front(3.3);
	seq.remove_front();
	seq.add_end(4.4);
	
	sequence seq1;
	seq1.insert(2.3);
	seq1.insert(4.2);
	
	seq += seq1;
	
	cout << seq << endl;
}