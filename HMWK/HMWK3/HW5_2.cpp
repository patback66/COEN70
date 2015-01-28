#include <iostream>
#include "HW5_2.h"
using namespace std;

node::node(int value, node* n) {
    data = value;
    next = n;
}

node node::operator ==(const node& other) {
    return data == other.data;
}


//remove all duplicates in the given linked list;
void prob2(node* list) {

  node* n1; 
  node* n2;
  node* dup;
  n1 = list;
 
  /* Pick elements one by one */
  while(n1 != NULL && n1->next != NULL)
  {
     n2 = n1;
     while(n2->next != NULL)
     {
       //delete if dup
       if(n1->data == n2->next->data)
       {
          dup = n2->next;
          n2->next = n2->next->next;
          delete dup;
       }
       else
       {
          n2 = n2->next;
       }
     }
     n1 = n1->next;
  }
}

//test for 5.2
void test2() {
    node* n = new node(1, NULL);
    node* tmp1 = n;
    node* tmp2  = new node(1);
    n->next = tmp2;
    tmp1 = tmp2; 
    tmp2 = new node(2, NULL);
    tmp1->next = tmp2;
    prob2(n);
    tmp1 = n;
    while(tmp1 != NULL) {
        cout << tmp1->data << endl;
        tmp1 = tmp1->next;
    } 
}

int main() {
    test2();
    
    
}