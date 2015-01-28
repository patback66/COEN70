#include <iostream>
using namespace std;

class node {
    public:
        node(int, node* = NULL);
        node operator ==(const node&);
        int data;
        node* next;
};