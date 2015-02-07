#include "HW8_6.h"

using namespace std;

template <class Item>
queue<Item>::queue() {
    count = 0;
    rear_ptr = NULL;
}

template <class Item>
queue<Item>::queue(const queue<Item>& source) {
    *this = source;
}

template <class Item>
queue<Item>::clear() {
    node* cur = rear_ptr;
    while(cur!=NULL) {
        node* delMe = cur;
        cur = cur-> n;
        delete delMe;
    }
    count = 0;
}

template <class item>
queue<Item>::~queue() {
    clear();
}

template <class Item>
void queue<Item>::operator =(const queue<Item>& source) {
    if(this == &source)
        return;
    clear();
    rear_ptr = NULL;
    if(source->rear_ptr == NULL)
        return;
    rear_ptr = new node(Item());
    node* temp = source.rear_ptr->n;
    while(temp!=NULL) {
        push(temp->d); //assumes add works with sentinel
        temp=temp->n;
    }
    return this;
}

template <class Item>
Item queue<Item>::front() const {
    assert(!empty());
    return rear_ptr->n->d;
}

template <class Item>
void queue<Item>::pop() {
    assert(!empty());
    node* delMe = rear_ptr->n;
    rear_ptr->n = delMe->n;
    delete delMe;
    count--;
}

template <class Item>
void queue<Item>::push(const Item& entry) {
    if(empty()) {
        rear_ptr = new node(entry);
        rear_ptr->n = rear_ptr;
    } else {
        node* newNode = new node(entry, rear_ptr->n);
        rear_ptr->n = newNode;
    }
    count++;
}