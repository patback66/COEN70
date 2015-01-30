#include <iostream>

#include "HW5_15.h"

using namespace std;

/*
Constructor
*/
sequence::sequence() {
    head = NULL;
    tail = NULL;
    cursor = NULL;
    nodeCount = 0;
    current_index = -1;
}

/*
Starts the sequence at index 0 if there is data, else -1.
*/
void sequence::start() {
    cursor = head;
    current_index = 0;
    if(head == NULL)
        current_index = -1;
}
/*
Advances to the next index if there is more, else becomes -1.
*/
void sequence::advance() {
    if(cursor->next != NULL) {
        cursor = cursor->next;
        current_index++;
    }
}
/*
Inserts "entry" after the current item or ar the front.
*/
void sequence::attach(const value_type& entry) {
    node* newNode = new node(entry, NULL, NULL);
    
    //inserting at the head - first insert
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        cursor = newNode;
        current_index = 0;
    } 
    //inserting at the end
    else if(cursor == tail) {
        cursor->next = newNode;
        newNode->prev = cursor;
        tail = newNode;
    } 
    //inserting somewhere in the middle
    else {
        newNode->next = cursor->next;
        newNode->prev = newNode;
        cursor->next = newNode;
        newNode->next->prev = newNode;
    }
    nodeCount++;
}
/*
Adds a copy of "entry" before the current item or to the end if no current.
*/
void sequence::insert(const value_type& entry) {
    node* newNode = new node(entry, NULL, NULL);
    
    //first insert
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        cursor = newNode;
        current_index = 0;
    }
    //inserting at the front
    else if(cursor == head) {
        newNode->next = cursor;
        cursor->prev = newNode;
        head = newNode;
        current_index++;
    } 
    //inserting in the middle
    else {
        newNode->next = cursor;
        newNode->prev = cursor->prev;
        cursor->prev->next = newNode;
        cursor->prev = newNode;
        current_index++;
    }
    nodeCount++; 
}

/*
Removes the current item, then shifts to fill the gap.
*/
void sequence::remove_current() {
    node* delMe;
    if(cursor!=NULL) {
        //deleting the only item
        if(nodeCount = 1) {
            delMe = cursor;
            cursor = NULL;
            head = NULL;
            tail = NULL;
            delete delMe;
            current_index = -1;
        }
        //deleting the head
        else if(cursor == head) {
            delMe = cursor;
            head = head->next;
            cursor = cursor->next;
            delete delMe;
        }
        //deleting the tail
        else if(cursor == tail) {
            delMe = tail;
            tail = tail->prev;
            tail->next = null;
            cursor = tail;
            delete delMe;
            current_index--;
        }
        //deleting in the middle
        else {
            delMe = cursor;
            cursor->prev->next = cursor->next;
            cursor->next->prev = cursor->prev;
            cursor = cursor->prev;
            delete delMe;
            current_index--;
        }
        nodeCount--;
    }
}
/*
Returns the size of the sequence.
*/
sequence::size_type sequence::size() const {
    return nodeCount;
}

/*
True if the current_index is an item, else false.
*/
bool sequence::is_item() const {
    return (current_index != -1);
}

/*
Returns the current item or -1 if no current item.
*/
sequence::value_type sequence::current() const {
    if (is_item())
    {
    	return cursor->data;
    } else {
    	return -1;
    }
}

/*
Override << operator.
*/
ostream& operator<< (ostream& out, const sequence& seq) {
    out << "{";
    node* cur = seq.head;
    while(cur!=NULL)
    {
        out << cur->data << ", ";
        cur = cur->next;
    }
    out << "}";
    return out;
}

/*
Adds "entry" to the front of the list. Updates current_index to match updated list.
*/
void sequence::add_front(const value_type& entry) {
    if(used >= size_cap) {
        expand();
    }
    if(current_index!=-1) {
        for(int i = used; i > current_index; i--) {
            data[i] = data[i - 1];
        }
    } 
    data[0] = entry;
    used++;
    current_index++;
}
/*
Removes the item in pos 0, then shifts the list down to fill the gap and 
updates the current index.
*/
void sequence::remove_front() {
    for(int i = 0; i < used; i++) {
        data[i] = data[i+1];
    }
    used--;
    current_index--;
    
}
/*
Adds "entry" to the end of the list. If the list is empty, "entry" becomes the 
current item.
*/
void sequence::add_end(const value_type& entry) {
    if(used >= size_cap) {
        expand();
    }
    data[used] = entry;
    used++;
    if(current_index==-1)
        current_index = 0;
}
/*
The last entry becomes the current entry.
*/
void sequence::last_current() {
    if(used == 0)
        current_index = 0;
    else
        current_index = used -1;
}
/*
Override + operator for sequences.
*/
sequence sequence::operator+(const sequence& other) {
	if (other.used == 0)
	{
		return *this;
	}

	if (used == 0)
	{
		return other;
	}

    if(used + other.used >= size_cap) {
        expand();
    }

    sequence nseq;
    copy(data, data + used, nseq.data);
    copy(other.data, other.data + other.used, nseq.data + used);
    nseq.used = used + other.used;
    nseq.current_index = -1;
    return nseq;
}
/*
Override += operator for the sequence operator.
*/
sequence sequence::operator+=(const sequence& other) {
    *this = *this + other;
    return *this;
}
/*
Override [] operator for sequence allows access to sequence elements by index.
*/
sequence::value_type sequence::operator[] (size_type index) const{
    if(index < used)
        return data[index];
    else
        return -1;
}

void sequence::retreat() {
    if(cursor->prev != NULL)
        cursror = cursor->prev;
    //if null, we are at the front so don't go back any more
}