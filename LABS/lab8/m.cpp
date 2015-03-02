//
//  expressiontree.cpp
//  Lab8
//
//  Created by brian kevin pingel on 2/23/15.
//  Copyright (c) 2015 Brian Pingel & Matthew Koken. All rights reserved.
//

#include "expressiontree.h"
#include <stack>

using namespace std;

//initializing tree builds it as well
ExpressionTree::ExpressionTree(){
    build();
}
//destructor calls a clearing function
ExpressionTree::~ExpressionTree(){
    dealloc(root);
}
//prints out tree in postorder, resembles postfix
void ExpressionTree::print_postorder(node* r){
    if(r!=NULL){
        print_postorder(r->left);
        print_postorder(r->right);
        if(r->type == 0){
            cout << r->value << " ";
        }
        else{
            //cases for operators
            switch (r->op) {
                case 0:
                    cout << "+ ";
                    break;
                case 1:
                    cout << "- ";
                    break;
                case 2:
                    cout << "* ";
                    break;
                case 3:
                    cout << "/ ";
                    break;
                    
                default:
                    break;
            }
        }
        if(r == root)
            cout << endl;
    }
}
//prints out in inorder, should resemble infix
void ExpressionTree::print_inorder(node* r){
    if(r!=NULL){
        print_inorder(r->left);
        if(r->type == 0){
            cout << r->value << " ";
        }
        else{
            switch (r->op) {
                case 0:
                    cout << "+ ";
                    break;
                case 1:
                    cout << "- ";
                    break;
                case 2:
                    cout << "* ";
                    break;
                case 3:
                    cout << "/ ";
                    break;
                    
                default:
                    break;
            }
        }
        print_inorder(r->right);
        if(r == root)
            cout << endl;
    }
}
//prints in preorder, looks dumb
void ExpressionTree::print_preorder(node* r){
    if(r!=NULL){
        if(r->type == 0){
            cout << r->value << " ";
        }
        else{
            switch (r->op) {
                case 0:
                    cout << "+ ";
                    break;
                case 1:
                    cout << "- ";
                    break;
                case 2:
                    cout << "* ";
                    break;
                case 3:
                    cout << "/ ";
                    break;
                    
                default:
                    break;
            }
        }
        print_preorder(r->left);
        print_preorder(r->right);
        if(r == root)
            cout << endl;
    }
}
//call to recursive eval
int ExpressionTree::evaluate(){
    return evaluateNode(root);
}
//evaluates subtrees recursively returning value of leaves up to subtrees
int ExpressionTree::evaluateNode(node* r){
    if(r!=NULL){
        int operand1;
        int operand2;
        if(r->type == 0)
            return r->value;
        if(r->left!= NULL)
            operand1 = evaluateNode(r->left);
        if(r->right!=NULL)
            operand2 = evaluateNode(r->right);
        switch (r->op) {
            case 0:
                return operand1 + operand2;
            case 1:
                return operand1 - operand2;
            case 2:
                return operand1 * operand2;
            case 3:
                return operand1 / operand2;
                
            default:
                return 0;
        }
    }
    else
        cout << "error" << endl;
        return -1;
}

void ExpressionTree::dealloc(node* r){
    if(r!=NULL){
        dealloc(r->left);
        dealloc(r->right);
        delete r;
    }
}

void ExpressionTree::build(){
    // Declaring the operands
    stack<node*> operands;
    node* par = NULL;
    string line;
    
    
    cout << "Add an equation: ";
    
    // Collects the input from the command line for parsing and adds a space to fit the constraints for the algorithm
    getline(cin, line);
    line = line + " ";
    ;
    
    /* Traverses through the line and reads operators/numbers until the first space.  After it reaches
     the space, it makes a new substring from the space to the end of the line and repeats the process
     until the string's length becomes 0;
     */
    
    while (line.length() != 0)
    {
        
        // Finds the space and saves the operator/number into a substring
        long pos = line.find(" ");
        string temp = line.substr(0, pos);
        
        // Reading an operator
        if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
        {
            if (temp == "+")
                par = new node(0, 1);
            if (temp == "-")
                par = new node(1, 1);
            if (temp == "*")
                par = new node(2, 1);
            if (temp == "/")
                par = new node(3, 1);
            par->right = operands.top();
            operands.pop();
            par->left = operands.top();
            operands.pop();
            operands.push(par);
        }
        
        // Reading an operand
        else
        {
            int operand = atoi(temp.c_str());
            node* n = new node(operand);
            operands.push(n);
        }
        
        line = line.substr(pos+1);
    }
    root = par;
}


