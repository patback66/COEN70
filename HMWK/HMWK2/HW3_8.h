#include <iostream>

using namespace std;

class keyed_bag {
	private:
		int _size;
		int _cap;
		/* TBD: Data Struct to implement? */
	public:
		keyed_bag(int = 30);
		~keyed_bag();
		keyed_bag(const keyed_bag&);
		keyed_bag& operator=(const keyed_bag&);
		friend ostream& operator<<(ostream&, const keyed_bag&);

		void insert(const double&, int);
		void remove(int);
		bool keyExist(int);
};