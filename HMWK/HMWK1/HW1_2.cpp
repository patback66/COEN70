#include <iostream>
#include <assert.h>

using namespace std;

class statistician {
	private:
		long _length;
		double _lastNumber;
		double _sum;
		double _smallest;
		double _largest;
	public:
		statistician() {
			
		}
		void next_number(double number) {
			
		}
		double getLastNumber() {
			
		}
		double getLargestNumber() {
			
		}
		double getSmallestNumber() {
			
		}
		double getMean() {
			
		}
		double getSum() {
			
		}
		long length() {
			
		}
		void reset() {
			
		}
		statistician operator+ (statistician b) {
			
		}
};

int main(int argc, char *argv[]) {
	statistician s;
	s.next_number(1.1);
	s.next_number(-2.4);
	s.next_number(0.8);
	cout << s.getLargestNumber() << endl;
	cout << s.getLastNumber() << endl;
	cout << s.getMean() << endl;
	cout << s.getSmallestNumber() << endl;
	cout << s.getSum() << endl;
}