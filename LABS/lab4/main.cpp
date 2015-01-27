#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

double postfix(string input) {
    input+=" ";
    double operand1;
    double operand2;
    string delim = " ";
    
    stack stk ;
    int curSpace = 0;
    
    string temp;
    
    
    while(curSpace <= input.length()) {
        double result;
        int pos = (int)input.find(delim, curSpace);
        temp = input.substr(curSpace, pos);
        curSpace = pos;
        
        //check the temp for operators or float
        if(temp == "+") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            result = operand1 + operand2;
            stk.push(result);
        } else if(temp == "-") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            result = operand1 - operand2;
            stk.push(result);
        } else if(temp == "*") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            result = operand1 * operand2;
            stk.push(result);
        } else if(temp == "/") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            result = operand1 / operand2;
            stk.push(result);
        } else if(temp == "%") {
            operand1 = stk.pop();
            operand2 = stk.pop();
            result = (int)operand1 % (int)operand2;
            stk.push(result);
        }
        else {
            double num = stof(temp);
            stk.push(num);
        }
            
    }
    return stfstk.pop();
}

int main(int argc, char *argv[]) {
    while(true)
    {
        string input;
        cout << "Enter Expression:" << endl;
        getline(cin, input);
        cout << postfix(input) << endl;
    }
}