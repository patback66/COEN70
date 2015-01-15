#include <iostream>
#include <math.h>
#include "HW1_5.h"

using namespace std;

/*
Constructor
*/
position::position(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;
}

/*
Sets the current position.
*/
void position::setPosition(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;
}

/*
Gets the current position
*/
position::point position::getCoordinates() {
	point p = {_x, _y, _z};
	return p;
}

/*
Makes a shift of length in the given axis.
Uses enum Axis defined in HW1_5.h
*/
void position::shift(Axis axis, double length) {
	switch (axis) {
		case X:
			_x += length;
			break;
		case Y:
			_y += length;
			break;
		case Z:
			_z += length;
			break;
		default:
			break;
	}
}

/*
Makes a rotation about the specified axis for the specified angle.
Uses Enum Axis defined in HW1_5.h
*/
void position::rotate(Axis axis, double angle) {
	double x = _x;
	double y = _y;
	double z = _z;
	//need to save current position to use while calculating and updating position
	switch (axis) {
		case X:
			_y = y * cos(angle) - z * sin(angle);
			_z = y * sin(angle) + z * cos(angle);
			break;
		case Y:
			_x = x * cos(angle) + z * sin(angle);
			_z = (-x) * sin(angle) + z * cos(angle);
			break;
		case Z:
			_x = x * cos(angle) - y * sin(angle);
			_y = x * sin(angle) + y * cos(angle);
			break;
		default:
			break;
	}
}