#include "vector"
using namespace std;

class MinHeap
{
private:
    vector<int> _vector;
    void reheap_down(int index);
    void reheap_up(int index);
    void Heapify();

public:
    MinHeap();
    MinHeap(const vector<int>& vector);
    MinHeap();

    void Insert(int newValue);
    int GetMin();
    void DeleteMin();
};