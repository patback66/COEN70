#include <iostream>
#include <math.h>
#include "HW1_5.h"

using namespace std;

position::position(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;
}

void position::setPosition(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;    
}

position::point position::getCoordinates() {
	point p = {_x, _y, _z};
	return p;
}

void position::shift(Axis axis, double length) {
	switch(axis) {
	    case X:
	        _x+=length;
	        break;
	    case Y:
	        _y+=length;
	        break;
	    case Z:
	        _z+=length;
	    default:
	        break;
	}
}

void position::rotate(Axis axis, double angle) {
	switch(axis) {
	    case X:
	        double y = _y;
	        double z = _z;
	        _y = y * cos(angle) + z * sin(angle);
	        _z = y * sin(angle) + z * cos(angle);
	        break;
	    case Y:
	        double x = _x;
	        double z = _z;
	        _x = x * cos(angle) + z * sin(angle);
	        _z = (-x) * sin(angle) + z * cos(angle);
	        break;
        case Z:
            double x = _x;
            double y = _y;
            _x = x * cos(angle) - y * sin(angle);
            _y = x * sin(angle) + y * cos(angle);
            break;
        default:
            break;
	}
}