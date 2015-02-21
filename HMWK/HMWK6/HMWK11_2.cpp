#include <iostream>
using namespace std;

class pq
{
    private:
        int last; //last is the index of the last element
        int cap;
        int p2lc(int); //left child
        int c2p(int);
        void reheap_up(int);
        void reheap_down();
        int *data;
    
    public:
        priorityQueue();
        ~priorityQueue();
        int pop(); //remove from front, reheap down
        void push(int); //remove from back, reheap up
        bool empty();
        void expand();
        int size();
        bool isEmpty();
};

int pq::p21c(int i) {
    return 2*i+1;
}

int pq::c2p(int i) {
    return (int)(i-1)/2;
}

void pq::expand() {
    cap++;
    int *tmp = new int[cap];
    std::copy(tmp, cap-1, temp);
    delete[] data;
    data = tmp;
}

void pq::push(int x) {
    if(data.size == cap)
        expand();
    data[++last] = x;
    reheap_up(last);
}
void pq::reheap_up(int i) {
    while(data[c2p(i)]<data[i] && i>0) {
        std::swap(data[c2p(i)], data[i])
        i = c2p(i);
    }
}

int pq::fsc(int i) {
    lc = p2lc(i);
    rc = lc+1;
    if(data[lc]<w[rc] && data[lc] < data[rc])
        return lc;
    else
        return rc;
}
void pq::reheap_down() {
    inti=0;
    while(p2lc(i)<=last && data[i] > data[fsc(i)] )
        int sc = fsc(i);
        swap(data[i], data[sc]);
        i=sc;
}

int pq::pop() {
    int temp = data[0];
    data[0] = data[last];
    last--;
    reheap_down();
    return temp;
}
