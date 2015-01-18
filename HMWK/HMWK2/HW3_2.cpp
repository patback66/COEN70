#include <iostream>
#include <assert.h>

#include "HW3_2.h"

using namespace std;

/*
Constructor
*/
bag::bag(int c) {
    cap = c;
    size = 0;
    p = new float[c];
}

/*
Destructor
*/
bag::~bag() {
    if(p!=NULL)
        delete [] p;
}

/*
Overload operator =
*/
bag& bag::operator= (const bag& other) {
    
    if(this == &other) //check for self assignment
        return *this;
        
    if(this->p != NULL) //clear
        delete[] this->p;
        
    //copy
    this->p = new float[other.cap];
    this->cap = other.cap;
    this->size = other.size;
    this->max = other.max;
    std::copy(other.p, other.p+other.size, this->p);
    return *this;
}

/*
Copy Constructor
*/
bag::bag(const bag& other) {
    this->p = NULL; //constructor
    *this=other;
}

/*
Overload operator <<
*/
ostream& operator<< (ostream& out, const bag& b) {
    for(int i = 0; i < b.size; i++) {
        out<< p[i] << (i==b.size-1)?'':',';
    }
    return out;
}

/*
Add one "float" to the bag.
*/
void bag::add(float x) {
    if(this->size >= cap) {
        increase();
    }
    p[size++]=x;
}

/*
Increase the capacity of the bag.
*/
void bag::increase() {
    
    float* temp = new float[cap*2];
    std::copy(p, p+size, temp);
    delete[] p;
    p=temp;
    cap*=2;
}

/*
Remove one of "float" from the bag.
*/
bool bag::remove_one(float x) {
    for(int i = 0; i < size; i++) {
        if(p[i]== x) {
            p[i] = p[size-1];
            size--;
            return true;
        }
    }
    return false;
}

/*
Remove all of "float" from the bag.
*/
void bag::remove_all(float x) {
    while(this->remove_one(x)){};
}

/*
Return the size of the bag.
*/
int bag::size() {return size;}

int bag:size_one(float x) {
    int count = 0;
    for(int i = 0; i< size; i++) {
        if(p[i] == x)
            count++;
    }
    return count;
}

/*
Overload the + operator
*/
bag bag::operator+ (const bag& rhs) {
    if(this->size == 0) {
        return rhs;
    }
    if(rhs.size == 0) {
        return *this;
    }
    bag new_bag;
    delete[] new_bag.p;
    new_bag.p = new float[cap + rhs.cap];
    new_bag.cap = cap + rhs.cap;
    new_bag.size = size + rhs.size;
    
    if(max>rhs.max) {
        max_bag.max = max;
    } else {
        new_bag.max = rhs.max;
    }
    
    std::copy(this->p, this->p + this->size, new_bag.p);
    std::copy(rhs.p, rhs.p + rhs.size, new_bag.p + this->size);
    return new_bag;
}

/*
Overload the - operator.
*/
bag& bag::operator- (const bag& rhs) {
    bag n;
    if(this->size == 0) {
        return n;
    } if(rhs.size == 0) {
        return n;
    }
    bag a = *this;
    bag b = rhs;
    for(int i = 0; i< b.size; i++) {
        a.remove_one(b.p[i]);
    }
    return a;
}

bag& operator-=(const bag& rhs) {
    *this = *this - rhs;
    return *this;
}