#include <iostream>
#include <math.h>

using namespace std;

class position {
	private:
		double _x;
		double _y;
		double _z;
	public:
		struct point {
			double x;
			double y;
			double z;
		};
		
		enum Axis
		{
			X, Y, Z
		};
		
		position(double x = 0, double y = 0, double z = 0) {
			
		}
		
		void setPosition(double x, double y, double z) {

		}
		
		point getCoordinates() {
			
		}
		
		void shift(Axis axis, double length) {
			
		}
		
		void rotate(Axis axis, double angle) {
			
		}
};

int main(int argc, char *argv[]) {
	position point(1,2,3);
	cout << point.getCoordinates().x;
}