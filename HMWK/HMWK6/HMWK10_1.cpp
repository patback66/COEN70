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
        if(n->d = '*')
            return evaluate(n->lc) * evaluate(n->rc);
        else if(n->d == '/')
            return evaluate(n->lc) / evaluate(n->rc);
        else if(n->d == '+')
            return evaluate(n->lc) + evaluate(n->rc);
        else if(n->d == '-')
            return evaluate(n->lc) - evaluate(n->rc);
    }
}

template <typeName T>
bool eTree<T>::isLeaf(const nodee& n) {
    if(n->lc == NULL && n->rc == NULL) 
        return true;
    return false;
}