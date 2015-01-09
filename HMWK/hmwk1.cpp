/*
Matthew Koken
*/

#include <stdio>

class fraction {
private:
	int n;
	int d;
public:
	//class interface - all the prototype for the class (typically inside the header), no implementation
	fraction(); //default constructor
	fraction(int);
	fraction(int, int);
	float frac2dec();
	void print();
	int getN();  //accessor 
	int getD();
	int setN(int); //mutator
	int setD(int);
	void simplify(); //homework: algorithm to simplify
	fraction operator+ (fraction);
	fraction operator- (fraction);
	fraction operator* (fraction);
	fraction operator/ (fraction);

	fraction(int a) {
		n = a;
		d = 1;
	}

	fraction(int a, int b) {
		n = a;
		d = b;
	}

	float frac2dec() {
		float dec = n / d;
		return dec;
	}
	
	void print() {
		cout << n << "/" << d;
	}
	
	int getN() {
		return n;
	}
	
	int getD() {
		return d;
	}
	
	void setN(int a) {
		n = a;
	}
	
	void setD(int a) {
		d = a;
	}
	
	int gcd(int a, int b) {
		int tmp;
		a = abs(a);
		b = abs(b);
		while (a > 0) {
			tmp = b;
			a = b % a;
			b = tmp;
		}
		return b;
	}
	
	void simplify() {
		int gcd;
		gcd = gcd(n, d);
		n /= gcd;
		d /= gcd;
	}



};
