#include <iostream>
#include "PriorityQueue.h"

using namespace std;
int main(int argc, char *argv[]) {
	PriorityQueue<double> q;
	q.push(1.11,2);
	q.push(2.22,0);
	q.push(3.33,3);
	
	while (q.size() > 0) {
		cout << q.pop() << endl;
	}
}