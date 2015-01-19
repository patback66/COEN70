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
    if (used > 0)
	{
		current_index = 0;
	} else {
		current_index = -1;
	}
}
void sequence::advance() {
    if(current_index )
}
void sequence::insert(const value_type& entry) {
    
}
void sequence::attach(const value_type& entry) {
    
}
void sequence::remove_current() {
    
}
size_type sequence::size() const {
    return used;
}
bool sequence::is_item() const {
    return (current_index != -1);
}
value_type sequence::current() const{
    if (is_item())
    {
    	return data[current_index];
    } else {
    	return -1;
    }
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