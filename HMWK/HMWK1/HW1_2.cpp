#include <iostream>
#include <assert.h>

#include "HW1_2.h"

using namespace std;

statistician::statistician() {
	_length = 0;
	_lastNumber = 0;
	_smallest = 0;
	_sum = 0;
	_largest = 0;
}
void statistician::next_number(double number) {
	_lastNumber = number;
	_sum+=number;
	if(_length > 0) {
	    if (_smallest > number) {
    	    _smallest = number
	    }
        if (largest < number) {
            _largest = number;
	    }
	}
	else {
	    _smallest = number;
	    _largest = number;
	}
	_length++;
}
double statistician::getLastNumber() {
    assert(_length>0);
	return _lastNumber;
}
double statistician::getLargestNumber() {
    assert(_length>0);
	return _largest;
}
double statistician::getSmallestNumber() {
    assert(_length>0);
	return _smallest;
}
double statistician::getMean() {
    assert(_length>0);
	return _sum/_length;
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
	statician newStatician = new statistician();
	newStatician._length = _length + b.length();
	newStatician._sum = _sum + b.getSum();
	
	
	if(_length > 0 && b._length > 0) {
	
    	if(_smallest > b.getSmallestNumber()) {
    	    newStatician._smallest = b.getSmallestNumber();
    	}
    	else {
    	    newStatician._smallest = _smallest;
    	}
        if(_largest > b.getLargestNumber()) {
	        newStatician._largest = _largest;
	    }
    	else {
	        newStatician._largest = b.getLargestNumber();
	    }
	}
	else if (_length == 0) {
	    newStatician._smallest = b.getSmallestNumber();
	    newStatician._largest = b.getLargestNumber();
	    newStatician._lastNumber = b.getLastNumber();
	}
	else { //b must be length zero
	    newStatician._smallest = _smallest;
	    newStatician._largest = _largest;
	    newStatician._lastNumber = _lastNumber;
	}    

	return newStatician;
}