#include <iostream>
#include <assert.h>

#include "HW1_2.h"

using namespace std;

statistician::statistician() {
	_length = 0;
	_lastNumber = 0;
	_sum = 0;
	_smallest = 0;
	_largest = 0;
}
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
double statistician::getLastNumber() {
	assert(_length > 0);
	return _lastNumber;
}
double statistician::getLargestNumber() {
	assert(_length > 0);
	return _largest;
}
double statistician::getSmallestNumber() {
	assert(_length > 0);
	return _smallest;
}
double statistician::getMean() {
	assert(_length > 0);
	return (_sum / _length);
}
double statistician::getSum() {
	return _sum;
}
long statistician::length() {
	return _length;
}
void statistician::reset() {
	_length = 0;
	_lastNumber = 0;
	_sum = 0;
	_smallest = 0;
	_largest = 0;
}
statistician statistician::operator+ (statistician b) {
	statistician newStatistician;
	
	newStatistician._length = _length + b._length;
	newStatistician._sum = _sum + b._sum;

	if (_length > 0 && b._length > 0)
	{
		newStatistician._lastNumber = b._lastNumber;
		newStatistician._smallest = (_smallest < b._smallest)?_smallest:b._smallest;
		newStatistician._largest = (_largest > b._largest)?_largest:b._largest;
	} else if (b._length == 0) {
		newStatistician._lastNumber = _lastNumber;
		newStatistician._smallest = _smallest;
		newStatistician._largest = _largest;
	} else {
		newStatistician._lastNumber = b._lastNumber;
		newStatistician._smallest = b._smallest;
		newStatistician._largest = b._largest;
	}
	
	return newStatistician;
}