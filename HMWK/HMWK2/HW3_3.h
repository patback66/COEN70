/*
 *
 *    COEN70 HW2
 *    Tian Zhang
 *    Matthew Koken
 *
 */

#include <iostream>

using namespace std;

class sequence {
    public:
        //Typedefs
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        /*
        Constructor
        */
        sequence();
        void start();
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        size_type size() const;
        bool is_item() const;
        value_type current() const;
        void add_front(const value_type& entry);
        void remove_front();
        void add_end(const value_type& entry);
        void last_current();
        sequence operator+(const sequence& other);
        sequence operator+=(const sequence& other);
        value_type operator[] (size_type index) const;
        friend ostream& operator<< (ostream&, const sequence&);
    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
};