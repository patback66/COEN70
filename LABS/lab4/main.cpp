//Matthew Koken and Eric Castronovo
#include <iostream>
#include <string>
#include <cstdlib>
#include "stack.h"

using namespace std;

double postfix(string input) {
    input+=" ";
    double operand1;
    double operand2;
    string delim = " ";
    
    stack stk ;
    int curSpace = 0;
    int pos = 0;
    
    
    string temp;
    //traverse line until everything is removed
    while(curSpace != input.length()) {
        double result;
        pos = (int)input.find(delim, curSpace);
        temp = input.substr(curSpace, pos);
        //remove the used substring
        input.erase(curSpace, pos+1);
        
        //check the temp for operators or float, use
        if(temp == "+") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            result = operand1 + operand2;
            stk.push(result);
        } else if(temp == "-") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            //reverse because stack adds to top
            result = operand2 - operand1;
            stk.push(result);
        } else if(temp == "*") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            result = operand1 * operand2;
            stk.push(result);
        } else if(temp == "/") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            //reverse because stack adds to top
            result = operand2 / operand1;
            stk.push(result);
        } else if(temp == "%") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            //reverse because stack adds to top
            result = (int)operand2 % (int)operand1;
            stk.push(result);
        } else if(temp != " " && temp!= "") {
            double num = stod(temp.c_str());
            stk.push(num);
        }
            
    }
    return stk.pop();
}

int main(int argc, char *argv[]) {
    cout << postfix("-3.0 5.1 + 4.2 2.1 - *") << endl; //expected 4.1
    cout << postfix("5.4 2.4 * 6.9 /") << endl; //expected 1.87826
    cout << postfix("32 15 % 2 9 + /") << endl; //expected 0.1818181
    cout << postfix("-3 +") << endl; //expected -3, stack returns 0 when nothing to pop so this doesn't break
    cout << postfix("243 3.2 * 8 / 778.5 +") << endl; //expected 875.7
    cout << postfix("22 93 - 15%") << endl; //expected 15
    cout << postfix("0") << endl; //expected 0
    cout << postfix("5 75 / 2 +") << endl; //expected 2.06667
    cout << postfix("468 63.5 * 8.325 2468 + +") << endl; //expected 32194.3
    cout << postfix("20 5 / 6 /") << endl; //expected 0.666667
    
    //user input ver
    /*while(true)
    {
        string input;
        cout << "Enter Expression:" << endl;
        getline(cin, input);
        cout << postfix(input) << endl;
    }*/
}

