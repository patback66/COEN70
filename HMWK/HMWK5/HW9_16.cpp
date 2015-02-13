#include <iostream>

using namespace std;

void guess(int low, int high) {
	if (low == high) {
		cout << "The number shoud be " << high;
		return;
	}
	
	int midpoint = (low + high) / 2;
	cout << "Is the number " << midpoint << " ? (y or n)" << endl;
	char input;
	cin >> input;
	input = tolower(input);
	if (input == 'y') {
		cout << "Great!" << endl;
		return;
	} else {
		cout << "Is the correct number larger than " << midpoint << " ? (y or n)" << endl;
		char input;
		cin >> input;
		input = tolower(input);
		if (input == 'y') {
			guess(midpoint + 1, high);
		} else {
			guess(low, midpoint - 1);
		}
	}
}

int main(int argc, char *argv[]) {
	guess(1, 100000);
	return 0;
}