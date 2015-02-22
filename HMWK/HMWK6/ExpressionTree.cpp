#include "ExpressionTree.h"
#include <iostream>

using namespace std;

string ExpressionTree::extractSubString(const string& str, int& strEnd) {
	int firstHalfBegin = -1;
	int firstHalfEnd = 0;
	int numberOfLeft = 0;
	int numberOfRight = 0;
	for (int i = 0;i < str.length(); i ++) {
		if (str[i] == '(') {
			if (firstHalfBegin == -1) {
				firstHalfBegin = i + 1;
			}
			numberOfLeft ++;
			continue;
		}
		if (str[i] == ')') {
			numberOfRight ++;
			if (numberOfLeft == numberOfRight) {
				firstHalfEnd = i - 1;
				break;
			}
		}
	}
	if (firstHalfBegin == -1) {
		firstHalfBegin = 0;
	}
	strEnd = firstHalfEnd;
	string firstHalfStr = str.substr(firstHalfBegin, firstHalfEnd - firstHalfBegin);
	return firstHalfStr;
}

ExpressionTree::node* ExpressionTree::constructTree(const string& str) {
	if (str.length() == 0) {
		return NULL;
	}
	int firstHalfEnd = 0;
	string firstHalfStr = extractSubString(str,firstHalfEnd);
	if (firstHalfStr.length() == 0) {
		//Final Stage
		string::size_type index = str.find_first_of("+*");
		if (index != string::npos) {
			double v1,v2;
			try {
				v1 = stod(str.substr(0,index - 1));
				v2 = stod(str.substr(index+1));
			} catch (...) {
				cout << "Convert Error!" << endl;
			}
			node *n = new node(str[index],1);
			n -> left = new node(v1);
			n -> right = new node(v2);
			return n;
		} else {
			double value;
			try {
				value = stod(str);
			} catch (...) {
				cout << "Convert Error!" << endl;
			}
			node *n = new node(value);
			return n;
		}
	} else {
		string restExpression = str.substr(firstHalfEnd);
		string::size_type index = restExpression.find_first_of("+*");
		if (index != string::npos) {
			node *nNode = new node(restExpression[index],1);
			nNode -> left = constructTree(firstHalfStr);
			string secHalf = extractSubString(restExpression.substr(index + 1), firstHalfEnd);
			if (secHalf.length() == 0) {
				nNode -> right = constructTree(restExpression.substr(index + 1));
			} else {
				nNode -> right = constructTree(secHalf);
			}
			return nNode;
		} else {
			throw "Error !";
		}
	}
	
	return NULL;
}

ExpressionTree::ExpressionTree(const string& str) {
	int firstHalfEnd = 0;
	string firstHalfStr = extractSubString(str,firstHalfEnd);
	string restExpression = str.substr(firstHalfEnd);
	string::size_type index = restExpression.find_first_of("+*");
	if (index != string::npos) {
		root = new node(restExpression[index],1);
		if (firstHalfStr.length() == 0) {
			firstHalfStr = restExpression.substr(0, index);
		}
		root -> left = constructTree(firstHalfStr);
		string secHalf = extractSubString(restExpression.substr(index + 1), firstHalfEnd);
		if (secHalf.length() == 0) {
			root -> right = constructTree(restExpression.substr(index + 1));
		} else {
			root -> right = constructTree(secHalf);
		}
	} else {
		double value;
		try {
			value = stod(str);
		} catch (...) {
			cout << "Convert Error!" << endl;
		}
		node *n = new node(value);
		root = n;
	}
}

double ExpressionTree::evaluateAtNode(node* n) {
	if (n != NULL) {
		if (n -> type == 0) {
			return n -> value;
		}
		double leftV = evaluateAtNode(n -> left);
		double rightV = evaluateAtNode(n -> right);
		if (n -> op == '+') {
			return leftV + rightV;
		}
		if (n -> op == '*') {
			return leftV * rightV;
		}
	}
	throw "Should Never Reach Here!";
	return -1;
}

double ExpressionTree::evaluate() {
	return evaluateAtNode(root);
}

int main() {
	ExpressionTree a("( ( 3 + 5 ) * ( 2 * 2 ) ) * ( 2 * 2 )");
	ExpressionTree b("( 5 + 5 ) + ( 5 + 2 )");
	ExpressionTree c("2 * 2");
	
	cout << a.evaluate() << endl; //128
	cout << b.evaluate() << endl; //17
	cout << c.evaluate() << endl; //4
	
	return 0;
}