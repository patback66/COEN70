#include <iostream>
#include "assert.h"

using namespace std;

float pow(float x, int n)
{
    float temp;
    if( n == 0)
       return 1;
   //need to calculate to reduce recursive iterations
    temp = pow(x, n/2);       
    if (n%2 == 0)
        return temp*temp;
        //use formula to cut down recursions
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