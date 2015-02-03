#include "orderedlist.h"

OrderedList::OrderedList() : List() {
}


void OrderedList::insert(const int& value) {
    node* cur = list;
    node* newNode = new node(value, NULL);
    
    // Special case for the head end
    if (cur == NULL)
    {
        list = newNode;
    }
    //inserting before head
    else if(value < cur->data) {
        newNode->next = list;
        list = newNode;
    }
    else
    {
        // Locate the node before the point of insertion
        while (cur->next!=NULL &&
               cur->next->data < newNode->data)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
    size++;
}

void OrderedList::replace(int index, int value) {
    node* cur = list;
    node* pprev = NULL;
    if(index-1 < size) {
        //delete at the index given
        for(int i = 0; i < index-1 && cur!=NULL; i++) {
            pprev = cur;
            cur = cur->next;
        }
        pprev->next = cur->next;
        delete cur;
        //use insert to preserve order
        insert(value);
    }
}

//Function:	output	operator
ostream& operator<<(ostream& out, const OrderedList& lhs) {
    List::node *newnode = lhs.list;
    while(newnode!=NULL) {
        out << newnode->data << ", ";
        newnode = newnode->next;
    }
    return out;
}