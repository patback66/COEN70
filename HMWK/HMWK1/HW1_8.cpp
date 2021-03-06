#include <iostream>
#include <math.h>
#include "HW1_8.h"

using namespace std;

/*
Returns the number of real roots, sets the solutions (up to 2) if there are
real roots.
*/
int quadratic::_numberOfRealRoots(double* sol1, double* sol2) {
	if (_a == 0) {
		if (_b == 0) {
			if (_c == 0) { //first case, where case is the given rule
				if (sol1 != NULL) {
					*sol1 = 0;
				}
				if (sol2 != NULL) {
					*sol2 = 0;
				}
				return 3;
			} else { //second case
				if (sol1 != NULL) {
					*sol1 = 0;
				}
				if (sol2 != NULL) {
					*sol2 = 0;
				}
				return 0;
			}
		} else { //3rd case
			if (sol1 != NULL) {
				*sol1 = (-_c)/(_b);
			}
			if (sol2 != NULL) {
				*sol2 = (-_c)/(_b);
			}
			return 1;
		}
	} else {
		double b2 = _b * _b;
		double _4ac = 4 * _a * _c;
		if (b2 < _4ac) { //4th case
			if (sol1 != NULL) {
				*sol1 = 0;
			}
			if (sol2 != NULL) {
				*sol2 = 0;
			}
			return 0;
		}
		if (b2 == _4ac) { //5th case
			if (sol1 != NULL) {
				*sol1 = (-_b)/(2*_a);
			}
			if (sol2 != NULL) {
				*sol2 = (-_b)/(2*_a);
			}
			return 1;
		}
		if (b2 > _4ac) { //6th case
			if (sol1 != NULL) {
				*sol1 = (-_b-sqrt((_b*_b) - (4*_a*_c)))/(2*_a);
			}
			if (sol2 != NULL) {
				*sol2 = (-_b+sqrt((_b*_b) - (4*_a*_c)))/(2*_a);
			}
			return 2;
		}
		return 0;
	}
}

/*
Constructor uses form ax^2+bx+c
*/
quadratic::quadratic(double a, double b, double c) {
	_a = a;
	_b = b;
	_c = c;
}

/*
Updates the coefficients for the form ax^2+bx+c
*/
void quadratic::updateCoeffcients(double a, double b, double c) {
	_a = a;
	_b = b;
	_c = c;
}

/*
Returns a from ax^2+bx+c
*/
double quadratic::getA() {
	return _a;
}

/*
Returns b from ax^2+bx+c
*/
double quadratic::getB() {
	return _b;
}

/*
Returns c from ax^2+bx+c
*/
double quadratic::getC() {
	return _c;
}

/*
Solves ax^2+bx+c given x
*/
double quadratic::evaluate(double x) {
	return ((_a * x * x) + (_b * x) + _c);
}

/*
Returns the number of real roots
*/
int quadratic::numberOfRealRoots() {
	return _numberOfRealRoots(NULL,NULL);
}

/*
Computes the smaller root (b-sqrt...)
*/
double quadratic::smallerSolution() {
	double sol1,sol2;
	_numberOfRealRoots(&sol1, &sol2);
	if (sol1 > sol2) {
		return sol2;
	} else {
		return sol1;
	}
}

/*
Computes the larger root (b+sqrt...)
*/
double quadratic::largerSolution() {
	double sol1,sol2;
	_numberOfRealRoots(&sol1, &sol2);
	if (sol1 < sol2) {
		return sol2;
	} else {
		return sol1;
	}
}

/*
Addition of quadratics of from ax^2+bx+c
*/
quadratic operator+ (const quadratic& q1, const quadratic& q2) {
	quadratic n;
	n._a = q1._a + q2._a;
	n._b = q1._b + q2._b;
	n._c = q1._c + q2._c;
	return n;
}

/*
Multiplication of quadratic of form ax^2+bx+c by a factor r
*/
quadratic operator * (double r, const quadratic& q) {
	quadratic n;
	n._a = q._a * r;
	n._b = q._b * r;
	n._c = q._c * r;
	return n;
}