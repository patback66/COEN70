#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main(int argc, char *argv[]) {
    stack stk;
    stk.push(1);
    stk.push(2.0);
    cout << stk.pop() << " " << stk.pop() << endl;
    
}

