//
//  expressiontree.h
//  Lab8
//
//  Created by brian kevin pingel on 2/23/15.
//  Copyright (c) 2015 Brian Pingel & Matthew Koken. All rights reserved.
//

#ifndef Lab8_expressiontree_h
#define Lab8_expressiontree_h

#include <iostream>

class ExpressionTree{
public:
    class node{
    public:
        node(int x) {value = x, type = 0, op = 0, left =NULL, right = NULL;};
        node(int o, int t) {type = t, op = o, left = NULL, right = NULL;};
        int type;
        int value;
        int op;
        node* left;
        node* right;
    };
    node* root;
    void build();
    int evaluateNode(node*);
    int evaluate();
    void print_postorder(node*);
    void print_inorder(node*);
    void print_preorder(node*);
    ExpressionTree();
    ~ExpressionTree();
    void dealloc(node*);
};

#endif
