#include <iostream>
#include "stack.h"

using namespace std;

stack::stack() {
    list = NULL;
    size = 0;
}

stack::~stack() {
    node* delMe = list;
    list = list->next;
    while(list != NULL) {
        delete delMe;
        delMe = list;
        list = list-> next;
    }
}

stack::node(double data, node* n) {
    value = data;
    next = n;
}

void stack::push(double x) {
    node newNode = new node(x);
    newNode->next = list;
    list = newNode;
    size++;
}

float stack::pop() {
    if(list!=NULL) {
        node current = list;
        float data = current->data;
        list = list->next;
        delete current;
        size--;
        return data;
    }
    return -1;
}

