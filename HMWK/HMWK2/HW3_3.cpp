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
/*
Inserts "entry" before the current item or ar the front.
*/
void sequence::insert(const value_type& entry) {
    if(size_t < CAPACITY) {
        
        if(current_index!=-1) {
            for(int i = used-1; i >= current_index; i--) {
                data[i+1]=data[i];
            }
        } else {
            current_index = 0;
        }
        data[current_index] = entry;
        used++;
    }
}
void sequence::attach(const value_type& entry) {
    if (used < CAPACITY)
    {
    	if (current_index == -1)
    	{
    		data[used] = entry;
    		current_index = used;
    	} else {
    		for (int i = used - 1; i > current_index; i--)
    		{
    			data[i + 1] = data[i];
    		}
    		data[++current_index] = entry;
    	}
		used ++;
    }
}
void sequence::remove_current() {
    if (/* condition */)
    {
    	/* code */
    }
}
size_type sequence::size() const {
    return used;
}
bool sequence::is_item() const {
    return (current_index != -1);
}

value_type sequence::current() const {
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