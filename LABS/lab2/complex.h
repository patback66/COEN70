/*

COEN 70 Lab 2

Tian Zhang
Matthew Koken

*/

#include <iostream>

using namespace std;

class Complex {
	private:
		double _real;
		double _imaginary;
	public:
		/*
		Constructor
		*/
		Complex(double real = 0, double imaginary = 0);
		/*
		Get the real part of the complex number
		*/
		double getReal();
		/*
		Get the imaginary part of the complex number
		*/
		double getImaginary();
		/*
		Set the real part of the complex number
		*/
		void setReal(double real);
		/*
		Set the imaginary part of the complex number
		*/
		void setImaginary(double imaginary);

		/*
		Operator + to process addition 
		*/
		friend Complex operator+ (const Complex &lhs, const Complex &rhs);
		/*
		Operator * to process multiplication 
		*/
		friend Complex operator* (const Complex &lhs, const Complex &rhs);

		/*
		Handle input/output
		*/
		friend ostream& operator<<(ostream& out, const Complex& object);
		friend istream& operator>>(istream& in, Complex& object);
};