#include <iostream>
#include <assert.h>
#include "stack.h"

using namespace std;

//Function used to evaluate the given expression
//Takes in an expression and an empty stack
//After evaluation, the result is being stored at the top of stack
void evaluateExpression(string& exp, stack* stk);

//Utility Function used to check if given string is an operator
bool isOperator(string& exp);

//Calculate the answer of given two numbers and operator
double processOpt(char&,double&,double&);

int main(int argc, char *argv[]) {
	
	//Create a stack
	stack* stk = new stack();
	
	while (true) {
		//Get the expression from std::cin
		string str;
		getline(cin, str);
		
		//Check if the input is empty
		while (str.length() == 0) {
			cout << "Please enter a valid expression." << endl;
			getline(cin,str);
		}
		
		//Evaluate the expression
		evaluateExpression(str, stk);
		
		
		//Print out the result
		cout << stk -> pop() << endl;
	}
	
	//Free the stack
	delete stk;
	return 0;
}

void evaluateExpression(string& exp, stack* stk) {
	exp += " ";
	long currentIndex = 0;
	//Find the space
	size_t index = exp.find_first_of(" ");

	//Check if space exist
	while (index != string::npos) {
		size_t len = index - currentIndex;
		//Get substring from currentIndex to index
		string value = exp.substr(currentIndex, len);
		
		//Check if the substring is operator
		if (isOperator(value)) {
			//Check if we have enough items in the stack to perform the operation
			if (stk -> size() >= 2) {

				//Get the value and operator
				double arg1 = stk -> pop();
				double arg2 = stk -> pop();
				char opt = value[0];

				//Push the result to stack
				stk -> push(processOpt(opt, arg2, arg1));
			}
		} else {
			//The substring may be a number
			if (value.length() > 0) {
				double dValue = 0;
				//Call stod to convert str to number
				try {
					dValue = stod(value);
				} catch(const std::invalid_argument& ia) {
					cout << "Expecting a number, get: "<< value << endl;
				}

				//Save the number to stack
				stk -> push(dValue);
			}
		}
		
		//Update Current Index and find next space
		currentIndex = index + 1;
		index = exp.find_first_of(" ", currentIndex);
	}
}

// Return result of operation
double processOpt(char& opt, double& arg2, double& arg1) {
	switch (opt) {
		case '+':
			{
				double rst = arg2 + arg1;
				return rst;
			}
			break;
		case '-':
			{
				double rst = arg2 - arg1;
				return rst;
			}
			break;
		case '*':
			{
				double rst = arg2 * arg1;
				return rst;
			}
			break;
		case '/':
			{
				double rst = arg2 / arg1;
				return rst;
			}
			break;
		case '%':
		{
			double rst = (int)arg2 % (int)arg1;
			return rst;
		}
		break;
		default:
			assert("Unexpected Operator");
			return -1;
	}
}

bool isOperator(string& exp) {
	if (exp.length() != 1) {
		return false;
	}
	
	if (exp[0] == '+' || exp[0] == '-' || exp[0] == '*' || exp[0] == '/' || exp[0] == '%') {
		return true;
	} else {
		return false;
	}
}