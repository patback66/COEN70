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
/*
Adds a copy of "entry" after the current item or to the end if no current.
*/
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
/*
Removes the current item, then shifts to fill the gap.
*/
void sequence::remove_current() {
    if (is_item())
    {
    	for (int i = current_index; i < used - 1; i++)
    	{
    		data[i] = data[i + 1];
    	}
    	used --;
    	if (used == 0)
    	{
    		current_index = -1;
    	}
    }
}
size_type sequence::size() const {
    return used;
}
bool sequence::is_item() const {
    return (current_index != -1);
}

/*
Returns the current item or -1 if no current item.
*/
value_type sequence::current() const {
    if (is_item())
    {
    	return data[current_index];
    } else {
    	return -1;
    }
}
/*
Adds "entry" to the front of the list. Updates current_index to match updated list.
*/
void sequence::add_front(const value_type& entry) {
    if(size_t < CAPACITY) {
        if(current_index!=-1) {
            for(int i = used-1; i >=0; i--) {
                data[i+1]=data[i];
            }
        } 
        data[0] = entry;
        used++;
        current_index++;
    }
}
/*
Removes the item in pos 0, then shifts the list down to fill the gap and 
updates the current index.
*/
void sequence::remove_front() {
    for(int i = 0; i < used; i++) {
        data[i] = data[i+1];
    }
    used--;
    current_index--;
    
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