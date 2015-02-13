#include <iostream>

using namespace std;
void asterisk(int n, int x) {
    if (n/2 >= x) {
        for(int i = 0; i <= x; i++) {
            cout << "*";
        }
        cout << endl; 
        asterisk(n,x+1);
        for(int i = 0; i <= x; i++) {
            cout << "*";
        }
        cout << endl;
    }
    
}

int main() {
    asterisk(10, 0);
}

