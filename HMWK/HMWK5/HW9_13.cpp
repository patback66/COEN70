#include <iostream>
#include "assert.h"

using namespace std;

float pow(float x, int n)
{
    float temp;
    if( n == 0)
       return 1;
    temp = pow(x, n/2);       
    if (n%2 == 0)
        return temp*temp;
    else
    {
        if(n > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

int main() {
    cout << pow(10, 2) << endl;
    cout << pow(2.5, 3) << endl;
}