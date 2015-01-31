#include <iostream>

using namespace std;


//Simple Node definition 
class item {
	public:
		item(int value, item* n = NULL) {
			data = value;
			next = n;
		}
		int data;
		item* next;
		
		bool operator == (item& rhs) {
			return (data == rhs.data);
		}
		
		friend ostream& operator << (ostream& out, item& rhs) {
			out << rhs.data;
			return out;
		}
};

void printItems(item* h, item* begin, item* end) {
	item* p = h;
	bool shouldPrint = false;
	while( p != NULL) {
		if (*p == *end) {
			shouldPrint = false;
			break;
		}
		if (shouldPrint) {
			cout << *p << ", ";
		}
		if (*p == *begin) {
			shouldPrint = true;
		}
		p = p -> next;
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	item* head = new item(0);
	for (int i = 1; i <= 100; i++) {
		head = new item(i, head);
	}
	item* b = new item(40);
	item* e = new item(30);
	printItems(head, b, e);
	
	return 0;
}