#include <iostream>

using namespace std;
void asterisk(int n, int x) {
    if (n/2 >= x) {
        //print the level n of asterisks
        for(int i = 0; i <= x; i++) {
            cout << "*";
        }
        cout << endl; 
        //print the next 2 levels of asterisks
        asterisk(n,x+1);
        //print this level again -> occurs after i>n
        for(int i = 0; i <= x; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    asterisk(10, 0);
}

