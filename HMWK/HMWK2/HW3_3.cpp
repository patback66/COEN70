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
/*
Starts the sequence at index 0 if there is data, else -1.
*/
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
    if(used < CAPACITY) {
        if(current_index!=-1) {
            for(int i = used; i > current_index; i--) {
                data[i] = data[i - 1];
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
/*
Returns the size of the sequence.
*/
sequence::size_type sequence::size() const {
    return used;
}

/*
True if the current_index is an item, else false.
*/
bool sequence::is_item() const {
    return (current_index != -1);
}

/*
Returns the current item or -1 if no current item.
*/
sequence::value_type sequence::current() const {
    if (is_item())
    {
    	return data[current_index];
    } else {
    	return -1;
    }
}

/*
Override << operator.
*/
ostream& operator<< (ostream& out, const sequence& seq) {
    for (int i = 0; i < seq.used; i++) {
        out << seq.data[i] << ", ";
    }
    return out;
}

/*
Adds "entry" to the front of the list. Updates current_index to match updated list.
*/
void sequence::add_front(const value_type& entry) {
    if(used < CAPACITY) {
        if(current_index!=-1) {
            for(int i = used; i > current_index; i--) {
                data[i] = data[i - 1];
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
/*
Adds "entry" to the end of the list. If the list is empty, "entry" becomes the 
current item.
*/
void sequence::add_end(const value_type& entry) {
    if(used < CAPACITY) {
        data[used] = entry;
        used++;
        if(current_index==-1)
            current_index = 0;
    }
}
/*
The last entry becomes the current entry.
*/
void sequence::last_current() {
    if(used == 0)
        current_index = 0;
    else
        current_index = used -1;
}
/*
Override + operator for sequences.
*/
sequence sequence::operator+(const sequence& other) {
	if (other.used == 0)
	{
		return *this;
	}

	if (used == 0)
	{
		return other;
	}

    sequence nseq;
    copy(data, data + used, nseq.data);
    copy(other.data, other.data + other.used, nseq.data + used);
    nseq.used = used + other.used;
    nseq.current_index = -1;
    return nseq;
}
/*
Override += operator for the sequence operator.
*/
sequence sequence::operator+=(const sequence& other) {
    *this = *this + other;
    return *this;
}
/*
Override [] operator for sequence allows access to sequence elements by index.
*/
sequence::value_type sequence::operator[] (size_type index) const{
    if(index < used)
        return data[index];
    else
        return -1;
}