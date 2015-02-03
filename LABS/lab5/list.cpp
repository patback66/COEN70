/*
@author Matthew Koken
@author Immanuel Amirtharaj
*/
#include <iostream>
#include "list.h"
using namespace std;

//Function:	Constructors	
List::List() {
    list = NULL;
    cursor = NULL;
    size = 0;
}
//Function:	Destructor	
List::~List() {
    node* deletenode = list;
    node* tempnode;
    while(deletenode != NULL) {
        tempnode = deletenode->next;
        delete deletenode;
        deletenode = tempnode;
    }
}
//Function:	Assignment operator
const List&	List::operator=(const List& other) {
    if(this != &other) {
        if(this->list!=NULL) {
            delete[] this->list;
            this->cursor = NULL;
        }
        
        size = other.size;
        
        node* np = other.list;
        this->list = new node(np->data, NULL);
        cursor = this->list;
        np = np->next;
        //loop to copy nodes
        while(np!=NULL) {
            cursor->next = new node(np->data, NULL);
            cursor=cursor->next;
            np=np->next;
        }
    }
    return *this;
}
//Function:	Copy constructor	
List::List(List& other) {
    if(this != &other) {
        if(this->list!=NULL) {
            this->cursor = NULL;
        }
        
        size = other.size;
        
        node* np = other.list;
        this->list = new node(np->data, NULL);
        cursor = this->list;
        np = np->next;
        //loop to copy all nodes
        while(np!=NULL) {
            cursor->next = new node(np->data, NULL);
            cursor=cursor->next;
            np=np->next;
        }
    }
}

//Function:	output	operator	
ostream& operator<<(ostream& out, const List& lhs) {
    List::node *newnode = lhs.list;
    while(newnode!=NULL) {
        out << newnode->data << ", ";
        newnode = newnode->next;
    }
    return out;
}

//Function:	Insert an item to the list	
//Postcondition: insert	after the pointer and	
//move the pointer to the new item	
void List::insert(const int& value) {
    List:node *n = new node(value, NULL);
    if(list == NULL) {
        list = n;
        cursor = n;
    }
    else {
        cursor->next = n;
        cursor = n;
    }
    size++;
}

/*
Constructor for node
*/
List::node::node(int value, node* n) {
    data = value;
    next = n;
}

void List::replace(int index, int value) {
    if(index > size - 1)
        return;
    node* cur = list;
    for(int i = 0; i<index-1 && cur!=NULL; i++)
        cur = cur->next;
    cur->data = value;
}