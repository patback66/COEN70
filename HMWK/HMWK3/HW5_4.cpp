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

void reverse(item*& head) {
	//Temp variable to store the head
	item* h = head;
	//Temp variable for next item
	item* n = h -> next;
	//Since the head will become the last node, set its next to NULL
	h -> next = NULL;
	while (n != NULL) {
		//Get the next item in the list
		item* t = n -> next;
		//Reverse the link
		n -> next = h;
		//Adjust current head
		h = n;
		//go next
		n = t;
	}

	//Save the new head back to pointer
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