#include "list.h"

class OrderedList: public List {
    public:
        OrderedList();
        //~OrderedList();
        OrderedList(const OrderedList&);
        friend ostream&	operator<<(ostream&, const OrderedList&);
        void insert(const int&);
        void replace(int, int);
};