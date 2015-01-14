using namespace std;
class Complex {
	private:
		double a;
		double b;
		
	public:
		Complex(double = 0, double = 0);
		double getReal();
		void setReal(double);
		double getImaginary();
		void setImaginary(double);
		
		friend Complex operator+(const Complex& left, const Complex& right);
		friend Complex operator-(const Complex& left, const Complex& right);
		friend Complex operator*(const Complex& left, const Complex& right);
		
		friend ostream& operator<<(ostream& out, const Complex& value);
		friend istream& operator>>(istream& in, Complex& r);
};