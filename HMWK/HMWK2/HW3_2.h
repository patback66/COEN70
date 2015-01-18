#include <iostream>

using namespace std;

class bag{
    private:
        int cap;
        int _size;
        float* p;
    public:
        /*
        Constructor
        */
        bag(int = 10);
        /*
        Construct a bag given a bag.
        */
        bag(const bag&);
        /*
        Destructor
        */
        ~bag();
        /*
        Overload operator =
        */
        bag& operator=(const bag&);
        /*
        Overload operator <<
        */
        friend ostream& operator<<(ostream&, const bag&);
        /*
        Add the "float" to the bag.
        */
        void add(float);
        /*
        Remove one of "float" from the bag.
        */
        bool remove_one(float);
        /*
        Remove all of "float" from the bag.
        */
        void remove_all(float);
        /*
        Ceck if "float" is contained within the bag.
        */
        bool contains(float);
        /*
        Returns the element count of the bag.
        */
        int size();
        int size_one(float);
        /*
        Overload the + operator
        */
        bag operator+(const bag&);
        /*
        Overload the - operator.
        */
        bag operator-(const bag&);
        bag operator-=(const bag&);
        /*
        Increase the capacity of the bag.
        */
        void increase();
};