/* ArrayExample.cpp */
/*
Matthew Koken
*/
#include <iostream>
using namespace std;

int main()
{
    int score[10];
    for (int i=0; i < 10; ++i) //original did not use proper parts of the array
    //should use slots 0-9 instead of 1-10 since 10 does not exist.
    {
        score[i]=3*i;
        cout << score[i] << " "; //added space at the end for readability
    }
return 0;}