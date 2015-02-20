#include <iostream>
#include "HMWK10_1.h"

using namespace std;

template <typeName T>
double eTree<T>::evaluate(node* n) {
    if(n==NULL)
        return 0;
    if(isleaf(n))
        return n->d;
    else if(isOperator(n)) {
        if(n->d == '*')
            return evaluate(n->lc) * evaluate(n->rc);
        else if(n->d == '+')
            return evaluate(n->lc) + evaluate(n->rc);
    }
}

template <typeName T>
bool eTree<T>::isLeaf(const node& n) {
    if(n->lc == NULL && n->rc == NULL) 
        return true;
    return false;
}

template <typeName T>
bool eTree<T>::isNonLeaf(const node& n) {
    char c = n->d;
    if (c.length() != 1) {
		return false;
	}
	
	if (c[0] == '+' || c[0] == '*') {
		return true;
	}
	return false;
}

template <typeName T>
void eTree<T>::build(String innput) {
    input+=" ";
    int pos = 0;
    while(input.length() != 0) {
        pos = (int)input.find(" ", 0);
        String temp = input.substr(0, pos);
        if(temp == "+" || temp == "*")
            insert(temp);
        else
            double num = stod(temp.c_str());
            insert(num);
        input.erase(0, pos+1);
    }
}

template <typeName T>
bool eTree<T>::insert(const T&) {
    
}


int main() {
    String input = "3 + 7 * 10";
    eTree et;
    et.build(input);
    cout << et.evaluate();
}
