#include <iostream>
#include "stack.h"

using namespace std;

stack::stack() {
    list = NULL;
    size = 0;
}

stack::~stack() {
    while(list != NULL) {
        node* delMe = list;
        list = list->next;
        delete delMe;
    }
}

stack::node::node(double value, node* n) {
    data = value;
    next = n;
}

void stack::push(double x) {
    node* newNode = new node(x);
    newNode->next = list;
    list = newNode;
    size++;
}

double stack::pop() {
    if(list!=NULL) {
        node* current = list;
        double data = current->data;
        list = list->next;
        delete current;
        size--;
        return data;
    }
    return 0;
}

