#include <iostream>
#include <math.h>
#include "HW1_8.h"

using namespace std;

int quadratic::_numberOfRealRoots(double* sol1, double* sol2) {
	
}

quadratic::quadratic(double a, double b, double c) {
	_a = a;
	_b = b;
	_c = c;
}

void quadratic::updateCoeffcients(double a, double b, double c) {
	_a = a;
	_b = b;
	_c = c;
}

double quadratic::getA() {
	return _a;
}

double quadratic::getB() {
	return _b;
}

double quadratic::getC() {
	return _c;
}

double quadratic::evaluate(double x) {
	return (_a * x * x) + (_b * x) + _c
}

int _numberOfRealRoots(double* sol1, double* sol2) {
	if(_a==0) {
		if(_b==0) {
			if(_c==0;) { //case 1
				if(sol!=NULL) {
					*sol1=0;
				}
				if(sol2!=NULL) {
					*sol2=0;
				}
				return 3;
			}
			else { //case 2
				return 0;
			}
		}
		else { //case 3
			if(sol1!=NULL) {
				*sol1 = (-_c/_b);
			}
			if(sol2!=NULL() {
				*sol2 = (-_c/_b);
			}
			return 1;
		}
	}
	else {
		double b2 = _b * _b;
		double _4ac = 4 * _a * _c;
		
		if(b2<_4ac) { //case 4
			if(*sol1!=NULL) {
				*sol1 = 0;
			}
			if(*sol2!=NULL) {
				*sol2 = 0;
			}
			return 0;
		}
		if(b2 == _4ac) { //case 5
			if(*sol1!=NULL) {
				*sol1 = -_b / (2 * _a);
			}
			if(*sol2!=NULL) {
				*sol2 = -_b / (2 * _a);
			}
			return 1;
		}
		if(b2 > _4ac) { //case 6
			if(*sol1!=NULL) {
				*sol1 = (-_b - sqrt(_b * _b - 4 * _a * _c))/(2 * _a)
			}
			if(*sol2!=NULL) {
				*sol2 = (-_b + sqrt(_b * _b - 4 * _a * _c))/(2 * _a)
			}
			return 2;
		}
		
	}
	return;
}

int quadratic::numberOfRealRoots() {
	return _numberOfRealRoots(NULL, NULL);
}

double quadratic::smallerSolution() {
	double sol1, sol2;
	_numberOfRealRoots(sol1, sol2);
	if(sol1 > sol2) {
		return sol2;
	}
	else {
		return sol2;
	}
}

double quadratic::largerSolution() {
	double sol1, sol2;
	_numberOfRealRoots(sol1, sol2);
	if(sol1 < sol2) {
		return sol2;
	}
	else {
		return sol1;
	}
}

quadratic operator+ (const quadratic& q1, const quadratic& q2) {
	quadratic q = new quadratic();
	q._a = (q1._a + q2._a);
	q._b = (q1._b + q2_b);
	q._c = q1._c + q2._c;
	return q;
}

quadratic operator * (double r, const quadratic& q) {
	quadratic newQ = new quadratic();
	newQ._a = r * q._a;
	newQ._b = r * q._b;
	newQ._c = r * q._c;
	return q;
}