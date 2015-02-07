#include <cstdlib>

using namespace std;

template <class Item>
class queue {
    public:
        //TYPEDEFS
        typedef std::size_t size_type;
        typedef Item value_type;
        //CTOR/DTOR
        queue();
        queue(const queue<Item>& source);
        ~queue();
        class node {
            public:
                Item d;
                node* n;
                node(const Item& x = Item(), node* y = NULL) : d(x), n(y) {};
        };
        
        void pop();
        void push(const Item& entry);
        void operator =(const queue<Item>& source);
        bool empty() const { return (count == 0); }
        Item front() const;
        size_type size() const { return count; }
        class 
    private:
        node *rear_ptr;
        size_type count;
}