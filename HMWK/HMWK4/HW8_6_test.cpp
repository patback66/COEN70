#include "HW8_6.h"

using namespace std;
int main() {
    queue<int> q;
    q.push(10);
    q.push(12);
    q.push(1);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
}