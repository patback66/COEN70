#include <iostream>

using namespace std;

void producePattern(int step, int max) {
	if (step < max * 2) {
		if (step <= max) {
			if (step % 2 != 0) {
				for (int i = 1 ;i < step; i += 2) {
					cout << "  ";
				}
				cout << "* " << endl;
				producePattern(step + 1, max);
			} else {
				if (step % 4 == 0) {
					for (int i = 1; i < step; i += 2) {
						cout << "* * ";
					}
				} else {
					for (int i = 1 ;i < step - 1; i += 1) {
						cout << " ";
					}
					cout << "* * ";
				}
				cout << endl;
				producePattern(step + 1, max);
			}
		} else {
			if (step % 2 != 0) {
				for (int i = 1 ;i < step; i += 2) {
					cout << "  ";
				}
				cout << "* " << endl;
				producePattern(step + 1, max);
			} else {
				if (step % 4 == 0) {
					for (int i = 1 ;i < step - ((max / 4) + 1); i += 1) {
						cout << " ";
					}
					for (int i = max; i < step; i += 2) {
						cout << "* * ";
					}
				} else {
					for (int i = 1 ;i < step - 1; i += 1) {
						cout << " ";
					}
					cout << "* * ";
				}
				cout << endl;
				producePattern(step + 1, max);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	producePattern(1, 8);
	return 0;
}