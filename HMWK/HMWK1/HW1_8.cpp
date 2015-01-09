#include <iostream>
#include <math.h>

class quadratic {
	private:
		double _a;
		double _b;
		double _c;
		
		int _numberOfRealRoots(double* sol1, double* sol2) {
			
		}
	public:
		quadratic(double a = 0, double b = 0, double c = 0) {
			
		}
		
		void updateCoeffcients(double a, double b, double c) {
			
		}
		
		double getA() {
			
		}
		
		double getB() {
			
		}
		
		double getC() {
			
		}
		
		double evaluate(double x) {
			
		}
		
		int numberOfRealRoots() {
			
		}
		
		double smallerSolution() {
			
		}
		
		double largerSolution() {
			
		}
		
		friend quadratic operator+ (const quadratic& q1, const quadratic& q2) {
			
		}
		
		friend quadratic operator * (double r, const quadratic& q) {
			
		}
};

using namespace std;
int main(int argc, char *argv[]) {
	quadratic q(2,-10,3);
	
	cout << q.numberOfRealRoots() << endl;
	cout << q.smallerSolution() << endl;
	cout << q.largerSolution() << endl;
	
	return 0;
}