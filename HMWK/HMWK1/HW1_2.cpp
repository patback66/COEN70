#include <iostream>
#include <assert.h>

#include "HW1_2.h"

using namespace std;

/*
Constructor
Initializes all to zero, next next takes care of smallest.
*/
statistician::statistician() {
	_length = 0;
	_lastNumber = 0;
	_sum = 0;
	_smallest = 0;
	_largest = 0;
}

/*
Add a new number. Updates sum and smallest/largest.
*/
void statistician::next_number(double number) {
	_sum += number;
	_lastNumber = number;
	if (_length > 0) {
		if (number > _largest) {
			_largest = number;
		}
		if (number < _smallest) {
			_smallest = number;
		}
	} else {
		_smallest = number;
		_largest = number;
	}
	_length ++;
}

/*
Returns the last added number.
*/
double statistician::getLastNumber() {
	assert(_length > 0);
	return _lastNumber;
}
/*
Returns the largest number.
*/
double statistician::getLargestNumber() {
	assert(_length > 0);
	return _largest;
}
/*
Returns the smallest number.
*/
double statistician::getSmallestNumber() {
	assert(_length > 0);
	return _smallest;
}
/*
Returns the mean.
*/
double statistician::getMean() {
	assert(_length > 0);
	return (_sum / _length);
}
/*
Returns the sum.
*/
double statistician::getSum() {
	return _sum;
}
/*
Returns the length.
*/
long statistician::length() {
	return _length;
}
/*
Resets to initial conditions.
*/
void statistician::reset() {
	_length = 0;
	_lastNumber = 0;
	_sum = 0;
	_smallest = 0;
	_largest = 0;
}
/*
Adds 2 statisticians together.
*/
statistician statistician::operator+ (statistician b) {
	statistician newStatistician;
	
	newStatistician._length = _length + b._length;
	newStatistician._sum = _sum + b._sum;
	
	/*
	Case for both > 0: last is the rhs's last
	*/
	if (_length > 0 && b._length > 0)
	{
		newStatistician._lastNumber = b._lastNumber;
		newStatistician._smallest = (_smallest < b._smallest)?_smallest:b._smallest;
		newStatistician._largest = (_largest > b._largest)?_largest:b._largest;
	} 
	/*
	Case for rhs length zero. Last number is lhs's last
	*/
	else if (b._length == 0) {
		newStatistician._lastNumber = _lastNumber;
		newStatistician._smallest = _smallest;
		newStatistician._largest = _largest;
	} 
	/*
	Case for lhs size 0: last number is rhs's last
	*/
	else{
		newStatistician._lastNumber = b._lastNumber;
		newStatistician._smallest = b._smallest;
		newStatistician._largest = b._largest;
	}
	
	return newStatistician;
}