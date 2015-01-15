/*

COEN 70 Lab 2

Tian Zhang
Matthew Koken

*/
#include "complex.h"
#include <string>

Complex::Complex(double real, double imaginary) {
	_real = real;
	_imaginary = imaginary;
}

double Complex::getReal() {
	return _real;
}

double Complex::getImaginary() {
	return _imaginary;
}

void Complex::setReal(double real) {
	_real = real;
}

void Complex::setImaginary(double imaginary) {
	_imaginary = imaginary;
}

Complex operator+ (const Complex &lhs, const Complex &rhs) {
	Complex n(lhs._real + rhs._real, lhs._imaginary + rhs._imaginary);
	return n;
}

Complex operator* (const Complex &lhs, const Complex &rhs) {
	Complex n(((lhs._real * rhs._real) - (lhs._imaginary * rhs._imaginary)), ((lhs._real * rhs._imaginary) + (lhs._imaginary * rhs._real)));
	return n;
}

ostream& operator<<(ostream& out, const Complex& object) {
	out << object._real << "+" << object._imaginary << "*i";
	return out;
}

istream& operator>>(istream& in, Complex& object) {
	//Get the input from istream
	string input;
	getline(in, input);

	//Find the appearance of "+" and "*" to determine where is the valid real and imaginary.
	size_t endOfReal = input.find_first_of("+");
	size_t endOfImaginary = input.find_first_of("*",endOfReal + 1);

	//Check if user entered a formatted real part
    if (endOfReal != string::npos)
	{
		//Get the substring and convert back to double
		string realStr = input.substr(0, endOfReal);
		if (realStr != "")
		{
			object._real = stod(realStr);
		} else {
			object._real = 0;
		}
	} else {
		//There is no "+", assume the input is a real number
		object._real = stod(input);
	}

	//Check if user entered a formatted imaginary part
	if (endOfImaginary != string::npos)
	{
		//Get the substring and convert back to double
		string imaginaryStr = input.substr(endOfReal + 1, endOfImaginary);
		if (imaginaryStr != "")
		{
			object._imaginary = stod(imaginaryStr);
		} else {
			object._imaginary = 0;
		}		
	} else {
		//No formatted imaginary part found, try to find the simplified expression (like 5+3i)
		endOfImaginary = input.find_first_of("i",endOfReal + 1);
		if (endOfImaginary != string::npos)
		{
			//Found the simplified expression
			//Store to Complex
			string imaginaryStr = input.substr(endOfReal + 1, endOfImaginary);
			object._imaginary = stod(imaginaryStr);
		} else {
			//Cannot find imaginary part, set it to 0
			object._imaginary = 0;
		}
	}

	return in;
}