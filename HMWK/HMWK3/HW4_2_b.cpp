#include <iostream>
#include "HW4_2_b.h"

using namespace std;

/*
Constructor
*/
set::set(long cap) {
	_size = 0;
	_cap = cap;
	_data = new double[cap];
}

/*
Destructor
*/
set::~set() {
	if (_data != NULL)
		delete []_data;
}

/*
Copy Comnstructor
*/
set::set(const set& other) {
	_data = NULL;
	*this = other;
}

/*
Override the + operator of the set.
*/
set& set::operator=(const set& rhs) {

	if (this != &rhs)
	{
		if (_data != NULL)
			delete []_data;

		_data = new double[rhs._cap];
		copy(rhs._data,rhs._data + rhs._size, _data);

		_size = rhs._size;
		_cap = rhs._cap;
	}

	return *this;
}

/*
Override the << operator for the set.
*/
ostream& operator<<(ostream& out, const set& rhs) {
	for (int i = 0; i < rhs._size; i++)
	{
		out << rhs._data[i] <<", ";
	}

	return out;
}

/*
Searches for "value" in the set. True if found, else false.
*/
bool set::contains(const double& value) const{
	bool find = false;

	for (int i = 0; i < _size; i++)
	{
		if (_data[i] == value)
		{
			find = true;
			break;
		}
	}

	return find;
}

/*
Checks for duplicate before adding to the end.
*/
void set::insert(const double& value) {
	if (!contains(value))
	{
		if (_size >= _cap)
		{
			_cap *= 2;
			double* temp = new double[_cap];
			copy(_data,_data + _size, temp);
			delete []_data;
			_data = temp;
		}

		_data[_size] = value;
		_size ++;
	}
}

/*
Removes specified node and fixes gap in the linked list.
*/
void set::remove(const double& value) {
	for (int i = 0; i < _size; i++)
	{
		if (_data[i] == value) {
			_size --;
			for (int j = i; j < _size; j++)
			{
				_data[j] = _data[j + 1];
			}
			break;
		}
	}
}

/*
Returns the size of the set.
*/
long set::size() const {
	return _size;
}