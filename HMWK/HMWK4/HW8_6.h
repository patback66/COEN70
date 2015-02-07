#include <cstdlib>
#include <iostream>
#include "assert.h"

using namespace std;

template <class Item>
class queue {
    public:
        //TYPEDEFS
        typedef std::size_t size_type;
        typedef Item value_type;
        //CTOR/DTOR
        queue() {
            count = 0;
            rear_ptr = NULL;
        }
        queue(const queue<Item>& source){
            rear_ptr = NULL;
           *this = source;
        }
        void clear() {
            if (rear_ptr != NULL)
            {
                node* cur = rear_ptr -> n;
                while(cur != rear_ptr) {
                    node* delMe = cur;
                    cur = cur -> n;
                    delete delMe;
                }
                delete rear_ptr;
                rear_ptr = NULL;
                count = 0;
            }
        }
        ~queue() {
            clear();    
        }

        class node {
            public:
                Item d;
                node* n;
                node(const Item& x = Item(), node* y = NULL) : d(x), n(y) {};
        };
        
        void pop() {
            assert(!empty());
            node* delMe = rear_ptr -> n;
            rear_ptr -> n = delMe->n;
            if (delMe == rear_ptr)
            {
                rear_ptr = NULL;
            }
            delete delMe;
            count--;
        }
        
        void push(const Item& entry) {
            if(empty()) {
                rear_ptr = new node(entry);
                rear_ptr->n = rear_ptr;
            } else {
                node* newNode = new node(entry, rear_ptr -> n);
                rear_ptr -> n = newNode;
            }
            count++;
        }
        
        void operator =(const queue<Item>& source) {
            if(this == &source)
                return;
            clear();
            rear_ptr = NULL;
            if(source.rear_ptr == NULL)
                return;
            rear_ptr = new node(Item());
            node* temp = source.rear_ptr->n;
            while(temp!=NULL) {
                push(temp->d); //assumes add works with sentinel
                temp=temp->n;
            }
        }
        
        bool empty() const { return (count == 0); }
        Item front()  const {
            assert(!empty());
            return rear_ptr-> n ->d;
        }
        size_type size() const { return count; }
    private:
        node *rear_ptr;
        size_type count;
};