#include <iostream>

using namespace std;

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

void reverse(item*& head) {
	item* h = head;
	item* n = h -> next;
	h -> next = NULL;
	while (n != NULL) {
		item* t = n -> next;
		n -> next = h;
		h = n;
		n = t;
	}
	head = h;
}

int main(int argc, char *argv[]) {
	item* head = new item(0);
	for (int i = 1; i <= 100; i++) {
		head = new item(i, head);
	}
	reverse(head);
	
	item* p = head;
	while( p != NULL) {
		cout << *p << ", ";
		p = p -> next;
	}
	cout << endl;
}