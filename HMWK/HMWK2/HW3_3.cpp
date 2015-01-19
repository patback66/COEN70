#include <iostream>
#include <assert.h>

#include "HW3_3.h"

using namespace std;

/*
Constructor
*/
sequence::sequence() {
    used = 0;
    current_index = -1;
}
void sequence::start() {
    
}
/*
Advances to the next index if there is more, else becomes -1.
*/
void sequence::advance() {
    if(is_item()) {
        if(current_index+1 >= used)
            current_index++;
        else
            current_index=-1;
    }
}
void sequence::insert(const value_type& entry) {
    
}
void sequence::attach(const value_type& entry) {
    
}
void sequence::remove_current() {
    
}
size_type sequence::size() const {
    
}
bool sequence::is_item() const {
    
}
value_type sequence::current() const {
    
}
void sequence::add_front(const value_type& entry) {
    
}
void sequence::remove_front() {
    
}
void sequence::add_end(const value_type& entry) {
    
}
void sequence::last_current() {
    
}
sequence& sequence::operator+(const sequence& other) {
    
}
sequence& sequence::operator+=(const sequence& other) {
    
}
value_type sequence::operator[] (size_type index) {
    
}