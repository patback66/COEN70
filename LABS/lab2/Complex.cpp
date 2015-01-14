#include <iostream>
#include <string>
#include "Complex.h"

using namespace std;

Complex::Complex(double real, double imaginary) {
    a = real;
    b = imaginary;
}

double Complex::getReal() {
    return a;
}

void Complex::setReal(double real) {
    a = real;
}

double  Complex::getImaginary() {
    return b;
}

void  Complex::setImaginary(double imaginary) {
    b = imaginary;
}

Complex  operator+(const Complex& left, const Complex& right) {
    Complex sum(0, 0);
    sum.a = (left.a + right.a);
    sum.b = (left.b + right.b);
    return sum;
}

Complex operator-(const Complex& left, const Complex& right) {
    Complex dif(0,0);
    dif.a = (left.a - right.a);
    dif.b = (right.b - right.b);
    return dif;
}

Complex operator*(const Complex& left, const Complex& right) {
    Complex product(0,0);
    product.a = (left.a * right.a) - (left.b * right.b);
    product.b = (left.a * right.b) + (left.b * right.a);
    return product;
}


ostream& operator<<(ostream& out, const Complex& value) {
    out << value.a << "+" << value.b << "*i";
	return out;
}

istream& operator>>(istream& in, Complex& r) {
    double real, imaginary;
    string input;
    getline (in,input);
    //get pos for real part of string
    size_t first = input.find_first_of("+");
    //get pos for imaginary part
    size_t second = input.find_first_of("*", first);
    
    if(first == string::npos) {
        real = 0;
    } else if (first == 0) {
        real = 0;
    } else {
        real = stod(input.substr(0, first));
    }
    
    if(second == string::npos) {
        imaginary = 0;
    } else if (second == 0) {
        imaginary = 0;
    } else {
        imaginary = stod(input.substr(first+1, second));
    }
    
    r.setReal(real);
    r.setImaginary(imaginary);
	return in;
}
