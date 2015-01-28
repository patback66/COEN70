#include <iostream>
using namespace std;

class set {
	private:
		long _size;
		long _cap;
		double *_data;
	public:
		set(long = 30);
		~set();
		set(const set&);
		set& operator=(const set&);
		friend ostream& operator<<(ostream&, const set&);

		void insert(const double&);
		void remove(const double&);
		long size() const;
		bool contains(const double&) const;
};