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
	//parse input so Y/y/N/n doesn't matter
	input = tolower(input);
	//found it
	if (input == 'y') {
		cout << "Great!" << endl;
		return;
	} else {
		//didn't find it -> need to guess higher or lower
		cout << "Is the correct number larger than " << midpoint << " ? (y or n)" << endl;
		char input;
		cin >> input;
		input = tolower(input);
		//guess higher
		if (input == 'y') {
			guess(midpoint + 1, high);
		} else {
		//guess lower
			guess(low, midpoint - 1);
		}
	}
}

int main(int argc, char *argv[]) {
	guess(1, 100000);
	return 0;
}